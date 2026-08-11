#pragma once
#include <entt/entity/registry.hpp>
#include <EngineCore/Scheduler.hpp>

class Scheduler;

namespace DPE
{
    class GameWorld
    {
    public:
        GameWorld() = default;
        ~GameWorld() = default;

        entt::registry& GetRegistry() { return m_registry; }
        Scheduler& GetScheduler() { return m_scheduler; }

        void Update() { m_scheduler.Update(); }

    private:
        entt::registry m_registry;
        Scheduler m_scheduler;
        
    };
}
