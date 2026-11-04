#include <iostream>
#include <map>
#include <vector>
#include <optional>
#include <stdexcept>

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

        std::optional<int> asignarPuesto(int placa) {
            if (puestoDePlaca.count(placa) == 1) {
                throw std::invalid_argument("placa ya registrada");
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

        std::optional<int> puestoDe(int placa) {
            if (puestoDePlaca.count(placa) == 0) {
                return std::nullopt;
            }

            return puestoDePlaca[placa];
        }

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
            std::optional<int> puesto = estacionamiento.asignarPuesto(llegadas[i]);

            if (puesto.has_value()) {
                std::cout << "Placa " << llegadas[i] << ": puesto " << *puesto << std::endl;
            } else {
                std::cout << "Placa " << llegadas[i] << ": sin puesto, estacionamiento lleno" << std::endl;
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Placa " << llegadas[i] << ": error, " << e.what() << std::endl;
        }
    }

    int consultas[2] = {7788, 5555};

    for (int i = 0; i < 2; i++) {
        std::optional<int> puesto = estacionamiento.puestoDe(consultas[i]);

        if (puesto.has_value()) {
            std::cout << "Placa " << consultas[i] << " esta en el puesto " << *puesto << std::endl;
        } else {
            std::cout << "Placa " << consultas[i] << " no esta en el estacionamiento" << std::endl;
        }
    }

    std::optional<int> liberado = estacionamiento.liberar(4521);

    if (liberado.has_value()) {
        std::cout << "Placa 4521 sale del puesto " << *liberado << std::endl;
    }

    std::optional<int> nuevo = estacionamiento.asignarPuesto(9090);

    if (nuevo.has_value()) {
        std::cout << "Placa 9090: puesto " << *nuevo << std::endl;
    }

    std::optional<int> otraVez = estacionamiento.liberar(4521);

    if (otraVez.has_value()) {
        std::cout << "Placa 4521 sale del puesto " << *otraVez << std::endl;
    } else {
        std::cout << "Placa 4521 no esta en el estacionamiento" << std::endl;
    }

    return 0;
}