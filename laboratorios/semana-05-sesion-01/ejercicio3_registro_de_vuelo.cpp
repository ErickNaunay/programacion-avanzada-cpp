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
