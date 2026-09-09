#include <iostream>

class Bateria {
    private:
        int nivelCargaPorc;
    public:
        Bateria() {
            nivelCargaPorc = 100;
        }

        bool setNivelCargaPorc(int nuevoNivel) {
            if (nuevoNivel < 0 || nuevoNivel > 100) { return false; }
            nivelCargaPorc = nuevoNivel;
            return true;
        }

        int getNivelCargaPorc() {
            return nivelCargaPorc;
        }

        bool estaCargada() {
            return nivelCargaPorc > 20;
        }
};
class Dron {
    private:
        Bateria bateria;
    
    public:
        bool despegar(){
            if (!bateria.estaCargada()) {
                std::cout << "Bateria muy baja, no despega" << std::endl;
                    return false;

        }

        std::cout << "Dron despegando con " << bateria.getNivelCargaPorc() << "% de bateria" << std::endl;
        
        return true;

    }

    void descargar(int porcentaje){

        int nuevoNivel = bateria.getNivelCargaPorc() - porcentaje;
        bateria.setNivelCargaPorc(nuevoNivel);
    }
};

int main() {
    Dron d;
    d.despegar();
    d.descargar(90);
    d.despegar();
    return 0;
}
