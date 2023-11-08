cmake_minimum_required(VERSION 3.16)

project(triangle)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/node/include)
add_library(triangle_lib STATIC src/triangle.cpp)
add_executable(triangle main.cpp)
target_link_libraries(triangle triangle_lib)
target_link_libraries(triangle node_lib)