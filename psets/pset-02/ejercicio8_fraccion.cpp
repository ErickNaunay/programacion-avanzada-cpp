// Ejercicio 8: Fraccion (constructor con valor por defecto y operator<<)
//
// Completa el constructor y operator<<. No cambies las firmas ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio8 ejercicio8_fraccion.cpp
// Ejecutar: ./ejercicio8
//
// Salida esperada:
// Denominador invalido, se asigna 1 por defecto
// 3/4
// 5/1

#include <iostream>

class Fraccion {
private:
    int numerador;
    int denominador;
public:
    Fraccion(int num, int denom) {
        // TODO: asigna numerador directamente.
        // TODO: si denom es distinto de 0, asigna denominador = denom.
        // Si denom es 0, imprime "Denominador invalido, se asigna 1 por defecto"
        // seguido de un salto de linea, y asigna denominador = 1.
    }
    int getNumerador() {
        // TODO: devuelve numerador.
        return 0;
    }
    int getDenominador() {
        // TODO: devuelve denominador.
        return 0;
    }
};

std::ostream& operator<<(std::ostream& os, Fraccion f) {
    // TODO: escribe en os el numerador, seguido de "/", seguido del denominador.
    // Devuelve os.
    return os;
}

int main() {
    Fraccion f1(3, 4);
    Fraccion f2(5, 0);
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    return 0;
}
