// Ejercicio 2: Fraccion
//
// Mismo patrón del ejercicio 1 (operator+ miembro, operator<< función
// libre), en una clase con invariante: el constructor ya está completo
// y valida que el denominador no sea 0 (si lo es, usa 0/1 y avisa).
// Completa operator+ y operator<<.
//
// Suma de fracciones: a/b + c/d = (ad + cb) / (bd). No simplifiques el
// resultado.
//
// Salida esperada:
// 1/2 + 1/3 = 5/6
// Aviso: denominador invalido, se uso 0/1 por defecto
// f3: 0/1
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio2_fraccion.cpp -o bin/ejercicio2
// Ejecutar:  ./bin/ejercicio2

#include <iostream>
using namespace std;
class Fraccion {
private:
    int numerador;
    int denominador;

public:
    Fraccion(int numeradorInicial, int denominadorInicial) {
        if (denominadorInicial == 0) {
            numerador = 0;
            denominador = 1;
            std::cout << "Aviso: denominador invalido, se uso 0/1 por defecto" << std::endl;
        } else {
            numerador = numeradorInicial;
            denominador = denominadorInicial;
        }
    }

    int getNumerador() { return numerador; }
    int getDenominador() { return denominador; }





    Fraccion operator+(Fraccion otra) {
        int nuevonumerador;
        int nuevodenominador;
        
        nuevonumerador =numerador * otra.getDenominador()+ otra.getNumerador() * denominador;
        nuevodenominador= denominador * otra.getDenominador();
        
        return Fraccion(nuevonumerador, nuevodenominador);
    }
};


//cout/////////////////////////////////////////////////////////////
//std::ostream& operator<<(std::ostream& cout , vector2d unvector){
    
    
//    cout<<unvector.getx() << " - "<< unvector.gety()<<")";
//    return cout ;
//}
///////////////////////////////////////////////////////////////////


std::ostream& operator<<(std::ostream& os, Fraccion f) {
    os <<f.getNumerador()<<"/"<<f.getDenominador();
    

    // TODO: escribe en os algo como "numerador/denominador", usando
    // f.getNumerador() y f.getDenominador(), y despues retorna os.
    return os;
}

int main() {
    Fraccion f1(1, 2);
    Fraccion f2(1, 3);
    Fraccion suma = f1 + f2;
    std::cout << f1 << " + " << f2 << " = " << suma << std::endl;

    Fraccion f3(1, 0);
    std::cout << "f3: " << f3 << std::endl;

    return 0;
}
