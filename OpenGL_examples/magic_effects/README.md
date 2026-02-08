# Magic Effects

![screenshot](../screenshots/magic_effects_1.png)

A collection of visual magic/spell effects commonly seen in RPG games and fantasy applications. This example demonstrates various particle systems, shaders, and visual effects techniques to create mystical and magical visuals.

## Features

### 1. Fire Spell
- Orange/red particle system with additive blending
- Animated flames using noise-based displacement
- Glow post-processing effect

### 2. Ice Crystal
- Blue crystalline geometry with refraction simulation
- Frost particle effects
- Shimmer effect using animated normals

### 3. Lightning Bolt
- Procedural lightning generation using line segments
- Branching algorithm for realistic electricity
- Bright white core with blue outline

### 4. Magic Circle
- Rotating runic symbols using instanced rendering
- Glowing geometry with bloom effect
- Pulsating intensity based on time

### 5. Healing Aura
- Green rising particles
- Soft glow with additive blending
- Spiral motion pattern

## Technical Implementation

### Particle System
Uses instanced rendering for efficient drawing of thousands of particles. Each particle has:
- Position, velocity, and acceleration
- Lifetime and fade out
- Color gradient over time
- Size variation

### Additive Blending
Magic effects use additive blending (`GL_ONE, GL_ONE`) to create bright, glowing visuals that combine when overlapping.

### Post-Processing Bloom
A multi-pass blur is applied to bright pixels to create the characteristic "glow" of magical effects.

## Controls

- WASD: Move the camera
- IJKL: Change camera view direction
- 1: Fire spell effect
- 2: Ice crystal effect
- 3: Lightning bolt effect
- 4: Magic circle effect
- 5: Healing aura effect
- Space: Toggle animation
- R: Reset effects
