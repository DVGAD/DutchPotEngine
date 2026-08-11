#pragma once
#include <World/GameWorld.hpp>

namespace DPE
{
    class Input;

    class InputSystem
    {
    public:
        static void Update(GameWorld& world, Input& input);
    };
}
