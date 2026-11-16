#include <iostream>
#include <list>

#include "contador_reservas.h"

// Ejercicio 3: el mismo buffer, con una std::list. No lo modifiques: es
// para comparar. Funciona, y da los mismos numeros que tu BufferCircular.
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -O2 ejercicio3_buffer_lista.cpp -o bin/ejercicio3_lista
// Ejecutar:  ./bin/ejercicio3_lista

const int CAPACIDAD = 64;
const int LECTURAS = 1000000;

class BufferLista {
public:
    void agregar(double valor) {
        lecturas.push_back(valor);
        if (static_cast<int>(lecturas.size()) > CAPACIDAD) {
            lecturas.pop_front();
        }
    }

    int getCantidad() {
        return lecturas.size();
    }

    double masAntigua() {
        return lecturas.front();
    }

    double promedio() {
        double suma = 0;
        for (double valor : lecturas) {
            suma += valor;
        }
        return suma / lecturas.size();
    }

    double minimo() {
        double menor = lecturas.front();
        for (double valor : lecturas) {
            if (valor < menor) {
                menor = valor;
            }
        }
        return menor;
    }

private:
    std::list<double> lecturas;
};

int main() {
    BufferLista buffer;
    long long reservasAntes = reservasHechas;

    unsigned int semilla = 2026;
    for (int i = 0; i < LECTURAS; i++) {
        semilla = semilla * 1103515245 + 12345;
        double lectura = 60.0 + ((semilla >> 8) % 2400) / 100.0;
        buffer.agregar(lectura);
    }

    long long reservasDurante = reservasHechas - reservasAntes;
    std::cout << "Lecturas guardadas: " << buffer.getCantidad() << std::endl;
    std::cout << "Mas antigua: " << buffer.masAntigua() << std::endl;
    std::cout << "Promedio de las ultimas 64: " << buffer.promedio() << std::endl;
    std::cout << "Minimo de las ultimas 64: " << buffer.minimo() << std::endl;
    std::cout << "Reservas de memoria mientras corria el sensor: " << reservasDurante << std::endl;
    return 0;
}
