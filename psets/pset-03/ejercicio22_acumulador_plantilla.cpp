// Ejercicio 22: Acumulador<T> (desde cero, plantilla de clase)
//
// Este archivo no tiene codigo de partida. Escribe tus propios includes, tu
// propia plantilla de clase y tu propio main().
//
// Disena la plantilla de clase Acumulador<T>, que recibe valores uno por
// uno y lleva cuenta de ellos sin guardarlos todos. Atributos privados:
// total (T), maximo (T) y cantidad (int). Metodos:
// - Constructor sin parametros: total en T(), maximo en T(), cantidad en 0.
// - void agregar(T valor): suma valor al total y cuenta uno mas. Si es el
//   primer valor, o si es mayor que el maximo, lo guarda como maximo.
// - T getTotal(), T getMaximo(), int getCantidad().
// - double promedio(): total dividido para cantidad, o 0 si no hay valores.
// - void reiniciar(): vuelve al estado del constructor.
//
// En main(): crea un Acumulador<int> para los goles de un equipo y agrega
// 2, 0, 5 y 1. Crea un Acumulador<double> para tiempos de vuelta y agrega
// -3.5, -1.25 y -2.0 (son diferencias negativas: el maximo tiene que ser
// -1.25, no 0). Imprime los valores con los textos de la salida esperada.
// Reinicia el de goles e imprime su cantidad y su promedio.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio22 ejercicio22_acumulador_plantilla.cpp
// Ejecutar: ./ejercicio22
//
// Salida esperada:
// Goles: 8 en 4 partidos, maximo 5, promedio 2
// Diferencias: total -6.75, maximo -1.25
// Despues de reiniciar: 0 partidos, promedio 0


 #include <iostream>
#include <map>
#include <optional>
#include <set>
#include <memory>

template <typename T>
class Acumulador {
private:
    T total;
    T maximo;
    int cantidad;
public:
    Acumulador() {
        total = T();
        maximo = T();   
        cantidad = 0;
    }
    void agregar(T valor) {
        total += valor;
        cantidad++;
        if (cantidad == 1 || valor > maximo) {
            maximo = valor;
        }
    }
    T getTotal() {
        return total;
    }
    T getMaximo() {
        return maximo;
    }
    int getCantidad() {
        return cantidad;
    }
    double promedio() {
        if (cantidad == 0) {
            return 0;
        }
        return static_cast<double>(total) / cantidad;
    }
    void reiniciar() {
        total = T();
        maximo = T();
        cantidad = 0;
    }
};  

int main() {
    Acumulador<int> goles;
    goles.agregar(2);
    goles.agregar(0);
    goles.agregar(5);
    goles.agregar(1);
    std::cout << "Goles: " << goles.getTotal() << " en " << goles.getCantidad() 
              << " partidos, maximo " << goles.getMaximo() 
              << ", promedio " << goles.promedio() << std::endl;

    Acumulador<double> diferencias;
    diferencias.agregar(-3.5);
    diferencias.agregar(-1.25);
    diferencias.agregar(-2.0);
    std::cout << "Diferencias: total " << diferencias.getTotal() 
              << ", maximo " << diferencias.getMaximo() << std::endl;

    goles.reiniciar();
    std::cout << "Despues de reiniciar: " << goles.getCantidad() 
              << " partidos, promedio " << goles.promedio() << std::endl;

    return 0;
}