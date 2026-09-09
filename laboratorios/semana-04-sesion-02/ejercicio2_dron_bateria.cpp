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

// TODO: Dron no tiene ninguna relacion "es un" con Bateria. Agrega un
// atributo privado "Bateria bateria;" y escribe:
// bool despegar(): si la bateria no esta cargada, imprime
//   "Bateria muy baja, no despega" y devuelve false; si esta cargada,
//   imprime "Dron despegando con <nivel>% de bateria" y devuelve true.
// void descargar(int porcentaje): reduce el nivel de carga de la bateria
//   en ese porcentaje.
class Dron {
    private:
        Bateria bateria;

    public: 
        bool despegar() {

            if (!bateria.estaCargada()) {
                std::cout << "Bateria muy baja, no despega" << std::endl;

                return false;
            }
            std::cout << "Dron despegando con " << bateria.getNivelCargaPorc() << "% de bateria" << std::endl;

            return true;
        }

        void descargar(int porcentaje) {
            bateria.setNivelCargaPorc(bateria.getNivelCargaPorc() - porcentaje);
        }
};

int main() {
    Dron d;
    d.despegar();
    d.descargar(90);
    d.despegar();
    return 0;
}
