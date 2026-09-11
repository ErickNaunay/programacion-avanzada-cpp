// Ejercicio 13: Ascensor (desde cero)
//
// Este ejercicio no trae código de partida: escribe tú el archivo
// completo, incluyendo los #include y el main().
//
// Diseña una class Ascensor con dos atributos privados, pisoMinimo y
// pisoMaximo (enteros). Agrega:
// - Un setter que devuelva bool, setRangoPisos(int minimo, int
//   maximo), que valide un invariante conjunto entre los dos: minimo
//   debe ser mayor o igual a -2 (hasta 2 sótanos), maximo menor o igual
//   a 50, y minimo estrictamente menor que maximo. Si el invariante se
//   rompe, no modifica ningún atributo y devuelve false; si es válido,
//   asigna los dos juntos y devuelve true.
// - Los getters getPisoMinimo() y getPisoMaximo().
//
// Tu main() debe:
// 1. Crear un Ascensor.
// 2. Intentar setRangoPisos(-1, 20) (válido) e imprimir el resultado y
//    los dos valores actuales.
// 3. Intentar setRangoPisos(30, 10) (inválido, minimo no es menor que
//    maximo) e imprimir el resultado y los dos valores actuales (que no
//    debieron cambiar).
//
// Salida esperada, exactamente:
// Rango aceptado (-1 a 20): true
// Minimo: -1
// Maximo: 20
// Rango aceptado (30 a 10): false
// Minimo: -1
// Maximo: 20
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio13_ascensor.cpp -o bin/ejercicio13
// Ejecutar:  ./bin/ejercicio13






#include <iostream>
using namespace std;
//Diseña una class Ascensor con dos atributos privados, pisoMinimo y
// pisoMaximo (enteros). Agrega:
// - Un setter que devuelva bool, setRangoPisos(int minimo, int
//   maximo), que valide un invariante conjunto entre los dos: minimo
//   debe ser mayor o igual a -2 (hasta 2 sótanos), maximo menor o igual
//   a 50, y minimo estrictamente menor que maximo. Si el invariante se
//   rompe, no modifica ningún atributo y devuelve false; si es válido,
//   asigna los dos juntos y devuelve true.
// - Los getters getPisoMinimo() y getPisoMaximo().
class Asensor{
private:
int pisoMaximo;
int pisoMinimo;

public:
bool setrangopisos(int pisomin, int pisomax){
if(pisomin>= -2 and pisomax<= 50 and pisomin<pisomax){
    pisoMinimo=pisomin;
    pisoMaximo= pisomax;
    return true;
}else{
    return false;}
}

int getpisomax(){return pisoMaximo; }
int getpisomin(){return pisoMinimo; }

}; 



int main(){


    Asensor a1;
    a1.setrangopisos(-1,20);
    cout<<"Rango esperado ("<<a1.getpisomin()<<" a "<<a1.getpisomax()<<"):"<<std::boolalpha<<a1.setrangopisos(-1,20)<<endl;
    cout<<"Minimo: "<< a1.getpisomin()<<endl;
    cout<<"Maximo: "<< a1.getpisomax()<<endl;
   

        a1.setrangopisos(30,10);
    cout<<"Rango esperado ("<<a1.getpisomin()<<" a "<<a1.getpisomax()<<"):"<<std::boolalpha<<a1.setrangopisos(30,10)<<endl;
    cout<<"Minimo: "<< a1.getpisomin()<<endl;
    cout<<"Maximo: "<< a1.getpisomax()<<endl;
    
//Tu main() debe:
// 1. Crear un Ascensor.
// 2. Intentar setRangoPisos(-1, 20) (válido) e imprimir el resultado y
//    los dos valores actuales.
// 3. Intentar setRangoPisos(30, 10) (inválido, minimo no es menor que
//    maximo) e imprimir el resultado y los dos valores actuales (que no
//    debieron cambiar).
//
// Salida esperada, exactamente:
// Rango aceptado (-1 a 20): true
// Minimo: -1
// Maximo: 20
// Rango aceptado (30 a 10): false
// Minimo: -1
// Maximo: 20




    return 0;
}