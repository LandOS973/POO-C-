cmake_minimum_required(VERSION 3.5)

project(controlecpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(controlecpp jeu.cpp jeu.h joueur.h joueur.cpp objetactif.h objetactif.cpp invader.h invader.cpp projectile.h projectile.cpp objet.h objet.cpp taille.h taille.cpp position.h position.cpp main.cpp)

install(TARGETS controlecpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
