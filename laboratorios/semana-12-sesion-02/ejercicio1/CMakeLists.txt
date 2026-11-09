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

# TODO 2: el ejecutable estacionamiento, a partir de main.cpp, compilado
# con -Wall -Wextra.

# TODO 3: el ejecutable pruebas, a partir de test_estacionamiento.cpp,
# enlazado con GoogleTest, y registrado para que ctest lo corra.

# TODO 4: el ejecutable reporte_tiempos, a partir de reporte_tiempos.cpp,
# compilado con -Wall -Wextra.
