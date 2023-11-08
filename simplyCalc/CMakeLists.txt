cmake_minimum_required(VERSION 3.16)

project(simplyCalc)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_library(calc STATIC src/calc.cpp)
add_executable(simplyCalc main.cpp)
target_link_libraries(simplyCalc calc)