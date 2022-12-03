cmake_minimum_required(VERSION 3.5)

project(jeuxDeLaVie LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(jeuxDeLaVie grille.h grille.cpp main.cpp)

install(TARGETS jeuxDeLaVie
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
