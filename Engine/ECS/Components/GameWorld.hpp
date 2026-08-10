#pragma once
#include <entt/entity/registry.hpp>

namespace DPE
{
    class GameWorld
    {
    public:
        GameWorld() = default;
        ~GameWorld() = default;

        entt::registry& GetRegistry() { return m_registry; }

    private:
        entt::registry m_registry;
 
    };
}