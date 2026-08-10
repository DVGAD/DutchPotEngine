#include <EngineCore/Scheduler.hpp>

namespace DPE
{
	void Scheduler::RegisterVariableSystem(SystemFunc system)
	{
		m_variable_update_systems.emplace_back(system);
	}

	void Scheduler::RegisterFixedSystem(SystemFunc system)
	{
		m_fixed_update_systems.emplace_back(system);
	}

	void Scheduler::Update()
	{
		
		float delta_time = GetDeltaTime();
		m_accumulator += delta_time;

		while (m_accumulator >= FIXED_60FPS)
		{
			for (auto& system : m_fixed_update_systems)
				system(FIXED_60FPS);
			m_accumulator -= FIXED_60FPS;
		}

		for (auto& system : m_variable_update_systems)
			system(GetDeltaTime());
	}

	float Scheduler::GetDeltaTime()
	{
		Uint64 current_time = SDL_GetPerformanceCounter();
		Uint64 frequency = SDL_GetPerformanceFrequency();
		float delta_time = static_cast<float>(current_time - m_last_frame_time) / static_cast<float>(frequency);
		m_last_frame_time = current_time;
		if (delta_time > 1.0f)
			delta_time = 1.0f;
		return delta_time;
	}
}