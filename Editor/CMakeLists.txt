# CMakeLists.txt for the Editor project

add_executable(Editor main.cpp)
target_link_libraries(Editor PRIVATE DutchPotEngine)

# Copy SDL3 shared library to the output directory on Windows
if(WIN32)
    add_custom_command(
        TARGET Editor POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy
            $<TARGET_FILE:SDL3::SDL3-shared>
            $<TARGET_FILE_DIR:Editor>
        VERBATIM
    )
endif()
