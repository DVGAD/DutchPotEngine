#include "RenderSystem.hpp"
#include <Renderer/Renderer.hpp>
#include <ECS/Components/Physics/Transform.hpp>
#include <ECS/Components/Rendering/Sprite.hpp>

namespace DPE
{
    void RenderSystem::Update(GameWorld& world, Renderer& renderer)
    {
        auto& registry = world.GetRegistry();
        auto view = registry.view<Transform, Sprite>();

        for (auto entity : view)
        {
            auto& transform = view.get<Transform>(entity);
            auto& sprite = view.get<Sprite>(entity);

            renderer.DrawRect(transform.x, transform.y, sprite.width, sprite.height, sprite.r, sprite.g, sprite.b, sprite.a);
        }
    }
}
