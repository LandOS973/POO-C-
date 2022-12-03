cmake_minimum_required(VERSION 3.5)

project(uniqueptr LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(uniqueptr pointeurintelligent.h pointeurintelligent.cpp main.cpp)

install(TARGETS uniqueptr
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
