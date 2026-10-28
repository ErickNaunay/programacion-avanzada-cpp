#include <iostream>
#include <memory>

class Figura {
public:
    virtual double area() = 0;

    virtual void imprimirNombre() = 0;

    void describir() {
        imprimirNombre();
        std::cout << " de area " << area() << std::endl;
    }

    virtual ~Figura() {
    }
};

class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(double nuevoRadio) {
        radio = nuevoRadio;
    }

    double area() override {
        return 3.14159 * radio * radio;
    }

    void imprimirNombre() override {
        std::cout << "Circulo";
    }
};

class Rectangulo : public Figura {
private:
    double base;
    double altura;

public:
    Rectangulo(double nuevaBase, double nuevaAltura) {
        base = nuevaBase;
        altura = nuevaAltura;
    }

    double area() override {
        return base * altura;
    }

    void imprimirNombre() override {
        std::cout << "Rectangulo";
    }
};

class Triangulo : public Figura {
private:
    double base;
    double altura;

public:
    Triangulo(double nuevaBase, double nuevaAltura) {
        base = nuevaBase;
        altura = nuevaAltura;
    }

    double area() override {
        return (base * altura) / 2;
    }

    void imprimirNombre() override {
        std::cout << "Triangulo";
    }
};

int main() {
    // Figura generica;

    std::unique_ptr<Figura> figuras[3];

    figuras[0] = std::make_unique<Circulo>(1.0);
    figuras[1] = std::make_unique<Rectangulo>(2.0, 3.0);
    figuras[2] = std::make_unique<Triangulo>(4.0, 3.0);

    for (int i = 0; i < 3; i++) {
        figuras[i]->describir();
    }

    return 0;
}