#version 330 core

out vec4 frag_color;

in vec3 particle_color;
in float particle_alpha;

void main() {
    // Create circular particle with soft edges
    vec2 coord = gl_PointCoord - vec2(0.5);
    float dist = length(coord);
    
    // Discard fragments outside the circle
    if (dist > 0.5) {
        discard;
    }
    
    // Soft edge falloff
    float alpha = 1.0 - smoothstep(0.3, 0.5, dist);
    alpha *= particle_alpha;
    
    // Add some glow by boosting center brightness
    float glow = 1.0 - dist * 2.0;
    glow = max(glow, 0.0);
    vec3 color = particle_color * (1.0 + glow * 0.5);
    
    frag_color = vec4(color, alpha);
}
