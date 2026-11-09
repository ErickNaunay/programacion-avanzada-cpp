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

# TODO 2: una opcion CON_SANITIZERS, apagada por defecto. Si esta
# encendida, todo lo que se compile despues usa
# -fsanitize=address,undefined y -fno-omit-frame-pointer al compilar, y
# -fsanitize=address,undefined al enlazar (add_compile_options y
# add_link_options, dentro de un if).

# TODO 3: el ejecutable promedios (main.cpp) y el ejecutable pruebas
# (test_lecturas.cpp, con GoogleTest y registrado para ctest), los dos
# con -Wall -Wextra.
