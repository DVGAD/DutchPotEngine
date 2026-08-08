#include "Log/Log.hpp"
#include <spdlog/sinks/stdout_color_sinks.h>

namespace DPE
{
    std::shared_ptr<spdlog::logger> Log::s_engine_core_logger;
    std::shared_ptr<spdlog::logger> Log::s_editor_logger;

    void Log::Init() {
        // Pattern: [Time] [LoggerName] [Message]
        spdlog::set_pattern("%^[%T] [%n] %v%$");

        s_engine_core_logger = spdlog::stdout_color_mt("ENGINE");
        s_engine_core_logger->set_level(spdlog::level::trace);

        s_editor_logger = spdlog::stdout_color_mt("EDITOR");
        s_editor_logger->set_level(spdlog::level::trace);
    }

    void Log::Shutdown()
    {
        // Clear shared_ptrs then call spdlog shutdown to release sinks
        s_engine_core_logger.reset();
        s_editor_logger.reset();
        spdlog::shutdown();
    }
}
