#include <iostream>
using namespace std;
class DispositivoElectronico {
    private:
        int numeroSerie;
        bool encendido;
    public:
        DispositivoElectronico() {
            numeroSerie = 0;
            encendido = false;
        }

        bool setNumeroSerie(int nuevoNumero) {
            if (nuevoNumero <= 0) { return false; }
            numeroSerie = nuevoNumero;
            return true;
        }

        void encender() {
            encendido = true;
        }

        void apagar() {
            encendido = false;
        }

        void describir() {
            std::cout << "Dispositivo #" << numeroSerie << ", encendido: " << (encendido ? "si" : "no") << std::endl;
        }
};



// TODO: RobotAspiradora hereda de una sola clase base (herencia simple,
// sin herencia multiple). Agrega:
// - void aspirar(): imprime "Aspirando el polvo del piso"
// - void moverse(int distanciaCm): imprime "Moviendose <distanciaCm> cm hacia adelante"
class RobotAspiradora : public virtual DispositivoElectronico {
    public:
    void aspirar(){ cout<<"Aspirando el polvo del piso. "; }
    void moverse(int movimiento){ cout<<"Moviendose "<<movimiento<< "cm hacia adelante. "; }
};

int main() {
    RobotAspiradora r;
    r.setNumeroSerie(77);
    r.encender();
    r.describir();
    r.aspirar();
    r.moverse(150);
    return 0;
}
