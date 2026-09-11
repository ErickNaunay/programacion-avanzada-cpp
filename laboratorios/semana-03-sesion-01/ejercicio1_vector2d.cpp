// Ejercicio 1: Vector2D
//
// Completa operator+ y operator<<.
//
// operator+ es un método miembro: v1 + v2 se traduce a v1.operator+(v2).
// Construye y devuelve un Vector2D nuevo con la suma de cada coordenada;
// no modifiques x ni y del objeto sobre el que se llama.
//
// operator<< tiene que ser una función libre (no un método de la
// clase): en `std::cout << v1`, el operando izquierdo es std::cout, no
// un Vector2D. Recibe el stream por referencia (std::ostream&, con &)
// porque un stream no se puede copiar, y también lo devuelve por
// referencia para poder encadenar varios `<<` seguidos.
//
// Salida esperada:
// (2, 3) + (4, -1) = (6, 2)
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio1_vector2d.cpp -o bin/ejercicio1
// Ejecutar:  ./bin/ejercicio1

#include <iostream>
using namespace std;
class vector2d{
    private:
    double x;
    double y;

    public:
    vector2d(double xinicial, double yinicial){
    x = xinicial;
    y= yinicial;
    }
    double getx(){return x;}
    double gety(){return y;}

   //sumar////////////////////////////////////////////////////////////////
    vector2d operator+(vector2d otrovector){
        return vector2d(x + otrovector.getx(), y + otrovector.gety());
    }
    //////////////////////////////////////////////////////////////////////

};

//cout/////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& cout , vector2d unvector){
    
    
    cout<<unvector.getx() << " - "<< unvector.gety()<<")";
    return cout ;


}
///////////////////////////////////////////////////////////////////

int main(){

  vector2d v1(2, 3);  
  vector2d v2(4,-1);
  
  vector2d v3 = v1 + v2;
   cout <<"("<<v1 <<" + "<<"("<<v2<< "= "<<"("<<v3 ;
    return 0;
}
