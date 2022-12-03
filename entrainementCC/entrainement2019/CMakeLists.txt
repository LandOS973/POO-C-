cmake_minimum_required(VERSION 3.5)

project(entrainement2019 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(entrainement2019 basemessage.cpp basemessage.h proposition.cpp proposition.h reponse.h reponse.cpp message.cpp message.h texte.h texte.cpp horaire.h horaire.cpp main.cpp)

install(TARGETS entrainement2019
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
