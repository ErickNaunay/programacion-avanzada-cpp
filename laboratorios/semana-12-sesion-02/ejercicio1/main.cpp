#include <iostream>
#include <optional>
#include <stdexcept>

#include "estacionamiento.h"

// El main de la Semana 11, Sesion 2, ahora usando estacionamiento.h.
//
// Salida esperada:
// Placa 4521: puesto 0
// Placa 7788: puesto 1
// Placa 3011: puesto 2
// Placa 9090: sin puesto, estacionamiento lleno
// Placa 7788: error, placa ya registrada
// Placa 4521 sale del puesto 0
// Placa 9090: puesto 0

int main() {
    Estacionamiento estacionamiento(3);

    int llegadas[5] = {4521, 7788, 3011, 9090, 7788};
    for (int i = 0; i < 5; i++) {
        try {
            std::optional<int> puesto = estacionamiento.asignarPuesto(llegadas[i]);
            if (puesto) {
                std::cout << "Placa " << llegadas[i] << ": puesto " << *puesto << std::endl;
            } else {
                std::cout << "Placa " << llegadas[i] << ": sin puesto, estacionamiento lleno" << std::endl;
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Placa " << llegadas[i] << ": error, " << e.what() << std::endl;
        }
    }

    std::optional<int> liberado = estacionamiento.liberar(4521);
    if (liberado) {
        std::cout << "Placa 4521 sale del puesto " << *liberado << std::endl;
    }

    std::optional<int> nuevo = estacionamiento.asignarPuesto(9090);
    if (nuevo) {
        std::cout << "Placa 9090: puesto " << *nuevo << std::endl;
    }

    return 0;
}
