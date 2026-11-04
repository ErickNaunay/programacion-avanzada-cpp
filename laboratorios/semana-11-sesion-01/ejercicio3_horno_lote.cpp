#include <iostream>

// Salida esperada:
// Ventilacion encendida
// Paso 1: programado a 180, sensor en 175
// Paso 2: programado a 220, sensor en 226
// Paso 3: rechazado, temperatura fuera de rango
// Paso 4: programado a 250, sensor en 249
// Ventilacion apagada
// Lote detenido: sensor fuera de control
// Temperatura programada al final: 200

// El horno de curado del laboratorio de materiales ejecuta un lote de pasos.
// En cada paso se programa una temperatura y despues se compara con la que
// mide el sensor. Hoy el programa no valida nada: corre todos los pasos,
// aunque una temperatura sea imposible o el sensor marque otra cosa.
//
// Las dos reglas que tiene que hacer cumplir:
// - Una temperatura programada fuera de 50 a 300 grados es un dato
//   invalido: ese paso se rechaza y el lote sigue con el siguiente.
// - Si el sensor se aleja mas de 30 grados de la temperatura programada,
//   el horno esta fuera de control: el lote completo se detiene en ese
//   paso y main informa el motivo.
// En los dos casos, la ventilacion tiene que apagarse al terminar el lote,
// termine como termine.
//
// Decide tu que excepcion de <stdexcept> lanza cada regla, donde se lanza,
// y en que funcion se atrapa cada una. No cambies la clase Ventilacion ni
// los datos del lote.

class Ventilacion {
    public:
        Ventilacion() {
            std::cout << "Ventilacion encendida" << std::endl;
        }

        ~Ventilacion() {
            std::cout << "Ventilacion apagada" << std::endl;
        }
};

class Horno {
    private:
        int temperaturaProgramada;
        int ultimaLectura;
    public:
        Horno() {
            temperaturaProgramada = 25;
            ultimaLectura = 25;
        }

        int getTemperaturaProgramada() {
            return temperaturaProgramada;
        }

        void programar(int temperatura) {
            temperaturaProgramada = temperatura;
        }

        void verificarSensor(int lectura) {
            ultimaLectura = lectura;
        }

        void ejecutarLote(int temperaturas[], int lecturas[], int pasos) {
            Ventilacion ventilacion;
            for (int i = 0; i < pasos; i++) {
                programar(temperaturas[i]);
                verificarSensor(lecturas[i]);
                std::cout << "Paso " << i + 1 << ": programado a " << temperaturas[i] << ", sensor en " << lecturas[i] << std::endl;
            }
        }
};

int main() {
    int temperaturas[6] = {180, 220, 350, 250, 200, 150};
    int lecturas[6] = {175, 226, 0, 249, 241, 150};

    Horno horno;
    horno.ejecutarLote(temperaturas, lecturas, 6);

    std::cout << "Temperatura programada al final: " << horno.getTemperaturaProgramada() << std::endl;
    return 0;
}
