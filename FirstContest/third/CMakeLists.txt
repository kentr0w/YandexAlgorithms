cmake_minimum_required(VERSION 3.13)
project(third)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address,undefined -fno-sanitize-recover=all"
        CACHE STRING "Compiler flags in asan build"
        FORCE)

add_executable(third main.cpp)