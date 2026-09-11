// Ejercicio 1:

// Objetivo: implementar area, perimetro, nuevaBase y nuevaAltura de un
// rectangulo usando funciones sueltas que reciben base y altura por
// separado.

// Salida esperada:
// Area: 50
// Perimetro: 30
// Despues de escalar x2 -> base: 20, altura: 10
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio1_funciones_sueltas.cpp -o bin/ejercicio1
// Ejecutar:  ./bin/ejercicio1

//crear una clase
#include <iostream>
using namespace std;
double Area(double base,double altura){
return base * altura; 
};

double perimetro(double base,double altura){
  return base*2 + altura*2;

};

double nuevo(double base){
  return base *2;
}
double nuevo2(double altura){

  return altura *2;
}



int main() {
  
  double altura = 5;
  double base =10;
cout<<"Area: " << Area(altura,base)<< endl;
cout<<"Perimetro: "<<perimetro(altura,base)<< endl;  
cout<<"Despues de escalar por 2 "<<"Altura: "<<nuevo2(altura)<<", base: "<<nuevo(base)<<endl;

return 0;
}