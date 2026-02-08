#ifndef G_BUFFER_H
#define G_BUFFER_H

#include <GL/glew.h>
#include <iostream>

/**
 * G-Buffer class for deferred shading
 * Stores position, normal, and albedo+specular data in separate textures
 */
class GBuffer {
public:
    GBuffer() : fbo(0), depth_texture(0), position_texture(0), 
                normal_texture(0), albedo_texture(0), width(0), height(0) {}

    void init(int w, int h) {
        width = w;
        height = h;

        glGenFramebuffers(1, &fbo);
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);

        // Position color buffer
        glGenTextures(1, &position_texture);
        glBindTexture(GL_TEXTURE_2D, position_texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, width, height, 0, GL_RGBA, GL_FLOAT, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, position_texture, 0);

        // Normal color buffer
        glGenTextures(1, &normal_texture);
        glBindTexture(GL_TEXTURE_2D, normal_texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, width, height, 0, GL_RGBA, GL_FLOAT, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, normal_texture, 0);

        // Albedo + Specular color buffer
        glGenTextures(1, &albedo_texture);
        glBindTexture(GL_TEXTURE_2D, albedo_texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT2, GL_TEXTURE_2D, albedo_texture, 0);

        // Depth texture
        glGenTextures(1, &depth_texture);
        glBindTexture(GL_TEXTURE_2D, depth_texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depth_texture, 0);

        // Tell OpenGL which color attachments we'll use
        GLuint attachments[3] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2 };
        glDrawBuffers(3, attachments);

        // Check framebuffer completeness
        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
            std::cerr << "Error: G-Buffer framebuffer not complete!" << std::endl;
        }

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void bind_for_geometry_pass() {
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    }

    void unbind() {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    GLuint get_position_texture() const { return position_texture; }
    GLuint get_normal_texture() const { return normal_texture; }
    GLuint get_albedo_texture() const { return albedo_texture; }
    GLuint get_depth_texture() const { return depth_texture; }

    void cleanup() {
        if (fbo != 0) {
            glDeleteFramebuffers(1, &fbo);
        }
        if (position_texture != 0) {
            glDeleteTextures(1, &position_texture);
        }
        if (normal_texture != 0) {
            glDeleteTextures(1, &normal_texture);
        }
        if (albedo_texture != 0) {
            glDeleteTextures(1, &albedo_texture);
        }
        if (depth_texture != 0) {
            glDeleteTextures(1, &depth_texture);
        }
    }

private:
    GLuint fbo;
    GLuint depth_texture;
    GLuint position_texture;
    GLuint normal_texture;
    GLuint albedo_texture;
    int width;
    int height;
};

#endif // G_BUFFER_H
