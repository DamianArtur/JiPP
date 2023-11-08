cmake_minimum_required(VERSION 3.16)

project(pointers)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_library(pointers_lib STATIC src/pointers.cpp)
add_executable(pointers main.cpp)
target_link_libraries(pointers pointers_lib)