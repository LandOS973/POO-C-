cmake_minimum_required(VERSION 3.5)

project(Element LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Element obstable.h obstable.cpp objetramassable.cpp objetramassable.h personnage.cpp personnage.h element.h element.cpp tailleposition.cpp tailleposition.h main.cpp)

install(TARGETS Element
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
