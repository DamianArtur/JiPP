cmake_minimum_required(VERSION 3.16)

project(calcArea)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_library(area STATIC src/area.cpp)
add_executable(calcArea main.cpp)
target_link_libraries(calcArea area)