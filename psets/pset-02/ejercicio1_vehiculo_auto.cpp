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
              if (v <= 0 || v > 300) {
            return false;
        }

                velocidadMaxima = v;
            return true;
        }

                double getVelocidadMaxima() {
            return velocidadMaxima;
        }
};

class Auto : public Vehiculo {
private:
    int numeroPuertas;
public:
       bool setNumeroPuertas(int n) {
            if (n != 2 && n != 4) {
                return false;
            }

                numeroPuertas = n;
            return true;
            }

            int getNumeroPuertas() {
        return numeroPuertas;
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
