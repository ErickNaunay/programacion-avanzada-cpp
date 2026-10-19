#include <iostream>

// Salida esperada:
// Suma de pasos: 9300
// Suma de temperaturas: 64.5
// Suma de desplazamientos: (4, 5)
// Dias con mas de 3000 pasos: 2
// Temperaturas sobre 21.0: 2

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

// TODO: escribe la plantilla de funcion sumarArreglo(datos, cantidad),
// que recibe un arreglo de T y su cantidad de elementos y devuelve la
// suma de todos. Tiene que funcionar para int, double y Vector2D.

// TODO: escribe la plantilla de funcion contarMayoresQue(datos, cantidad,
// umbral), que devuelve cuantos elementos del arreglo son mayores que
// umbral (un int).

int main() {
    int pasos[3] = {4200, 1800, 3300};
    double temperaturas[3] = {20.5, 21.5, 22.5};
    Vector2D desplazamientos[3] = {Vector2D(1.0, 2.0), Vector2D(3.0, -1.0), Vector2D(0.0, 4.0)};

    std::cout << "Suma de pasos: " << sumarArreglo(pasos, 3) << std::endl;
    std::cout << "Suma de temperaturas: " << sumarArreglo(temperaturas, 3) << std::endl;
    std::cout << "Suma de desplazamientos: " << sumarArreglo(desplazamientos, 3) << std::endl;

    std::cout << "Dias con mas de 3000 pasos: " << contarMayoresQue(pasos, 3, 3000) << std::endl;
    std::cout << "Temperaturas sobre 21.0: " << contarMayoresQue(temperaturas, 3, 21.0) << std::endl;

    return 0;
}
