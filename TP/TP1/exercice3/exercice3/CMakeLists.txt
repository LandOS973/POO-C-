cmake_minimum_required(VERSION 3.5)

project(exercice3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(exercice3 main.cpp sequence.h sequence.cpp)

install(TARGETS exercice3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
