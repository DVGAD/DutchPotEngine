#include <SDL3/SDL_render.h>
#include <Log/Log.hpp>
#include "Renderer.hpp"

namespace DPE
{
    bool Renderer::Init(SDL_Window* window)
    {
        m_renderer = SDL_CreateRenderer(window, NULL);
        if (!m_renderer)
        {
            LOG_CRITICAL("Renderer Failed: {}", SDL_GetError());
            return false;
        }

        if (!SDL_SetRenderVSync(m_renderer, 1))
        {
            LOG_WARN("Renderer(V-Sync): FAIL", SDL_GetError());
        }

        LOG_STATUS("Renderer(V-Sync): OK");
        return true;
    }

    void Renderer::Shutdown()
    {
        if (m_renderer)
        {
            SDL_DestroyRenderer(m_renderer);
            m_renderer = nullptr;
        }
    }

    void Renderer::Clear()
    {
        SDL_SetRenderDrawColor(m_renderer, 30, 30, 30, 255);
        SDL_RenderClear(m_renderer);
    }

    void Renderer::Present()
    {
        SDL_RenderPresent(m_renderer);
    }

    void Renderer::DrawRect(float x, float y, float width, float height, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    {
        SDL_FRect rect = { x, y, width, height };
        SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
        SDL_RenderFillRect(m_renderer, &rect);
    }
}

