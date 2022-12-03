cmake_minimum_required(VERSION 3.5)

project(Tableauaintervalleindices LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Tableauaintervalleindices tableau.h tableau.cpp main.cpp)

install(TARGETS Tableauaintervalleindices
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
