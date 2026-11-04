#include <iostream>
#include <stdexcept>
#include <cmath>

// Salida esperada:
// Ventilacion encendida
// Paso 1: programado a 180, sensor en 175
// Paso 2: programado a 220, sensor en 226
// Paso 3: rechazado, temperatura fuera de rango
// Paso 4: programado a 250, sensor en 249
// Ventilacion apagada
// Lote detenido: sensor fuera de control
// Temperatura programada al final: 200

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
            if (temperatura < 50 || temperatura > 300) {
                throw std::invalid_argument("temperatura fuera de rango");
            }
            temperaturaProgramada = temperatura;
        }

        void verificarSensor(int lectura) {
            ultimaLectura = lectura;

            if (std::abs(ultimaLectura - temperaturaProgramada) > 30) {
                throw std::runtime_error("sensor fuera de control");
            }
        }

        void ejecutarLote(int temperaturas[], int lecturas[], int pasos) {
            Ventilacion ventilacion;

            for (int i = 0; i < pasos; i++) {
                try {
                    programar(temperaturas[i]);
                } catch (const std::invalid_argument& e) {
                    std::cout << "Paso " << i + 1 << ": rechazado, " << e.what() << std::endl;
                    continue;
                }

                verificarSensor(lecturas[i]);

                std::cout << "Paso " << i + 1 << ": programado a " << temperaturas[i] << ", sensor en " << lecturas[i] << std::endl;
            }
        }
};

int main() {
    int temperaturas[6] = {180, 220, 350, 250, 200, 150};
    int lecturas[6] = {175, 226, 0, 249, 241, 150};

    Horno horno;

    try {
        horno.ejecutarLote(temperaturas, lecturas, 6);
    } catch (const std::runtime_error& e) {
        std::cout << "Lote detenido: " << e.what() << std::endl;
    }

    std::cout << "Temperatura programada al final: " << horno.getTemperaturaProgramada() << std::endl;
    return 0;
}