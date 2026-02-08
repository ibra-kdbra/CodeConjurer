#version 330 core

out vec4 frag_color;

in vec3 frag_pos;
in vec3 frag_normal;

uniform vec3 object_color;

void main() {
    // Simple ambient lighting for the floor
    vec3 ambient = 0.3 * object_color;
    
    // Simple diffuse with a top-down light
    vec3 light_dir = normalize(vec3(0.0, 1.0, 0.0));
    float diff = max(dot(normalize(frag_normal), light_dir), 0.0);
    vec3 diffuse = diff * object_color;
    
    vec3 result = ambient + diffuse;
    
    frag_color = vec4(result, 1.0);
}
