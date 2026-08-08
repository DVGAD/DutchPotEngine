#pragma once

// Forward declaration of SDL_Window
struct SDL_Window;

// EngineCore class definition
namespace DPE
{
    class EngineCore
    {
    public:
        // Constructor
        EngineCore(int width, int height, char const* title);

        // Destructor
        ~EngineCore();

        // Run the main loop of the engine
        void Run();
    private:
		// Engine boolean to control the main loop
        bool m_engine_running = true;
		// SDL_Window pointer to hold the window instance
        SDL_Window* m_window = nullptr;
    };
}
