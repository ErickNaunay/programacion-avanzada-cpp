#include <iostream>
#include <memory>
#include <utility>

// Salida esperada:
// Medidores conectados: 3
// Temperatura: 21.5 C
// Presion: 1013.2 hPa
// Viento: 12.4 km/h
// Agregar un cuarto medidor: rechazado

// TODO: disena la interfaz IMedidor. Toda estacion necesita, de cualquier
// medidor, tres cosas: leer su valor actual (double), imprimir el nombre
// de la magnitud que mide ("Temperatura", "Presion", "Viento") e imprimir
// su unidad ("C", "hPa", "km/h"). Sigue la convencion de interfaz de la
// sesion: sin atributos.
class IMedidor {
};

// TODO: Termometro, Barometro y Anemometro implementan IMedidor. Cada uno
// recibe su valor actual en el constructor y lo devuelve en la lectura.
// Marca con override cada metodo que implementa la interfaz.
class Termometro {
};

class Barometro {
};

class Anemometro {
};

class EstacionMeteorologica {
    private:
        std::unique_ptr<IMedidor> medidores[3];
        int cantidad;
        int capacidad;
    public:
        EstacionMeteorologica() {
            cantidad = 0;
            capacidad = 3;
        }

        // TODO: guarda "nuevo" en la siguiente posicion libre del arreglo
        // y devuelve true. Si la estacion ya esta llena, devuelve false
        // sin guardar nada. Un unique_ptr no se copia.
        bool agregar(std::unique_ptr<IMedidor> nuevo) {
            return false;
        }

        int getCantidad() {
            return cantidad;
        }

        // TODO: por cada medidor conectado, imprime una linea con el
        // formato "<magnitud>: <valor> <unidad>". Esta clase no puede
        // mencionar Termometro, Barometro ni Anemometro en ningun lugar.
        void reportar() {
        }
};

int main() {
    EstacionMeteorologica estacion;
    estacion.agregar(std::make_unique<Termometro>(21.5));
    estacion.agregar(std::make_unique<Barometro>(1013.2));

    std::unique_ptr<IMedidor> viento = std::make_unique<Anemometro>(12.4);
    estacion.agregar(std::move(viento));

    std::cout << "Medidores conectados: " << estacion.getCantidad() << std::endl;
    estacion.reportar();

    bool aceptado = estacion.agregar(std::make_unique<Termometro>(30.0));
    std::cout << "Agregar un cuarto medidor: ";
    if (aceptado) {
        std::cout << "aceptado" << std::endl;
    } else {
        std::cout << "rechazado" << std::endl;
    }

    return 0;
}
