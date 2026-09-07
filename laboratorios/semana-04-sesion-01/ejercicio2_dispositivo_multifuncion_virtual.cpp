#include <iostream>

class Dispositivo {
    private:
        int numeroSerie;
        bool encendido;
    public:
        Dispositivo() {
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

        void describir() {
            std::cout << "Dispositivo #" << numeroSerie << ", encendido: " << (encendido ? "si" : "no") << std::endl;
        }
};

// TODO: agrega "virtual" a la herencia de Impresora y de Escaner, para que
// las dos compartan una sola copia de Dispositivo.
class Impresora: public virtual Dispositivo {
    private:
        int paginasPorMinuto;
    public:
        Impresora() {
            paginasPorMinuto = 0;
        }

        bool setPaginasPorMinuto(int nuevasPpm) {
            if (nuevasPpm <= 0) { return false; }
            paginasPorMinuto = nuevasPpm;
            return true;
        }

        void imprimir() {
            std::cout << "Imprimiendo a " << paginasPorMinuto << " paginas por minuto" << std::endl;
        }
};

// TODO: lo mismo aqui.
class Escaner: public virtual Dispositivo {
    private:
        int resolucionDPI;
    public:
        Escaner() {
            resolucionDPI = 0;
        }

        bool setResolucionDPI(int nuevaResolucion) {
            if (nuevaResolucion <= 0) { return false; }
            resolucionDPI = nuevaResolucion;
            return true;
        }

        void escanear() {
            std::cout << "Escaneando a " << resolucionDPI << " DPI" << std::endl;
        }
};

class ImpresoraMultifuncion: public Impresora, public Escaner {
};

int main() {
    ImpresoraMultifuncion mfp;

    mfp.setPaginasPorMinuto(20);
    mfp.imprimir();

    mfp.setResolucionDPI(600);
    mfp.escanear();

    mfp.setNumeroSerie(1234);
    mfp.describir();

    return 0;
}