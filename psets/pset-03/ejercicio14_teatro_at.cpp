// Ejercicio 14: Teatro (at(), propagacion y orden de los catch)
//
// Completa los metodos marcados con TODO y el cuerpo de procesar. No
// cambies las firmas ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio14 ejercicio14_teatro_at.cpp
// Ejecutar: ./ejercicio14
//
// Salida esperada:
// Compra aceptada: 3 asientos en la fila 1, total 45
// Rechazada (no existe): vector::_M_range_check: __n (which is 7) >= this->size() (which is 4)
// Rechazada (no existe): map::at
// Rechazada (dato invalido): cantidad no positiva
// Rechazada (no alcanza): asientos insuficientes
// Libres en la fila 1: 2
// Solicitudes procesadas: 5

#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>

class Teatro {
private:
    std::vector<int> libresPorFila;
    std::map<int, double> precioPorZona;
public:
    Teatro() {
        libresPorFila = {10, 5, 8, 2};
        precioPorZona[1] = 15.0;
        precioPorZona[2] = 9.5;
    }
    int libresEn(int fila) {
        // TODO: devuelve los libres de esa fila con at(), que lanza
        // std::out_of_range si la fila no existe.
        return 0;
    }
    double precioDe(int zona) {
        // TODO: devuelve el precio de la zona con at() del map: lanza
        // std::out_of_range si la zona no existe, sin crearla.
        return 0;
    }
    double comprar(int fila, int zona, int cantidad) {
        // TODO: en este orden: lee los libres de la fila y el precio de la zona
        // (con los dos metodos de arriba); si cantidad <= 0, lanza
        // std::invalid_argument("cantidad no positiva"); si cantidad es
        // mayor que los libres, lanza std::runtime_error("asientos
        // insuficientes"). Si todo esta bien, resta cantidad a esa fila y
        // devuelve cantidad * precio.
        return 0;
    }
};

void procesar(Teatro* teatro, int fila, int zona, int cantidad) {
    // TODO: llama teatro->comprar dentro de un try. Si sale bien, imprime
    // "Compra aceptada: <cantidad> asientos en la fila <fila>, total
    // <total>". Atrapa por referencia constante, en este orden:
    // std::out_of_range ("Rechazada (no existe): "), std::invalid_argument
    // ("Rechazada (dato invalido): ") y std::runtime_error ("Rechazada (no
    // alcanza): "), cada uno seguido de e.what().
}

int main() {
    Teatro teatro;
    int solicitudes[5][3] = {{1, 1, 3}, {7, 1, 2}, {0, 4, 2}, {2, 2, 0}, {3, 2, 5}};
    for (int i = 0; i < 5; i++) {
        procesar(&teatro, solicitudes[i][0], solicitudes[i][1], solicitudes[i][2]);
    }
    std::cout << "Libres en la fila 1: " << teatro.libresEn(1) << std::endl;
    std::cout << "Solicitudes procesadas: 5" << std::endl;
    return 0;
}
