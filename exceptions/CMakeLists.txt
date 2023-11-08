cmake_minimum_required(VERSION 3.16)

project(exceptions)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_library(exceptions_lib STATIC src/exceptions.cpp)
add_executable(exceptions main.cpp)
target_link_libraries(exceptions exceptions_lib)