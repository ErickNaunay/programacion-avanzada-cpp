// Ejercicio 4: Figura, Rectangulo y Triangulo (clase abstracta)
//
// Completa lo marcado con TODO. No cambies las firmas ni el main().
//
// Figura no debe poder instanciarse: una Figura sin forma no tiene area.
// Hoy area() tiene un cuerpo que devuelve 0; conviertela en virtual pura.
// Cuando lo hagas, prueba agregar "Figura f;" en el main: no debe compilar.
// Despues borra esa linea.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio4 ejercicio4_figuras_abstractas.cpp
// Ejecutar: ./ejercicio4
//
// Salida esperada:
// Area: 12
// Area: 7.5
// Area: 0
// La de mayor area es la figura con area 12

#include <iostream>

class Figura {
public:
    virtual ~Figura() {}
    // TODO: convierte area en una funcion virtual pura (sin cuerpo).
    virtual double area() = 0;
};

class Rectangulo : public Figura {
private:
    double base;
    double altura;
public:
    Rectangulo(double b, double h) {
        // TODO: si b o h es negativo, guarda 0 en ese lado; si no, guarda el valor.
        base = (b < 0) ? 0 : b;
        altura = (h < 0) ? 0 : h;
    }
    double area() override {
        // TODO: devuelve base * altura.
        return base * altura;
    }
};

class Triangulo : public Figura {
private:
    double base;
    double altura;
public:
    Triangulo(double b, double h) {
        // TODO: igual que en Rectangulo.
        base = (b < 0) ? 0 : b;
        altura = (h < 0) ? 0 : h;
    }
    double area() override {
        // TODO: devuelve base * altura / 2.
        return (base * altura) / 2.0;
    }
};

void imprimirArea(Figura* figura) {
    // TODO: imprime "Area: " seguido de figura->area() y un salto de linea.
    std::cout << "Area: " << figura->area() << std::endl;
}

Figura* mayorArea(Figura* a, Figura* b) {
    // TODO: devuelve el puntero a la figura de mayor area; si son iguales, a.
    if (b->area() > a->area()) {
        return b;
    }
    return a;
}

int main() {
    Rectangulo rectangulo(3, 4);
    Triangulo triangulo(5, 3);
    Rectangulo invalido(-2, 6);

    imprimirArea(&rectangulo);
    imprimirArea(&triangulo);
    imprimirArea(&invalido);

    Figura* mayor = mayorArea(&triangulo, &rectangulo);
    std::cout << "La de mayor area es la figura con area " << mayor->area() << std::endl;
    return 0;
}