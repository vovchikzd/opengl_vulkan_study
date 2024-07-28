cmake_minimum_required(VERSION 3.28)

project(opengl_vulkan_study
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS Off)
set(CMAKE_COLOR_DIAGNOSTICS On)
add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(result)
target_sources(result PUBLIC
                 ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
