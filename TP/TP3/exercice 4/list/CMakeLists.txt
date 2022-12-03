cmake_minimum_required(VERSION 3.5)

project(list LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(list graphe.h graphe.cpp sommet.h sommet.cpp main.cpp)

install(TARGETS list
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
