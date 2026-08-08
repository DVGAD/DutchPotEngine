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

        static std::shared_ptr<spdlog::logger>& GetEngineCoreLogger() { return s_engine_core_logger; }
        static std::shared_ptr<spdlog::logger>& GetEditorLogger() { return s_editor_logger; }
    private:
        static std::shared_ptr<spdlog::logger> s_engine_core_logger;
        static std::shared_ptr<spdlog::logger> s_editor_logger;
    };
}

// Engine Core Logging Macros
#define DPE_CORE_TRACE(...)    SPDLOG_LOGGER_TRACE(::DPE::Log::GetEngineCoreLogger().get(), __VA_ARGS__)
#define DPE_CORE_INFO(...)     SPDLOG_LOGGER_INFO(::DPE::Log::GetEngineCoreLogger().get(), __VA_ARGS__)
#define DPE_CORE_WARN(...)     SPDLOG_LOGGER_WARN(::DPE::Log::GetEngineCoreLogger().get(), __VA_ARGS__)
#define DPE_CORE_ERROR(...)    SPDLOG_LOGGER_ERROR(::DPE::Log::GetEngineCoreLogger().get(), __VA_ARGS__)
#define DPE_CORE_CRITICAL(...) SPDLOG_LOGGER_CRITICAL(::DPE::Log::GetEngineCoreLogger().get(), __VA_ARGS__)

// Editor Logging Macros
#define DPE_EDITOR_TRACE(...)    SPDLOG_LOGGER_TRACE(::DPE::Log::GetEditorLogger().get(), __VA_ARGS__)
#define DPE_EDITOR_INFO(...)     SPDLOG_LOGGER_INFO(::DPE::Log::GetEditorLogger().get(), __VA_ARGS__)
#define DPE_EDITOR_WARN(...)     SPDLOG_LOGGER_WARN(::DPE::Log::GetEditorLogger().get(), __VA_ARGS__)
#define DPE_EDITOR_ERROR(...)    SPDLOG_LOGGER_ERROR(::DPE::Log::GetEditorLogger().get(), __VA_ARGS__)
#define DPE_EDITOR_CRITICAL(...) SPDLOG_LOGGER_CRITICAL(::DPE::Log::GetEditorLogger().get(), __VA_ARGS__)

