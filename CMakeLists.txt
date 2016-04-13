cmake_minimum_required(VERSION 2.6)
project(kitsune)

set (kitsune_VERSION_MAJOR 0)
set (kitsune_VERSION_MINOR 1)

include_directories(
    "${PROJECT_SOURCE_DIR}/src/"
    "${PROJECT_SOURCE_DIR}/src/painter"
    "${PROJECT_SOURCE_DIR}/external/SDL2-2.0.4/include/")

add_subdirectory(${PROJECT_SOURCE_DIR}/src/painter)

add_executable(kitsune src/main.cpp)
target_link_libraries(kitsune painter)
