#include "EngineCore.hpp"
#include <SDL3/SDL.h>
#include <Log/Log.hpp>
#include <Renderer/Renderer.hpp>
#include <World/GameWorld.hpp>
#include <World/Scene.hpp>
#include <Input/Input.hpp>

namespace DPE
{
    EngineCore::EngineCore() {}

    bool EngineCore::Init(int width, int height, char const* title)
    {
        DPE::Log::Init();
        LOG_STATUS("--DutchPotEngine--");

        if (!SDL_Init(SDL_INIT_VIDEO))
        {
            LOG_CRITICAL("SDL_Init Failed: {0}", SDL_GetError());
            return false;
        }

        m_window = SDL_CreateWindow(title, width, height, 0);
        if (!m_window)
        {
            LOG_CRITICAL("SDL_CreateWindow Failed: {0}", SDL_GetError());
            return false;
        }

        LOG_STATUS("Initializing Engine Systems...");

        m_renderer = std::make_unique<Renderer>();
        if (!m_renderer->Init(m_window))
        {
            LOG_CRITICAL("Renderer Initialization Failed {0}", SDL_GetError());
            m_renderer = nullptr;
            return false;
        }

        m_world = std::make_unique<GameWorld>();
        m_input = std::make_unique<Input>();
        m_input->Init();

        LOG_STATUS("Engine Initialization Complete.");
        m_engine_running = true;
        return true;
    }

    void EngineCore::SetScene(std::unique_ptr<Scene> scene)
    {
        if (m_scene)
            m_scene->Shutdown();

        m_scene = std::move(scene);
        m_scene->Init(*m_world, *m_renderer, *m_input);
    }

    EngineCore::~EngineCore()
    {
        LOG_STATUS("Engine Shutting Down...");

        if (m_scene)
            m_scene->Shutdown();
        m_scene.reset();

        m_input.reset();
        m_world.reset();


        if (m_renderer)
            m_renderer->Shutdown();
        m_renderer.reset();

        if (m_window)
        {
            SDL_DestroyWindow(m_window);
            m_window = nullptr;
        }

        SDL_Quit();
        LOG_STATUS("Engine Shutdown: COMPLETE");
        DPE::Log::Shutdown();
    }

    void EngineCore::Run()
    {
        if (!m_engine_running)
        {
            LOG_WARN("Engine Start: FAIL");
            return;
        }

        LOG_STATUS("Engine Start: OK");
        while (m_engine_running)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
                if (event.type == SDL_EVENT_QUIT)
                    m_engine_running = false;

            m_input->Update();
            m_world->Update();
        }
    }
}
