cmake_minimum_required(VERSION 3.16)

project(node)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_library(node_lib STATIC src/node.cpp)
add_executable(node main.cpp)
target_link_libraries(node node_lib)