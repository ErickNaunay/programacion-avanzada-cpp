// Ejercicio 1: Rectangulo encapsulado
//
// La sesion pasada, Rectangulo era un struct con base y altura publicos:
// cualquiera podia escribir r.base = -5.0 y el compilador lo aceptaba sin
// aviso, aunque un rectangulo con base negativa no tiene sentido.
//
// Hoy, base y altura son privados: la unica forma de cambiarlos es a
// traves de setBase() y setAltura(), y esos metodos primero verifican
// que el valor sea positivo antes de aceptarlo. Si el valor no es
// valido, el metodo lo rechaza (devuelve false) y el atributo no cambia.
//
// Salida esperada:
// Area: 50, Perimetro: 30
// setBase(-3) rechazado: true, base sigue en: 10
// Area: 200, Perimetro: 60
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio1_class_rectangulo.cpp -o bin/ejercicio1
// Ejecutar:  ./bin/ejercicio1

#include <iostream>

class Rectangulo {
private:
    double base;
    double altura;

public:
    double getBase() { return base; }
    double getAltura() { return altura; }

    bool setBase(double nuevaBase) {
        // TODO: si nuevaBase no es positiva, devuelve false sin modificar base.
        // Si es positiva, asigna base = nuevaBase y devuelve true.
        return false;
    }

    bool setAltura(double nuevaAltura) {
        // TODO: mismo patron que setBase(), pero para altura.
        return false;
    }

    double area() {
        // TODO: retorna base * altura
        return 0.0;
    }

    double perimetro() {
        // TODO: retorna 2 * (base + altura)
        return 0.0;
    }
};

int main() {
    Rectangulo r;
    r.setBase(10.0);
    r.setAltura(5.0);

    std::cout << "Area: " << r.area() << ", Perimetro: " << r.perimetro() << std::endl;

    bool aceptado = r.setBase(-3.0);
    std::cout << "setBase(-3) rechazado: " << (!aceptado ? "true" : "false")
              << ", base sigue en: " << r.getBase() << std::endl;

    r.setBase(20.0);
    r.setAltura(10.0);
    std::cout << "Area: " << r.area() << ", Perimetro: " << r.perimetro() << std::endl;

    return 0;
}
