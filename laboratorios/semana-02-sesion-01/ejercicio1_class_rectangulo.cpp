#include <iostream>

class Rectangulo {
private:
    double base;
    double altura;

public:
    double getBase() { return base; }
    double getAltura() { return altura; }

    bool setBase(double nuevaBase) {
        if(nuevaBase<=0){return false;}
        base =nuevaBase;
        return true;
    }

    bool setAltura(double nuevaAltura) {
        if(nuevaAltura<=0){return false;}
        altura = nuevaAltura;
        return true;
    }

    double area() {
        return base * altura;
    }

    double perimetro() {
        return base*2+altura*2;
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