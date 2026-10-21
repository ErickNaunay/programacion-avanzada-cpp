#include <iostream>

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

        void guardarAltura(int indice, double valor) {
            alturas[indice] = valor;
        }

        double getAltura(int indice) {
            return alturas[indice];
        }

        ~RegistroDeVuelo() {
            std::cout << "Destruyendo registro (capacidad " << capacidad << ")" << std::endl;
            delete[] alturas;
        }

        // Sin constructor de copia propio: el compilador genera uno por
        // defecto que copia "alturas" y "capacidad" tal cual estan, sin
        // reservar un arreglo nuevo. Eso es lo que hoy vamos a revisar.

        
};

int main() {
    RegistroDeVuelo registro1(5);
    registro1.guardarAltura(0, 120.0);

    RegistroDeVuelo registro2 = registro1;
    registro2.guardarAltura(0, 999.0);

    std::cout << "registro1.getAltura(0) = " << registro1.getAltura(0) << std::endl;
    std::cout << "registro2.getAltura(0) = " << registro2.getAltura(0) << std::endl;

    return 0;
}
