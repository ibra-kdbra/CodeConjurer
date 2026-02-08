/**
 * Deferred Shading Example
 * 
 * This example demonstrates deferred shading, a rendering technique
 * where geometry information is first rendered to a G-buffer, and
 * lighting calculations are performed in a separate pass.
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
#include "_cube/cube.h"
#include "_sphere/sphere.h"
#include "transform.h"
#include "_quad_screen/quad_screen.h"
#include "drawable.h"

#include "g_buffer.hpp"

void init();
void display();
void cleanup();
void render_geometry_pass();
void render_lighting_pass();
void update_lights(float time);

Camera *cam;
Camera cam_fixed;
Camera_free cam_free;

// G-Buffer for deferred shading
GBuffer gbuffer;

// Scene objects
Cube floor_cube;
Transform floor_transf;

Cube wall_cubes[4];
Transform wall_transf[4];

Sphere spheres[5];
Transform sphere_transf[5];

Cube center_cube;
Transform center_cube_transf;

Quad_screen quad_screen;

glm::mat4x4 projection_mat;

std::vector<Drawable*> lst_drawable;

// Light properties
const int NUM_LIGHTS = 32;
struct PointLight {
    glm::vec3 position;
    glm::vec3 color;
    float radius;
};
PointLight lights[NUM_LIGHTS];

GLfloat camera_position[3];
GLfloat camera_direction[3];

const int win_width = 1280;
const int win_height = 720;

float time_measured;
unsigned int display_mode = 0;
bool animate_lights = true;

GLuint geometry_pid;
GLuint lighting_pid;

int main() {
    if (!glfwInit()) {
        std::cout << "Error to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(win_width, win_height, "deferred_shading", NULL, NULL);

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

        // Display mode selection
        if (glfwGetKey(window, '1') == GLFW_PRESS) {
            display_mode = 0; // Combined result
        }
        if (glfwGetKey(window, '2') == GLFW_PRESS) {
            display_mode = 1; // Position buffer
        }
        if (glfwGetKey(window, '3') == GLFW_PRESS) {
            display_mode = 2; // Normal buffer
        }
        if (glfwGetKey(window, '4') == GLFW_PRESS) {
            display_mode = 3; // Albedo buffer
        }
        if (glfwGetKey(window, '5') == GLFW_PRESS) {
            display_mode = 4; // Depth buffer
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

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    ilInit();

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);

    glViewport(0, 0, win_width, win_height);
    projection_mat = glm::perspective(glm::radians(60.0f), (float)win_width / (float)win_height, 0.1f, 100.0f);

    // Initialize G-Buffer
    gbuffer.init(win_width, win_height);

    // Load shaders
    geometry_pid = load_shaders("geometry_vshader.glsl", "geometry_fshader.glsl");
    lighting_pid = load_shaders("lighting_vshader.glsl", "lighting_fshader.glsl");

    // Initialize floor
    floor_cube.init(geometry_pid);
    floor_cube.set_color(0.3f, 0.3f, 0.3f);
    floor_transf.scale(20.0f, 0.5f, 20.0f);
    floor_transf.translate(0.0f, -0.25f, 0.0f);
    lst_drawable.push_back(&floor_cube);

    // Initialize walls
    float wall_colors[4][3] = {
        {0.6f, 0.2f, 0.2f},
        {0.2f, 0.6f, 0.2f},
        {0.2f, 0.2f, 0.6f},
        {0.6f, 0.6f, 0.2f}
    };

    for (int i = 0; i < 4; i++) {
        wall_cubes[i].init(geometry_pid);
        wall_cubes[i].set_color(wall_colors[i][0], wall_colors[i][1], wall_colors[i][2]);
    }

    wall_transf[0].translate(0.0f, 5.0f, 10.0f);
    wall_transf[0].scale(20.0f, 10.0f, 0.5f);

    wall_transf[1].translate(0.0f, 5.0f, -10.0f);
    wall_transf[1].scale(20.0f, 10.0f, 0.5f);

    wall_transf[2].translate(10.0f, 5.0f, 0.0f);
    wall_transf[2].scale(0.5f, 10.0f, 20.0f);

    wall_transf[3].translate(-10.0f, 5.0f, 0.0f);
    wall_transf[3].scale(0.5f, 10.0f, 20.0f);

    for (int i = 0; i < 4; i++) {
        lst_drawable.push_back(&wall_cubes[i]);
    }

    // Initialize spheres
    float sphere_colors[5][3] = {
        {1.0f, 0.5f, 0.2f},
        {0.5f, 1.0f, 0.2f},
        {0.2f, 0.5f, 1.0f},
        {1.0f, 0.2f, 0.5f},
        {0.8f, 0.8f, 0.8f}
    };

    for (int i = 0; i < 5; i++) {
        spheres[i].init(geometry_pid, 24, 24);
        spheres[i].set_color(sphere_colors[i][0], sphere_colors[i][1], sphere_colors[i][2]);
        lst_drawable.push_back(&spheres[i]);
    }

    sphere_transf[0].translate(-4.0f, 1.5f, -4.0f);
    sphere_transf[0].scale(1.5f, 1.5f, 1.5f);

    sphere_transf[1].translate(4.0f, 1.5f, -4.0f);
    sphere_transf[1].scale(1.5f, 1.5f, 1.5f);

    sphere_transf[2].translate(-4.0f, 1.5f, 4.0f);
    sphere_transf[2].scale(1.5f, 1.5f, 1.5f);

    sphere_transf[3].translate(4.0f, 1.5f, 4.0f);
    sphere_transf[3].scale(1.5f, 1.5f, 1.5f);

    sphere_transf[4].translate(0.0f, 2.0f, 0.0f);
    sphere_transf[4].scale(2.0f, 2.0f, 2.0f);

    // Initialize center cube
    center_cube.init(geometry_pid);
    center_cube.set_color(0.9f, 0.9f, 0.9f);
    center_cube_transf.translate(0.0f, 6.0f, 0.0f);
    center_cube_transf.scale(2.0f, 2.0f, 2.0f);
    lst_drawable.push_back(&center_cube);

    // Initialize quad screen for lighting pass
    quad_screen.init(gbuffer.get_position_texture(), win_width, win_height, lighting_pid);

    // Initialize lights in a circular pattern
    for (int i = 0; i < NUM_LIGHTS; i++) {
        float angle = (2.0f * M_PI * i) / NUM_LIGHTS;
        float radius = 7.0f;

        lights[i].position = glm::vec3(
            cos(angle) * radius,
            1.0f + (i % 4) * 1.5f,
            sin(angle) * radius
        );

        // Colorful lights
        lights[i].color = glm::vec3(
            0.5f + 0.5f * sin(angle),
            0.5f + 0.5f * sin(angle + 2.0f),
            0.5f + 0.5f * sin(angle + 4.0f)
        );

        lights[i].radius = 8.0f;
    }

    // Camera setup
    cam_free.lookAt(0.0f, 8.0f, -15.0f, 0.0f, 3.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    cam_free.set_window_size(win_width, win_height);
    cam = &cam_free;
    cam_free.update_pos();
}

void update_lights(float time) {
    for (int i = 0; i < NUM_LIGHTS; i++) {
        float base_angle = (2.0f * M_PI * i) / NUM_LIGHTS;
        float angle = base_angle + time * 0.5f;
        float radius = 7.0f + sin(time * 2.0f + i) * 1.0f;

        lights[i].position.x = cos(angle) * radius;
        lights[i].position.y = 1.0f + (i % 4) * 1.5f + sin(time * 3.0f + i) * 0.5f;
        lights[i].position.z = sin(angle) * radius;
    }
}

void render_geometry_pass() {
    gbuffer.bind_for_geometry_pass();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Render all objects to G-buffer
    floor_cube.set_MVP_matrices(floor_transf.get_matrix(), cam->getMatrix(), projection_mat);
    floor_cube.draw();

    for (int i = 0; i < 4; i++) {
        wall_cubes[i].set_MVP_matrices(wall_transf[i].get_matrix(), cam->getMatrix(), projection_mat);
        wall_cubes[i].draw();
    }

    for (int i = 0; i < 5; i++) {
        spheres[i].set_MVP_matrices(sphere_transf[i].get_matrix(), cam->getMatrix(), projection_mat);
        spheres[i].draw();
    }

    center_cube.set_MVP_matrices(center_cube_transf.get_matrix(), cam->getMatrix(), projection_mat);
    center_cube.draw();

    gbuffer.unbind();
}

void render_lighting_pass() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glUseProgram(lighting_pid);

    // Bind G-buffer textures
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gbuffer.get_position_texture());
    glUniform1i(glGetUniformLocation(lighting_pid, "g_position"), 0);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, gbuffer.get_normal_texture());
    glUniform1i(glGetUniformLocation(lighting_pid, "g_normal"), 1);

    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, gbuffer.get_albedo_texture());
    glUniform1i(glGetUniformLocation(lighting_pid, "g_albedo_spec"), 2);

    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, gbuffer.get_depth_texture());
    glUniform1i(glGetUniformLocation(lighting_pid, "g_depth"), 3);

    // Pass light data to shader
    for (int i = 0; i < NUM_LIGHTS; i++) {
        std::string index = std::to_string(i);
        glUniform3fv(glGetUniformLocation(lighting_pid, ("lights[" + index + "].position").c_str()), 1, &lights[i].position[0]);
        glUniform3fv(glGetUniformLocation(lighting_pid, ("lights[" + index + "].color").c_str()), 1, &lights[i].color[0]);
        glUniform1f(glGetUniformLocation(lighting_pid, ("lights[" + index + "].radius").c_str()), lights[i].radius);
    }

    // Camera position for specular
    cam->get_position(camera_position);
    glUniform3fv(glGetUniformLocation(lighting_pid, "view_pos"), 1, camera_position);

    // Display mode
    glUniform1i(glGetUniformLocation(lighting_pid, "display_mode"), display_mode);

    // Number of lights
    glUniform1i(glGetUniformLocation(lighting_pid, "num_lights"), NUM_LIGHTS);

    quad_screen.draw(0);
}

void display() {
    cam->get_position(camera_position);
    cam->get_direction(camera_direction);

    // Rotate center cube
    if (time_measured != 0.0f) {
        float diff = glfwGetTime() - time_measured;
        center_cube_transf.rotate(0.0f, 1.0f, 0.0f, diff * 0.5f);
    }
    time_measured = glfwGetTime();

    // Deferred shading passes
    render_geometry_pass();
    render_lighting_pass();
}

void cleanup() {
    gbuffer.cleanup();
}
