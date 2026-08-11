#include <SDL3/SDL_scancode.h>
#include <ECS/Components/Physics/Velocity.hpp>
#include <ECS/Components/Core/PlayerController.hpp>
#include <Input/Input.hpp>
#include "InputSystem.hpp"

namespace DPE
{
    void InputSystem::Update(GameWorld& world, Input& input)
    {
        auto& registry = world.GetRegistry();
        auto view = registry.view<Velocity, PlayerController>();

        for (auto entity : view)
        {
            auto& velocity = view.get<Velocity>(entity);
            auto& controller = view.get<PlayerController>(entity);

            velocity.x = 0.0f;
            velocity.y = 0.0f;

            if (input.IsKeyDown(SDL_SCANCODE_LEFT) || input.IsKeyDown(SDL_SCANCODE_A))
                velocity.x = -controller.move_speed;

            if (input.IsKeyDown(SDL_SCANCODE_RIGHT) || input.IsKeyDown(SDL_SCANCODE_D))
                velocity.x = controller.move_speed;

            if (input.IsKeyDown(SDL_SCANCODE_UP) || input.IsKeyDown(SDL_SCANCODE_W))
                velocity.y = -controller.move_speed;

            if (input.IsKeyDown(SDL_SCANCODE_DOWN) || input.IsKeyDown(SDL_SCANCODE_S))
                velocity.y = controller.move_speed;
        }
    }
}
