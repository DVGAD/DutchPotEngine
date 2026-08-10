#pragma once
#include <SDL3/SDL_timer.h>
#include <functional>
#include <vector>

namespace DPE
{
    class Scheduler
    {
    public:
        Scheduler() = default;
        ~Scheduler() = default;

    private:
        using SystemFunc = std::function<void(float)>;
        std::vector<SystemFunc> m_fixed_update_systems;
        std::vector<SystemFunc> m_variable_update_systems;

		float m_accumulator = 0.0f;
        Uint64 m_last_frame_time = 0;
		static float constexpr FIXED_60FPS = 0.01667f;


    public:
		void RegisterVariableSystem(SystemFunc system);
		void RegisterFixedSystem(SystemFunc system);
		void Update();

        float GetDeltaTime();
    };
}
