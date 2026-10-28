#include <iostream>
#include <vector>

template <typename T>
class Historial {
private:
    std::vector<T> valores;

public:
    Historial(int capacidadInicial) {
        valores.reserve(capacidadInicial);
    }

    bool agregar(T valor) {
        valores.push_back(valor);
        return true;
    }

    T obtener(int indice) {
        return valores[indice];
    }

    T ultimo() {
        return valores.back();
    }

    int getUsadas() {
        return valores.size();
    }

    int getCapacidad() {
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

    std::vector<int> semana = {
        4200, 1800, 3300, 5100, 2700, 3900, 4600
    };

    std::cout << "Semana:";

    for (std::vector<int>::iterator it = semana.begin();
         it != semana.end();
         ++it) {
        std::cout << " " << *it;
    }

    std::cout << std::endl;

    int total = 0;

    for (int valor : semana) {
        total += valor;
    }

    std::cout << "Total de la semana: " << total << std::endl;

    return 0;
}