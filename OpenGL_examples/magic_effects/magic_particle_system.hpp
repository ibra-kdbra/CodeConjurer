#ifndef MAGIC_PARTICLE_SYSTEM_HPP
#define MAGIC_PARTICLE_SYSTEM_HPP

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <random>
#include <cmath>

enum class MagicEffectType {
    FIRE,
    ICE,
    LIGHTNING,
    MAGIC_CIRCLE,
    HEALING
};

struct MagicParticle {
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 color;
    float lifetime;
    float max_lifetime;
    float size;
    float rotation;
    bool active;
};

/**
 * Magic Particle System
 * Handles different types of magical visual effects
 */
class MagicParticleSystem {
public:
    MagicParticleSystem() : vao(0), vbo_positions(0), vbo_colors(0), 
                            vbo_sizes(0), shader_pid(0), num_particles(0),
                            effect_type(MagicEffectType::FIRE) {}

    void init(int max_particles, GLuint pid, MagicEffectType type) {
        shader_pid = pid;
        num_particles = max_particles;
        effect_type = type;

        particles.resize(max_particles);
        positions.resize(max_particles);
        colors.resize(max_particles);
        sizes.resize(max_particles);

        // Initialize random generator
        std::random_device rd;
        rng = std::mt19937(rd());

        // Initialize all particles as inactive
        for (auto& p : particles) {
            p.active = false;
            p.lifetime = 0;
        }

        // Create VAO and VBOs
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        // Positions VBO
        glGenBuffers(1, &vbo_positions);
        glBindBuffer(GL_ARRAY_BUFFER, vbo_positions);
        glBufferData(GL_ARRAY_BUFFER, max_particles * sizeof(glm::vec3), nullptr, GL_DYNAMIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        glEnableVertexAttribArray(0);

        // Colors VBO
        glGenBuffers(1, &vbo_colors);
        glBindBuffer(GL_ARRAY_BUFFER, vbo_colors);
        glBufferData(GL_ARRAY_BUFFER, max_particles * sizeof(glm::vec3), nullptr, GL_DYNAMIC_DRAW);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        glEnableVertexAttribArray(1);

        // Sizes VBO
        glGenBuffers(1, &vbo_sizes);
        glBindBuffer(GL_ARRAY_BUFFER, vbo_sizes);
        glBufferData(GL_ARRAY_BUFFER, max_particles * sizeof(float), nullptr, GL_DYNAMIC_DRAW);
        glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, 0, nullptr);
        glEnableVertexAttribArray(2);

        glBindVertexArray(0);
    }

    void set_position(const glm::vec3& pos) { spawn_position = pos; }
    void set_colors(const glm::vec3& start, const glm::vec3& end) { 
        color_start = start; 
        color_end = end; 
    }
    void set_spawn_radius(float radius) { spawn_radius = radius; }
    void set_velocity(const glm::vec3& base_vel, float variance) { 
        base_velocity = base_vel; 
        velocity_variance = variance; 
    }
    void set_lifetime(float min_lt, float max_lt) { 
        min_lifetime = min_lt; 
        max_lifetime = max_lt; 
    }
    void set_size(float start, float end) { 
        size_start = start; 
        size_end = end; 
    }

    void update(float time, float delta) {
        // Spawn new particles
        int spawn_count = static_cast<int>(spawn_rate * delta * num_particles);
        for (int i = 0; i < spawn_count; i++) {
            spawn_particle(time);
        }

        // Update existing particles
        active_count = 0;
        for (size_t i = 0; i < particles.size(); i++) {
            if (particles[i].active) {
                particles[i].lifetime -= delta;

                if (particles[i].lifetime <= 0) {
                    particles[i].active = false;
                    continue;
                }

                // Update position based on effect type
                update_particle_motion(particles[i], time, delta);

                // Calculate life factor (0 to 1)
                float life_factor = particles[i].lifetime / particles[i].max_lifetime;

                // Update color
                particles[i].color = glm::mix(color_end, color_start, life_factor);

                // Update size
                particles[i].size = glm::mix(size_end, size_start, life_factor);

                // Store data for rendering
                positions[active_count] = particles[i].position;
                colors[active_count] = particles[i].color;
                sizes[active_count] = particles[i].size;
                active_count++;
            }
        }

        // Upload data to GPU
        glBindBuffer(GL_ARRAY_BUFFER, vbo_positions);
        glBufferSubData(GL_ARRAY_BUFFER, 0, active_count * sizeof(glm::vec3), positions.data());

        glBindBuffer(GL_ARRAY_BUFFER, vbo_colors);
        glBufferSubData(GL_ARRAY_BUFFER, 0, active_count * sizeof(glm::vec3), colors.data());

        glBindBuffer(GL_ARRAY_BUFFER, vbo_sizes);
        glBufferSubData(GL_ARRAY_BUFFER, 0, active_count * sizeof(float), sizes.data());
    }

    void draw(const glm::mat4& view, const glm::mat4& projection, const GLfloat* cam_pos) {
        if (active_count == 0) return;

        glUseProgram(shader_pid);

        glUniformMatrix4fv(glGetUniformLocation(shader_pid, "view"), 1, GL_FALSE, &view[0][0]);
        glUniformMatrix4fv(glGetUniformLocation(shader_pid, "projection"), 1, GL_FALSE, &projection[0][0]);
        glUniform3fv(glGetUniformLocation(shader_pid, "camera_pos"), 1, cam_pos);
        glUniform1f(glGetUniformLocation(shader_pid, "glow_intensity"), get_glow_intensity());

        glBindVertexArray(vao);
        glDrawArrays(GL_POINTS, 0, active_count);
        glBindVertexArray(0);
    }

    void reset() {
        for (auto& p : particles) {
            p.active = false;
        }
        active_count = 0;
    }

    void cleanup() {
        if (vao != 0) glDeleteVertexArrays(1, &vao);
        if (vbo_positions != 0) glDeleteBuffers(1, &vbo_positions);
        if (vbo_colors != 0) glDeleteBuffers(1, &vbo_colors);
        if (vbo_sizes != 0) glDeleteBuffers(1, &vbo_sizes);
    }

private:
    void spawn_particle(float time) {
        // Find inactive particle
        for (auto& p : particles) {
            if (!p.active) {
                p.active = true;
                
                // Random position within spawn radius
                std::uniform_real_distribution<float> dist(-1.0f, 1.0f);
                std::uniform_real_distribution<float> lifetime_dist(min_lifetime, max_lifetime);
                
                glm::vec3 offset = glm::vec3(
                    dist(rng) * spawn_radius,
                    dist(rng) * spawn_radius * 0.5f,
                    dist(rng) * spawn_radius
                );

                // Special spawn patterns for different effects
                if (effect_type == MagicEffectType::MAGIC_CIRCLE) {
                    float angle = dist(rng) * 3.14159f * 2.0f;
                    float radius = spawn_radius * (0.8f + dist(rng) * 0.2f);
                    offset = glm::vec3(cos(angle) * radius, 0.0f, sin(angle) * radius);
                } else if (effect_type == MagicEffectType::HEALING) {
                    float angle = dist(rng) * 3.14159f * 2.0f;
                    std::uniform_real_distribution<float> radius_dist(0.0f, 1.0f);
                    float radius = spawn_radius * sqrt(radius_dist(rng));
                    offset = glm::vec3(cos(angle) * radius, 0.0f, sin(angle) * radius);
                }

                p.position = spawn_position + offset;
                
                // Initial velocity with variance
                p.velocity = base_velocity + glm::vec3(
                    dist(rng) * velocity_variance,
                    dist(rng) * velocity_variance,
                    dist(rng) * velocity_variance
                );
                
                p.max_lifetime = lifetime_dist(rng);
                p.lifetime = p.max_lifetime;
                p.color = color_start;
                p.size = size_start;
                p.rotation = dist(rng) * 3.14159f * 2.0f;
                
                break;
            }
        }
    }

    void update_particle_motion(MagicParticle& p, float time, float delta) {
        switch (effect_type) {
            case MagicEffectType::FIRE:
                // Fire rises with turbulence
                p.velocity.x = sin(time * 3.0f + p.position.y * 2.0f) * 0.5f;
                p.velocity.z = cos(time * 2.5f + p.position.y * 2.0f) * 0.5f;
                p.position += p.velocity * delta;
                break;

            case MagicEffectType::ICE:
                // Ice drifts slowly and sparkles
                p.velocity.x = sin(time * 1.0f + p.position.y) * 0.2f;
                p.velocity.z = cos(time * 1.2f + p.position.y) * 0.2f;
                p.position += p.velocity * delta;
                break;

            case MagicEffectType::LIGHTNING:
                // Lightning is fast and erratic
                {
                    std::uniform_real_distribution<float> dist(-5.0f, 5.0f);
                    p.velocity.x += dist(rng) * delta * 10.0f;
                    p.velocity.z += dist(rng) * delta * 10.0f;
                    p.position += p.velocity * delta;
                }
                break;

            case MagicEffectType::MAGIC_CIRCLE:
                // Particles orbit and rise slowly
                {
                    float angle = atan2(p.position.z - spawn_position.z, p.position.x - spawn_position.x);
                    float radius = glm::length(glm::vec2(p.position.x - spawn_position.x, p.position.z - spawn_position.z));
                    angle += delta * 2.0f; // Rotation speed
                    p.position.x = spawn_position.x + cos(angle) * radius;
                    p.position.z = spawn_position.z + sin(angle) * radius;
                    p.position.y += p.velocity.y * delta;
                }
                break;

            case MagicEffectType::HEALING:
                // Healing particles spiral upward
                {
                    float angle = atan2(p.position.z - spawn_position.z, p.position.x - spawn_position.x);
                    float radius = glm::length(glm::vec2(p.position.x - spawn_position.x, p.position.z - spawn_position.z));
                    angle += delta * 3.0f;
                    radius *= (1.0f - delta * 0.5f); // Slowly shrink radius
                    p.position.x = spawn_position.x + cos(angle) * radius;
                    p.position.z = spawn_position.z + sin(angle) * radius;
                    p.position.y += p.velocity.y * delta;
                }
                break;
        }
    }

    float get_glow_intensity() const {
        switch (effect_type) {
            case MagicEffectType::FIRE: return 1.5f;
            case MagicEffectType::ICE: return 1.2f;
            case MagicEffectType::LIGHTNING: return 2.5f;
            case MagicEffectType::MAGIC_CIRCLE: return 1.8f;
            case MagicEffectType::HEALING: return 1.3f;
            default: return 1.0f;
        }
    }

    GLuint vao;
    GLuint vbo_positions;
    GLuint vbo_colors;
    GLuint vbo_sizes;
    GLuint shader_pid;
    
    int num_particles;
    int active_count = 0;
    MagicEffectType effect_type;
    
    std::vector<MagicParticle> particles;
    std::vector<glm::vec3> positions;
    std::vector<glm::vec3> colors;
    std::vector<float> sizes;
    
    std::mt19937 rng;
    
    glm::vec3 spawn_position = glm::vec3(0.0f);
    glm::vec3 color_start = glm::vec3(1.0f);
    glm::vec3 color_end = glm::vec3(0.5f);
    glm::vec3 base_velocity = glm::vec3(0.0f, 1.0f, 0.0f);
    
    float spawn_radius = 1.0f;
    float velocity_variance = 0.5f;
    float min_lifetime = 1.0f;
    float max_lifetime = 3.0f;
    float size_start = 0.2f;
    float size_end = 0.05f;
    float spawn_rate = 0.1f;
};

#endif // MAGIC_PARTICLE_SYSTEM_HPP
