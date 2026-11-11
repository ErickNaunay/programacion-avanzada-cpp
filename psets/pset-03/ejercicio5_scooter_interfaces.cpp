// Ejercicio 5: Cargable, Localizable y Scooter (dos interfaces)
//
// Completa los metodos marcados con TODO. No cambies las firmas ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio5 ejercicio5_scooter_interfaces.cpp
// Ejecutar: ./ejercicio5
//
// Salida esperada:
// Bateria inicial: 35
// Bateria despues de cargar: 100
// Zona inicial: 2
// Zona despues de moverse: 5
// Zona invalida rechazada: 5

#include <iostream>

class Cargable {
public:
    virtual ~Cargable() {}
    virtual int nivelBateria() = 0;
    virtual void cargar(int porcentaje) = 0;
};

class Localizable {
public:
    virtual ~Localizable() {}
    virtual int zona() = 0;
    virtual void moverA(int nuevaZona) = 0;
};

class Scooter : public Cargable, public Localizable {
private:
    int bateria;
    int zonaActual;
public:
    Scooter(int b, int z) {
        bateria = b;
        zonaActual = z;
    }
    int nivelBateria() override {
        // TODO: devuelve bateria.
        return bateria;
    }
    void cargar(int porcentaje) override {
        // TODO: suma porcentaje a bateria, sin pasar de 100. Si porcentaje es
        // negativo, no hace nada.
        if (porcentaje <= 0) {
            return;
        }
        bateria += porcentaje;
        if (bateria > 100) {
            bateria = 100;
        }
    }
    int zona() override {
        // TODO: devuelve zonaActual.
        return zonaActual;
    }
    void moverA(int nuevaZona) override {
        // TODO: las zonas validas van de 1 a 9. Si nuevaZona es valida, la asigna;
        // si no, no cambia nada.
        if (nuevaZona >= 1 && nuevaZona <= 9) {
            zonaActual = nuevaZona;
        }
    }
};

void cargarCompleto(Cargable* dispositivo) {
    // TODO: carga el dispositivo con lo que le falta para llegar a 100.
    int faltante = 100 - dispositivo->nivelBateria();
    if (faltante > 0) {
        dispositivo->cargar(faltante);
    }
}

int main() {
    Scooter scooter(35, 2);
    Cargable* cargable = &scooter;
    Localizable* localizable = &scooter;

    std::cout << "Bateria inicial: " << cargable->nivelBateria() << std::endl;
    cargarCompleto(cargable);
    std::cout << "Bateria despues de cargar: " << cargable->nivelBateria() << std::endl;

    std::cout << "Zona inicial: " << localizable->zona() << std::endl;
    localizable->moverA(5);
    std::cout << "Zona despues de moverse: " << localizable->zona() << std::endl;
    localizable->moverA(12);
    std::cout << "Zona invalida rechazada: " << localizable->zona() << std::endl;
    return 0;
}