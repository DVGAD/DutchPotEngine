#include <SDL3/SDL.h>
#include <EngineCore/EngineCore.hpp>
#include <ECS/Components/GameWorld.hpp>
#include <ECS/Components/Physics/Physics.hpp>
#include <ECS/Components/Rendering/Rendering.hpp>
#include <ECS/Systems/RenderSystem.hpp>
#include <ECS/Systems/MovementSystem.hpp>
#include <Log/Log.hpp>

namespace DPE
{
    EngineCore::EngineCore() {}

    bool EngineCore::Init(int width, int height, char const* title)
    {
        DPE::Log::Init();
        LOG_STATUS("--DutchPotEngine--");
        LOG_STATUS("Initializing Engine Systems...");

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

        m_renderer = std::make_unique<Renderer>();
        if (!m_renderer->Init(m_window))
        {
            LOG_CRITICAL("Renderer Initialization Failed {0}", SDL_GetError());
            m_renderer = nullptr;
            return false;
        }
        m_scheduler.RegisterVariableSystem([this](float dt) { m_renderer->Clear(); m_renderer->Present(); });
        //----------------------------------//

        // Test
        m_world = std::make_unique<GameWorld>();
        entt::entity test_entity = m_world->GetRegistry().create();
        m_world->GetRegistry().emplace<Transform>(test_entity, 100.0f, 200.0f);
        m_world->GetRegistry().emplace<Velocity>(test_entity, 50.0f, 0.0f);
        m_world->GetRegistry().emplace<Sprite>(test_entity, 50.0f, 50.0f, uint8_t{ 255 }, uint8_t{ 0 }, uint8_t{ 0 }, uint8_t{ 255 });

        m_scheduler.RegisterVariableSystem([this](float dt) { m_renderer->Clear(); });
        m_scheduler.RegisterVariableSystem([this](float dt) {
            RenderSystem::Update(*m_world, *m_renderer);});
        m_scheduler.RegisterVariableSystem([this](float dt) { m_renderer->Present(); });
        m_scheduler.RegisterFixedSystem([this](float dt) {
            MovementSystem::Update(*m_world, dt);});

		//---------------------------------//
        LOG_STATUS("Engine Initialization Complete.");
        m_engine_running = true;
        return true;
	}

    EngineCore::~EngineCore()
    {
        LOG_STATUS("Engine Closing...");

        if (m_renderer)
            m_renderer->Shutdown();
        m_renderer.reset(); 

        if (m_window)
        {
            SDL_DestroyWindow(m_window);
            m_window = nullptr;
        }

        SDL_Quit();
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

            m_scheduler.Update();
        }
    }
}

