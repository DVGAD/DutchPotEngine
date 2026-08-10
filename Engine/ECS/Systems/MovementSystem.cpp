#include <ECS/Systems/MovementSystem.hpp>
#include <ECS/Components/Physics/Physics.hpp>
#include <Log/Log.hpp>

namespace DPE
{
    void MovementSystem::Update(GameWorld& world, float dt)
    {
        auto& registry = world.GetRegistry();
        auto view = registry.view<Transform, Velocity>();

        for (auto entity : view)
        {
            auto& transform = view.get<Transform>(entity);
            auto& velocity = view.get<Velocity>(entity);

            transform.x += velocity.x * dt;
            transform.y += velocity.y * dt;
        }
    }
}
