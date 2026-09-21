#include <iostream>
#include <utility>

class RegistroDeVuelo {
    private:
        double* alturas;
        int capacidad;
    public:
        RegistroDeVuelo(int nuevaCapacidad) {
            capacidad = nuevaCapacidad;
            alturas = new double[capacidad];
            std::cout << "Registro de vuelo creado para " << capacidad << " lecturas" << std::endl;
        }

        // TODO: constructor de movimiento. Recibe RegistroDeVuelo&& otro,
        // roba su puntero "alturas" y su "capacidad" (sin reservar memoria
        // nueva ni copiar ningun elemento), y deja "otro" en un estado
        // vacio y seguro (alturas = nullptr, capacidad = 0).

        // TODO: operador de asignacion de movimiento. Misma idea que el
        // constructor de movimiento, pero primero libera con delete[] la
        // memoria que este objeto ya tenia, antes de robar la de "otro".
        // Recuerda comprobar "this != &otro" antes de liberar.

        void guardarAltura(int indice, double valor) {
            alturas[indice] = valor;
        }

        double getAltura(int indice) {
            if (alturas == nullptr) {
                std::cout << "Registro vacio (fue movido)" << std::endl;
                return 0.0;
            }
            return alturas[indice];
        }

        ~RegistroDeVuelo() {
            std::cout << "Destruyendo registro (capacidad " << capacidad << ")" << std::endl;
            delete[] alturas;
        }
};

int main() {
    RegistroDeVuelo registro1(5);
    registro1.guardarAltura(0, 120.0);

    RegistroDeVuelo registro2 = std::move(registro1);
    registro2.guardarAltura(0, 999.0);

    std::cout << "registro1.getAltura(0) = " << registro1.getAltura(0) << std::endl;
    std::cout << "registro2.getAltura(0) = " << registro2.getAltura(0) << std::endl;

    RegistroDeVuelo registro3(3);
    registro3 = std::move(registro2);
    std::cout << "registro3.getAltura(0) = " << registro3.getAltura(0) << std::endl;

    return 0;
}
