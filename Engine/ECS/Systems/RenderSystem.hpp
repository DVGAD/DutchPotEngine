#pragma once
#include <World/GameWorld.hpp>

namespace DPE
{

    class Renderer;

    class RenderSystem
    {
    public:
        static void Update(GameWorld& world, Renderer& renderer);
    };
}
