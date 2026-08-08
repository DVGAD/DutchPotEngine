### Asset Management: Reference Counting with On-Demand Loading

DutchPot uses a reference-counted asset manager. Assets are loaded into memory when a system first requests them and remain in memory as long as at least one system is using them. When the reference count drops to zero the asset is unloaded.

This approach was chosen over camera-based streaming for several reasons. Streaming is primarily a solution for memory-constrained environments or massive 3D open worlds where everything cannot fit in RAM at once. 
For a 2D sprite-based engine on a modern system with 16GB or more of RAM, a complete level with high-resolution sprites, multiple parallax layers, and effects fits comfortably in memory. Streaming adds significant complexity around predicting what needs to load and when, and introduces bugs like pop-in where assets appear late on screen.

Reference counting is simpler, more predictable, and protects against accidentally deleting an asset that is still in use. It is the standard approach used by engines like `Unity` and `Unreal`.

Assets are loaded on a per-level basis. When a level starts the required assets are loaded. When a level ends they are unloaded. Individual systems request and release assets as needed during gameplay.