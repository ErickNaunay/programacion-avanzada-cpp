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
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio11_escalera.cpp -o bin/ejercicio11
// Ejecutar:  ./bin/ejercicio11

#include <iostream>
using namespace std;

// Diseña un struct Escalera con un atributo numeroPeldanos (entero).
// Agrega un método esSegura() que devuelva true si numeroPeldanos es
// menor o igual a 12, y false si no.


struct escalera{
    int numeroPeldanos;



    string essegura(int numeroPeldanos){
    if(numeroPeldanos <= 12){
        return  "es segura "; 
    }else{
        return "no es segura ";
}
}
double getpeldanos(){return numeroPeldanos;}


};


// Tu main() debe:
// 1. Crear una Escalera con numeroPeldanos = 10.
// 2. Crear una Escalera con numeroPeldanos = 15.
// 3. Imprimir, para cada una, si es segura o no.






int main(){
escalera e1;
e1.numeroPeldanos=10;

cout<<"El numero de peldanos es " <<e1.getpeldanos()<<" y "<<e1.essegura(e1.getpeldanos())<<endl ;


escalera e2;
e2.numeroPeldanos=15;
cout<<"El numero de peldanos es " <<e2.getpeldanos()<<" y "<<e2.essegura(e2.getpeldanos());

    return 0;
}