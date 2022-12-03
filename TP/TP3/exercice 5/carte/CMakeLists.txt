cmake_minimum_required(VERSION 3.5)

project(carte LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(carte carte.h carte.cpp personnage.h personnage.cpp objetramassable.h objetramassable.cpp obstacle.cpp obstacle.h tailleposition.cpp tailleposition.h element.h element.cpp main.cpp)

install(TARGETS carte
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
