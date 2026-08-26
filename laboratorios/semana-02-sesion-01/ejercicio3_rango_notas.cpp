// Ejercicio 3: RangoNotas
//
// Resuelve este ejercicio por tu cuenta. Usa el mismo patron de los
// ejercicios 1 y 2: atributos privados, y metodos publicos que
// verifican un invariante antes de modificar el estado.
//
// A diferencia de los ejercicios anteriores, aqui el invariante junta
// dos atributos a la vez: minima <= maxima, y ambos entre 0 y 100. Los
// dos se validan y se asignan juntos, en un solo metodo, no por separado.
//
// Salida esperada:
// setRango(60, 40) rechazado: true
// setRango(60, 90) aceptado: true
// Rango: [60, 90]
// 75 esta en rango: true
// 50 esta en rango: false
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio3_rango_notas.cpp -o bin/ejercicio3
// Ejecutar:  ./bin/ejercicio3

#include <iostream>

class RangoNotas {
private:
    double minima;
    double maxima;

public:
    double getMinima() { return minima; }
    double getMaxima() { return maxima; }

    bool setRango(double nuevaMinima, double nuevaMaxima) {
        // TODO: si nuevaMinima es menor que 0, o nuevaMaxima es mayor que
        // 100, o nuevaMinima es mayor que nuevaMaxima, devuelve false sin
        // modificar minima ni maxima. Si las tres condiciones son
        // validas, asigna minima y maxima, y devuelve true.
        return false;
    }

    bool estaEnRango(double nota) {
        // TODO: retorna true si nota esta entre minima y maxima (incluidos).
        return false;
    }
};

int main() {
    RangoNotas rango;

    bool ok1 = rango.setRango(60.0, 40.0);
    std::cout << "setRango(60, 40) rechazado: " << (!ok1 ? "true" : "false") << std::endl;

    bool ok2 = rango.setRango(60.0, 90.0);
    std::cout << "setRango(60, 90) aceptado: " << (ok2 ? "true" : "false") << std::endl;
    std::cout << "Rango: [" << rango.getMinima() << ", " << rango.getMaxima() << "]" << std::endl;

    std::cout << "75 esta en rango: " << (rango.estaEnRango(75.0) ? "true" : "false") << std::endl;
    std::cout << "50 esta en rango: " << (rango.estaEnRango(50.0) ? "true" : "false") << std::endl;

    return 0;
}
