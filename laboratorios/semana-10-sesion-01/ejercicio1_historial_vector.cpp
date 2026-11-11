#include <iostream>
#include <memory>
#include <vector>

// Historial<T> de la sesion pasada: capacidad fija, y rechaza el valor
// que ya no cabe.

template <typename T>
class Historial {
    private:
        // TODO (paso 1): reemplaza estos tres atributos por un solo
        // std::vector<T> llamado valores. Incluye <vector> arriba.
        std::vector<T> valores;
    public:
        Historial(int capacidadInicial) {
            // TODO (paso 1): con el vector, reserva espacio para
            // capacidadInicial elementos con valores.reserve(...).
            valores.reserve(capacidadInicial);
        }

        bool agregar(T valor) {
            // TODO (paso 2): con push_back el historial ya no se llena.
            // Agrega el valor y devuelve true siempre.
            valores.push_back(valor);
            return true;
        }

        T obtener(int indice) {
            return valores[indice];
        }

        T ultimo() {
            // TODO (paso 2): el ultimo elemento del vector.
            return valores.back();
        }

        int getUsadas() {
            // TODO (paso 2): cuantos elementos tiene el vector.
            return valores.size();
        }

        int getCapacidad() {
            // TODO (paso 3): cuantos elementos caben sin reservar memoria
            // nueva.
            return valores.capacity();
        }
};

int main() {
    Historial<int> pasos(3);
    int dias[6] = {4200, 1800, 3300, 5100, 2700, 3900};

    for (int i = 0; i < 6; i++) {
        bool aceptado = pasos.agregar(dias[i]);
        std::cout << "Agregar " << dias[i] << ": ";
        if (aceptado) {
            std::cout << "aceptado";
        } else {
            std::cout << "rechazado";
        }
        std::cout << " (usadas " << pasos.getUsadas() << ", capacidad " << pasos.getCapacidad() << ")" << std::endl;
    }
    std::cout << "Ultimo dia: " << pasos.ultimo() << std::endl;
    std::cout << "Primer dia: " << pasos.obtener(0) << std::endl;

    // TODO (paso 4): crea un std::vector<int> llamado semana con los
    // valores {4200, 1800, 3300, 5100, 2700, 3900, 4600}.
    // a) Imprime "Semana:" y cada valor precedido de un espacio,
    //    recorriendo con un iterador, de semana.begin() a semana.end().
    // b) Suma los valores con un for de rango e imprime
    //    "Total de la semana: " con el resultado.
    std::vector<int> semana = {4200, 1800, 3300, 5100, 2700, 3900, 4600};

    std::cout << "Semana:";
    for (auto it = semana.begin(); it != semana.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    int totalSemana = 0;
    for (int v : semana) {
        totalSemana += v;
    }
    std::cout << "Total de la semana: " << totalSemana << std::endl;

    return 0;
}