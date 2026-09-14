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

        struct Escalera {
            int numeroPeldanos;

            bool esSegura(){
                if(numeroPeldanos <= 12){
                    return true;
                } else {
                    return false;
                }
            }
};

int main(){
        Escalera escalera1;
        escalera1.numeroPeldanos = 10;

        Escalera escalera2;
        escalera2.numeroPeldanos = 15;

        if (escalera1.esSegura()) {
                std::cout << "Escalera de 10 peldanos: segura" << std::endl;
        } else {
                std::cout << "Escalera de 10 peldanos: no segura" << std::endl;
        }

        if (escalera2.esSegura()) {
                std::cout << "Escalera de 15 peldanos: segura" << std::endl;
        } else {
            std::cout << "Escalera de 15 peldanos: no segura" << std::endl;
        }
    
    return 0;
}

