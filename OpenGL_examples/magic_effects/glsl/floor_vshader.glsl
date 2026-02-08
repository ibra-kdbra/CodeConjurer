#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

out vec3 frag_pos;
out vec3 frag_normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    vec4 world_pos = model * vec4(position, 1.0);
    frag_pos = world_pos.xyz;
    frag_normal = mat3(transpose(inverse(model))) * normal;
    
    gl_Position = projection * view * world_pos;
}
