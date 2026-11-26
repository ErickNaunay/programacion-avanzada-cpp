#include <iostream>

// TODO: define aqui la clase RegistroDeVuelo, con:
// - un puntero privado double* alturas y un int capacidad.
// - un constructor RegistroDeVuelo(int nuevaCapacidad) que reserve
//   memoria dinamica con new[] para "capacidad" valores double, e
//   imprima "Registro de vuelo creado para <capacidad> lecturas".
// - void guardarAltura(int indice, double valor).
// - double getAltura(int indice).
// - un destructor ~RegistroDeVuelo() que libere la memoria con delete[]
//   e imprima "Registro de vuelo destruido, memoria liberada", para atar
//   la vida de esa memoria a la vida del objeto (RAII).
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
            delete[] alturas;
            std::cout << "Registro de vuelo destruido, memoria liberada" << std::endl;
        }
};

bool procesarVuelo(int capacidad, double alturaMinima) {
    RegistroDeVuelo registro(capacidad);
    registro.guardarAltura(0, 120.0);
    registro.guardarAltura(1, 95.0);

    if (registro.getAltura(1) < alturaMinima) {
        std::cout << "Vuelo rechazado: altura " << registro.getAltura(1) << " bajo el minimo" << std::endl;
        return false;
    }

    std::cout << "Vuelo aceptado" << std::endl;
    return true;
}

int main() {
    procesarVuelo(5, 100.0);
    std::cout << "---" << std::endl;
    procesarVuelo(5, 50.0);
    return 0;
}
