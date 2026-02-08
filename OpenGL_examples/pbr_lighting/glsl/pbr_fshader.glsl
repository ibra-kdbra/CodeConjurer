#version 330 core

out vec4 frag_color;

in vec3 world_pos;
in vec3 world_normal;
in vec2 tex_coords;

// Material parameters
uniform vec3 albedo;
uniform float metallic;
uniform float roughness;
uniform float ao;

// Lights
uniform vec3 light_positions[4];
uniform vec3 light_colors[4];

uniform vec3 cam_pos;

const float PI = 3.14159265359;

// Normal Distribution Function (Trowbridge-Reitz GGX)
// Describes the alignment of microfacets
float DistributionGGX(vec3 N, vec3 H, float roughness) {
    float a = roughness * roughness;
    float a2 = a * a;
    float NdotH = max(dot(N, H), 0.0);
    float NdotH2 = NdotH * NdotH;
    
    float nom = a2;
    float denom = (NdotH2 * (a2 - 1.0) + 1.0);
    denom = PI * denom * denom;
    
    return nom / denom;
}

// Geometry function (Schlick-GGX)
// Describes self-shadowing of microfacets
float GeometrySchlickGGX(float NdotV, float roughness) {
    float r = (roughness + 1.0);
    float k = (r * r) / 8.0;
    
    float nom = NdotV;
    float denom = NdotV * (1.0 - k) + k;
    
    return nom / denom;
}

// Smith's method for geometry obstruction and shadowing
float GeometrySmith(vec3 N, vec3 V, vec3 L, float roughness) {
    float NdotV = max(dot(N, V), 0.0);
    float NdotL = max(dot(N, L), 0.0);
    float ggx2 = GeometrySchlickGGX(NdotV, roughness);
    float ggx1 = GeometrySchlickGGX(NdotL, roughness);
    
    return ggx1 * ggx2;
}

// Fresnel equation (Schlick approximation)
// Describes how light reflects at different angles
vec3 fresnelSchlick(float cosTheta, vec3 F0) {
    return F0 + (1.0 - F0) * pow(clamp(1.0 - cosTheta, 0.0, 1.0), 5.0);
}

void main() {
    vec3 N = normalize(world_normal);
    vec3 V = normalize(cam_pos - world_pos);
    
    // Calculate reflectance at normal incidence
    // For dielectrics (non-metals), use 0.04 as base reflectivity
    // For metals, use the albedo color
    vec3 F0 = vec3(0.04);
    F0 = mix(F0, albedo, metallic);
    
    // Reflectance equation
    vec3 Lo = vec3(0.0);
    
    for (int i = 0; i < 4; ++i) {
        // Calculate per-light radiance
        vec3 L = normalize(light_positions[i] - world_pos);
        vec3 H = normalize(V + L);
        float distance = length(light_positions[i] - world_pos);
        float attenuation = 1.0 / (distance * distance);
        vec3 radiance = light_colors[i] * attenuation;
        
        // Cook-Torrance BRDF
        float NDF = DistributionGGX(N, H, roughness);
        float G = GeometrySmith(N, V, L, roughness);
        vec3 F = fresnelSchlick(max(dot(H, V), 0.0), F0);
        
        vec3 numerator = NDF * G * F;
        float denominator = 4.0 * max(dot(N, V), 0.0) * max(dot(N, L), 0.0) + 0.0001;
        vec3 specular = numerator / denominator;
        
        // kS is equal to Fresnel
        vec3 kS = F;
        
        // Energy conservation: diffuse + specular = 1
        // Multiply by (1 - metallic) because metals have no diffuse
        vec3 kD = vec3(1.0) - kS;
        kD *= 1.0 - metallic;
        
        // Scale light by NdotL
        float NdotL = max(dot(N, L), 0.0);
        
        // Add to outgoing radiance Lo
        Lo += (kD * albedo / PI + specular) * radiance * NdotL;
    }
    
    // Ambient lighting (simple approximation)
    vec3 ambient = vec3(0.03) * albedo * ao;
    
    vec3 color = ambient + Lo;
    
    // HDR tonemapping (Reinhard operator)
    color = color / (color + vec3(1.0));
    
    // Gamma correction
    color = pow(color, vec3(1.0 / 2.2));
    
    frag_color = vec4(color, 1.0);
}
