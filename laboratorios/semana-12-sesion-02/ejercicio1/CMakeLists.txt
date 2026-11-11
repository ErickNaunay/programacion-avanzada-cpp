# Configuracion de CMake del estacionamiento. Hoy la completamos en clase.
#
# Configurar (una vez, o cuando cambia este archivo):
#     cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
# Compilar (cada vez que cambias el codigo):
#     cmake --build build
# Correr las pruebas:
#     ctest --test-dir build --output-on-failure

# TODO 1: la version minima de CMake (3.20), el nombre del proyecto
# (Estacionamiento, en lenguaje CXX) y el estandar C++20 obligatorio, sin
# extensiones de GCC (para que compile con -std=c++20, como hasta ahora).
# TODO 1: ...
cmake_minimum_required(VERSION 3.20)
project(Estacionamiento LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# TODO 2: el ejecutable estacionamiento, a partir de main.cpp, compilado
# con -Wall -Wextra.
add_executable(estacionamiento main.cpp)
target_compile_options(estacionamiento PRIVATE -Wall -Wextra)

# TODO 3: el ejecutable pruebas, a partir de test_estacionamiento.cpp,
# enlazado con GoogleTest, y registrado para que ctest lo corra.
add_executable(pruebas test_estacionamiento.cpp)
find_package(GTest REQUIRED)
target_link_libraries(pruebas PRIVATE GTest::gtest_main)
enable_testing()
include(GoogleTest)
gtest_discover_tests(pruebas)

# TODO 4: el ejecutable reporte_tiempos, a partir de reporte_tiempos.cpp,
# compilado con -Wall -Wextra.
add_executable(reporte_tiempos reporte_tiempos.cpp)
target_compile_options(reporte_tiempos PRIVATE -Wall -Wextra)
