## Build System & Dependency Management

**Build System: CMake**
DutchPot uses CMake with a modern, target-based approach. The root `CMakeLists.txt` handles global setup, finds external dependencies, and includes the `Engine` and `Editor` sub-projects via `add_subdirectory`. 

**Dependency Strategy: Precompiled Binaries & Source Inclusion**
To maintain full control over the build process and ensure fast iteration times, DutchPot avoids package managers like vcpkg and git submodules. 
Instead, dependencies are managed manually inside a `Dependencies/` folder at the project root:
- `SDL3`: Precompiled MSVC binaries (`.lib`, `.dll`, and headers) are downloaded from the official GitHub releases and committed directly to the repo. CMake finds them using `find_package` and an imported target. A post-build command automatically copies the `.dll` to the executable output directory.
- `spdlog`: Compiled externally as a static library with C++23 `std::format` support. The resulting `.lib` files (Debug/Release) and headers are committed to the repo. It is linked via a global `IMPORTED` CMake target.
- `EnTT` & `ImGui`: Will be added later as source/header files committed directly to the repo, compiling alongside the engine.

**Build Configurations**
VS 2022 is the primary IDE. The `CMakePresets.json` file is `.gitignored` to prevent hardcoded local build paths (like `C:/Development/BuildTemp`) from polluting the repository. Anyone cloning this repo will generate a fresh, portable preset file for their machine. 
Compile definitions (like `SPDLOG_ACTIVE_LEVEL`) are handled per-target using CMake generator expressions to ensure trace logs are compiled out in Release builds but active in Debug.
