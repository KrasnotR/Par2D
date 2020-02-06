cmake_minimum_required(VERSION 3.12.4)
project(Par2D)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "-O2")

add_library(Par2D RenderGFX.cpp RenderGFX.hpp)
target_link_libraries(Par2D ${SDL2_LIBRARIES})