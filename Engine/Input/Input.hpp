#pragma once
#include <array>
#include <SDL3/SDL_scancode.h>
namespace DPE
{
    class Input
    {
    public:
        void Init();
        void Update();

        bool IsKeyDown(SDL_Scancode key) const;
        bool IsKeyPressed(SDL_Scancode key) const;
        bool IsKeyReleased(SDL_Scancode key) const;

    private:
        std::array<bool, SDL_SCANCODE_COUNT> m_current_state{};
        std::array<bool, SDL_SCANCODE_COUNT> m_previous_state{};
    };
}
