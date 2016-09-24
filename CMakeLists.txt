cmake_minimum_required(VERSION 2.6)
project(kitsune)

set (kitsune_VERSION_MAJOR 0)
set (kitsune_VERSION_MINOR 1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lGL -O3")
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

add_subdirectory(lib/gtest-1.7.0)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/painter)

include_directories(
	${gtest_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/src/painter
    ${PROJECT_SOURCE_DIR}/src/composer
    ${SDL2_INCLUDE_DIR})

add_executable(kitsune src/main.cpp)
target_link_libraries(kitsune painter)
