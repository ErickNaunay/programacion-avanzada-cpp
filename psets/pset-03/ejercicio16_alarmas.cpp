// Ejercicio 16: Alarma, AlarmaDeIncendio y AlarmaDeIntrusion (desde cero, funciones virtuales)
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio16 ejercicio16_alarmas.cpp
// Ejecutar: ./ejercicio16
//
// Salida esperada:
// Incendio por puntero, aviso: 60
// Incendio por puntero, prioridad: 1
// Incendio directa, prioridad: 3
// Intrusion por puntero, aviso: 36
// Alarma comun por puntero, aviso: 10

#include <iostream>

class Alarma {
public:
    virtual ~Alarma() {}

    virtual int segundosDeAviso() const {
        return 10;
    }

    int prioridad() const {
        return 1;
    }
};

class AlarmaDeIncendio : public Alarma {
private:
    int pisos;

public:
    AlarmaDeIncendio(int p) : pisos(p) {}

    int segundosDeAviso() const override {
        return pisos * 15;
    }

    int prioridad() const {
        return 3;
    }
};

class AlarmaDeIntrusion : public Alarma {
private:
    int sensores;

public:
    AlarmaDeIntrusion(int s) : sensores(s) {}

    int segundosDeAviso() const override {
        return sensores * 4;
    }
};

int main() {
    AlarmaDeIncendio incendio(4);
    AlarmaDeIntrusion intrusion(9);

    Alarma* ptr = &incendio;
    std::cout << "Incendio por puntero, aviso: " << ptr->segundosDeAviso() << std::endl;
    std::cout << "Incendio por puntero, prioridad: " << ptr->prioridad() << std::endl;
    std::cout << "Incendio directa, prioridad: " << incendio.prioridad() << std::endl;

    ptr = &intrusion;
    std::cout << "Intrusion por puntero, aviso: " << ptr->segundosDeAviso() << std::endl;

    Alarma comun;
    ptr = &comun;
    std::cout << "Alarma comun por puntero, aviso: " << ptr->segundosDeAviso() << std::endl;

    return 0;
}