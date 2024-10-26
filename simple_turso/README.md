# Simple_Turso

An experimental 3D/game engine technology partially based on the Urho3D codebase.

- OpenGL 3.2 / SDL2
- Forward+ rendering, currently up to 255 lights in view
- Threaded work queue to speed up animation and view preparation
- Caching of static shadow maps
- Hardware occlusion queries that work on the octree hierarchy
- SSAO

## Test application controls

- WSAD + mouse to move
- SHIFT move faster
- F1-F3 switch scene preset
- SPACE toggle scene animation
- 1 toggle shadow modes
- 2 toggle SSAO
- 3 toggle occlusion culling
- 4 toggle scene debug draw
- 5 toggle shadow debug draw
- F toggle fullscreen
- V toggle vsync
