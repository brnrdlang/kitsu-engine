cmake_minimum_required(VERSION 2.6)
project(kitsune)

set (kitsune_VERSION_MAJOR 0)
set (kitsune_VERSION_MINOR 1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(lib/gtest-1.7.0)
add_subdirectory(lib/SDL2-2.0.3)

include_directories(
	${gtest_SOURCE_DIR}/include
    ${SDL2_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/src/painter)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/painter)

add_executable(kitsune src/main.cpp)
target_link_libraries(kitsune painter)
