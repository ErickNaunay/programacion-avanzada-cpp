// Ejercicio 21: plantillas de funcion (desde cero)
//
// Este archivo no tiene codigo de partida. Escribe tus propios includes, tus
// propias plantillas y tu propio main().
//
// Escribe tres plantillas de funcion, cada una con template <typename T>:
//
// - T menorDeTres(T a, T b, T c): el menor de los tres, usando solo
//   operator<.
// - T sumarArreglo(T valores[], int cantidad): la suma de todos los
//   valores, empezando desde el primero (si cantidad es 0, devuelve T(),
//   el valor por defecto del tipo, que es 0 para int y double).
// - void intercambiar(T* a, T* b): intercambia los valores a los que
//   apuntan a y b.
//
// En main(), con los textos de la salida esperada:
// - menorDeTres con 14, 9 y 30; con 0.75, 1.5 y 0.25; y con 'q', 'c' y 'x'.
// - sumarArreglo con el arreglo int {4, 8, 15, 16, 23, 42} y con el arreglo
//   double {1.5, 2.25, 0.25}.
// - intercambiar dos int que valen 3 y 7 (imprime los dos despues) y dos
//   double que valen 1.5 y 9.5 (imprime los dos despues).
// - menorDeTres con 5, 2.5 y 4, que mezcla int y double: escribe el tipo
//   entre angulos para que compile.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio21 ejercicio21_plantillas_menor_suma.cpp
// Ejecutar: ./ejercicio21
//
// Salida esperada:
// Menor de 14, 9 y 30: 9
// Menor de 0.75, 1.5 y 0.25: 0.25
// Menor de q, c y x: c
// Suma de enteros: 108
// Suma de decimales: 4
// Intercambio de enteros: 7 3
// Intercambio de decimales: 9.5 1.5
// Menor de 5, 2.5 y 4: 2.5
