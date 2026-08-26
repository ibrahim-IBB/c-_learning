cmake_minimum_required(VERSION 3.20)

project(MyGameProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ------------------------------------------------------------------
# Executable
# ------------------------------------------------------------------
add_executable(MyGame
    src/main.cpp
)

# ------------------------------------------------------------------
# SDL3 headers + library search path
# ------------------------------------------------------------------
target_include_directories(MyGame PRIVATE vendor/include)
target_link_directories(MyGame PRIVATE vendor/lib)

target_link_libraries(MyGame PRIVATE
    SDL3
    SDL3_image

)

# ------------------------------------------------------------------
# Runtime DLLs — always copy the project's own DLLs next to the exe,
# so the build never silently depends on a system/global install.
# ------------------------------------------------------------------
add_custom_command(TARGET MyGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/SDL3.dll
        $<TARGET_FILE_DIR:MyGame>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/SDL3_image.dll
        $<TARGET_FILE_DIR:MyGame>
    COMMENT "Copying project-local SDL3 runtime DLLs next to the executable"
)

# ------------------------------------------------------------------
# Assets — junctioned into the build folder, not copied.
# Real files stay in ./assets (tracked in git, survives a build/ wipe).
# Runs once at configure time; skipped on subsequent reconfigures.
# ------------------------------------------------------------------
if(NOT EXISTS ${CMAKE_BINARY_DIR}/assets)
    if(WIN32)
        execute_process(
            COMMAND cmd /c mklink /J "${CMAKE_BINARY_DIR}/assets" "${CMAKE_SOURCE_DIR}/assets"
        )
    else()
        file(CREATE_LINK ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets SYMBOLIC)
    endif()
endif()

# ------------------------------------------------------------------
# Convenience: build + run in one command
#   cmake --build build --target run
# ------------------------------------------------------------------
add_custom_target(run POST_BUILD
    COMMAND MyGame
    DEPENDS MyGame
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)