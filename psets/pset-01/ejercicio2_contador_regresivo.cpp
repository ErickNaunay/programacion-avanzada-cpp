// Ejercicio 2: ContadorRegresivo
//
// Completa el struct ContadorRegresivo: un atributo valor y un metodo
// decrementar() que le reste 1 a valor, pero solo si valor es mayor
// que 0 (nunca debe volverse negativo).
//
// Salida esperada:
// Valor inicial: 3
// Valor: 2
// Valor: 1
// Valor: 0
// Valor: 0
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio2_contador_regresivo.cpp -o bin/ejercicio2
// Ejecutar:  ./bin/ejercicio2

#include <iostream>

struct ContadorRegresivo {
    int valor;

    void decrementar() {
        // TODO: si valor > 0, resta 1 a valor. Si no, no hagas nada.
    }
};

int main() {
    ContadorRegresivo c;
    c.valor = 3;
    std::cout << "Valor inicial: " << c.valor << std::endl;

    c.decrementar();
    std::cout << "Valor: " << c.valor << std::endl;
    c.decrementar();
    std::cout << "Valor: " << c.valor << std::endl;
    c.decrementar();
    std::cout << "Valor: " << c.valor << std::endl;
    c.decrementar();
    std::cout << "Valor: " << c.valor << std::endl;

    return 0;
}
