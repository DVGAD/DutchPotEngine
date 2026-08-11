#pragma once
#include <World/GameWorld.hpp>

namespace DPE
{
    class MovementSystem
    {
    public:
        static void Update(GameWorld& world, float dt);
    };
}
