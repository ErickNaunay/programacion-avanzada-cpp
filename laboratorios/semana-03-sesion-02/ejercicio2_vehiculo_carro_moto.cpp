// Ejercicio 2: Vehiculo, Carro y Moto
//
// Mismo patrón del ejercicio 1, en un dominio distinto: Vehiculo agrupa
// velocidadKmh y kilometraje; Carro y Moto heredan de Vehiculo y
// agregan tocarBocina() y acelerar(). Completa los TODO en Vehiculo.
//
// Salida esperada:
// Vehiculo a 120 km/h, 45000 km recorridos
// Piii!
// Vehiculo a 90 km/h, 8000 km recorridos
// Vrrrm!
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio2_vehiculo_carro_moto.cpp -o bin/ejercicio2
// Ejecutar:  ./bin/ejercicio2

#include <iostream>
using namespace std;

class Vehiculo {
private:
    double velocidadKmh;
    double kilometraje;

public:
    Vehiculo() {
        velocidadKmh = 0.0;
        kilometraje = 0.0;
    }

    bool setVelocidadKmh(double nuevaVelocidad) {
        // TODO: si nuevaVelocidad es negativa, devuelve false sin modificar
        // velocidadKmh. Si no, asigna velocidadKmh = nuevaVelocidad y
        // devuelve true.
        if(nuevaVelocidad <0)return false;
        velocidadKmh = nuevaVelocidad; return true;
    }

    bool setKilometraje(double nuevoKilometraje) {
        // TODO: mismo patron que setVelocidadKmh(), pero para kilometraje
        // (no puede ser negativo).
        if(nuevoKilometraje <0)return false;
        kilometraje = nuevoKilometraje; return true;
    }

    double getVelocidadKmh() { return velocidadKmh; }
    double getKilometraje() { return kilometraje; }

    void describir() {
        // TODO: imprime "Vehiculo a " + velocidadKmh + " km/h, " +
        // kilometraje + " km recorridos"
        cout<<"Vehiculo a "<< velocidadKmh<<" km/h, "<< kilometraje<< " km recorridos"<<endl; 
    }
};

class Carro : public Vehiculo {
public:
    void tocarBocina() {
        std::cout << "Piii!" << std::endl;
    }
};

class Moto : public Vehiculo {
public:
    void acelerar() {
        std::cout << "Vrrrm!" << std::endl;
    }
};

int main() {
    Carro c;
    c.setVelocidadKmh(120.0);
    c.setKilometraje(45000.0);
    c.describir();
    c.tocarBocina();

    Moto m;
    m.setVelocidadKmh(90.0);
    m.setKilometraje(8000.0);
    m.describir();
    m.acelerar();

    return 0;
}
