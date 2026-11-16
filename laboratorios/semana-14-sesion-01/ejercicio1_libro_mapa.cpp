#include <iostream>
#include <map>

// Ejercicio 1: el libro de ordenes de una bolsa, con un std::map.
// No lo modifiques: es la version contra la que comparas la tuya.
//
// Un libro de ordenes guarda, para cada precio, cuantas acciones hay
// ofrecidas a ese precio. Llegan 20 millones de eventos: una orden nueva
// suma acciones en un precio, una cancelacion las resta, y despues de cada
// evento el programa de trading consulta cuanto hay en ese precio. Los
// precios estan en centavos, entre 10000 y 10999 (de 100.00 a 109.99).
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -O2 ejercicio1_libro_mapa.cpp -o bin/ejercicio1_mapa
// Medir:     time ./bin/ejercicio1_mapa

const int PRECIO_MINIMO = 10000;
const int NIVELES = 1000;
const int EVENTOS = 20000000;

class LibroMapa {
public:
    void agregar(int precio, int cantidad) {
        niveles[precio] += cantidad;
    }

    void cancelar(int precio, int cantidad) {
        if (niveles.count(precio) == 0) {
            return;
        }
        if (niveles[precio] <= cantidad) {
            niveles.erase(precio);
        } else {
            niveles[precio] -= cantidad;
        }
    }

    int cantidadEn(int precio) {
        if (niveles.count(precio) == 0) {
            return 0;
        }
        return niveles[precio];
    }

private:
    std::map<int, int> niveles;
};

int main() {
    LibroMapa libro;
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
