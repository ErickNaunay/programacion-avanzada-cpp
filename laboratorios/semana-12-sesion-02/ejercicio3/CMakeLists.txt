cmake_minimum_required(VERSION 3.20)

project(ColaImpresion LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(CON_SANITIZERS "Usar sanitizers" OFF)

if(CON_SANITIZERS)
    add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address,undefined)
endif()

add_executable(cola main.cpp)
target_compile_options(cola PRIVATE -Wall -Wextra)

add_executable(pruebas test_cola.cpp)
target_compile_options(pruebas PRIVATE -Wall -Wextra)

find_package(GTest REQUIRED)
target_link_libraries(pruebas PRIVATE GTest::gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(pruebas)