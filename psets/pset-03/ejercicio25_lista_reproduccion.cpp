// Ejercicio 25: ListaDeReproduccion (desde cero, std::list y std::set)
//
// Este archivo no tiene codigo de partida. Escribe tus propios includes, tu
// propia clase y tu propio main().
//
// Disena la clase ListaDeReproduccion, con dos atributos privados: una
// std::list<int> pendientes (los ids de canciones por sonar, en orden) y un
// std::set<int> reproducidas (las que ya sonaron). Metodos:
// - void agregarAlFinal(int id): la pone al final de pendientes.
// - void agregarSiguiente(int id): la pone al principio de pendientes.
// - int reproducir(): si no hay pendientes, devuelve -1. Si hay, saca la
//   primera, la agrega a reproducidas y devuelve su id.
// - bool yaSono(int id): true si esta en reproducidas.
// - int quitarTodas(int id): borra de pendientes todas las apariciones de
//   ese id (puede estar repetido) y devuelve cuantas borro. Recorre con un
//   iterador y usa lo que devuelve erase(it) para seguir: despues de borrar,
//   el iterador viejo ya no sirve.
// - int pendientesPorSonar(): cuantas quedan.
//
// En main(): agrega al final 11, 22, 11 y 33; agrega como siguiente la 44.
// Reproduce dos veces (imprime cada id). Quita todas las 11 (imprime
// cuantas). Imprime cuantas quedan, si la 44 ya sono y si la 33 ya sono.
// Reproduce dos veces mas. Usa los textos de la salida esperada.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio25 ejercicio25_lista_reproduccion.cpp
// Ejecutar: ./ejercicio25
//
// Salida esperada:
// Suena: 44
// Suena: 11
// Quitadas: 1
// Pendientes: 2
// La 44 ya sono: 1
// La 33 ya sono: 0
// Suena: 22
// Suena: 33
