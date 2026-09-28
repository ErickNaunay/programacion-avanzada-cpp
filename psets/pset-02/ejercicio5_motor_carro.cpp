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
            if (c <= 0 || c > 1500) {
                return false;
        }

            caballosFuerza = c;
        return true;
    }

    void mostrarPotencia() {
        std::cout << "Motor con " << caballosFuerza << " caballos de fuerza" << std::endl;
    }
};

class Carro {
private:
    Motor motor;
    int colorCodigo;
public:
    bool configurarMotor(double c) {
        return motor.setCaballosFuerza(c);
        }

    bool setColorCodigo(int c) {
            if (c < 0 || c > 9) {
                return false;
        }

            colorCodigo = c;
        return true;
    }

        int getColorCodigo() {
            return colorCodigo;
    }

    void encender() {
        motor.mostrarPotencia();
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
