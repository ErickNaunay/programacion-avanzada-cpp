// Ejercicio 2: SerVivo, Animal y Perro (herencia multinivel)
//
// Completa los metodos marcados con TODO. No cambies las firmas ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio2 ejercicio2_servivo_animal_perro.cpp
// Ejecutar: ./ejercicio2
//
// Salida esperada:
// Guau guau
// Edad: 3
// Patas: 4
// Rescatado: true

#include <iostream>

class SerVivo {
private:
    int edadAnios;
public:
    bool setEdadAnios(int e) {
        if (e < 0 || e > 100) {
            return false;
            }

            edadAnios = e;
        return true;
    }

    int getEdadAnios() {
        return edadAnios;
    }
};


class Animal : public SerVivo {
private:
    int numeroPatas;
public:
     bool setNumeroPatas(int p) {
        if (p < 0 || p > 8) {
            return false;
        }

        numeroPatas = p;
        return true;
    }

    int getNumeroPatas() {
        return numeroPatas;
    }
};

class Perro : public Animal {
private:
    bool esRescatado;
public:
    void setEsRescatado(bool r) {
        esRescatado = r;
    }

    bool getEsRescatado() {
        return esRescatado;
    }

    void ladrar() {
        std::cout << "Guau guau" << std::endl;
    }
};

int main() {
    Perro perro1;
    perro1.setEdadAnios(3);
    perro1.setNumeroPatas(4);
    perro1.setEsRescatado(true);
    perro1.ladrar();
    std::cout << "Edad: " << perro1.getEdadAnios() << std::endl;
    std::cout << "Patas: " << perro1.getNumeroPatas() << std::endl;
    std::cout << "Rescatado: " << std::boolalpha << perro1.getEsRescatado() << std::endl;
    return 0;
}
