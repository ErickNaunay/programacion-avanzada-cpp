// Ejercicio 4: Termostato
//
// Completa la clase Termostato: un atributo privado temperaturaActual,
// un metodo fijarTemperaturaInicial(double t) que lo asigne directamente,
// y un getter getTemperaturaActual() que lo devuelva sin modificarlo.
//
// Salida esperada:
// Temperatura actual: 21.5
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio4_termostato.cpp -o bin/ejercicio4
// Ejecutar:  ./bin/ejercicio4

#include <iostream>

class Termostato {
private:
    double temperaturaActual;

public:
    double getTemperaturaActual() {
        // TODO: retorna temperaturaActual
        return 0.0;
    }

    void fijarTemperaturaInicial(double t) {
        // TODO: asigna t a temperaturaActual
    }
};

int main() {
    Termostato t;
    t.fijarTemperaturaInicial(21.5);

    std::cout << "Temperatura actual: " << t.getTemperaturaActual() << std::endl;

    return 0;
}
