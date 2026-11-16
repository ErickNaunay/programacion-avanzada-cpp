cmake_minimum_required(VERSION 3.20)
project(Cafeteria LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(CON_SANITIZERS "Compilar con AddressSanitizer y UBSan" OFF)
if(CON_SANITIZERS)
    add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address,undefined)
endif()

# TODO 6: una opcion CON_TSAN, apagada por defecto, que compile y enlace
# todo con -fsanitize=thread (como CON_SANITIZERS, en la Semana 12). Las dos
# opciones no se usan a la vez: ThreadSanitizer no se combina con
# AddressSanitizer.

add_executable(cafeteria main.cpp)
target_compile_options(cafeteria PRIVATE -Wall -Wextra)

find_package(GTest REQUIRED)
add_executable(pruebas test_pedidos.cpp)
target_compile_options(pruebas PRIVATE -Wall -Wextra)
target_link_libraries(pruebas PRIVATE GTest::gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(pruebas)
