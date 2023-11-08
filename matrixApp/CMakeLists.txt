cmake_minimum_required(VERSION 3.20)

project(matrixApp)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR}/matrixLib/include)
add_executable(matrixApp src/main.cpp)
target_link_libraries(matrixApp matrixLib)