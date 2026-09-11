// Diagnostico 1: Control de flujo
// Objetivo: escribir una funcion que determine si un numero es primo,
// y usarla para imprimir todos los primos entre 2 y 30.
// Un numero primo es un entero mayor que 1 que solo es divisible por 1 y por si mismo.
//
// Salida esperada:
// 2 3 5 7 11 13 17 19 23 29
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio1_control_flujo.cpp -o bin/ejercicio1
// Ejecutar:  ./bin/ejercicio1

#include <iostream>
using namespace std;

bool esPrimo(int n) {
    if(n < 2) return false;
    for(int i = 2; i < n; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    for (int n = 2; n <= 30; ++n) {
        if (esPrimo(n)) {
            std::cout << n << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}
