#include <iostream>
#include <vector>

// Ejercicio 1: el mismo libro de ordenes, con un std::vector.
//
// Los precios posibles son pocos y conocidos (1000 niveles, de 10000 a
// 10999 centavos), asi que cada precio puede tener su casilla fija en un
// vector: la casilla precio - PRECIO_MINIMO. El main es el mismo que el de
// ejercicio1_libro_mapa.cpp, y las dos versiones tienen que imprimir los
// mismos numeros.
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -O2 ejercicio1_libro_arreglo.cpp -o bin/ejercicio1_arreglo
// Medir:     time ./bin/ejercicio1_arreglo

const int PRECIO_MINIMO = 10000;
const int NIVELES = 1000;
const int EVENTOS = 20000000;

class LibroArreglo {
public:
    LibroArreglo() {
        // TODO 1: deja el vector con NIVELES casillas en 0 (reserve y
        // push_back), antes de que llegue el primer evento.
    }

    void agregar(int precio, int cantidad) {
        // TODO 2: suma la cantidad en la casilla de ese precio.
    }

    void cancelar(int precio, int cantidad) {
        // TODO 2: resta la cantidad, sin bajar de 0 (como el mapa, que borra
        // el nivel cuando se cancela todo lo que habia).
    }

    int cantidadEn(int precio) {
        // TODO 3: devuelve lo que hay en la casilla de ese precio.
        return 0;
    }

private:
    std::vector<int> cantidades;
};

int main() {
    LibroArreglo libro;
    unsigned int semilla = 12345;
    long long sumaConsultas = 0;
    for (int i = 0; i < EVENTOS; i++) {
        semilla = semilla * 1103515245 + 12345;
        int precio = PRECIO_MINIMO + (semilla >> 8) % NIVELES;
        int cantidad = 1 + (semilla >> 20) % 100;
        if ((semilla >> 4) % 3 == 0) {
            libro.cancelar(precio, cantidad);
        } else {
            libro.agregar(precio, cantidad);
        }
        sumaConsultas += libro.cantidadEn(precio);
    }
    long long total = 0;
    for (int precio = PRECIO_MINIMO; precio < PRECIO_MINIMO + NIVELES; precio++) {
        total += libro.cantidadEn(precio);
    }
    std::cout << "Acciones en el libro: " << total << std::endl;
    std::cout << "Suma de las consultas: " << sumaConsultas << std::endl;
    return 0;
}
