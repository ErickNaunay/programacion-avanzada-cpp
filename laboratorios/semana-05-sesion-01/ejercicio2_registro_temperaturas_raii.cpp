#include <iostream>
using namespace std;
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
        ~ RegistroTemperaturas(){
            //libera leturas 
            delete[] lecturas;
            cout<<"Memoria liberada "<<endl;
        }
        // TODO: agrega el destructor. Debe liberar "lecturas" con delete[]
        // e imprimir "Memoria liberada", para atar la vida de ese recurso
        // a la vida del objeto (RAII).
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
