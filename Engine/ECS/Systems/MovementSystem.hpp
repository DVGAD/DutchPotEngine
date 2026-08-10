#pragma once
#include <ECS/Components/GameWorld.hpp>

namespace DPE
{
    class MovementSystem
    {
    public:
        static void Update(GameWorld& world, float dt);
    };
}
