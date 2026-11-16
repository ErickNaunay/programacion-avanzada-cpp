// Ejercicio 10: TurnosDeLaboratorio (std::list y std::set)
//
// Completa los metodos marcados con TODO. No cambies las firmas ni el main().
// La cola de turnos es una std::list (se atiende por delante y los urgentes
// entran por delante); el set guarda quienes ya estan en la cola, para
// responder rapido si alguien ya pidio turno.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio10 ejercicio10_turnos_list_set.cpp
// Ejecutar: ./ejercicio10
//
// Salida esperada:
// Pedir 3021 otra vez: 0
// En cola: 4
// Atendido: 4410
// Atendido: 3021
// Retirar 5100: 1
// Retirar 7777: 0
// En cola: 1
// Atendido: 1888
// Atendido: -1

#include <iostream>
#include <list>
#include <set>

class TurnosDeLaboratorio {
private:
    std::list<int> cola;
    std::set<int> enCola;
public:
    bool pedirTurno(int carnet) {
        // TODO: si el carnet ya esta en enCola, devuelve false. Si no, lo agrega
        // al final de la cola y a enCola, y devuelve true.
        return false;
    }
    bool pedirTurnoUrgente(int carnet) {
        // TODO: igual que pedirTurno, pero lo agrega al principio de la cola.
        return false;
    }
    int atender() {
        // TODO: si la cola esta vacia, devuelve -1. Si no, saca el primero (front
        // y pop_front), lo borra de enCola y lo devuelve.
        return -1;
    }
    bool retirar(int carnet) {
        // TODO: recorre la cola con un iterador; si encuentra el carnet, lo borra
        // con erase(it), lo borra de enCola y devuelve true (sin seguir
        // usando ese iterador). Si no esta, devuelve false.
        return false;
    }
    int enEspera() {
        return cola.size();
    }
};

int main() {
    TurnosDeLaboratorio turnos;
    turnos.pedirTurno(3021);
    turnos.pedirTurno(5100);
    std::cout << "Pedir 3021 otra vez: " << turnos.pedirTurno(3021) << std::endl;
    turnos.pedirTurno(1888);
    turnos.pedirTurnoUrgente(4410);
    std::cout << "En cola: " << turnos.enEspera() << std::endl;

    std::cout << "Atendido: " << turnos.atender() << std::endl;
    std::cout << "Atendido: " << turnos.atender() << std::endl;
    std::cout << "Retirar 5100: " << turnos.retirar(5100) << std::endl;
    std::cout << "Retirar 7777: " << turnos.retirar(7777) << std::endl;
    std::cout << "En cola: " << turnos.enEspera() << std::endl;
    std::cout << "Atendido: " << turnos.atender() << std::endl;
    std::cout << "Atendido: " << turnos.atender() << std::endl;
    return 0;
}
