#include "Input/Input.hpp"
#include "SDL3/SDL.h"

namespace DPE
{
    void Input::Init()
    {
        m_current_state.fill(false);
        m_previous_state.fill(false);
    }

    void Input::Update()
    {
        m_previous_state = m_current_state;

        const bool* sdl_state = SDL_GetKeyboardState(nullptr);
        for (int i = 0; i < SDL_SCANCODE_COUNT; ++i)
        {
            m_current_state[i] = sdl_state[i];
        }
    }

    bool Input::IsKeyDown(SDL_Scancode key) const
    {
        return m_current_state[key];
    }

    bool Input::IsKeyPressed(SDL_Scancode key) const
    {
        return m_current_state[key] && !m_previous_state[key];
    }

    bool Input::IsKeyReleased(SDL_Scancode key) const
    {
        return !m_current_state[key] && m_previous_state[key];
    }
}
