// Ejercicio 6: plantillas de funcion
//
// Completa las dos plantillas marcadas con TODO. No cambies el main().
// Antes de compilar, fijate en la ultima llamada del main: por que necesita
// el tipo entre angulos?
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio6 ejercicio6_plantillas_de_funcion.cpp
// Ejecutar: ./ejercicio6
//
// Salida esperada:
// Mayor de 7, 19 y 4: 19
// Mayor de 2.5, 1.75 y 2.25: 2.5
// Mayor de b, z y m: z
// Lecturas entre 18 y 22: 3
// Notas entre 14.5 y 20: 2
// Mayor de 3, 4.5 y 2: 4.5

#include <iostream>

template <typename T>
T mayorDeTres(T a, T b, T c) {
    // TODO: devuelve el mayor de los tres valores, usando solo operator>.
    return a;
}

template <typename T>
int contarEnRango(T valores[], int cantidad, T minimo, T maximo) {
    // TODO: cuenta cuantos valores estan entre minimo y maximo, ambos incluidos.
    return 0;
}

int main() {
    std::cout << "Mayor de 7, 19 y 4: " << mayorDeTres(7, 19, 4) << std::endl;
    std::cout << "Mayor de 2.5, 1.75 y 2.25: " << mayorDeTres(2.5, 1.75, 2.25) << std::endl;
    std::cout << "Mayor de b, z y m: " << mayorDeTres('b', 'z', 'm') << std::endl;

    int lecturas[6] = {17, 18, 25, 22, 20, 30};
    std::cout << "Lecturas entre 18 y 22: " << contarEnRango(lecturas, 6, 18, 22) << std::endl;

    double notas[4] = {12.0, 14.5, 20.0, 21.0};
    std::cout << "Notas entre 14.5 y 20: " << contarEnRango(notas, 4, 14.5, 20.0) << std::endl;

    std::cout << "Mayor de 3, 4.5 y 2: " << mayorDeTres<double>(3, 4.5, 2) << std::endl;
    return 0;
}
