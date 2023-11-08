cmake_minimum_required(VERSION 3.16)

project(csvLib)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_library(csvLib STATIC src/csvLib.cpp)
add_executable(csv main.cpp)
target_link_libraries(csv csvLib)