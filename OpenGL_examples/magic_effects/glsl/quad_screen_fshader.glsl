#version 330 core

out vec4 frag_color;

in vec2 tex_coords;

uniform sampler2D tex;

void main() {
    vec3 color = texture(tex, tex_coords).rgb;
    
    // Simple bloom effect - extract bright areas and add glow
    float brightness = dot(color, vec3(0.2126, 0.7152, 0.0722));
    
    if (brightness > 0.8) {
        color *= 1.2;
    }
    
    // Tone mapping
    color = color / (color + vec3(1.0));
    
    // Gamma correction
    color = pow(color, vec3(1.0 / 2.2));
    
    frag_color = vec4(color, 1.0);
}
