// Ejercicio 3: NumeroComplejo
//
// Resuelve este ejercicio por tu cuenta. Mismo patrón de los ejercicios
// 1 y 2, sin invariante: sumar dos números complejos suma la parte real
// y la parte imaginaria por separado.
//
// Salida esperada:
// 3 + 2i + 1 + -5i = 4 + -3i
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio3_numero_complejo.cpp -o bin/ejercicio3
// Ejecutar:  ./bin/ejercicio3

#include <iostream>

class NumeroComplejo {
private:
    double real;
    double imaginario;

public:
    NumeroComplejo(double realInicial, double imaginarioInicial) {
        real = realInicial;
        imaginario = imaginarioInicial;
    }

    double getReal() { return real; }
    double getImaginario() { return imaginario; }

    NumeroComplejo operator+(NumeroComplejo otro) {
        // TODO: retorna un NumeroComplejo nuevo con la suma de las
        // partes reales y la suma de las partes imaginarias.
        return NumeroComplejo(0.0, 0.0);
    }
};

std::ostream& operator<<(std::ostream& os, NumeroComplejo c) {
    // TODO: escribe en os algo como "real + imaginarioi" (por ejemplo,
    // "3 + 2i"), usando c.getReal() y c.getImaginario(), y despues
    // retorna os.
    return os;
}

int main() {
    NumeroComplejo c1(3.0, 2.0);
    NumeroComplejo c2(1.0, -5.0);
    NumeroComplejo suma = c1 + c2;

    std::cout << c1 << " + " << c2 << " = " << suma << std::endl;

    return 0;
}
