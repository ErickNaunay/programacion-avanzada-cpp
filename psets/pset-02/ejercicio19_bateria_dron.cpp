// Ejercicio 19: Bateria y Dron (desde cero, composicion)
//
// Este archivo no tiene codigo de partida. Escribe tu de tu propia clase,
// tus propios includes y tu propio main().
//
// Disena dos clases:
//
// Bateria: atributo privado cargaPorcentaje (int). Setter bool
// setCargaPorcentaje(int c) valido si c esta entre 0 y 100 (ambos
// incluidos). Getter int getCargaPorcentaje().
//
// Dron: tiene como atributo privado un objeto Bateria (composicion, no
// herencia) y un atributo privado altitudMetros (double). Metodo bool
// configurarBateria(int c) que delega en el setter de la bateria interna y
// devuelve su resultado. Setter bool setAltitudMetros(double a) valido si a
// esta entre 0 y 500 (ambos incluidos). Metodo bool puedeDespegar() que
// devuelve true si la carga de la bateria interna es mayor o igual a 20,
// false en cualquier otro caso (usa el getter publico de Bateria, no
// accedas a su atributo privado).
//
// En main(): crea un Dron. Asignale altitudMetros = 0. Configura su
// bateria con 10% de carga y muestra el resultado de puedeDespegar(),
// precedido por "Puede despegar con 10%: ". Despues reconfigura la bateria
// a 45% y muestra puedeDespegar() otra vez, precedido por "Puede despegar
// con 45%: ". Usa std::boolalpha antes de imprimir cada resultado booleano.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio19 ejercicio19_bateria_dron.cpp
// Ejecutar: ./ejercicio19
//
// Salida esperada:
// Puede despegar con 10%: false
// Puede despegar con 45%: true

#include <iostream>
class Bateria{
    private:
    int cargaPorcentaje;

    public:
    bool setCargaPorcentaje(int c){
        if(c >= 0 and c <= 100){
            cargaPorcentaje = c;
            return true;
        }
        return false;
    }

    int getCargaPorcentaje(){
        return cargaPorcentaje;
    }
};

class Dron{
    private:
    Bateria bateria;
    double altitudMetros;

    public:
    bool configurarBateria(int c){
        return bateria.setCargaPorcentaje(c);
    }

    bool setAlturaMetros(int a){
        if(a >= 0 and a <= 500){
            altitudMetros = a;
            return true;
        }
        return false;
    }

    bool puedeDespegar(){
        if(bateria.getCargaPorcentaje() >= 20){
            return true;
        }
        return false;
    }

};

int main(){
    Dron d1;
    std::cout<<std::boolalpha;

    d1.setAlturaMetros(0);
    d1.configurarBateria(10);
    std::cout<<"Puede despegar con 10%: "<<d1.puedeDespegar()<<std::endl;
    d1.configurarBateria(45);
    std::cout<<"Puede despegar con 45%: "<<d1.puedeDespegar()<<std::endl;
}