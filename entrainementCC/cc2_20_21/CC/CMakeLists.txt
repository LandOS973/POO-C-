cmake_minimum_required(VERSION 3.5)

project(CC LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CC cc.h cc.cpp main.cpp)

install(TARGETS CC
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
