// Ejercicio 7: Cronometro
//
// Completa la clase Cronometro: un atributo privado segundos y un
// constructor Cronometro(double segundosIniciales) que lo asigne
// directamente en el cuerpo del constructor (todavia no usamos lista
// de inicializacion). Agrega tambien el getter getSegundos().
//
// Salida esperada:
// Segundos: 90
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio7_cronometro.cpp -o bin/ejercicio7
// Ejecutar:  ./bin/ejercicio7

#include <iostream>

class Cronometro {
private:
    double segundos;

public:
    Cronometro(double segundosIniciales) {
        // TODO: asigna segundosIniciales a segundos
    }

    double getSegundos() {
        return segundos;
    }
};

int main() {
    Cronometro c(90.0);
    std::cout << "Segundos: " << c.getSegundos() << std::endl;

    return 0;
}
