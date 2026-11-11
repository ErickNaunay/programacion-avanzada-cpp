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
            delete [] lecturas;
            std::cout<<"Memoria liberada"<<std::endl;
        }
};

void registrarDia(int capacidad) {
    RegistroTemperaturas registro(capacidad);
    registro.guardar(0, 18.5);
    std::cout << "Lectura 0: " << registro.obtener(0) << std::endl;
}

int main() {
    registrarDia(5);
    registrarDia(5);
    registrarDia(5);
    return 0;
}
