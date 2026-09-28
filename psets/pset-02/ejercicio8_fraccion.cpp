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
    numerador = num;

        if (denom != 0) {
            denominador = denom;
        } else {
            std::cout << "Denominador invalido, se asigna 1 por defecto" << std::endl;
            denominador = 1;
        }
    }

        int getNumerador() {
            return numerador;
    }

        int getDenominador() {
            return denominador;
    }
};

std::ostream& operator<<(std::ostream& os, Fraccion f) {
    os << f.getNumerador() << "/" << f.getDenominador();
    return os;
}

int main() {
    Fraccion f1(3, 4);
    Fraccion f2(5, 0);
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    return 0;
}
