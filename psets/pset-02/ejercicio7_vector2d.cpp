// Ejercicio 7: Vector2D (sobrecarga de operator+)
//
// Completa el constructor, los getters y operator+. No cambies las firmas ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio7 ejercicio7_vector2d.cpp
// Ejecutar: ./ejercicio7
//
// Salida esperada:
// Suma: (6, 4)

#include <iostream>

class Vector2D {
private:
    double x;
    double y;
public:
    Vector2D(double xInicial, double yInicial) {
        // TODO: asigna x y y por asignacion directa.
        x = xInicial;
        y = yInicial;
    }
    double getX() {
        // TODO: devuelve x.
        return x;
    }
    double getY() {
        // TODO: devuelve y.
        return y;
    }
    Vector2D operator+(Vector2D otro) {
        // TODO: devuelve un Vector2D nuevo con la suma de x y de y de ambos vectores.
        return Vector2D(x + otro.getX(), y + otro.getY());
    }
};

int main() {
    Vector2D v1(2, 3);
    Vector2D v2(4, 1);
    Vector2D v3 = v1 + v2;
    std::cout << "Suma: (" << v3.getX() << ", " << v3.getY() << ")" << std::endl;
    return 0;
}
