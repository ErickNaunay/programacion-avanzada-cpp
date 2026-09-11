// Ejercicio 2:

// Objetivo: el mismo comportamiento del ejercicio 1, pero base y altura
// viven juntos dentro de un objeto Rectangulo, y area(), perimetro() y
// escalar() son metodos de ese objeto: ya no se pasan como parametros
// sueltos, y no existe forma de mezclar la base de un rectangulo con la
// altura de otro.
//
// Usamos struct (no class): en C++ ambas definen una clase en el sentido
// de la sesion de hoy (agrupan atributos y metodos), la diferencia lo veremos la siguiente clase
//
// Salida esperada:
// Area: 50
// Perimetro: 30
// Despues de escalar x2 -> base: 20, altura: 10
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio2_struct_rectangulo.cpp -o bin/ejercicio2
// Ejecutar:  ./bin/ejercicio2

#include <iostream>
using namespace std;

struct Rectangulo {
    double base;
    double altura;

    double area() {
        return base * altura;
    }

    double perimetro() {
        return base*2+altura*2;
    }

    void escalar(double factor) {
       base= base * factor;
       altura= altura *factor;
    cout<< "Despues de escalar x"<<factor<<"->"<<"base: "<<base<<", altura:"<<altura<<endl;    
    }
};

int main() {
    Rectangulo r;
    r.base = 10.0;
    r.altura = 5.0;

    cout << "Area: " << r.area() << endl;
    cout << "Perimetro: " << r.perimetro() << endl;

    r.escalar(2.0);

    return 0;
}
