// Ejercicio 1: Circulo
//
// Completa el struct Circulo: un atributo radio y un metodo area() que
// devuelva el area del circulo (pi * radio al cuadrado). Usa 3.14159265
// como valor de pi.
//
// Salida esperada:
// Radio: 4
// Area: 50.2655
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio1_circulo.cpp -o bin/ejercicio1
// Ejecutar:  ./bin/ejercicio1

#include <iostream>

struct Circulo {
    double radio;

    double area() {
        // TODO: retorna 3.14159265 * radio * radio
        return 0.0;
    }
};

int main() {
    Circulo c;
    c.radio = 4.0;

    std::cout << "Radio: " << c.radio << std::endl;
    std::cout << "Area: " << c.area() << std::endl;

    return 0;
}
