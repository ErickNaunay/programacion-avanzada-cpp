#pragma once

#include <vector>

// Promedio movil de las lecturas del sensor de temperatura del
// invernadero: el promedio de cada grupo de `ventana` lecturas seguidas.
// Con 6 lecturas y ventana 3 hay 4 promedios: lecturas 0 a 2, 1 a 3, 2 a 4
// y 3 a 5.

\
#pragma once

#include <vector>

// Promedio movil de las lecturas del sensor de temperatura del
// invernadero.

std::vector<double> promedioMovil(std::vector<double> lecturas, int ventana) {
    std::vector<double> promedios;
    int cantidad = lecturas.size();
    if (ventana <= 0 || ventana > cantidad) {
        return promedios;
    }
    for (int inicio = 0; inicio <= cantidad - ventana; inicio++) {
        double suma = 0.0;
        for (int j = 0; j < ventana; j++) {
            suma = suma + lecturas[inicio + j];
        }
        promedios.push_back(suma / ventana);
    }
    return promedios;
}

