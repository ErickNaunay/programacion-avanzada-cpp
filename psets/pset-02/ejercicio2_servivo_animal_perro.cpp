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
        if (e >= 0 && e <= 100) {
            edadAnios = e;
            return true;
        }
        return false;
    }
    int getEdadAnios() {
        // TODO: devuelve edadAnios.
        return edadAnios;
    }
};

class Animal : public SerVivo {
private:
    int numeroPatas;
public:
    bool setNumeroPatas(int p) {
        // TODO: valida que p este entre 0 y 8 (ambos incluidos).
        if (p >= 0 && p <= 8) {
            numeroPatas = p;
            return true;
        }
        return false;
    }
    int getNumeroPatas() {
        // TODO: devuelve numeroPatas.
        return numeroPatas;
    }
};

class Perro : public Animal {
private:
    bool esRescatado;
public:
    void setEsRescatado(bool r) {
        // TODO: asigna esRescatado. No hay invariante que validar.
        esRescatado = r;
    }
    bool getEsRescatado() {
        // TODO: devuelve esRescatado.
        return esRescatado;
    }
    void ladrar() {
        // TODO: imprime "Guau guau" seguido de un salto de linea.
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
