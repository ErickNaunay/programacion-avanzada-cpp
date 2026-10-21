// Ejercicio 2:

// Objetivo: el mismo comportamiento del ejercicio 1, pero base y altura
// viven juntos dentro de un objeto Rectangulo, y area(), perimetro() y
// escalar() son metodos de ese objeto: ya no se pasan como parametros
// sueltos, y no existe forma de mezclar la base de un rectangulo con la
// altura de otro.
//
// Usamos struct (no class): en C++ ambas definen una clase en el sentido
// de la sesion de hoy (agrupan atributos y metodos), la diferencia lo veremos la siguiente clase
//
// Salida esperada:
// Area: 50
// Perimetro: 30
// Despues de escalar x2 -> base: 20, altura: 10
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio2_struct_rectangulo.cpp -o bin/ejercicio2
// Ejecutar:  ./bin/ejercicio2

#include <iostream>

struct Rectangulo {
    double base;
    double altura;

    double area() {
        // TODO: retorna base * altura
        return base * altura;
    }

    double perimetro() {
        // TODO: retorna 2 * (base + altura)
        return 2 * (base + altura);
    }

    void escalar(double factor) {
        // TODO: reasigna base y altura multiplicandolos por factor
        // (usa base = ... y altura = ..., como en cualquier funcion que ya conoces)
        base *= factor;
        altura *= factor;
    }
};

int main() {
    Rectangulo r;
    r.base = 10.0;
    r.altura = 5.0;

    std::cout << "Area: " << r.area() << std::endl;
    std::cout << "Perimetro: " << r.perimetro() << std::endl;

    r.escalar(2.0);
    std::cout << "Despues de escalar x2 -> base: " << r.base << ", altura: " << r.altura << std::endl;

    return 0;
}
