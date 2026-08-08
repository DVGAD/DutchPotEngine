# 🍲DutchPot Engine (DPE2D)

A 2D game engine built in C++23 with an editor-first workflow.
Focused on learning systems architecture and engine design.

##  🖥️ Tech Stack

- **Language:** C++23
- **Build System:** CMake
- **Windowing/Input/Audio:** SDL3
- **ECS:** EnTT
- **Logging:** spdlog
## 📋 Build Requirements

| Required                |                                Name                                 |      Version       |
| ----------------------- | :-----------------------------------------------------------------: | :----------------: |
| **OS**                  |                               Windows                               |      `10/11`       |
| **Compiler**            |                                MSVC                                 | `v14.51` or higher |
| **IDE** *(Recommended)* | [Visual Studio 2022](https://visualstudio.microsoft.com/downloads/) | `v17.14` or higher |
| **Build System**        |                [CMake](https://cmake.org/download/)                 | `v3.20` or higher  |

## 📦 Build Instructions

1. Clone the repository
2. Open the project folder in Visual Studio 2022
3. VS 2022 will auto-configure CMake and generate a fresh `CMakePresets.json`
4. Select `x64-Debug` configuration
5. Build and run `Editor`

## 📁 Project Structure

```
📂 DutchPotEngine/
├── 📁 Engine/                # Static engine library
│   ├── 📁 Core/              # Engine heartbeat (main loop, windowing)
│   ├── 📁 Log/               # Logging subsystem wrapper
│   ├── 📁 ECS/               # Entity-Component-System architecture
│   ├── 📁 Renderer/          # Graphics pipeline & rendering abstractions
│   ├── 📁 Assets/            # Reference-counted asset pipeline
│   └── 📁 EditorCore/        # In-engine editor hooks & state
├── 📁 Editor/                # Standalone editor executable (main.cpp)
├── 📁 Dependencies/          # Precompiled third-party libraries
│   ├── 📁 SDL3/              # Platform & windowing binaries (MSVC)
│   └── 📁 spdlog/            # Fast C++ logging library (MSVC static)
└── 📁 docs/                  # Architecture & design specifications
```

## 🔗 Dependencies

Dependencies for DPE2D are included in the repository as precompiled MSVC binaries.
If you wish to use a different compiler, you will need to source or compile the dependencies yourself.

| Dependency        |           Type            | Version   |
| ----------------- | :-----------------------: | --------- |
| SDL3              | Precompiled MSVC binaries | `v3.4.14` |
| EnTT              |        Header-only        | `v4.0.0`  |
| spdlog            |  Compiled static library  | `v1.17.0` |

## 📕 Documentation

Design documentation for DPE2D is in the `docs/` folder and covers architecture decisions, ECS design, scheduler design, editor architecture, and more.

## ⚖️ License

**MIT License**

