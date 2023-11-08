cmake_minimum_required(VERSION 3.16)

project(imaginary)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_library(imaginary_lib STATIC src/imaginary.cpp)
add_executable(imaginary main.cpp)
target_link_libraries(imaginary imaginary_lib)