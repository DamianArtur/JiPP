cmake_minimum_required(VERSION 3.20)

project(matrixLib)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
add_library(matrixLib STATIC src/matrixLib.cpp)