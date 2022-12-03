cmake_minimum_required(VERSION 3.5)

project(crlt2019 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(crlt2019 bidon2.h bidon2.cpp bidon3.h bidon3.cpp basemessages.cpp basemessages.h reponse.cpp reponse.h proposition.cpp proposition.h texte.cpp texte.h message.cpp message.h horaire.cpp horaire.h main.cpp)

install(TARGETS crlt2019
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
