#include <iostream>
#include <memory>
#include <utility>

// Salida esperada:
// Medidores conectados: 3
// Temperatura: 21.5 C
// Presion: 1013.2 hPa
// Viento: 12.4 km/h
// Agregar un cuarto medidor: rechazado

class IMedidor {
public:
    virtual double leerValor() = 0;
    virtual void imprimirMagnitud() = 0;
    virtual void imprimirUnidad() = 0;

    virtual ~IMedidor() {
    }
};

class Termometro : public IMedidor {
private:
    double valor;

public:
    Termometro(double nuevoValor) {
        valor = nuevoValor;
    }

    double leerValor() override {
        return valor;
    }

    void imprimirMagnitud() override {
        std::cout << "Temperatura";
    }

    void imprimirUnidad() override {
        std::cout << "C";
    }
};

class Barometro : public IMedidor {
private:
    double valor;

public:
    Barometro(double nuevoValor) {
        valor = nuevoValor;
    }

    double leerValor() override {
        return valor;
    }

    void imprimirMagnitud() override {
        std::cout << "Presion";
    }

    void imprimirUnidad() override {
        std::cout << "hPa";
    }
};

class Anemometro : public IMedidor {
private:
    double valor;

public:
    Anemometro(double nuevoValor) {
        valor = nuevoValor;
    }

    double leerValor() override {
        return valor;
    }

    void imprimirMagnitud() override {
        std::cout << "Viento";
    }

    void imprimirUnidad() override {
        std::cout << "km/h";
    }
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

    bool agregar(std::unique_ptr<IMedidor> nuevo) {
        if (cantidad >= capacidad) {
            return false;
        }

        medidores[cantidad] = std::move(nuevo);
        cantidad++;

        return true;
    }

    int getCantidad() {
        return cantidad;
    }

    void reportar() {
        for (int i = 0; i < cantidad; i++) {
            medidores[i]->imprimirMagnitud();
            std::cout << ": "
                      << medidores[i]->leerValor()
                      << " ";
            medidores[i]->imprimirUnidad();
            std::cout << std::endl;
        }
    }
};

int main() {
    EstacionMeteorologica estacion;

    estacion.agregar(std::make_unique<Termometro>(21.5));
    estacion.agregar(std::make_unique<Barometro>(1013.2));

    std::unique_ptr<IMedidor> viento =
        std::make_unique<Anemometro>(12.4);

    estacion.agregar(std::move(viento));

    std::cout << "Medidores conectados: "
              << estacion.getCantidad()
              << std::endl;

    estacion.reportar();

    bool aceptado =
        estacion.agregar(std::make_unique<Termometro>(30.0));

    std::cout << "Agregar un cuarto medidor: ";

    if (aceptado) {
        std::cout << "aceptado" << std::endl;
    } else {
        std::cout << "rechazado" << std::endl;
    }

    return 0;
}