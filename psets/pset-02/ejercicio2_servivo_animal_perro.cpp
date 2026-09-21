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
        // TODO: valida que e este entre 0 y 100 (ambos incluidos).
        return false;
    }
    int getEdadAnios() {
        // TODO: devuelve edadAnios.
        return 0;
    }
};

class Animal : public SerVivo {
private:
    int numeroPatas;
public:
    bool setNumeroPatas(int p) {
        // TODO: valida que p este entre 0 y 8 (ambos incluidos).
        return false;
    }
    int getNumeroPatas() {
        // TODO: devuelve numeroPatas.
        return 0;
    }
};

class Perro : public Animal {
private:
    bool esRescatado;
public:
    void setEsRescatado(bool r) {
        // TODO: asigna esRescatado. No hay invariante que validar.
    }
    bool getEsRescatado() {
        // TODO: devuelve esRescatado.
        return false;
    }
    void ladrar() {
        // TODO: imprime "Guau guau" seguido de un salto de linea.
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
