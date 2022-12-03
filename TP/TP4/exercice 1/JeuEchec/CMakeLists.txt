cmake_minimum_required(VERSION 3.5)

project(JeuEchec LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(JeuEchec echequier.h echequier.cpp dame.h dame.cpp tour.h tour.cpp fou.cpp fou.h position.h position.cpp piece.h piece.cpp cavalier.h cavalier.cpp pion.h pion.cpp roi.h roi.cpp main.cpp)

install(TARGETS JeuEchec
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
