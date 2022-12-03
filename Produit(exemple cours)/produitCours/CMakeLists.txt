cmake_minimum_required(VERSION 3.5)

project(produitCours LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(produitCours stockvectors.h stockvectors.cpp stockuniqueptr.cpp stockuniqueptr.h stockptr.cpp stockptr.h produitculturel.h produitculturel.cpp produitperissable.h produitperissable.cpp produit.h produit.cpp main.cpp)

install(TARGETS produitCours
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
