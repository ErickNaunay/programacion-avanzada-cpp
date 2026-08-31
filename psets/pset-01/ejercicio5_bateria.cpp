// Ejercicio 5: Bateria
//
// Completa la clase Bateria: un atributo privado porcentajeCarga y un
// setter que devuelva bool, setPorcentajeCarga(double p), que solo
// acepte valores entre 0 y 100 (ambos incluidos). Si p esta fuera de
// rango, no modifica el atributo y devuelve false; si es valido, lo
// asigna y devuelve true. Agrega tambien el getter getPorcentajeCarga().
//
// Salida esperada:
// Carga aceptada (80): true
// Porcentaje de carga: 80
// Carga aceptada (150): false
// Porcentaje de carga: 80
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio5_bateria.cpp -o bin/ejercicio5
// Ejecutar:  ./bin/ejercicio5

#include <iostream>

class Bateria {
private:
    double porcentajeCarga;

public:
    bool setPorcentajeCarga(double p) {
        // TODO: si p < 0 o p > 100, retorna false sin modificar el
        // atributo. Si no, asigna porcentajeCarga = p y retorna true.
        return false;
    }

    double getPorcentajeCarga() {
        return porcentajeCarga;
    }
};

int main() {
    Bateria b;

    bool resultado1 = b.setPorcentajeCarga(80.0);
    std::cout << "Carga aceptada (80): " << std::boolalpha << resultado1 << std::endl;
    std::cout << "Porcentaje de carga: " << b.getPorcentajeCarga() << std::endl;

    bool resultado2 = b.setPorcentajeCarga(150.0);
    std::cout << "Carga aceptada (150): " << std::boolalpha << resultado2 << std::endl;
    std::cout << "Porcentaje de carga: " << b.getPorcentajeCarga() << std::endl;

    return 0;
}
