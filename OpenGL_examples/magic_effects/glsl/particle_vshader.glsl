#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in float size;

out vec3 particle_color;
out float particle_alpha;

uniform mat4 view;
uniform mat4 projection;
uniform vec3 camera_pos;
uniform float glow_intensity;

void main() {
    vec4 view_pos = view * vec4(position, 1.0);
    gl_Position = projection * view_pos;
    
    // Calculate point size based on distance
    float distance = length(camera_pos - position);
    gl_PointSize = (size * 500.0) / distance;
    
    // Pass color with glow intensity
    particle_color = color * glow_intensity;
    
    // Alpha based on some variation
    particle_alpha = 0.8;
}
