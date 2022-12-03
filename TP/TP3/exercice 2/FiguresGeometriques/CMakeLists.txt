cmake_minimum_required(VERSION 3.5)

project(FiguresGeometriques LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FiguresGeometriques rectangle.cpp rectangle.h triangle.h triangle.cpp texte.h texte.cpp segment.h segment.cpp figure.cpp figure.h point.cpp point.h couleur.h main.cpp)

install(TARGETS FiguresGeometriques
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
