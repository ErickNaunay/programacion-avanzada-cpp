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

        double getX() {
            return x;
        }

        double getY() {
            return y;
        }

        Vector2D operator+(Vector2D otro) {
            return Vector2D(x + otro.getX(), y + otro.getY());
        }
};

std::ostream& operator<<(std::ostream& os, Vector2D v) {
    os << "(" << v.getX() << ", " << v.getY() << ")";
    return os;
}

// TODO (paso 1): estas tres funciones son identicas salvo el tipo.
// Reemplazalas por una sola plantilla de funcion "mayor".
int mayorEntero(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

double mayorDecimal(double a, double b) {
    if (a > b) {
        return a;
    }
    return b;
}

char mayorCaracter(char a, char b) {
    if (a > b) {
        return a;
    }
    return b;
}

// TODO (paso 3): escribe una plantilla "sumarTres" que reciba tres
// valores del mismo tipo y devuelva a + b + c.

int main() {
    // TODO (paso 1): cambia las tres llamadas para que usen "mayor".
    std::cout << "mayor(3, 7) = " << mayorEntero(3, 7) << std::endl;
    std::cout << "mayor(2.5, 1.5) = " << mayorDecimal(2.5, 1.5) << std::endl;
    std::cout << "mayor('a', 'z') = " << mayorCaracter('a', 'z') << std::endl;

    // TODO (paso 2): quita el comentario de la siguiente linea, compila y
    // lee el error. Corrigela indicando el tipo entre angulos.
    // std::cout << "mayor(3, 4.5) = " << mayor(3, 4.5) << std::endl;

    Vector2D v1(2.0, 3.0);
    Vector2D v2(4.0, -1.0);
    Vector2D v3(0.0, 1.0);

    // TODO (paso 3): imprime "sumarTres(1, 2, 3) = " con el resultado de
    // sumarTres(1, 2, 3), y "sumarTres(v1, v2, v3) = " con el resultado
    // de sumarTres(v1, v2, v3).

    // TODO (paso 4): quita el comentario de la siguiente linea, compila y
    // lee el error. Vuelve a comentarla.
    // std::cout << "mayor(v1, v2) = " << mayor(v1, v2) << std::endl;

    return 0;
}
