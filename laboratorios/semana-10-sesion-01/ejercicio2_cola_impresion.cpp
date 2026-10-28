#include <iostream>
#include <list>

// Salida esperada:
// Fila: 101 102 103
// Fila: 900 101 102 103
// Cancelar 102: cancelado
// Cancelar 555: no estaba en la fila
// Fila: 900 101 103 104
// Imprimiendo: 900
// Imprimiendo: 101
// Fila: 103 104
// Trabajos en la fila: 2

class ColaDeImpresion {
private:
    std::list<int> trabajos;

public:
    void agregar(int id) {
        trabajos.push_back(id);
    }

    void agregarUrgente(int id) {
        trabajos.push_front(id);
    }

    bool cancelar(int id) {
        for (std::list<int>::iterator it = trabajos.begin();
             it != trabajos.end();
             ++it) {

            if (*it == id) {
                trabajos.erase(it);
                return true;
            }
        }

        return false;
    }

    int siguiente() {
        int trabajo = trabajos.front();
        trabajos.pop_front();
        return trabajo;
    }

    int cantidad() {
        return static_cast<int>(trabajos.size());
    }

    void imprimir() {
        std::cout << "Fila:";

        for (int trabajo : trabajos) {
            std::cout << " " << trabajo;
        }

        std::cout << std::endl;
    }
};

void informarCancelacion(int id, bool cancelado) {
    std::cout << "Cancelar " << id << ": ";
    if (cancelado) {
        std::cout << "cancelado" << std::endl;
    } else {
        std::cout << "no estaba en la fila" << std::endl;
    }
}

int main() {
    ColaDeImpresion fila;
    fila.agregar(101);
    fila.agregar(102);
    fila.agregar(103);
    fila.imprimir();

    fila.agregarUrgente(900);
    fila.imprimir();

    informarCancelacion(102, fila.cancelar(102));
    informarCancelacion(555, fila.cancelar(555));

    fila.agregar(104);
    fila.imprimir();

    std::cout << "Imprimiendo: " << fila.siguiente() << std::endl;
    std::cout << "Imprimiendo: " << fila.siguiente() << std::endl;
    fila.imprimir();
    std::cout << "Trabajos en la fila: " << fila.cantidad() << std::endl;

    return 0;
}
