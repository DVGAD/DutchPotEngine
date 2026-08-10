add_library(DutchPotEngine STATIC
    EngineCore/EngineCore.cpp
    EngineCore/Scheduler.cpp
    Renderer/Renderer.cpp
    ECS/Components/GameWorld.cpp
    ECS/Systems/MovementSystem.cpp
    ECS/Systems/RenderSystem.cpp

    Log/Log.cpp
)

target_include_directories(DutchPotEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(DutchPotEngine PRIVATE
    $<$<CONFIG:Debug>:SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_TRACE>
    $<$<CONFIG:Release>:SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_INFO>
)

target_link_libraries(DutchPotEngine PUBLIC
    SDL3::SDL3
    spdlog::spdlog
    EnTT::EnTT
)
