#pragma once
#include <stdint.h>

struct SDL_Renderer;
struct SDL_Window;

namespace DPE
{
    class Renderer
    {
    public:
        Renderer() = default;
        ~Renderer() = default;

        bool Init(SDL_Window* window);
        void Shutdown();

        void Clear();
        void Present();
        void DrawRect(float x, float y, float width, float height, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    private:
        SDL_Renderer* m_renderer = nullptr;
    };
}
