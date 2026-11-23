// Ejercicio 19: Envio, EnvioNacional y EnvioInternacional (desde cero, clase abstracta)
//
// Este archivo no tiene codigo de partida. Escribe tus propios includes, tus
// propias clases y tu propio main().
//
// Disena tres clases:
//
// Envio: clase abstracta, que no se puede instanciar. Destructor virtual
// con cuerpo vacio y una funcion virtual pura double costo().
//
// EnvioNacional: hereda publicamente de Envio. Atributo privado pesoKg
// (double), asignado en el constructor; si el peso recibido es negativo,
// guarda 0. costo() con override: 2 mas 1.5 por kilo.
//
// EnvioInternacional: igual que EnvioNacional, pero costo() devuelve 10
// mas 4 por kilo.
//
// Dos funciones libres:
// - void imprimirCosto(Envio* envio): imprime "Costo: " y el costo.
// - Envio* masBarato(Envio* a, Envio* b): el de menor costo; si cuestan lo
//   mismo, a.
//
// En main(): crea un EnvioNacional de 3 kg, un EnvioInternacional de 0.5 kg
// y un EnvioNacional de -4 kg. Imprime el costo de los tres en ese orden
// con imprimirCosto. Despues imprime el costo del mas barato entre el
// nacional de 3 kg y el internacional, con el texto de la salida esperada.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio19 ejercicio19_envios_abstractos.cpp
// Ejecutar: ./ejercicio19
//
// Salida esperada:
// Costo: 6.5
// Costo: 12
// Costo: 2
// El mas barato cuesta 6.5

#include <iostream>
#include <map>
#include <optional>
#include <set>
#include <memory>

class envio {
public:
    virtual ~envio() {}
    virtual double costo() = 0;
};  

class envioNacional : public envio {
private:
    double pesoKg;
public:
    envioNacional(double peso) {    
        pesoKg = (peso < 0) ? 0 : peso;
    }
    double costo() override {
        return 2 + (pesoKg * 1.5);
    }
};

class envioInternacional : public envio {
private:
    double pesoKg;
public:
    envioInternacional(double peso) {
        pesoKg = (peso < 0) ? 0 : peso;
    }
    double costo() override {
        return 10 + (pesoKg * 4);
    }
};

void imprimirCosto(envio* envio) {
    std::cout << "Costo: " << envio->costo() << std::endl;
}

void masBarato(envio* a, envio* b) {
    if (a->costo() <= b->costo()) {
        std::cout << "El mas barato cuesta " << a->costo() << std::endl;
    } else {
        std::cout << "El mas barato cuesta " << b->costo() << std::endl;
    }
}

int main() {
    envioNacional nacional1(3);
    envioInternacional internacional(0.5);
    envioNacional nacional2(-4);

    imprimirCosto(&nacional1);
    imprimirCosto(&internacional);
    imprimirCosto(&nacional2);

    masBarato(&nacional1, &internacional);

    return 0;
}