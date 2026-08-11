#pragma once
#include <memory>

struct SDL_Window;

namespace DPE
{
    class Renderer;
    class GameWorld;
    class Scene;
    class Input;

    class EngineCore
    {
    public:
        EngineCore();
        ~EngineCore();

        bool Init(int width, int height, char const* title);
        void Run();
        void SetScene(std::unique_ptr<Scene> scene);

    private:
        SDL_Window* m_window = nullptr;
        std::unique_ptr<Renderer> m_renderer = nullptr;
        std::unique_ptr<GameWorld> m_world = nullptr;
        std::unique_ptr<Scene> m_scene = nullptr;
        std::unique_ptr<Input> m_input = nullptr;
        bool m_engine_running = false;
    };
}
