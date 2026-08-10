#pragma once
#include <memory>
#include <spdlog/spdlog.h>

namespace DPE
{
    class Log
    {
    public:
        static void Init();
        static void Shutdown();

        static std::shared_ptr<spdlog::logger>& EngineStatusLogger() { return s_engine_task_logger; }
        static std::shared_ptr<spdlog::logger>& EngineInfoLogger() { return s_engine_info_logger; }
        static std::shared_ptr<spdlog::logger>& EngineCoreLogger() { return s_engine_core_logger; }

        static std::shared_ptr<spdlog::logger>& EditorStatusLogger() { return s_editor_task_logger; }
        static std::shared_ptr<spdlog::logger>& EditorInfoLogger() { return s_editor_info_logger; }
        static std::shared_ptr<spdlog::logger>& EditorCoreLogger() { return s_editor_core_logger; }
    private:
        static std::shared_ptr<spdlog::logger> s_engine_task_logger;
        static std::shared_ptr<spdlog::logger> s_engine_info_logger;
		static std::shared_ptr<spdlog::logger> s_engine_core_logger;

        static std::shared_ptr<spdlog::logger> s_editor_task_logger;
		static std::shared_ptr<spdlog::logger> s_editor_info_logger;
		static std::shared_ptr<spdlog::logger> s_editor_core_logger;
    };
}

#define LOG_TRACE(...)    SPDLOG_LOGGER_TRACE(::DPE::Log::EngineCoreLogger().get(), __VA_ARGS__)
#define LOG_STATUS(...)     SPDLOG_LOGGER_DEBUG(::DPE::Log::EngineStatusLogger().get(), __VA_ARGS__)
#define LOG_INFO(...)     SPDLOG_LOGGER_INFO(::DPE::Log::EngineInfoLogger().get(), __VA_ARGS__)
#define LOG_WARN(...)     SPDLOG_LOGGER_WARN(::DPE::Log::EngineCoreLogger().get(), __VA_ARGS__)
#define LOG_ERROR(...)    SPDLOG_LOGGER_ERROR(::DPE::Log::EngineCoreLogger().get(), __VA_ARGS__)
#define LOG_CRITICAL(...) SPDLOG_LOGGER_CRITICAL(::DPE::Log::EngineCoreLogger().get(), __VA_ARGS__)

#define LOG_EDITOR_TRACE(...)    SPDLOG_LOGGER_TRACE(::DPE::Log::EditorCoreLogger().get(), __VA_ARGS__)
#define LOG_EDITOR_STATUS(...)     SPDLOG_LOGGER_DEBUG(::DPE::Log::EditorStatusLogger().get(), __VA_ARGS__)
#define LOG_EDITOR_INFO(...)     SPDLOG_LOGGER_INFO(::DPE::Log::EditorInfoLogger().get(), __VA_ARGS__)
#define LOG_EDITOR_WARN(...)     SPDLOG_LOGGER_WARN(::DPE::Log::EditorCoreLogger().get(), __VA_ARGS__)
#define LOG_EDITOR_ERROR(...)    SPDLOG_LOGGER_ERROR(::DPE::Log::EditorCoreLogger().get(), __VA_ARGS__)
#define LOG_EDITOR_CRITICAL(...) SPDLOG_LOGGER_CRITICAL(::DPE::Log::EditorCoreLogger().get(), __VA_ARGS__)

