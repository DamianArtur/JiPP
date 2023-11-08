cmake_minimum_required(VERSION 3.16)

project(arrays)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_library(arrays_lib STATIC src/arrays.cpp)
add_executable(arrays main.cpp)
target_link_libraries(arrays arrays_lib)