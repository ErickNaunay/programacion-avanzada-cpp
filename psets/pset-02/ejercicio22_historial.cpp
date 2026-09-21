// Ejercicio 22: Historial (desde cero, evita la fuga de memoria)
//
// Este archivo no tiene codigo de partida. Escribe tu de tu propia clase,
// tus propios includes y tu propio main().
//
// Disena la clase Historial: atributos privados registros (double*) y
// cantidad (int). Constructor Historial(int n) que asigna cantidad = n,
// reserva con new[] un arreglo de cantidad doubles y lo guarda en
// registros, e inicializa cada posicion en 0.0. Destructor: si tu
// destructor no libera con delete[] la memoria que el constructor reservo,
// tu clase tiene una fuga de memoria cada vez que se crea y se destruye un
// Historial, asi que asegurate de liberarla ahi (el destructor no imprime
// nada). Metodo bool setRegistro(int indice, double valor) que valida que
// indice este entre 0 (incluido) y cantidad (excluido); si es valido
// asigna registros[indice] = valor y devuelve true, si no devuelve false.
// Metodo double promedio() que devuelve el promedio de todas las
// posiciones de registros (la suma de todas dividida entre cantidad).
//
// En main(), dentro de un bloque { }: crea un Historial de tamano 3,
// asigna 10.0, 20.0 y 30.0 en las posiciones 0, 1 y 2, e imprime su
// promedio precedido por "Promedio h1: ". Crea un segundo Historial de
// tamano 2, asigna 5.0 y 7.0, e imprime su promedio precedido por
// "Promedio h2: ". Al cerrar el bloque { }, imprime "Fin del bloque"
// despues de que el bloque termine.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio22 ejercicio22_historial.cpp
// Ejecutar: ./ejercicio22
//
// Salida esperada:
// Promedio h1: 20
// Promedio h2: 6
// Fin del bloque
