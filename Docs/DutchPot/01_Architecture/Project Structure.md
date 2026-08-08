## Project Structure

DutchPot is separated into a static engine library and a lightweight executable bootstrap.

**Root Directory**
- `Engine/` - The core engine static library (`DutchPotEngine.lib`).
- `Editor/` - The executable entry point (`Editor.exe`). Contains only `main.cpp`.
- `Dependencies/` - All external libraries (SDL3, spdlog, etc.).
- `Docs/` - Obsidian vault containing all design documentation.

**Engine Subsystems (`Engine/`)**
The engine is divided into distinct subsystem folders, keeping concerns isolated:
- `Core/` - The heartbeat of the engine. Contains `EngineCore.hpp/cpp` (application loop, SDL windowing, and lifecycle).
- `Log/` - The logging system. Contains the `Log` class wrapper around `spdlog` and the `DPE_CORE_*` / `DPE_EDITOR_*` macros.
- `ECS/` - (Planned) Entity-Component-System wrappers and component definitions.
- `Renderer/` - (Planned) SDL3 rendering context, sprite batching, and framebuffers.
- `Assets/` - (Planned) Reference-counted asset manager.
- `EditorCore/` - (Planned) Editor-specific systems that live inside the engine library (ImGui panels, Two-World simulation logic, inspector).

**Naming Conventions**
- `EngineCore`: Both a folder name and the primary class that runs the engine.
- `EditorCore`: The folder holding editor systems inside the engine.
- `Editor`: The executable folder. This distinction prevents naming overlaps between the editor *systems* and the editor *application*.
