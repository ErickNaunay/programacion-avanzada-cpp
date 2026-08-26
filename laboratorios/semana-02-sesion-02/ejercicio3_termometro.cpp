// Ejercicio 3: Termometro
//
// Resuelve este ejercicio por tu cuenta. A diferencia de los ejercicios
// 1 y 2, aqui construyes la clase completa: no hay nada heredado de una
// sesion anterior.
//
// Invariante: gradosCelsius no puede ser menor que -273.15 (el cero
// absoluto). El constructor recibe celsiusInicial: si es menor que
// -273.15, asigna gradosCelsius = 0.0 y avisa por consola; si no,
// asigna gradosCelsius = celsiusInicial. Despues de decidir el valor,
// el constructor tambien imprime "Termometro creado con " seguido del
// valor final y " grados Celsius".
//
// Salida esperada:
// Termometro creado con 25 grados Celsius
// 25 C equivalen a 77 F
// Termometro destruido, ultima lectura: 25 C
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio3_termometro.cpp -o bin/ejercicio3
// Ejecutar:  ./bin/ejercicio3

#include <iostream>

class Termometro {
private:
    double gradosCelsius;

public:
    Termometro(double celsiusInicial) {
        // TODO: si celsiusInicial es menor que -273.15, asigna
        // gradosCelsius = 0.0 y avisa por consola:
        // "Aviso: temperatura invalida, se uso 0 por defecto"
        // Si no, asigna gradosCelsius = celsiusInicial.
        //
        // TODO: despues de decidir el valor, imprime
        // "Termometro creado con " + gradosCelsius + " grados Celsius"
    }

    ~Termometro() {
        // TODO: imprime "Termometro destruido, ultima lectura: "
        // seguido de gradosCelsius y " C".
    }

    double getCelsius() {
        return gradosCelsius;
    }

    double convertirAFahrenheit() {
        // TODO: retorna gradosCelsius convertido a Fahrenheit:
        // celsius * 9 / 5 + 32
        return 0.0;
    }
};

int main() {
    Termometro t(25.0);
    std::cout << t.getCelsius() << " C equivalen a " << t.convertirAFahrenheit() << " F" << std::endl;

    return 0;
}
