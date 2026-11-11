# Configuracion de CMake del promedio movil.
#
#     cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
#     cmake --build build
#     ctest --test-dir build --output-on-failure
#
# Con sanitizers, en otra carpeta de compilacion:
#     cmake -S . -B build-asan -DCMAKE_BUILD_TYPE=Debug -DCON_SANITIZERS=ON
#     cmake --build build-asan

# TODO 1: igual que en el Ejercicio 1: version minima 3.20, el proyecto
# (PromedioMovil, lenguaje CXX) y C++20 obligatorio, sin extensiones.
cmake_minimum_required(VERSION 3.20)
project(PromedioMovil LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# TODO 2: una opcion CON_SANITIZERS, apagada por defecto. Si esta
# encendida, todo lo que se compile despues usa
# -fsanitize=address,undefined y -fno-omit-frame-pointer al compilar, y
# -fsanitize=address,undefined al enlazar (add_compile_options y
# add_link_options, dentro de un if).
option(CON_SANITIZERS "Activar sanitizers" OFF)

if(CON_SANITIZERS)
    add_compile_options(
        -fsanitize=address,undefined
        -fno-omit-frame-pointer
    )
    add_link_options(
        -fsanitize=address,undefined
    )
endif()
# TODO 3: el ejecutable promedios (main.cpp) y el ejecutable pruebas
# (test_lecturas.cpp, con GoogleTest y registrado para ctest), los dos
# con -Wall -Wextra.
add_executable(promedios main.cpp)
target_compile_options(promedios PRIVATE -Wall -Wextra)

find_package(GTest REQUIRED)
enable_testing()
include(GoogleTest)

add_executable(pruebas test_lecturas.cpp)
target_compile_options(pruebas PRIVATE -Wall -Wextra)
target_link_libraries(pruebas PRIVATE GTest::gtest_main)

gtest_discover_tests(pruebas)