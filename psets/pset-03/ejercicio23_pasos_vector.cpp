// Ejercicio 23: HistorialDePasos (desde cero, std::vector)
//
// Este archivo no tiene codigo de partida. Escribe tus propios includes, tu
// propia clase y tu propio main().
//
// Disena la clase HistorialDePasos, con un atributo privado
// std::vector<int> pasos (los pasos de cada dia, en orden). Metodos:
// - bool registrar(int cantidad): si cantidad es negativa devuelve false;
//   si no, la agrega al final y devuelve true.
// - int dias(): cuantos dias hay registrados.
// - double promedio(): el promedio de pasos, o 0 si no hay dias.
// - int diasSobreMeta(int meta): cuantos dias llegaron a la meta (mayor o
//   igual).
// - int mejorRacha(int meta): la mayor cantidad de dias seguidos que
//   llegaron a la meta. Recorre el vector una sola vez.
//
// En main(): registra, en este orden, 8000, 12000, 10500, -50, 4000, 11000,
// 13000, 9999 y 10000 (el -50 se rechaza: imprime el resultado de ese
// registro). Imprime los valores con los textos de la salida esperada, con
// meta 10000.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio23 ejercicio23_pasos_vector.cpp
// Ejecutar: ./ejercicio23
//
// Salida esperada:
// Registrar -50: 0
// Dias registrados: 8
// Promedio: 9812.38
// Dias con meta: 5
// Mejor racha: 2
