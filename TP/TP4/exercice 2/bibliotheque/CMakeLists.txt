cmake_minimum_required(VERSION 3.5)

project(bibliotheque LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bibliotheque bibliotheque.cpp bibliotheque.h periodique.cpp periodique.h livres.cpp livres.h documentecrit.cpp documentecrit.h video.cpp video.h document.cpp document.h main.cpp)

install(TARGETS bibliotheque
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
