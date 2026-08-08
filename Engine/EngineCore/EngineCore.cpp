// Using SDL3 API
#include <SDL3/SDL.h>

#include "EngineCore/EngineCore.hpp"
#include "Log/Log.hpp"

// EngineCore class implementation
namespace DPE
{
	// Constructor
    EngineCore::EngineCore(int width, int height, char const* title)
    {
		// Initialize the logging system
        DPE::Log::Init();

		// Log the initialization of the engine
        DPE_CORE_INFO("Initializing DutchPotEngine...");

        if (!SDL_Init(SDL_INIT_VIDEO))
        {
			// Log the error if SDL initialization fails
            DPE_CORE_CRITICAL("SDL_Init failed: {0}", SDL_GetError());
            m_engine_running = false;
            return;
        }

		// Create the SDL window
        m_window = SDL_CreateWindow(title, width, height, 0);
        if (!m_window)
        {
			// Log the error if window creation fails
            DPE_CORE_CRITICAL("SDL_CreateWindow failed: {0}", SDL_GetError());
            m_engine_running = false;
        }
    }

    // Destructor
    EngineCore::~EngineCore()
    {
        // Log the shutdown of the engine
        DPE_CORE_INFO("Engine shutting down...");

        if (m_window)
        {
            SDL_DestroyWindow(m_window);
            m_window = nullptr;
        }
		// Quit SDL subsystems
        SDL_Quit();

        // Shutdown logging
        DPE::Log::Shutdown();
    }

	// Run the main loop of the engine
    void EngineCore::Run() 
    {
        // Only start if initialization succeeded
        if (!m_engine_running)
        {
            DPE_CORE_WARN("Engine Run() called but initialization failed.");
            return;
        }

		// Log that the engine has started
        DPE_CORE_INFO("Engine started.");

		// Main loop
        while (m_engine_running)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
                if (event.type == SDL_EVENT_QUIT)
                    m_engine_running = false;
        }
    }
}
