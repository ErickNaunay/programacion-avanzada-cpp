// Ejercicio 1: Vehiculo y Auto
//
// Completa los metodos marcados con TODO. No cambies las firmas ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio1 ejercicio1_vehiculo_auto.cpp
// Ejecutar: ./ejercicio1
//
// Salida esperada:
// Velocidad maxima: 220
// Numero de puertas: 4

#include <iostream>

class Vehiculo {
private:
    double velocidadMaxima;
public:
    bool setVelocidadMaxima(double v) {
        // TODO: valida que v sea mayor a 0 y menor o igual a 300.
        // Si es valido, asigna velocidadMaxima y devuelve true.
        // Si no, devuelve false sin modificar el atributo.
        return false;
    }
    double getVelocidadMaxima() {
        // TODO: devuelve velocidadMaxima.
        return 0;
    }
};

class Auto : public Vehiculo {
private:
    int numeroPuertas;
public:
    bool setNumeroPuertas(int n) {
        // TODO: valida que n sea 2 o 4.
        // Si es valido, asigna numeroPuertas y devuelve true.
        // Si no, devuelve false sin modificar el atributo.
        return false;
    }
    int getNumeroPuertas() {
        // TODO: devuelve numeroPuertas.
        return 0;
    }
};

int main() {
    Auto auto1;
    auto1.setVelocidadMaxima(220);
    auto1.setNumeroPuertas(4);
    std::cout << "Velocidad maxima: " << auto1.getVelocidadMaxima() << std::endl;
    std::cout << "Numero de puertas: " << auto1.getNumeroPuertas() << std::endl;
    return 0;
}
