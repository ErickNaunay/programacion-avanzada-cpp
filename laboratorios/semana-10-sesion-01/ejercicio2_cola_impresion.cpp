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

// La fila de la impresora del laboratorio. Cada trabajo se identifica
// con un numero. Un trabajo normal va al final; uno urgente, al frente.
// Cualquier trabajo puede cancelarse, este donde este en la fila.
class ColaDeImpresion {
    private:
        std::list<int> trabajos;
    public:
        void agregar(int id) {
            // TODO: agrega el trabajo al final de la fila.
            trabajos.push_back(id);
        }

        void agregarUrgente(int id) {
            // TODO: agrega el trabajo al frente de la fila.
            trabajos.push_front(id);
        }

        bool cancelar(int id) {
            // TODO: recorre la fila con un iterador. Si encuentras el
            // trabajo, borralo con trabajos.erase(...) y devuelve true.
            // Si no esta, devuelve false.
            for (auto it = trabajos.begin(); it != trabajos.end(); ++it) {
                if (*it == id) {
                    trabajos.erase(it);
                    return true;
                }
            }
            return false;
        }

        int siguiente() {
            // TODO: devuelve el trabajo del frente y quitalo de la fila.
            int id = trabajos.front();
            trabajos.pop_front();
            return id;
        }

        int cantidad() {
            // TODO: cuantos trabajos quedan en la fila.
            return trabajos.size();
        }

        void imprimir() {
            // TODO: imprime "Fila:" y cada trabajo precedido de un
            // espacio, con un for de rango, y termina la linea.
            std::cout << "Fila:";
            for (int id : trabajos) {
                std::cout << " " << id;
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