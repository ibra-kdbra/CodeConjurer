#version 330 core

layout (location = 0) out vec4 g_position;
layout (location = 1) out vec4 g_normal;
layout (location = 2) out vec4 g_albedo_spec;

in vec3 frag_pos;
in vec3 frag_normal;
in vec2 frag_uv;

uniform vec3 object_color;
uniform float specular_intensity;

void main() {
    // Store position in world space
    g_position = vec4(frag_pos, 1.0);
    
    // Store normalized normal in world space
    g_normal = vec4(normalize(frag_normal), 1.0);
    
    // Store albedo color and specular intensity
    g_albedo_spec.rgb = object_color;
    g_albedo_spec.a = specular_intensity;
}
