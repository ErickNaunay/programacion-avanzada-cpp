// Ejercicio 26: puntajes del concurso (desde cero, algoritmos y lambdas)
//
// Este archivo no tiene codigo de partida. Escribe tus propios includes, tus
// propias funciones y tu propio main().
//
// Escribe seis funciones libres que reciben un std::vector<int> de
// puntajes (por valor). Ninguna usa un ciclo escrito a mano: cada una usa
// el algoritmo de <algorithm> o <numeric> indicado.
//
// - int posicionDelPrimerPerfecto(std::vector<int> puntajes): la posicion
//   del primer 100 (std::find), o -1 si no hay.
// - int aprobados(std::vector<int> puntajes, int minimo): cuantos son
//   mayores o iguales a minimo (std::count_if con una lambda que captura
//   minimo por valor).
// - int mejor(std::vector<int> puntajes): el mayor (std::max_element), o 0
//   si el vector esta vacio.
// - double promedio(std::vector<int> puntajes): con std::accumulate,
//   empezando en 0.0; 0 si el vector esta vacio.
// - int primeroBajo(std::vector<int> puntajes, int limite): el primer
//   puntaje menor que limite (std::find_if con una lambda), o -1.
// - std::vector<int> podio(std::vector<int> puntajes): ordena la copia de
//   mayor a menor (std::sort con una lambda comparadora) y devuelve un
//   vector con los tres primeros (o con todos, si hay menos de tres).
//
// En main(): usa el vector {72, 100, 45, 88, 100, 59, 91, 64} e imprime
// cada resultado con los textos de la salida esperada (minimo 70 para
// aprobados, limite 60 para primeroBajo). Al final, llama mejor y promedio
// con un vector vacio.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio26 ejercicio26_puntajes_algoritmos.cpp
// Ejecutar: ./ejercicio26
//
// Salida esperada:
// Primer perfecto en la posicion: 1
// Aprobados con 70: 5
// Mejor: 100
// Promedio: 77.375
// Primero bajo 60: 45
// Podio: 100 100 91
// Vacio, mejor: 0
// Vacio, promedio: 0
