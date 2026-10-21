// Ejercicio 23: Llave y Cerradura (desde cero, unique_ptr y std::move)
//
// Este archivo no tiene codigo de partida. Escribe tu de tu propia clase,
// tus propios includes (necesitas <memory> ademas de <iostream>) y tu
// propio main().
//
// Disena dos clases:
//
// Llave: atributo privado numeroSerie (int). Constructor Llave() sin
// parametros que asigna numeroSerie = 0. Metodo void
// setNumeroSerie(int n) sin validacion (asignacion directa). Getter int
// getNumeroSerie().
//
// Cerradura: atributo privado llaveAsignada, de tipo
// std::unique_ptr<Llave>. Metodo bool asignarLlave(std::unique_ptr<Llave>
// nuevaLlave) que recibe la llave por valor (un unique_ptr no se puede
// copiar, solo mover, asi que quien llame a este metodo va a tener que
// usar std::move). Si llaveAsignada ya tiene una llave asignada (no es
// nullptr), el metodo no hace nada y devuelve false. Si esta vacia, mueve
// nuevaLlave hacia llaveAsignada (con std::move) y devuelve true. Metodo
// bool tieneLlave() que devuelve true si llaveAsignada no es nullptr.
//
// En main(): crea dos unique_ptr<Llave> con std::make_unique, llamalos
// llave1 y llave2. Asignales numeroSerie 101 y 202 respectivamente (con
// ->). Crea una Cerradura. Imprime tieneLlave() antes de asignar nada,
// precedido por "Tiene llave antes: ". Llama a asignarLlave moviendo
// llave1 (con std::move) e imprime el resultado, precedido por "Asignar
// llave1: ". Llama a asignarLlave moviendo llave2 e imprime el resultado,
// precedido por "Asignar llave2: " (debe fallar, porque la cerradura ya
// tiene una llave). Imprime tieneLlave() de nuevo, precedido por "Tiene
// llave despues: ". Usa std::boolalpha antes de imprimir cada resultado
// booleano.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio23 ejercicio23_llave_cerradura.cpp
// Ejecutar: ./ejercicio23
//
// Salida esperada:
// Tiene llave antes: false
// Asignar llave1: true
// Asignar llave2: false
// Tiene llave despues: true

#include <iostream>
#include <memory>

class Llave {
private:
    int numeroSerie;
public:
    Llave() : numeroSerie(0) {}
    void setNumeroSerie(int n) {
        numeroSerie = n;
    }
    int getNumeroSerie() const {
        return numeroSerie;
    }
};

class Cerradura {
private:
    std::unique_ptr<Llave> llaveAsignada;
public:
    Cerradura() : llaveAsignada(nullptr) {}
    bool asignarLlave(std::unique_ptr<Llave> nuevaLlave) {
        if (!llaveAsignada) {
            llaveAsignada = std::move(nuevaLlave);
            return true;
        }
        return false;
    }
    bool tieneLlave() const {
        return !!llaveAsignada;
    }
};

int main() {
    auto llave1 = std::make_unique<Llave>();
    llave1->setNumeroSerie(101);
    auto llave2 = std::make_unique<Llave>();
    llave2->setNumeroSerie(202);
    Cerradura cerradura;
    std::cout << std::boolalpha;
    std::cout << "Tiene llave antes: " << cerradura.tieneLlave() << std::endl;
    std::cout << "Asignar llave1: " << cerradura.asignarLlave(std::move(llave1)) << std::endl;
    std::cout << "Asignar llave2: " << cerradura.asignarLlave(std::move(llave2)) << std::endl;
    std::cout << "Tiene llave despues: " << cerradura.tieneLlave() << std::endl;
    return 0;
}