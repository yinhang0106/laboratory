cmake_minimum_required(VERSION 3.22)

project(lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(profiler/googletest)
add_subdirectory(profiler/benchmark)


add_subdirectory(utils)
add_subdirectory(profiler)

add_subdirectory(erasure)
add_subdirectory(stream)
add_subdirectory(crtp)