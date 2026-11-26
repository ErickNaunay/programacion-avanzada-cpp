// Ejercicio 8: RegistroDeNotas (std::vector)
//
// Completa los metodos marcados con TODO. No cambies las firmas ni el main().
// Recorre el vector con el for de rango (for (double nota : notas)) donde
// solo necesitas leer cada nota.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio8 ejercicio8_registro_notas_vector.cpp
// Ejecutar: ./ejercicio8
//
// Salida esperada:
// Agregar 25: 0
// Notas registradas: 5
// Promedio: 15.7
// Mejor nota: 19.5
// Notas desde 16: 2
// Ultima nota: 13

#include <iostream>
#include <vector>

class RegistroDeNotas {
private:
    std::vector<double> notas;
public:
    bool agregar(double nota) {
        // TODO: si nota esta entre 0 y 20 (incluidos), la agrega al final con
        // push_back y devuelve true; si no, devuelve false.
        if (nota >= 0.0 && nota <= 20.0) {
            notas.push_back(nota);
            return true;
        }
        return false;
    }
    int cantidad() {
        // TODO: devuelve el tamano del vector.
        return static_cast<int>(notas.size());
    }
    double promedio() {
        // TODO: devuelve la suma de las notas dividida para la cantidad, o 0 si no
        // hay ninguna.
        if (notas.empty()) {
            return 0.0;
        }
        double suma = 0.0;
        for (double nota : notas) {
            suma += nota;
        }
        return suma / notas.size();
    }
    double mejor() {
        // TODO: devuelve la nota mas alta, o 0 si no hay ninguna.
        if (notas.empty()) {
            return 0.0;
        }
        double maxima = notas[0];
        for (double nota : notas) {
            if (nota > maxima) {
                maxima = nota;
            }
        }
        return maxima;
    }
    int cuantasDesde(double minimo) {
        // TODO: cuenta las notas mayores o iguales a minimo.
        int contador = 0;
        for (double nota : notas) {
            if (nota >= minimo) {
                contador++;
            }
        }
        return contador;
    }
    double ultima() {
        // TODO: devuelve la ultima nota agregada (back()), o 0 si no hay ninguna.
        if (notas.empty()) {
            return 0.0;
        }
        return notas.back();
    }
};

int main() {
    RegistroDeNotas registro;
    registro.agregar(15.0);
    registro.agregar(19.5);
    registro.agregar(12.5);
    registro.agregar(18.5);
    std::cout << "Agregar 25: " << registro.agregar(25) << std::endl;
    registro.agregar(13.0);

    std::cout << "Notas registradas: " << registro.cantidad() << std::endl;
    std::cout << "Promedio: " << registro.promedio() << std::endl;
    std::cout << "Mejor nota: " << registro.mejor() << std::endl;
    std::cout << "Notas desde 16: " << registro.cuantasDesde(16) << std::endl;
    std::cout << "Ultima nota: " << registro.ultima() << std::endl;
    return 0;
}