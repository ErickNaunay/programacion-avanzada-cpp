#pragma once

#include <vector>

// Cola de impresion de la biblioteca. Cada trabajo es su numero de
// paginas.
//
// - agregar(paginas) pone un trabajo al final de la cola.
// - dividirGrandes() deja todos los trabajos en 20 paginas o menos: un
//   trabajo de mas de 20 paginas se queda con 20 en su lugar, y el resto
//   va al final de la cola como un trabajo nuevo (que a su vez se divide
//   si pasa de 20).
// - minutosDeImpresion(paginas): la impresora imprime 10 paginas por
//   minuto, y un bloque incompleto cuenta como un minuto entero: 25 paginas
//   toman 3 minutos, 20 paginas toman 2.
// - minutosTotales() suma los minutos de todos los trabajos de la cola.

int minutosDeImpresion(int paginas) {
    return paginas / 10;
}

class ColaDeImpresion {
    private:
        std::vector<int> trabajos;
    public:
        void agregar(int paginas) {
            trabajos.push_back(paginas);
        }

        int cantidad() {
            return trabajos.size();
        }

        int paginasDe(int posicion) {
            return trabajos.at(posicion);
        }

        void dividirGrandes() {
            for (auto it = trabajos.begin(); it != trabajos.end(); ++it) {
                if (*it > 20) {
                    int resto = *it - 20;
                    *it = 20;
                    trabajos.push_back(resto);
                }
            }
        }

        int minutosTotales() {
            int total = 0;
            for (int i = 0; i < cantidad(); i++) {
                total = total + minutosDeImpresion(trabajos[i]);
            }
            return total;
        }
};
