cmake_minimum_required(VERSION 3.20)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project("DutchPotEngine")

# spdlog
add_library(spdlog::spdlog STATIC IMPORTED GLOBAL)
target_include_directories(spdlog::spdlog INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/spdlog/include)
target_compile_definitions(spdlog::spdlog INTERFACE SPDLOG_USE_STD_FORMAT)
set_target_properties(spdlog::spdlog PROPERTIES
    IMPORTED_LOCATION_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/spdlog/lib/Debug/spdlogd.lib"
    IMPORTED_LOCATION_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/spdlog/lib/Release/spdlog.lib"
    IMPORTED_CONFIGURATIONS "DEBUG;RELEASE"
)

# SDL3
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/SDL3/cmake")
find_package(SDL3 REQUIRED CONFIG)

# EnTT
add_library(EnTT::EnTT INTERFACE IMPORTED GLOBAL)
target_include_directories(EnTT::EnTT INTERFACE
    ${CMAKE_SOURCE_DIR}/Dependencies/entt/include
)

add_subdirectory(Engine)
add_subdirectory(Editor)