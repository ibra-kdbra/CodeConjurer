#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

out vec3 world_pos;
out vec3 world_normal;
out vec2 tex_coords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    world_pos = vec3(model * vec4(position, 1.0));
    world_normal = mat3(transpose(inverse(model))) * normal;
    tex_coords = uv;
    
    gl_Position = projection * view * vec4(world_pos, 1.0);
}
