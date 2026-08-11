#pragma once
#include <World/GameWorld.hpp>

namespace DPE
{
    class Renderer;
    class Input;

    class Scene
    {
    public:
        Scene() = default;
        virtual ~Scene() = default;

        virtual void Init(GameWorld& world, Renderer& renderer, Input& input) = 0;
        virtual void Shutdown() = 0;
    };
}
