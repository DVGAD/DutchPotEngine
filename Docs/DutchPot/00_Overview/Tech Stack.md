## Tech Stack

**Build System: CMake**
`CMake` is the industry standard for C++ projects and handles the complexity of managing multiple dependencies (`SDL3`, `EnTT`, `ImGui`, scripting bindings) cleanly. It also scales well if the project grows beyond a single developer.

**Platform & Language: C++ 23 (Windows Only)** 
C++ was chosen as the core language for its performance, control over memory, and industry relevance in game engine development. DutchPot targets Windows only to reduce platform abstraction complexity during the learning phase. This decision can be revisited later without major architectural changes since `SDL3` and the other chosen libraries are cross-platform.

**Windowing, Input and Rendering: SDL3**
`SDL3` provides a clean middle ground. It handles OS window creation, input polling, and provides a modern rendering context without imposing a high-level sprite framework.
This means DutchPot builds its own Sprite, Animation, and Batch-Renderer classes from scratch on top of `SDL3`'s rendering context. This aligns perfectly with the goal of building custom systems while avoiding the tedium of OS-level graphics code.
`SDL3` specifically was chosen over `SDL2` because it is a major architectural overhaul with a cleaner API and a more modern GPU abstraction layer.

**Entity Architecture: ECS with EnTT**
DutchPot uses an Entity-Component-System architecture. This was chosen over traditional object-oriented inheritance to avoid the refactoring problems that come with deep class hierarchies. With ECS new features can be added by creating new components and systems without modifying existing code.
The `EnTT` library was chosen as the ECS implementation rather than building one from scratch. Building a custom ECS is a valuable learning exercise but it is a rabbit hole that can consume months of development time. `Entt` is the industry standard C++ ECS library, it is header-only, extremely performant, and handles all memory management and cache optimization internally. Using it allows focus to remain on building the actual engine systems.

**Editor: Dear ImGui**
`ImGui` with the docking branch is used for the editor interface. `ImGui` was chosen because it is lightweight, immediate-mode (meaning no complex UI state management), and integrates cleanly with `SDL3`. 
The docking branch allows for detachable panels similar to `Unity` and `Godot`.
The editor renders the game viewport by rendering the game scene to a framebuffer object and displaying that texture inside an `ImGui` window. This allows the game to run inside the editor without a separate window.

**Logging: spdlog**
`spdlog` is used for all engine and editor logging. It is compiled as a static library externally and linked via CMake as an imported target.
It was specifically configured with `SPDLOG_USE_STD_FORMAT` to use modern C++23 `std::format` syntax rather than bundling the older `fmt` library.
Logging is wrapped in a custom `Log` class inside the engine that initializes two distinct loggers: one for the EngineCore (`DPE`) and one for the Editor (`EDITOR`). 
Custom macros (e.g., `DPE_CORE_INFO`, `DPE_EDITOR_ERROR`) are provided to automatically inject source location (`__FILE__`, `__LINE__`) and to allow stripping lower-level logs (Trace/Info) out of Release builds for performance.










