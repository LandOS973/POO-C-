cmake_minimum_required(VERSION 3.5)

project(Carte LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Carte main.cpp tailleposition.h tailleposition.cpp)

install(TARGETS Carte
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
