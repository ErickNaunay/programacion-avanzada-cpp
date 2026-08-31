// Ejercicio 9: VelaEncendida
//
// Completa la clase VelaEncendida: un atributo privado minutosRestantes,
// un constructor VelaEncendida(double minutosIniciales) que lo asigne y
// avise por consola que la vela se encendio (incluye el valor asignado),
// y un destructor ~VelaEncendida() que avise por consola que la vela se
// apago.
//
// Salida esperada:
// Vela encendida con 30 minutos
// La vela se apago
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio9_vela_encendida.cpp -o bin/ejercicio9
// Ejecutar:  ./bin/ejercicio9

#include <iostream>

class VelaEncendida {
private:
    double minutosRestantes;

public:
    VelaEncendida(double minutosIniciales) {
        // TODO: asigna minutosIniciales a minutosRestantes e imprime
        // "Vela encendida con " + minutosRestantes + " minutos"
    }

    ~VelaEncendida() {
        // TODO: imprime "La vela se apago"
    }
};

int main() {
    VelaEncendida v(30.0);

    return 0;
}
