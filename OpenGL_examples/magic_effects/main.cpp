/**
 * Magic Effects Example
 * 
 * Demonstrates various magical visual effects using particles,
 * shaders, and post-processing techniques.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <chrono>
#include <vector>
#include <random>
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
#include "transform.h"
#include "_quad_screen/quad_screen.h"
#include "framebuffer.h"
#include "drawable.h"

#include "magic_particle_system.hpp"

void init();
void display();
void cleanup();
void update_effects(float time, float delta);

Camera *cam;
Camera cam_fixed;
Camera_free cam_free;

Framebuffer *framebuffer;

// Floor
Cube floor_cube;
Transform floor_transf;

Quad_screen quad_screen;

glm::mat4x4 projection_mat;

// Magic effect systems
MagicParticleSystem fire_system;
MagicParticleSystem ice_system;
MagicParticleSystem lightning_system;
MagicParticleSystem magic_circle_system;
MagicParticleSystem healing_system;

std::vector<Drawable*> lst_drawable;

GLfloat camera_position[3];
GLfloat camera_direction[3];

const int win_width = 1280;
const int win_height = 720;

float time_measured;
int current_effect = 0;
bool animate = true;

GLuint floor_pid;
GLuint particle_pid;

int main() {
    if (!glfwInit()) {
        std::cout << "Error to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(win_width, win_height, "magic_effects", NULL, NULL);

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

        // Effect selection
        if (glfwGetKey(window, '1') == GLFW_PRESS) {
            current_effect = 0; // Fire
        }
        if (glfwGetKey(window, '2') == GLFW_PRESS) {
            current_effect = 1; // Ice
        }
        if (glfwGetKey(window, '3') == GLFW_PRESS) {
            current_effect = 2; // Lightning
        }
        if (glfwGetKey(window, '4') == GLFW_PRESS) {
            current_effect = 3; // Magic circle
        }
        if (glfwGetKey(window, '5') == GLFW_PRESS) {
            current_effect = 4; // Healing
        }

        // Toggle animation
        static bool space_pressed = false;
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            if (!space_pressed) {
                animate = !animate;
                space_pressed = true;
            }
        } else {
            space_pressed = false;
        }

        // Reset effects
        static bool r_pressed = false;
        if (glfwGetKey(window, 'R') == GLFW_PRESS) {
            if (!r_pressed) {
                fire_system.reset();
                ice_system.reset();
                lightning_system.reset();
                magic_circle_system.reset();
                healing_system.reset();
                r_pressed = true;
            }
        } else {
            r_pressed = false;
        }

        if (animate) {
            update_effects(current_time, time_delta);
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

    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);

    ilInit();

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glViewport(0, 0, win_width, win_height);
    projection_mat = glm::perspective(glm::radians(60.0f), (float)win_width / (float)win_height, 0.1f, 100.0f);

    // Load shaders
    floor_pid = load_shaders("floor_vshader.glsl", "floor_fshader.glsl");
    particle_pid = load_shaders("particle_vshader.glsl", "particle_fshader.glsl");

    // Initialize floor
    floor_cube.init(floor_pid);
    floor_cube.set_color(0.15f, 0.15f, 0.2f);
    floor_transf.scale(20.0f, 0.2f, 20.0f);
    floor_transf.translate(0.0f, -0.1f, 0.0f);
    lst_drawable.push_back(&floor_cube);

    // Initialize particle systems with different effects
    
    // Fire effect - orange/red rising particles
    fire_system.init(5000, particle_pid, MagicEffectType::FIRE);
    fire_system.set_position(glm::vec3(0.0f, 0.5f, 0.0f));
    fire_system.set_colors(glm::vec3(1.0f, 0.3f, 0.0f), glm::vec3(1.0f, 0.8f, 0.2f));
    fire_system.set_spawn_radius(0.5f);
    fire_system.set_velocity(glm::vec3(0.0f, 3.0f, 0.0f), 1.0f);
    fire_system.set_lifetime(1.0f, 2.0f);
    fire_system.set_size(0.3f, 0.1f);

    // Ice effect - blue crystalline particles
    ice_system.init(3000, particle_pid, MagicEffectType::ICE);
    ice_system.set_position(glm::vec3(-5.0f, 0.5f, 0.0f));
    ice_system.set_colors(glm::vec3(0.3f, 0.6f, 1.0f), glm::vec3(0.8f, 0.95f, 1.0f));
    ice_system.set_spawn_radius(0.8f);
    ice_system.set_velocity(glm::vec3(0.0f, 0.5f, 0.0f), 0.5f);
    ice_system.set_lifetime(2.0f, 4.0f);
    ice_system.set_size(0.2f, 0.05f);

    // Lightning effect - bright white with blue tint
    lightning_system.init(1000, particle_pid, MagicEffectType::LIGHTNING);
    lightning_system.set_position(glm::vec3(5.0f, 3.0f, 0.0f));
    lightning_system.set_colors(glm::vec3(0.5f, 0.5f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    lightning_system.set_spawn_radius(0.1f);
    lightning_system.set_velocity(glm::vec3(0.0f, -5.0f, 0.0f), 2.0f);
    lightning_system.set_lifetime(0.1f, 0.3f);
    lightning_system.set_size(0.15f, 0.08f);

    // Magic circle - purple rotating particles
    magic_circle_system.init(2000, particle_pid, MagicEffectType::MAGIC_CIRCLE);
    magic_circle_system.set_position(glm::vec3(0.0f, 0.1f, -5.0f));
    magic_circle_system.set_colors(glm::vec3(0.8f, 0.2f, 1.0f), glm::vec3(0.4f, 0.0f, 0.8f));
    magic_circle_system.set_spawn_radius(2.0f);
    magic_circle_system.set_velocity(glm::vec3(0.0f, 0.2f, 0.0f), 0.3f);
    magic_circle_system.set_lifetime(1.5f, 3.0f);
    magic_circle_system.set_size(0.25f, 0.15f);

    // Healing aura - green rising spiral
    healing_system.init(4000, particle_pid, MagicEffectType::HEALING);
    healing_system.set_position(glm::vec3(0.0f, 0.5f, 5.0f));
    healing_system.set_colors(glm::vec3(0.2f, 1.0f, 0.3f), glm::vec3(0.8f, 1.0f, 0.6f));
    healing_system.set_spawn_radius(1.0f);
    healing_system.set_velocity(glm::vec3(0.0f, 2.0f, 0.0f), 0.5f);
    healing_system.set_lifetime(1.5f, 3.0f);
    healing_system.set_size(0.2f, 0.08f);

    // Framebuffer for post-processing (bloom effect)
    framebuffer = new Framebuffer();
    GLuint tex_fb = framebuffer->init(win_width, win_height, true);

    GLuint pid_quad_screen = load_shaders("quad_screen_vshader.glsl", "quad_screen_fshader.glsl");
    quad_screen.init(tex_fb, win_width, win_height, pid_quad_screen);

    // Camera setup
    cam_free.lookAt(8.0f, 6.0f, 8.0f, 0.0f, 2.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    cam_free.set_window_size(win_width, win_height);
    cam = &cam_free;
    cam_free.update_pos();
}

void update_effects(float time, float delta) {
    fire_system.update(time, delta);
    ice_system.update(time, delta);
    lightning_system.update(time, delta);
    magic_circle_system.update(time, delta);
    healing_system.update(time, delta);
}

void display() {
    cam->get_position(camera_position);
    cam->get_direction(camera_direction);

    framebuffer->bind();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw floor
    floor_cube.set_MVP_matrices(floor_transf.get_matrix(), cam->getMatrix(), projection_mat);
    floor_cube.draw();

    // Enable additive blending for magic effects
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glDepthMask(GL_FALSE);

    // Draw active effects based on selection
    fire_system.draw(cam->getMatrix(), projection_mat, camera_position);
    ice_system.draw(cam->getMatrix(), projection_mat, camera_position);
    lightning_system.draw(cam->getMatrix(), projection_mat, camera_position);
    magic_circle_system.draw(cam->getMatrix(), projection_mat, camera_position);
    healing_system.draw(cam->getMatrix(), projection_mat, camera_position);

    // Restore normal blending
    glDepthMask(GL_TRUE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    framebuffer->unbind();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    quad_screen.draw(0);
}

void cleanup() {
    fire_system.cleanup();
    ice_system.cleanup();
    lightning_system.cleanup();
    magic_circle_system.cleanup();
    healing_system.cleanup();
    delete framebuffer;
}
