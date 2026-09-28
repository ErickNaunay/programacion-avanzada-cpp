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
        centavos = centavosIniciales;
    }

    int getCentavos() {
        return centavos;
    }

    Dinero operator+(Dinero otro) {
        return Dinero(centavos + otro.getCentavos());
    }

};

std::ostream& operator<<(std::ostream& os, Dinero d) {
    int totalCentavos = d.getCentavos();
    int dolares = totalCentavos / 100;
    int centavosRestantes = totalCentavos % 100;

            os << "$" << dolares << ".";

        if (centavosRestantes < 10) {
            os << "0";
        }

        os << centavosRestantes;
        
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
