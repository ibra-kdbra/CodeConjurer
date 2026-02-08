# Deferred Shading

![screenshot](../screenshots/deferred_shading_1.png)

Deferred shading is a screen-space shading technique that separates the geometry pass from the lighting pass. Instead of calculating lighting for each fragment during the geometry pass, the scene's geometry information is first rendered to multiple textures (the G-buffer), and then lighting is calculated in a separate pass.

## How It Works

### Geometry Pass (G-Buffer)
The scene is rendered once, storing the following data in separate textures:
- **Position**: World-space position of each fragment
- **Normal**: Surface normal for lighting calculations
- **Albedo + Specular**: Base color and specular intensity

### Lighting Pass
Using a screen-filling quad, each pixel samples the G-buffer textures and calculates lighting. This approach has several advantages:
- Lighting calculations only happen once per pixel (not per fragment)
- Easy to add many lights without performance penalties
- Enables complex post-processing effects

## Features

- Multiple render targets (MRT) for G-buffer
- Support for many point lights (up to 32 in this demo)
- Light volumes visualization
- Post-processing integration ready

## Advantages Over Forward Rendering

1. **Many Lights**: O(n + m) complexity instead of O(n * m), where n = objects and m = lights
2. **Decoupling**: Geometry and lighting are independent
3. **Post-processing**: Easy access to depth, normals, and positions

## Limitations

- Higher memory bandwidth usage (G-buffer textures)
- Transparency requires additional handling (forward pass)
- MSAA is more complex to implement

## Controls

- WASD: Move the camera
- IJKL: Change camera view direction
- 1: Show combined result
- 2: Show position buffer
- 3: Show normal buffer
- 4: Show albedo buffer
- 5: Show depth buffer
- Space: Toggle light animation
