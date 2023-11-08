cmake_minimum_required(VERSION 3.16)

project(vector)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_library(vector_lib STATIC src/vector.cpp)
add_executable(vector main.cpp)
target_link_libraries(vector vector_lib)