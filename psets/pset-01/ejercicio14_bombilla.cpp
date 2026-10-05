// Ejercicio 14: Bombilla (desde cero)
//
// Este ejercicio no trae código de partida: escribe tú el archivo
// completo, incluyendo los #include y el main().
//
// Diseña una class Bombilla con un atributo privado vidaUtilHoras
// (double) y un constructor Bombilla(double horasIniciales):
// - Si horasIniciales es menor o igual a 0, el constructor imprime
//   exactamente "Vida util invalida, se asigna 1000 horas por defecto"
//   y asigna vidaUtilHoras = 1000.0.
// - Si es válida (mayor que 0), la asigna directamente, sin imprimir
//   nada.
// Agrega también el getter getVidaUtilHoras().
//
// Tu main() debe:
// 1. Crear una Bombilla con 5000.0 horas (válida) e imprimir su vida
//    útil.
// 2. Crear una Bombilla con -200.0 horas (inválida) e imprimir su vida
//    útil.
//
// Salida esperada, exactamente:
// Vida util: 5000
// Vida util invalida, se asigna 1000 horas por defecto
// Vida util: 1000
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio14_bombilla.cpp -o bin/ejercicio14
// Ejecutar:  ./bin/ejercicio14

#include <iostream>
using namespace std;

class Bombilla{

    private:
    double vida_util_horas{0};
    public:

    Bombilla(double horas_iniciales){
        if(horas_iniciales <= 0){
            cout<<"Vida util invalida, se asigna 1000 horas por defecto"<<endl;
            vida_util_horas = 1000.0;
        }else{
            vida_util_horas = horas_iniciales;
        }
    }

    double get_vida_util_horas(){
        return vida_util_horas;
    }

};

int main(){
    
    Bombilla bombilla(5000.0);
    cout<<"Vida util: "<<bombilla.get_vida_util_horas()<<endl;
    Bombilla bombilla_1(-200);
    cout<<"Vida util: "<<bombilla_1.get_vida_util_horas()<<endl;

}