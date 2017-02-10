cmake_minimum_required(VERSION 3.6)
project(clientSk2)

set(CMAKE_CXX_STANDARD 11)
include_directories(./headers ${CMAKE_BINARY_DIR})
set(SOURCE_FILES main.cpp ./headers/client.h src/client.cpp)
add_executable(clientSk2  main.cpp src/client.cpp ${SOURCE_FILES})