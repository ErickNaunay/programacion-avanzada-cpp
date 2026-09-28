// Ejercicio 16: Empleado y Gerente (desde cero)
//
// Este archivo no tiene codigo de partida. Escribe tu de tu propia clase,
// tus propios includes y tu propio main().
//
// Disena dos clases:
//
// Empleado: atributo privado salarioBase (double). Setter bool
// setSalarioBase(double s) que valida que s sea mayor a 0 y menor o igual a
// 50000; si es valido asigna y devuelve true, si no devuelve false sin
// modificar el atributo. Getter double getSalarioBase().
//
// Gerente: hereda publicamente de Empleado. Agrega un atributo privado bono
// (double). Setter bool setBono(double b) que valida que b sea mayor a 0 y
// menor o igual a 10000, con el mismo patron que el setter anterior. Getter
// double getBono().
//
// En main(): crea un Gerente, asignale un salario base de 4200 con el setter
// heredado y un bono de 800 con su propio setter. Imprime la suma de ambos
// valores (salario base mas bono), precedida por "Total: ".
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio16 ejercicio16_empleado_gerente.cpp
// Ejecutar: ./ejercicio16
//
// Salida esperada:
// Total: 5000
#include <iostream>

class Empleado {
private:
    double salarioBase;
public:
    Empleado() : salarioBase(0.0) {}
    bool setSalarioBase(double s) {
        if (s > 0 && s <= 50000) {
            salarioBase = s;
            return true;
        }
        return false;
    }
    double getSalarioBase() const {
        return salarioBase;
    }
};

class Gerente : public Empleado {
private:
    double bono;
public:
    Gerente() : bono(0.0) {}
    bool setBono(double b) {
        if (b > 0 && b <= 10000) {
            bono = b;
            return true;
        }
        return false;
    }
    double getBono() const {
        return bono;
    }
};

int main() {
    Gerente g;
    g.setSalarioBase(4200);
    g.setBono(800);
    std::cout << "Total: " << g.getSalarioBase() + g.getBono() << std::endl;
    return 0;
}
