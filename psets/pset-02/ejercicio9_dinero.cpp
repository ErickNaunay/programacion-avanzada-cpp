// Ejercicio 9: Dinero (operator+ y operator<< juntos)
//
// Completa el constructor, el getter, operator+ y operator<<. No cambies las
// firmas ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio9 ejercicio9_dinero.cpp
// Ejecutar: ./ejercicio9
//
// Salida esperada:
// $10.50
// $2.75
// $13.25

#include <iostream>

class Dinero {
private:
    int centavos;
public:
    Dinero(int centavosIniciales) {
        // TODO: asigna centavos por asignacion directa.
        centavos = centavosIniciales;
    }
    int getCentavos() {
        // TODO: devuelve centavos.
        return centavos;
    }
    Dinero operator+(Dinero otro) {
        // TODO: devuelve un Dinero nuevo con la suma de los centavos de ambos.
        return Dinero(centavos + otro.getCentavos());
    }
};

std::ostream& operator<<(std::ostream& os, Dinero d) {
    // TODO: escribe en os "$" seguido de los dolares (centavos / 100), un punto,
    // y los centavos restantes (centavos % 100) con dos digitos: si es menor a
    // 10 antepon un "0" (por ejemplo 275 centavos se imprime como "$2.75").
    // Devuelve os.
    int dolares = d.getCentavos() / 100;
    int centavos_restantes = d.getCentavos() % 100;
    os << "$" << dolares << ".";
    if (centavos_restantes < 10) {
        os << "0";
    }
    os << centavos_restantes;
    return os;
}

int main() {
    Dinero d1(1050);
    Dinero d2(275);
    Dinero d3 = d1 + d2;
    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;
    std::cout << d3 << std::endl;
    return 0;
}
