// Ejercicio 10: Figura y Circulo (herencia + operator<< juntos)
//
// Completa los metodos marcados con TODO y operator<<. No cambies las firmas
// ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio10 ejercicio10_figura_circulo.cpp
// Ejecutar: ./ejercicio10
//
// Salida esperada:
// Figura 7, radio 5.5

#include <iostream>

class Figura {
private:
    int nombreCodigo;
public:
    bool setNombreCodigo(int n) {
        if (n < 1 || n > 99) {
            return false;
        }

        nombreCodigo = n;
        return true;
    }

    int getNombreCodigo() {
        return nombreCodigo;
    }
};

class Circulo : public Figura {
private:
    double radio;
public:
    bool setRadio(double r) {
        if (r <= 0 || r > 1000) {
            return false;
        }

        radio = r;
        return true;
    }

    double getRadio() {
        return radio;
    }

};

std::ostream& operator<<(std::ostream& os, Circulo c) {
    os << "Figura " << c.getNombreCodigo() << ", radio " << c.getRadio();
    return os;
}

int main() {
    Circulo c1;
    c1.setNombreCodigo(7);
    c1.setRadio(5.5);
    std::cout << c1 << std::endl;
    return 0;
}
