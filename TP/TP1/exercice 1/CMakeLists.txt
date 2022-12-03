cmake_minimum_required(VERSION 3.5)

project(TP1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall)

add_executable(TP1 main.cpp sequence.h)
