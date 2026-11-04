#include <iostream>
#include <map>
#include <vector>

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

// El estacionamiento de la facultad tiene 3 puestos, numerados desde 0.
// Hoy cada funcion devuelve un codigo: -1 o -2 en vez de un numero de
// puesto. Corre el archivo antes de cambiar nada: main imprime esos
// codigos como si fueran puestos.
//
// Refactoriza asignarPuesto, puestoDe y liberar para que ninguna devuelva
// codigos. Para cada caso que hoy es un codigo, decide si es una ausencia
// esperada (std::optional) o un error de quien llama (una excepcion de
// <stdexcept>), y ajusta main para producir la salida esperada. No cambies
// los datos de main ni el orden de las operaciones.

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

        // Devuelve el puesto asignado, -1 si no hay puestos libres, o -2 si
        // la placa ya esta adentro.
        int asignarPuesto(int placa) {
            if (puestoDePlaca.count(placa) == 1) {
                return -2;
            }
            for (int i = 0; i < totalPuestos; i++) {
                if (!ocupado[i]) {
                    ocupado[i] = true;
                    puestoDePlaca[placa] = i;
                    return i;
                }
            }
            return -1;
        }

        // Devuelve el puesto de la placa, o -1 si no esta adentro.
        int puestoDe(int placa) {
            if (puestoDePlaca.count(placa) == 0) {
                return -1;
            }
            return puestoDePlaca[placa];
        }

        // Libera el puesto de la placa y lo devuelve, o -1 si no estaba.
        int liberar(int placa) {
            int puesto = puestoDe(placa);
            if (puesto == -1) {
                return -1;
            }
            ocupado[puesto] = false;
            puestoDePlaca.erase(placa);
            return puesto;
        }
};

int main() {
    Estacionamiento estacionamiento(3);

    int llegadas[5] = {4521, 7788, 3011, 9090, 7788};
    for (int i = 0; i < 5; i++) {
        int puesto = estacionamiento.asignarPuesto(llegadas[i]);
        std::cout << "Placa " << llegadas[i] << ": puesto " << puesto << std::endl;
    }

    int consultas[2] = {7788, 5555};
    for (int i = 0; i < 2; i++) {
        int puesto = estacionamiento.puestoDe(consultas[i]);
        std::cout << "Placa " << consultas[i] << " esta en el puesto " << puesto << std::endl;
    }

    int liberado = estacionamiento.liberar(4521);
    std::cout << "Placa 4521 sale del puesto " << liberado << std::endl;

    int nuevo = estacionamiento.asignarPuesto(9090);
    std::cout << "Placa 9090: puesto " << nuevo << std::endl;

    int otraVez = estacionamiento.liberar(4521);
    std::cout << "Placa 4521 sale del puesto " << otraVez << std::endl;

    return 0;
}
