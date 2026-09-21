// Ejercicio 14: Buffer (encuentra y corrige la fuga de memoria)
//
// El constructor, setDato y getDato ya estan completos. El destructor esta
// incompleto: hoy no libera la memoria que el constructor reserva, lo que
// produce una fuga de memoria cada vez que se crea y se destruye un Buffer.
// Completa unicamente el destructor. No cambies el resto del archivo ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio14 ejercicio14_buffer.cpp
// Ejecutar: ./ejercicio14
//
// Salida esperada:
// Buffer de 2 creado
// Dato 0: 100
// Dato 1: 200
// Buffer liberado
// Fin del programa

#include <iostream>

class Buffer {
private:
    int* datos;
    int tamano;
public:
    Buffer(int t) {
        tamano = t;
        datos = new int[tamano];
        for (int i = 0; i < tamano; i++) {
            datos[i] = 0;
        }
        std::cout << "Buffer de " << tamano << " creado" << std::endl;
    }
    ~Buffer() {
        // TODO: esta es la fuga. Libera datos con delete[], y despues imprime
        // "Buffer liberado" seguido de un salto de linea.
    }
    bool setDato(int indice, int valor) {
        if (indice >= 0 && indice < tamano) {
            datos[indice] = valor;
            return true;
        }
        return false;
    }
    int getDato(int indice) {
        return datos[indice];
    }
};

int main() {
    {
        Buffer b1(2);
        b1.setDato(0, 100);
        b1.setDato(1, 200);
        std::cout << "Dato 0: " << b1.getDato(0) << std::endl;
        std::cout << "Dato 1: " << b1.getDato(1) << std::endl;
    }
    std::cout << "Fin del programa" << std::endl;
    return 0;
}
