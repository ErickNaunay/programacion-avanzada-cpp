#pragma once

#include <map>
#include <optional>
#include <stdexcept>
#include <vector>

// El estacionamiento de la facultad de la Semana 11, Sesion 2, ya
// refactorizado con std::optional. Ahora vive en su propio archivo para
// que dos programas lo puedan usar: el main de la sesion pasada y el
// archivo de pruebas de esta sesion.
//
// - asignarPuesto: el primer puesto libre, desde 0; vacio si esta lleno;
//   std::invalid_argument si la placa ya esta adentro.
// - puestoDe: el puesto de la placa, o vacio si no esta.
// - liberar: el puesto que deja la placa, o vacio si no estaba.

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
