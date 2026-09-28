// Ejercicio 1: Vector2D
//
// Completa operator+ y operator<<.
//
// operator+ es un método miembro: v1 + v2 se traduce a v1.operator+(v2).
// Construye y devuelve un Vector2D nuevo con la suma de cada coordenada;
// no modifiques x ni y del objeto sobre el que se llama.
//
// operator<< tiene que ser una función libre (no un método de la
// clase): en `std::cout << v1`, el operando izquierdo es std::cout, no
// un Vector2D. Recibe el stream por referencia (std::ostream&, con &)
// porque un stream no se puede copiar, y también lo devuelve por
// referencia para poder encadenar varios `<<` seguidos.
//
// Salida esperada:
// (2, 3) + (4, -1) = (6, 2)
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio1_vector2d.cpp -o bin/ejercicio1
// Ejecutar:  ./bin/ejercicio1

#include <iostream>

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double xInicial, double yInicial) {
        x = xInicial;
        y = yInicial;
    }

    double getX() { return x; }
    double getY() { return y; }

    Vector2D operator+(Vector2D otroVector) {
        return Vector2D(x+otroVector.getX(),y+otroVector.getY());

    }
};

std::ostream& operator<<(std::ostream& out, Vector2D unVector) {
    out<< unVector.getX()<<"-"<<unVector.getY();
    return out;
}

int main() {
    Vector2D v1(2.0, 3.0);
    Vector2D v2(4.0, -1.0);
    Vector2D suma = v1 + v2;

    std::cout << v1 << " + " << v2 << " = " << suma << std::endl;

    return 0;
}
