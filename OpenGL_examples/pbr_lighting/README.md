# Physically Based Rendering (PBR)

![screenshot](../screenshots/pbr_lighting_1.png)

Physically Based Rendering (PBR) is a rendering approach that aims to simulate the flow of light in the real world. This example implements the Cook-Torrance BRDF (Bidirectional Reflectance Distribution Function), which is the industry standard for realistic material rendering.

## Theory

### The Rendering Equation

PBR is based on the rendering equation, which describes how light interacts with surfaces:

```
Lo(p, ωo) = Le(p, ωo) + ∫Ω fr(p, ωi, ωo) Li(p, ωi) (n · ωi) dωi
```

### Cook-Torrance BRDF

The Cook-Torrance BRDF divides light into two components:

1. **Diffuse (Lambertian)**: Light that enters the surface and scatters
2. **Specular**: Light that reflects off the surface

```
fr = kd * f_lambert + ks * f_cook-torrance
```

### Key Components

- **Normal Distribution Function (NDF)**: Describes how microfacets are aligned (Trowbridge-Reitz GGX)
- **Geometry Function**: Describes self-shadowing of microfacets (Smith's method with Schlick-GGX)
- **Fresnel Equation**: Describes how light reflects at different angles (Schlick approximation)

## Material Properties

- **Albedo**: Base color of the material
- **Metallic**: How metallic the surface is (0 = dielectric, 1 = metal)
- **Roughness**: How rough/smooth the surface is (0 = mirror, 1 = fully rough)
- **AO**: Ambient occlusion factor

## Features

- Cook-Torrance BRDF implementation
- Multiple point lights with HDR colors
- Interactive material parameter adjustment
- Real-time roughness/metallic visualization
- Energy conservation

## Controls

- WASD: Move the camera
- IJKL: Change camera view direction
- 1-5: Select different preset materials
- R/F: Increase/decrease roughness
- M/N: Increase/decrease metallic
- Space: Toggle light animation
