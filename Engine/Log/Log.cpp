#include <spdlog/sinks/stdout_color_sinks.h>
#include <Log/Log.hpp>

namespace DPE
{
    std::shared_ptr<spdlog::logger> Log::s_engine_task_logger;
    std::shared_ptr<spdlog::logger> Log::s_engine_info_logger;
    std::shared_ptr<spdlog::logger> Log::s_engine_core_logger;
	std::shared_ptr<spdlog::logger> Log::s_editor_task_logger;
	std::shared_ptr<spdlog::logger> Log::s_editor_info_logger;
	std::shared_ptr<spdlog::logger> Log::s_editor_core_logger;

    void Log::Init() 
    {
        s_engine_task_logger = spdlog::stdout_color_mt("ENGINE STATUS");
        s_engine_info_logger = spdlog::stdout_color_mt("ENGINE INFO");
        s_engine_core_logger = spdlog::stdout_color_mt("ENGINE CORE");
        s_engine_task_logger->set_pattern("[%n] %v%$");
        s_engine_info_logger->set_pattern("[%n] %v [%!] [%s:%#]%$");
        s_engine_core_logger->set_pattern("[%n] %v [%!] [%T] [%s:%#]%$");
        s_engine_task_logger->set_level(spdlog::level::debug);
        s_engine_info_logger->set_level(spdlog::level::info);
        s_engine_core_logger->set_level(spdlog::level::debug);

		s_editor_task_logger = spdlog::stdout_color_mt("EDITOR STATUS");
        s_editor_info_logger = spdlog::stdout_color_mt("EDITOR INFO");
		s_editor_core_logger = spdlog::stdout_color_mt("EDITOR CORE");
		s_editor_task_logger->set_pattern("[%n] %v%$");
		s_editor_info_logger->set_pattern("[%n] %v [%!] [%s:%#]%$");
		s_editor_core_logger->set_pattern("[%n] %v [%!] [%T] [%s:%#]%$");
		s_editor_task_logger->set_level(spdlog::level::debug);
		s_editor_info_logger->set_level(spdlog::level::info);
		s_editor_core_logger->set_level(spdlog::level::debug);
    }

    void Log::Shutdown()
    {
		s_engine_task_logger.reset();
		s_engine_info_logger.reset();
        s_engine_core_logger.reset();
        s_editor_task_logger.reset();
        s_editor_info_logger.reset();
        s_editor_core_logger.reset();
        spdlog::shutdown();
    }
}
