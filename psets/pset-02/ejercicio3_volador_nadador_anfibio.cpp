// Ejercicio 3: Volador, Nadador y VehiculoAnfibio (herencia multiple)
//
// Completa los metodos marcados con TODO. No cambies las firmas ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio3 ejercicio3_volador_nadador_anfibio.cpp
// Ejecutar: ./ejercicio3
//
// Salida esperada:
// Altitud maxima: 3000
// Profundidad maxima: 50
// Tripulantes: 6

#include <iostream>

class Volador {
private:
    double altitudMaxima;
public:
    bool setAltitudMaxima(double a) {
        // TODO: valida que a sea mayor a 0 y menor o igual a 15000.
        return false;
    }
    double getAltitudMaxima() {
        // TODO: devuelve altitudMaxima.
        return 0;
    }
};

class Nadador {
private:
    double profundidadMaxima;
public:
    bool setProfundidadMaxima(double p) {
        // TODO: valida que p sea mayor a 0 y menor o igual a 300.
        return false;
    }
    double getProfundidadMaxima() {
        // TODO: devuelve profundidadMaxima.
        return 0;
    }
};

class VehiculoAnfibio : public Volador, public Nadador {
private:
    int numeroTripulantes;
public:
    bool setNumeroTripulantes(int n) {
        // TODO: valida que n sea mayor a 0 y menor o igual a 20.
        return false;
    }
    int getNumeroTripulantes() {
        // TODO: devuelve numeroTripulantes.
        return 0;
    }
};

int main() {
    VehiculoAnfibio v1;
    v1.setAltitudMaxima(3000);
    v1.setProfundidadMaxima(50);
    v1.setNumeroTripulantes(6);
    std::cout << "Altitud maxima: " << v1.getAltitudMaxima() << std::endl;
    std::cout << "Profundidad maxima: " << v1.getProfundidadMaxima() << std::endl;
    std::cout << "Tripulantes: " << v1.getNumeroTripulantes() << std::endl;
    return 0;
}
