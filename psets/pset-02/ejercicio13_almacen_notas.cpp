// Ejercicio 13: AlmacenNotas (RAII con new[] y delete[])
//
// Completa el constructor, el destructor y los metodos marcados con TODO.
// No cambies las firmas ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio13 ejercicio13_almacen_notas.cpp
// Ejecutar: ./ejercicio13
//
// Salida esperada:
// Nota 0: 18.5
// Nota 1: 15
// Nota 2: 20
// Almacen de notas liberado

#include <iostream>

class AlmacenNotas {
private:
    double* notas;
    int cantidad;
public:

    AlmacenNotas(int n) {
        cantidad = n;
             notas = new double[cantidad];

            for (int i = 0; i < cantidad; i++) {
                notas[i] = 0.0;
            }
        }

    ~AlmacenNotas() {
            delete[] notas;
        std::cout << "Almacen de notas liberado" << std::endl;
    }

        bool setNota(int indice, double valor) {
                if (indice < 0 || indice >= cantidad || valor < 0 || valor > 20) {
            return false;
        }

                notas[indice] = valor;
            return true;
        }

            double getNota(int indice) {

    return notas[indice];
    }

};


int main() {
    AlmacenNotas almacen1(3);
    almacen1.setNota(0, 18.5);
    almacen1.setNota(1, 15.0);
    almacen1.setNota(2, 20.0);
    std::cout << "Nota 0: " << almacen1.getNota(0) << std::endl;
    std::cout << "Nota 1: " << almacen1.getNota(1) << std::endl;
    std::cout << "Nota 2: " << almacen1.getNota(2) << std::endl;
    return 0;
}
