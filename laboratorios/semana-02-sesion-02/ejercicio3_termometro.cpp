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
// Compilar:  g++ -std=c++20 -Wall -Wextra -g laboratorios/semana-02-sesion-02/ejercicio3_termometro.cpp -o bin/ejercicio3
// Ejecutar:  ./bin/ejercicio3

#include <iostream>

class Termometro {
private:
    double gradosCelsius;

public:
    Termometro(double celsiusInicial) {
        if (!setCelsius(celsiusInicial)){
            gradosCelsius=0.0;
            std::cout<<"Aviso: temperatura invalida, se uso 0 por defecto"<<std::endl;
        }
        std::cout<<"Termometro creado con "<<gradosCelsius<<" grados Celsius"<<std::endl;
        
    }

    ~Termometro() {
        std::cout<<"Termometro destruido, ultima lectura:"<<gradosCelsius<<" C"<<std::endl;

    }

    double getCelsius() {
        return gradosCelsius;
    }

    bool setCelsius(double nuevo_gradoCelcius){
        if(nuevo_gradoCelcius < -273.15){
            return false;
        }
        gradosCelsius=nuevo_gradoCelcius;
        return true;
    }

    double convertirAFahrenheit() {
        return gradosCelsius* 9 / 5 + 32;
    }
};

int main() {
    Termometro t(25.0);
    std::cout << t.getCelsius() << " C equivalen a " << t.convertirAFahrenheit() << " F" << std::endl;

    return 0;
}
