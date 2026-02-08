#version 330 core

out vec4 frag_color;

in vec2 tex_coords;

uniform sampler2D g_position;
uniform sampler2D g_normal;
uniform sampler2D g_albedo_spec;
uniform sampler2D g_depth;

struct Light {
    vec3 position;
    vec3 color;
    float radius;
};

#define MAX_LIGHTS 32
uniform Light lights[MAX_LIGHTS];
uniform int num_lights;
uniform vec3 view_pos;
uniform int display_mode;

void main() {
    // Retrieve data from G-buffer
    vec3 frag_pos = texture(g_position, tex_coords).rgb;
    vec3 normal = normalize(texture(g_normal, tex_coords).rgb);
    vec3 albedo = texture(g_albedo_spec, tex_coords).rgb;
    float specular_intensity = texture(g_albedo_spec, tex_coords).a;
    float depth = texture(g_depth, tex_coords).r;

    // Display mode selection for debugging G-buffer
    if (display_mode == 1) {
        // Position buffer visualization
        frag_color = vec4(frag_pos * 0.1, 1.0);
        return;
    } else if (display_mode == 2) {
        // Normal buffer visualization
        frag_color = vec4(normal * 0.5 + 0.5, 1.0);
        return;
    } else if (display_mode == 3) {
        // Albedo buffer visualization
        frag_color = vec4(albedo, 1.0);
        return;
    } else if (display_mode == 4) {
        // Depth buffer visualization
        float linear_depth = (2.0 * 0.1 * 100.0) / (100.0 + 0.1 - depth * (100.0 - 0.1));
        frag_color = vec4(vec3(linear_depth / 100.0), 1.0);
        return;
    }

    // Skip empty pixels (background)
    if (length(normal) < 0.1) {
        discard;
    }

    // Calculate lighting
    vec3 view_dir = normalize(view_pos - frag_pos);
    
    // Ambient component
    vec3 ambient = 0.05 * albedo;
    vec3 lighting = ambient;

    // Calculate contribution from each light
    for (int i = 0; i < num_lights && i < MAX_LIGHTS; i++) {
        vec3 light_dir = normalize(lights[i].position - frag_pos);
        float distance = length(lights[i].position - frag_pos);
        
        // Attenuation based on light radius
        float attenuation = 1.0 - clamp(distance / lights[i].radius, 0.0, 1.0);
        attenuation = attenuation * attenuation; // Quadratic falloff
        
        if (attenuation > 0.0) {
            // Diffuse
            float diff = max(dot(normal, light_dir), 0.0);
            vec3 diffuse = diff * lights[i].color * albedo;
            
            // Specular (Blinn-Phong)
            vec3 halfway_dir = normalize(light_dir + view_dir);
            float spec = pow(max(dot(normal, halfway_dir), 0.0), 32.0);
            vec3 specular = spec * lights[i].color * specular_intensity;
            
            lighting += (diffuse + specular) * attenuation;
        }
    }

    frag_color = vec4(lighting, 1.0);
}
