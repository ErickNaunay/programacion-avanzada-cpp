#include <iostream>
#include <map>
#include <vector>
#include <optional>
#include <stdexcept>

// Salida esperada:
// Placa 4521: puesto 0
// Placa 7788: puesto 1
// Placa 3011: puesto 2
// Placa 9090: sin puesto, estacionamiento lleno
// Placa 7788: error, placa ya registrada
// Placa 7788 esta en el puesto 1
// Placa 5555 no esta en el estacionamiento
// Placa 4521 sale del puesto 0
// Placa 9090: puesto 0
// Placa 4521 no esta en el estacionamiento

class Estacionamiento {
private:
    int totalPuestos;
    std::vector<bool> ocupado;
    std::map<int, int> puestoDePlaca;

public:
    Estacionamiento(int puestos) {
        totalPuestos = puestos;

        for (int i = 0; i < puestos; i++) {
            ocupado.push_back(false);
        }
    }

    // Devuelve el puesto si hay uno libre.
    // Si esta lleno, devuelve nullopt.
    // Si la placa ya esta registrada, lanza excepcion.
    std::optional<int> asignarPuesto(int placa) {

        if (puestoDePlaca.count(placa) == 1) {
            throw std::runtime_error("placa ya registrada");
        }

        for (int i = 0; i < totalPuestos; i++) {

            if (!ocupado[i]) {
                ocupado[i] = true;
                puestoDePlaca[placa] = i;

                return i;
            }
        }

        return std::nullopt;
    }

    // Devuelve el puesto si la placa existe.
    // Si no esta, devuelve nullopt.
    std::optional<int> puestoDe(int placa) {

        if (puestoDePlaca.count(placa) == 0) {
            return std::nullopt;
        }

        return puestoDePlaca[placa];
    }

    // Devuelve el puesto liberado.
    // Si la placa no estaba, devuelve nullopt.
    std::optional<int> liberar(int placa) {

        std::optional<int> puesto = puestoDe(placa);

        if (!puesto.has_value()) {
            return std::nullopt;
        }

        ocupado[*puesto] = false;
        puestoDePlaca.erase(placa);

        return puesto;
    }
};

int main() {
    Estacionamiento estacionamiento(3);

    int llegadas[5] = {4521, 7788, 3011, 9090, 7788};

    for (int i = 0; i < 5; i++) {

        try {

            std::optional<int> puesto =
                estacionamiento.asignarPuesto(llegadas[i]);

            if (puesto.has_value()) {

                std::cout << "Placa "
                          << llegadas[i]
                          << ": puesto "
                          << *puesto
                          << std::endl;

            } else {

                std::cout << "Placa "
                          << llegadas[i]
                          << ": sin puesto, estacionamiento lleno"
                          << std::endl;
            }

        } catch (const std::runtime_error& e) {

            std::cout << "Placa "
                      << llegadas[i]
                      << ": error, "
                      << e.what()
                      << std::endl;
        }
    }

    int consultas[2] = {7788, 5555};

    for (int i = 0; i < 2; i++) {

        std::optional<int> puesto =
            estacionamiento.puestoDe(consultas[i]);

        if (puesto.has_value()) {

            std::cout << "Placa "
                      << consultas[i]
                      << " esta en el puesto "
                      << *puesto
                      << std::endl;

        } else {

            std::cout << "Placa "
                      << consultas[i]
                      << " no esta en el estacionamiento"
                      << std::endl;
        }
    }

    std::optional<int> liberado =
        estacionamiento.liberar(4521);

    if (liberado.has_value()) {

        std::cout << "Placa 4521 sale del puesto "
                  << *liberado
                  << std::endl;

    } else {

        std::cout << "Placa 4521 no esta en el estacionamiento"
                  << std::endl;
    }

    try {

        std::optional<int> nuevo =
            estacionamiento.asignarPuesto(9090);

        if (nuevo.has_value()) {

            std::cout << "Placa 9090: puesto "
                      << *nuevo
                      << std::endl;

        } else {

            std::cout << "Placa 9090: sin puesto, estacionamiento lleno"
                      << std::endl;
        }

    } catch (const std::runtime_error& e) {

        std::cout << "Placa 9090: error, "
                  << e.what()
                  << std::endl;
    }

    std::optional<int> otraVez =
        estacionamiento.liberar(4521);

    if (otraVez.has_value()) {

        std::cout << "Placa 4521 sale del puesto "
                  << *otraVez
                  << std::endl;

    } else {

        std::cout << "Placa 4521 no esta en el estacionamiento"
                  << std::endl;
    }

    return 0;
}