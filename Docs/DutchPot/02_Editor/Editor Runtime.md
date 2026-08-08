### Editor Architecture: Two-World Simulation Separation

The editor and the game runtime live in the same application. The editor is not a separate tool that launches the game as a child process. Instead the editor runs inside the same window as the game, with the game viewport rendered to an ImGui panel.
This architecture was chosen because the editor is the core product of this project. The workflow is designed around rapid iteration — making changes in the editor and seeing results immediately without launching a separate application.
To support a Play/Stop workflow where the game can be run and then returned to its original editor state, DutchPot uses a two-world architecture.

**Editor World** holds the pristine, unmodified state of the level being edited. When the user hits the Play button, the Editor World is cloned into a Game World. The simulation runs in the Game World. Entities move, collide, and are destroyed, but only in the Game World. The Editor World remains untouched.
When the user hits Stop, the Game World is destroyed and the editor returns to viewing the Editor World, which is exactly as it was before Play was pressed.

This architecture is critical for hot reloading. When a script or asset is modified while the game is running, the new logic or resource is applied to the Game World. If the reload causes a crash or unexpected behavior, only the Game World is affected. The Editor World remains safe and intact.

Assets are shared between both worlds. Textures, audio files, and scripts are loaded once by the Asset Manager and referenced by both the Editor World and the Game World. This means that hot reloading an asset updates it in both the editor viewport and the game viewport simultaneously. Only entity data (the ECS state) is duplicated between worlds.