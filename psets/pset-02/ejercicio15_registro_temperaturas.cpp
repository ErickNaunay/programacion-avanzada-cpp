// Ejercicio 15: RegistroTemperaturas (integrador: RAII + puntero seguro)
//
// Completa el constructor, el destructor y los metodos marcados con TODO.
// Presta atencion especial a buscarValor: debe devolver la direccion de una
// posicion dentro del arreglo que ya administra el objeto, nunca la direccion
// de una variable local de la funcion (eso seria un puntero colgante).
// No cambies las firmas ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio15 ejercicio15_registro_temperaturas.cpp
// Ejecutar: ./ejercicio15
//
// Salida esperada:
// Encontrado: 22
// No encontrado
// --- fin del bloque ---
// Registro de temperaturas liberado
// Registro de temperaturas liberado

#include <iostream>

class RegistroTemperaturas {
private:
    double* lecturas;
    int cantidad;
public:
    RegistroTemperaturas(int n) {
        // TODO: asigna cantidad = n.
        // TODO: reserva con new[] un arreglo de cantidad doubles y guardalo en lecturas.
        // TODO: en un bucle, inicializa cada posicion de lecturas en 0.0.
    }
    ~RegistroTemperaturas() {
        // TODO: libera lecturas con delete[].
        // TODO: imprime "Registro de temperaturas liberado" seguido de un salto de linea.
    }
    bool setLectura(int indice, double valor) {
        // TODO: valida que indice este entre 0 (incluido) y cantidad (excluido).
        return false;
    }
    double* buscarValor(double objetivo) {
        // TODO: recorre lecturas. Si encuentras una posicion igual a objetivo,
        // devuelve la direccion de esa posicion dentro del arreglo (con &).
        // Si no encuentras ninguna, devuelve nullptr.
        return nullptr;
    }
};

int main() {
    {
        RegistroTemperaturas r1(3);
        r1.setLectura(0, 18.5);
        r1.setLectura(1, 22.0);
        r1.setLectura(2, 19.5);

        double* encontrado = r1.buscarValor(22.0);
        if (encontrado != nullptr) {
            std::cout << "Encontrado: " << *encontrado << std::endl;
        } else {
            std::cout << "No encontrado" << std::endl;
        }

        double* noEncontrado = r1.buscarValor(99.0);
        if (noEncontrado != nullptr) {
            std::cout << "Encontrado: " << *noEncontrado << std::endl;
        } else {
            std::cout << "No encontrado" << std::endl;
        }

        RegistroTemperaturas r2(1);
        r2.setLectura(0, 30.0);
        std::cout << "--- fin del bloque ---" << std::endl;
    }
    return 0;
}
