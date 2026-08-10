#pragma once
#include <EngineCore/Scheduler.hpp>
#include <Renderer/Renderer.hpp>
#include <memory>

struct SDL_Window;

namespace DPE
{
    class GameWorld;
    class Rendering;

    class EngineCore
    {
    public:
        EngineCore();
        ~EngineCore();

        bool Init(int width, int height, char const* title);
        void Run();
    private:
        SDL_Window* m_window = nullptr;
        DPE::Scheduler m_scheduler;
        std::unique_ptr<Renderer> m_renderer = nullptr;
        std::unique_ptr<GameWorld> m_world = nullptr;
        bool m_engine_running = false;
    };
}
