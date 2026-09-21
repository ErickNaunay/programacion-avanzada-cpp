// Ejercicio 5: Motor y Carro (composicion y delegacion)
//
// Completa los metodos marcados con TODO. No cambies las firmas ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio5 ejercicio5_motor_carro.cpp
// Ejecutar: ./ejercicio5
//
// Salida esperada:
// Motor con 450 caballos de fuerza
// Color: 3

#include <iostream>

class Motor {
private:
    double caballosFuerza;
public:
    bool setCaballosFuerza(double c) {
        // TODO: valida que c sea mayor a 0 y menor o igual a 1500.
        return false;
    }
    void mostrarPotencia() {
        // TODO: imprime "Motor con " + caballosFuerza + " caballos de fuerza" y un salto de linea.
    }
};

class Carro {
private:
    Motor motor;
    int colorCodigo;
public:
    bool configurarMotor(double c) {
        // TODO: delega en motor.setCaballosFuerza(c) y devuelve su resultado.
        return false;
    }
    bool setColorCodigo(int c) {
        // TODO: valida que c este entre 0 y 9 (ambos incluidos).
        return false;
    }
    int getColorCodigo() {
        // TODO: devuelve colorCodigo.
        return 0;
    }
    void encender() {
        // TODO: delega en motor.mostrarPotencia().
    }
};

int main() {
    Carro carro1;
    carro1.configurarMotor(450);
    carro1.setColorCodigo(3);
    carro1.encender();
    std::cout << "Color: " << carro1.getColorCodigo() << std::endl;
    return 0;
}
