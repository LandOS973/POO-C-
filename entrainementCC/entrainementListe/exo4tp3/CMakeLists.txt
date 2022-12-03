cmake_minimum_required(VERSION 3.5)

project(exo4tp3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(exo4tp3 graphe.h graphe.cpp sommet.cpp sommet.h main.cpp)

install(TARGETS exo4tp3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
