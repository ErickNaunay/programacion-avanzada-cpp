// Ejercicio 3:

// Parte A: un "sistema" de dos rectangulos
// armado con funciones sueltas y 4 variables independientes. Tiene un bug.
//
// TODO (escribe tu respuesta como comentario justo aqui):
// En que linea esta el bug, y que deberia decir en su lugar?
//
//El bug esta en la linea que imprime el rectangulo 2
//se usa altura 1 cuando deberia usarse altura 2
//deberia decir: std::cout <<" Rectangulo 2, Area:" <<area (base2, altura1)
//                         << ", Perimetro:" << perimetro(base2, altura1) << std::endl;
//
// Parte B: usa el struct Rectangulo del ejercicio 2 para
// reescribir el mismo resumen con dos objetos, rect1 y rect2, en vez de 4
// variables sueltas.
//
// Salida esperada:
// Con funciones sueltas (bug incluido):
// Rectangulo 1, Area: 50, Perimetro: 30
// Rectangulo 2, Area: 30, Perimetro: 22
//
// Con objetos (Parte B):
// Rectangulo 1, Area: 50, Perimetro: 30
// Rectangulo 2, Area: 24, Perimetro: 20
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio3_dos_rectangulos.cpp -o bin/ejercicio3
// Ejecutar:  ./bin/ejercicio3

#include <iostream>

// Funciones sueltas
double area(double base, double altura) { return base * altura; }
double perimetro(double base, double altura) { return 2 * (base + altura); }

void imprimirConFuncionesSueltas() {
    double base1 = 10.0, altura1 = 5.0;
    double base2 = 6.0, altura2 = 4.0;

    std::cout << "Rectangulo 1, Area: " << area(base1, altura1)
              << ", Perimetro: " << perimetro(base1, altura1) << std::endl;

    std::cout << "Rectangulo 2, Area: " << area(base2, altura1)
              << ", Perimetro: " << perimetro(base2, altura1) << std::endl; //bug encontrado se debe usar la altura 2 para el rectangulo 2 en area y perimetro en lugar de altura1
}

// Struct Rectangulo
struct Rectangulo {
    double base;
    double altura;
    double area() { return base * altura; }
    double perimetro() { return 2 * (base + altura); }
};

void imprimirConObjetos() {
    // TODO: declara rect1 (base 10, altura 5) y rect2 (base 6, altura 4),
    // igual que declaraste 'r' en el ejercicio 2.
    Rectangulo rect1 = {10, 5};
    Rectangulo rect2 = {6, 4};
    // TODO: imprime el resumen de cada uno, en el mismo formato de arriba,
    // usando rect1.area(), rect1.perimetro(), rect2.area(), rect2.perimetro()
    std::cout << "Rectangulo 1, Area: " << rect1.area()
              << ", Perimetro: " << rect1.perimetro() << std::endl;
    std::cout << "Rectangulo 2, Area: " << rect2.area()
              << ", Perimetro: " << rect2.perimetro() << std::endl;
}

int main() {
    std::cout << "Con funciones sueltas (bug incluido):" << std::endl;
    imprimirConFuncionesSueltas();

    std::cout << std::endl << "Con objetos (Parte B):" << std::endl;
    imprimirConObjetos();

    return 0;
}
