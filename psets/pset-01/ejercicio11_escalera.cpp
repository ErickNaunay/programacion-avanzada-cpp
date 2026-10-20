// Ejercicio 11: Escalera (desde cero)
//
// Este ejercicio no trae código de partida: escribe tú el archivo
// completo, incluyendo los #include y el main().
//
// Diseña un struct Escalera con un atributo numeroPeldanos (entero).
// Agrega un método esSegura() que devuelva true si numeroPeldanos es
// menor o igual a 12, y false si no.
//
// Tu main() debe:
// 1. Crear una Escalera con numeroPeldanos = 10.
// 2. Crear una Escalera con numeroPeldanos = 15.
// 3. Imprimir, para cada una, si es segura o no.
//
// Salida esperada, exactamente:
// Escalera de 10 peldanos: segura
// Escalera de 15 peldanos: no segura
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g psets/pset-01/ejercicio11_escalera.cpp -o bin/ejercicio11
// Ejecutar:  ./bin/ejercicio11

#include <iostream>
struct Escalera{
    int numeroPeldanos;
    bool esSegura(){
        if(numeroPeldanos<=12){
            return true;
        }
        return false;
    }
};

int main(){
    Escalera E1;
    Escalera E2;
    E1.numeroPeldanos=10;
    E2.numeroPeldanos=15;
    bool ok1 = E1.esSegura();
    std::cout<<"Escalera de 10 peldanos: "<<(ok1 ? "segura" : "no segura") << std::endl;
    bool ok2 = E2.esSegura();
    std::cout<<"Escalera de 15 peldanos: "<<(ok2 ? "segura" : "no segura") << std::endl;
    return 0;
}