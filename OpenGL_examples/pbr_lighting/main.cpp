/**
 * Physically Based Rendering (PBR) Example
 * 
 * This example demonstrates PBR lighting using the Cook-Torrance BRDF.
 * Features metallic-roughness workflow commonly used in modern game engines.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <chrono>
#include <vector>
#define GL_GLEXT_PROTOTYPES 1
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <IL/il.h>
#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "camera.h"
#include "camera_free.h"
#include "shader_helper.h"
#include "_sphere/sphere.h"
#include "_cube/cube.h"
#include "transform.h"
#include "drawable.h"

void init();
void display();
void cleanup();
void update_lights(float time);

Camera *cam;
Camera cam_fixed;
Camera_free cam_free;

// PBR spheres for material demonstration
const int SPHERE_ROWS = 7;
const int SPHERE_COLS = 7;
Sphere spheres[SPHERE_ROWS][SPHERE_COLS];
Transform sphere_transf[SPHERE_ROWS][SPHERE_COLS];

// Floor
Cube floor_cube;
Transform floor_transf;

glm::mat4x4 projection_mat;

// Light properties
const int NUM_LIGHTS = 4;
struct PointLight {
    glm::vec3 position;
    glm::vec3 color;
};
PointLight lights[NUM_LIGHTS];

// Material presets
struct Material {
    glm::vec3 albedo;
    float metallic;
    float roughness;
    float ao;
};

Material current_material;
int material_preset = 0;

GLfloat camera_position[3];
GLfloat camera_direction[3];

const int win_width = 1280;
const int win_height = 720;

float time_measured;
bool animate_lights = true;

GLuint pbr_pid;

int main() {
    if (!glfwInit()) {
        std::cout << "Error to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(win_width, win_height, "pbr_lighting", NULL, NULL);

    if (!window) {
        std::cout << "Failed to open window" << std::endl;
        return -1;
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_NO_ERROR) {
        std::cout << "GLEW error\n";
        return -1;
    }

    init();

    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window)) {
        glfwPollEvents();

        static float prev_time = 0;
        float current_time = glfwGetTime();
        float time_delta = current_time - prev_time;

        // Camera controls
        if (glfwGetKey(window, 'S') == GLFW_PRESS) {
            cam->input_handling('S', time_delta);
        }
        if (glfwGetKey(window, 'A') == GLFW_PRESS) {
            cam->input_handling('A', time_delta);
        }
        if (glfwGetKey(window, 'W') == GLFW_PRESS) {
            cam->input_handling('W', time_delta);
        }
        if (glfwGetKey(window, 'D') == GLFW_PRESS) {
            cam->input_handling('D', time_delta);
        }
        if (glfwGetKey(window, 'L') == GLFW_PRESS) {
            cam->input_handling('L', time_delta);
        }
        if (glfwGetKey(window, 'J') == GLFW_PRESS) {
            cam->input_handling('J', time_delta);
        }
        if (glfwGetKey(window, 'K') == GLFW_PRESS) {
            cam->input_handling('K', time_delta);
        }
        if (glfwGetKey(window, 'I') == GLFW_PRESS) {
            cam->input_handling('I', time_delta);
        }

        // Material presets
        if (glfwGetKey(window, '1') == GLFW_PRESS) {
            material_preset = 0; // Gold
        }
        if (glfwGetKey(window, '2') == GLFW_PRESS) {
            material_preset = 1; // Silver
        }
        if (glfwGetKey(window, '3') == GLFW_PRESS) {
            material_preset = 2; // Copper
        }
        if (glfwGetKey(window, '4') == GLFW_PRESS) {
            material_preset = 3; // Plastic (Red)
        }
        if (glfwGetKey(window, '5') == GLFW_PRESS) {
            material_preset = 4; // Rubber
        }

        // Toggle light animation
        static bool space_pressed = false;
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            if (!space_pressed) {
                animate_lights = !animate_lights;
                space_pressed = true;
            }
        } else {
            space_pressed = false;
        }

        if (animate_lights) {
            update_lights(current_time);
        }

        display();
        glfwSwapBuffers(window);

        prev_time = current_time;
    }

    cleanup();
    return 0;
}

void init() {
    time_measured = 0.0f;

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    ilInit();

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);

    glViewport(0, 0, win_width, win_height);
    projection_mat = glm::perspective(glm::radians(60.0f), (float)win_width / (float)win_height, 0.1f, 100.0f);

    // Load PBR shader
    pbr_pid = load_shaders("pbr_vshader.glsl", "pbr_fshader.glsl");

    // Initialize spheres in a grid pattern to demonstrate roughness/metallic variations
    float spacing = 2.5f;
    for (int row = 0; row < SPHERE_ROWS; row++) {
        for (int col = 0; col < SPHERE_COLS; col++) {
            spheres[row][col].init(pbr_pid, 32, 32);
            
            float x = (col - (SPHERE_COLS / 2)) * spacing;
            float y = (row - (SPHERE_ROWS / 2)) * spacing + 5.0f;
            float z = 0.0f;
            
            sphere_transf[row][col].translate(x, y, z);
        }
    }

    // Initialize floor
    GLuint floor_pid = load_shaders("pbr_vshader.glsl", "pbr_fshader.glsl");
    floor_cube.init(floor_pid);
    floor_transf.scale(30.0f, 0.5f, 30.0f);
    floor_transf.translate(0.0f, -5.0f, 0.0f);

    // Initialize lights with HDR colors
    lights[0].position = glm::vec3(-10.0f, 10.0f, 10.0f);
    lights[0].color = glm::vec3(300.0f, 300.0f, 300.0f);

    lights[1].position = glm::vec3(10.0f, 10.0f, 10.0f);
    lights[1].color = glm::vec3(300.0f, 300.0f, 300.0f);

    lights[2].position = glm::vec3(-10.0f, -10.0f, 10.0f);
    lights[2].color = glm::vec3(300.0f, 300.0f, 300.0f);

    lights[3].position = glm::vec3(10.0f, -10.0f, 10.0f);
    lights[3].color = glm::vec3(300.0f, 300.0f, 300.0f);

    // Camera setup
    cam_free.lookAt(0.0f, 5.0f, -25.0f, 0.0f, 5.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    cam_free.set_window_size(win_width, win_height);
    cam = &cam_free;
    cam_free.update_pos();

    // Default material
    current_material.albedo = glm::vec3(0.5f, 0.0f, 0.0f);
    current_material.metallic = 0.5f;
    current_material.roughness = 0.5f;
    current_material.ao = 1.0f;
}

void update_lights(float time) {
    float radius = 15.0f;
    for (int i = 0; i < NUM_LIGHTS; i++) {
        float angle = time * 0.5f + (i * M_PI / 2.0f);
        lights[i].position.x = cos(angle) * radius;
        lights[i].position.z = sin(angle) * radius + 10.0f;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    cam->get_position(camera_position);
    cam->get_direction(camera_direction);

    glUseProgram(pbr_pid);

    // Pass camera position
    glUniform3fv(glGetUniformLocation(pbr_pid, "cam_pos"), 1, camera_position);

    // Pass light data
    for (int i = 0; i < NUM_LIGHTS; i++) {
        std::string idx = std::to_string(i);
        glUniform3fv(glGetUniformLocation(pbr_pid, ("light_positions[" + idx + "]").c_str()), 1, &lights[i].position[0]);
        glUniform3fv(glGetUniformLocation(pbr_pid, ("light_colors[" + idx + "]").c_str()), 1, &lights[i].color[0]);
    }

    // Material presets for the base albedo
    glm::vec3 presetAlbedos[5] = {
        glm::vec3(1.0f, 0.765f, 0.336f),  // Gold
        glm::vec3(0.972f, 0.960f, 0.915f), // Silver
        glm::vec3(0.955f, 0.637f, 0.538f), // Copper
        glm::vec3(0.8f, 0.1f, 0.1f),       // Red Plastic
        glm::vec3(0.2f, 0.2f, 0.2f)        // Rubber
    };

    float presetMetallic[5] = { 1.0f, 1.0f, 1.0f, 0.0f, 0.0f };

    glm::vec3 baseAlbedo = presetAlbedos[material_preset];
    float baseMetallic = presetMetallic[material_preset];

    // Render spheres with varying roughness and metallic values
    for (int row = 0; row < SPHERE_ROWS; row++) {
        for (int col = 0; col < SPHERE_COLS; col++) {
            // Metallic varies from 0 to 1 across columns
            float metallic = glm::clamp((float)col / (float)(SPHERE_COLS - 1), 0.05f, 1.0f);
            
            // Roughness varies from 0 to 1 across rows
            float roughness = glm::clamp((float)row / (float)(SPHERE_ROWS - 1), 0.05f, 1.0f);

            glUniform3fv(glGetUniformLocation(pbr_pid, "albedo"), 1, &baseAlbedo[0]);
            glUniform1f(glGetUniformLocation(pbr_pid, "metallic"), metallic);
            glUniform1f(glGetUniformLocation(pbr_pid, "roughness"), roughness);
            glUniform1f(glGetUniformLocation(pbr_pid, "ao"), 1.0f);

            spheres[row][col].set_MVP_matrices(sphere_transf[row][col].get_matrix(), cam->getMatrix(), projection_mat);
            spheres[row][col].draw();
        }
    }

    // Render floor
    glUniform3f(glGetUniformLocation(pbr_pid, "albedo"), 0.3f, 0.3f, 0.3f);
    glUniform1f(glGetUniformLocation(pbr_pid, "metallic"), 0.0f);
    glUniform1f(glGetUniformLocation(pbr_pid, "roughness"), 0.8f);
    glUniform1f(glGetUniformLocation(pbr_pid, "ao"), 1.0f);

    floor_cube.set_MVP_matrices(floor_transf.get_matrix(), cam->getMatrix(), projection_mat);
    floor_cube.draw();
}

void cleanup() {
}
