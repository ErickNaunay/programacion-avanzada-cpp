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

class Cartucho {

private: 
int nivelTintaporc;

public:
        Cartucho(){
            nivelTintaporc = 100;
        }

        bool tieneTinta(){
            return nivelTintaporc > 0;

        }
        
        void consumir(int porcentaje){
            nivelTintaporc = nivelTintaporc - porcentaje;

            if (nivelTintaporc < 0){
                nivelTintaporc = 0;
            }
        }

        int getNivelTintaPorc() {
            return nivelTintaporc;
        }

};

class Impresora: public virtual Dispositivo {
    private:
        int paginasPorMinuto;
        Cartucho cartucho;
    public:
        Impresora() {
            paginasPorMinuto = 0;
        }

        bool setPaginasPorMinuto(int nuevasPpm) {
            if (nuevasPpm <= 0) { return false; }
            paginasPorMinuto = nuevasPpm;
            return true;
        }

        bool imprimir(int paginas){
            if(!cartucho.tieneTinta()){
                std::cout << "Sin tinta, no se puede imprimir" << std::endl;
                return false;
            }
                std::cout << "Imprimiendo " << paginas << " paginas a " << paginasPorMinuto << " paginas por minuto" << std::endl;
                
                    cartucho.consumir(paginas * 2);
                return true;
        }

        int getNivelTintaPorc() {
            return cartucho.getNivelTintaPorc();
    }

};

int main() {
    Impresora i;
    i.setNumeroSerie(500);
    i.encender();
    i.setPaginasPorMinuto(20);
    i.imprimir(10);
    std::cout << "Tinta restante: " << i.getNivelTintaPorc() << "%" << std::endl;
    i.imprimir(45);
    std::cout << "Tinta restante: " << i.getNivelTintaPorc() << "%" << std::endl;
    i.imprimir(10);
    return 0;
}
