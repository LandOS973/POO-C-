cmake_minimum_required(VERSION 3.5)

project(vectors LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(vectors main.cpp)

install(TARGETS vectors
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
