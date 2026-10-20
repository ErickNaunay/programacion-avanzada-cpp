#include <iostream>

class RegistroTemperaturas {
    private:
        double* lecturas;
        int capacidad;
    public:
        RegistroTemperaturas(int nuevaCapacidad) {
            capacidad = nuevaCapacidad;
            lecturas = new double[capacidad];
            std::cout << "Memoria reservada para " << capacidad << " lecturas" << std::endl;
        }

        void guardar(int indice, double valor) {
            lecturas[indice] = valor;
        }

        double obtener(int indice) {
            return lecturas[indice];
        }
        ~RegistroTemperaturas(){
            delete[] lecturas;
            std::cout<<"Memoria liberada"<<std::endl;
        }
};

void registrarDia(int capacidad) {
    RegistroTemperaturas registro(capacidad);
    registro.guardar(0, 18.5);
    std::cout << "Lectura 0: " << registro.obtener(0) << std::endl;
    // "registro" deja de existir aqui, al cerrar este bloque.
}

int main() {
    // TODO: antes de correr, predice: ¿cuantas veces esperas ver
    // "Memoria liberada" en la salida, si registramos 3 dias seguidos?
    //Memoraia liberada 3 veces
    registrarDia(5);
    registrarDia(5);
    registrarDia(5);
    return 0;
}
