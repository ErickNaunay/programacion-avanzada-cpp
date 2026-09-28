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
// Compilar:  g++ -std=c++20 -Wall -Wextra -g laboratorios/semana-02-sesion-01/ejercicio3_rango_notas.cpp -o bin/ejercicio3
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
        if(nuevaMinima<0 or nuevaMaxima>100 or nuevaMinima>nuevaMaxima){
            return false;
        }
        else{
            minima=nuevaMinima;
            maxima=nuevaMaxima;
            return true;
        }
    }

    bool estaEnRango(double nota) {
        if(nota>maxima or nota<minima){
            return false;
        }
        return true;
        // TODO: retorna true si nota esta entre minima y maxima (incluidos).
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
