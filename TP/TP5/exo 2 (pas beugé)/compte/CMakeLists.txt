cmake_minimum_required(VERSION 3.5)

project(compte LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(compte proprietaire.h proprietaire.cpp main.cpp)

install(TARGETS compte
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
