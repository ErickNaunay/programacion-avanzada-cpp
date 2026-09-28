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
// Compilar:  g++ -std=c++20 -Wall -Wextra -g laboratorios/semana-02-sesion-01/ejercicio1_class_rectangulo.cpp -o bin/ejercicio1
// Ejecutar:  ./bin/ejercicio1

#include <iostream>

class Rectangulo {
private:
    double base; //se define la variabl, al estar en una privada nadie peude editarlo desde afuera
    double altura;   

public:
    double getBase() { return base; }    //llamamos
    double getAltura() { return altura; }

    bool setBase(double nuevaBase) {
        if(nuevaBase<=0){      //set para colocar el nuevo valor para la variale
            return false;
        }
        base=nuevaBase;
        return true;
    }
    bool setAltura(double nuevaAltura) {
        if(nuevaAltura<=0){
            return false;
        }
        altura=nuevaAltura;
        return true;
    }

    double area() {
        return base*altura;
    }

    double perimetro() {
        return 2*(base+altura);
    }
};

int main() {
    Rectangulo r;
    bool resultadoSetBase=r.setBase(10.0);
    bool resultadoSetAltura=r.setAltura(5.0);

    std::cout << "Area: " << r.area() << ", Perimetro: " << r.perimetro() << std::endl;

    bool aceptado = r.setBase(-3.0);
    std::cout << "setBase(-3) rechazado: " << (!aceptado ? "true" : "false")
              << ", base sigue en: " << r.getBase() << std::endl;

    r.setBase(20.0);
    r.setAltura(10.0);
    std::cout << "Area: " << r.area() << ", Perimetro: " << r.perimetro() << std::endl;

    return 0;
}

//Si hay un error y no se ingresa el valor el programa tomara la direccion como valor
//defecto para continuar