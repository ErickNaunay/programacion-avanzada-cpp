// Ejercicio 3: PuntoCartesiano
//
// Completa el struct PuntoCartesiano: dos atributos, x e y, y un metodo
// distancia(PuntoCartesiano otro) que devuelva la distancia entre este
// punto y otro, recibido como parametro por valor. Usa la formula de
// distancia euclidiana: raiz cuadrada de (dx*dx + dy*dy). std::sqrt vive
// en <cmath>.
//
// Salida esperada:
// Distancia entre p1 y p2: 5
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio3_punto_cartesiano.cpp -o bin/ejercicio3
// Ejecutar:  ./bin/ejercicio3

#include <iostream>
#include <cmath>

struct PuntoCartesiano {
    double x, y;

    double distancia(PuntoCartesiano otro) {
        // TODO: calcula dx = x - otro.x, dy = y - otro.y, y retorna
        // std::sqrt(dx * dx + dy * dy)
        return 0.0;
    }
};

int main() {
    PuntoCartesiano p1;
    p1.x = 0.0;
    p1.y = 0.0;

    PuntoCartesiano p2;
    p2.x = 3.0;
    p2.y = 4.0;

    std::cout << "Distancia entre p1 y p2: " << p1.distancia(p2) << std::endl;

    return 0;
}
