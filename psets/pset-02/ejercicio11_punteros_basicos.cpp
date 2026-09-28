// Ejercicio 11: Punteros basicos
//
// Completa las lineas marcadas con TODO dentro de main(). No agregues includes
// ni cambies el resto del archivo.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio11 ejercicio11_punteros_basicos.cpp
// Ejecutar: ./ejercicio11
//
// Salida esperada:
// Temperatura (variable): 35
// Temperatura (via puntero): 35

#include <iostream>

int main() {
    int temperatura = 25;

    int* punteroTemp = &temperatura;

    *punteroTemp = *punteroTemp + 10;

    std::cout << "Temperatura (variable): " << temperatura << std::endl;
    std::cout << "Temperatura (via puntero): " << *punteroTemp  << std::endl;
    
    return 0;
}
