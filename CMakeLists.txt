cmake_minimum_required(VERSION 3.6)
project(MemcashedServer)

set(CMAKE_CXX_STANDARD 11)
include_directories(./headers ${CMAKE_BINARY_DIR})
set(SOURCE_FILES main.cpp src/server.cpp)
add_executable(MemcashedServer main.cpp src/server.cpp)