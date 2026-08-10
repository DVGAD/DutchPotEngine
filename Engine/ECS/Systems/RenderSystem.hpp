#pragma once
#include <ECS/Components/GameWorld.hpp>

namespace DPE
{

    class Renderer;

    class RenderSystem
    {
    public:
        static void Update(GameWorld& world, Renderer& renderer);
    };
}
