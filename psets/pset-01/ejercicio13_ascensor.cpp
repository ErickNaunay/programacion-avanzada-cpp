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

class ascensor{

    private:
        int pisoMinimo, pisoMaximo;

    public:
    bool setRangoPisos(int minimo,int maximo){
            if( minimo >= -2 && maximo <= 50 && minimo < maximo)
            {
                pisoMinimo = minimo;
                pisoMaximo = maximo;
                cout<<"Rango aceptado ("<<minimo<<" a "<<maximo<<"): true"<<endl;
                cout<<"Minimo: "<<pisoMinimo<<endl<<"Maximo: "<<pisoMaximo<<endl;
                return true;
            }   cout<<"Rango aceptado ("<<minimo<<" a "<<maximo<<"): false"<<endl;
                cout<<"Minimo: "<<pisoMinimo<<endl<<"Maximo: "<<pisoMaximo<<endl;
                return false;
    }
    int getpisomin(){
        return pisoMinimo;
    }
    int getpisoMax(){
        return pisoMaximo;
    }
};


int main(){

    ascensor c,c1;
    c.setRangoPisos(-1,20);
    c.setRangoPisos(30,10);

    return 0;
}