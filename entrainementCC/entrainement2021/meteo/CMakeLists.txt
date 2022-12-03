cmake_minimum_required(VERSION 3.5)

project(meteo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(meteo vent.h vent.cpp basereleve.h basereleve.cpp temperature.h temperature.cpp precipitation.h precipitation.cpp releve.h releve.cpp datereleve.h datereleve.cpp main.cpp)

install(TARGETS meteo
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
