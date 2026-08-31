// Ejercicio 3: Empleado, Gerente y Vendedor
//
// Resuelve este ejercicio por tu cuenta. Mismo patrón de los ejercicios
// 1 y 2: Empleado agrupa salarioBase y aniosServicio; Gerente y
// Vendedor heredan de Empleado y agregan aprobarPresupuesto() y
// registrarVenta(). Además, agrega a Empleado un método nuevo,
// calcularBonoAntiguedad(), que Gerente y Vendedor van a heredar sin
// tener que escribirlo de nuevo.
//
// Salida esperada:
// Empleado con salario base 1500, 4 anios de servicio
// Bono de antiguedad: 400
// Presupuesto aprobado
// Empleado con salario base 900, 1 anios de servicio
// Bono de antiguedad: 100
// Venta registrada
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio3_empleado_gerente_vendedor.cpp -o bin/ejercicio3
// Ejecutar:  ./bin/ejercicio3

#include <iostream>

class Empleado {
private:
    double salarioBase;
    double aniosServicio;

public:
    Empleado() {
        salarioBase = 0.0;
        aniosServicio = 0.0;
    }

    bool setSalarioBase(double nuevoSalario) {
        // TODO: si nuevoSalario no es positivo, devuelve false sin
        // modificar salarioBase. Si no, asigna salarioBase = nuevoSalario
        // y devuelve true.
        return false;
    }

    bool setAniosServicio(double nuevosAnios) {
        // TODO: mismo patron que setSalarioBase(), pero para
        // aniosServicio (no puede ser negativo).
        return false;
    }

    double getSalarioBase() { return salarioBase; }
    double getAniosServicio() { return aniosServicio; }

    void describir() {
        // TODO: imprime "Empleado con salario base " + salarioBase +
        // ", " + aniosServicio + " anios de servicio"
    }

    double calcularBonoAntiguedad() {
        // TODO: retorna aniosServicio * 100.0
        return 0.0;
    }
};

class Gerente : public Empleado {
public:
    void aprobarPresupuesto() {
        std::cout << "Presupuesto aprobado" << std::endl;
    }
};

class Vendedor : public Empleado {
public:
    void registrarVenta() {
        std::cout << "Venta registrada" << std::endl;
    }
};

int main() {
    Gerente g;
    g.setSalarioBase(1500.0);
    g.setAniosServicio(4.0);
    g.describir();
    std::cout << "Bono de antiguedad: " << g.calcularBonoAntiguedad() << std::endl;
    g.aprobarPresupuesto();

    Vendedor v;
    v.setSalarioBase(900.0);
    v.setAniosServicio(1.0);
    v.describir();
    std::cout << "Bono de antiguedad: " << v.calcularBonoAntiguedad() << std::endl;
    v.registrarVenta();

    return 0;
}
