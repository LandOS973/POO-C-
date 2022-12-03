cmake_minimum_required(VERSION 3.5)

project(sequence LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sequence sequence.cpp sequence.h main.cpp)

install(TARGETS sequence
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
