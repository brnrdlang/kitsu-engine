cmake_minimum_required(VERSION 2.6)
project(kitsune)

set (kitsune_VERSION_MAJOR 0)
set (kitsune_VERSION_MINOR 1)

include_directories(
    "${PROJECT_SOURCE_DIR}/src/"
    "${PROJECT_SOURCE_DIR}/src/painter")

add_subdirectory(${PROJECT_SOURCE_DIR}/src/painter)

add_executable(kitsune src/main.cpp)
target_link_libraries(kitsune painter)
