// Ejercicio 1: Instrumento, Guitarra y Bateria (funciones virtuales)
//
// Completa lo marcado con TODO. No cambies las firmas ni el main().
//
// Fijate en volumen(): no es virtual en Instrumento. Antes de correr el
// programa, decide que va a imprimir la segunda linea y por que.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio1 ejercicio1_instrumento_guitarra.cpp
// Ejecutar: ./ejercicio1
//
// Salida esperada:
// Guitarra por puntero, notas por minuto: 120
// Guitarra por puntero, volumen: 5
// Guitarra directa, volumen: 8
// Bateria por puntero, notas por minuto: 150

#include <iostream>

class Instrumento {
public:
    virtual ~Instrumento() {}
    virtual int notasPorMinuto() {
        return 60;
    }
    int volumen() {
        return 5;
    }
};

class Guitarra : public Instrumento {
private:
    int cuerdas;
public:
    Guitarra(int c) {
        cuerdas = c;
    }
    int notasPorMinuto() override {
        // TODO: devuelve cuerdas * 20.
        return 0;
    }
    int volumen() {
        return 8;
    }
};

class Bateria : public Instrumento {
private:
    int tambores;
public:
    Bateria(int t) {
        tambores = t;
    }
    // TODO: escribe aqui notasPorMinuto, sobrescrito con override: devuelve
    // tambores * 30.
};

int main() {
    Guitarra guitarra(6);
    Bateria bateria(5);

    Instrumento* instrumento = &guitarra;
    std::cout << "Guitarra por puntero, notas por minuto: " << instrumento->notasPorMinuto() << std::endl;
    std::cout << "Guitarra por puntero, volumen: " << instrumento->volumen() << std::endl;
    std::cout << "Guitarra directa, volumen: " << guitarra.volumen() << std::endl;

    instrumento = &bateria;
    std::cout << "Bateria por puntero, notas por minuto: " << instrumento->notasPorMinuto() << std::endl;
    return 0;
}
