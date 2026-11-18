// Ejercicio 27: Ascensor (desde cero, lanzar y atrapar excepciones)
//
// Este archivo no tiene codigo de partida. Escribe tus propios includes
// (necesitas <stdexcept>), tu propia clase y tu propio main().
//
// Disena la clase Ascensor, con atributos privados pisoActual (int, empieza
// en 0) y cargaKg (double, empieza en 0). El edificio tiene pisos del 0 al
// 10 y el ascensor soporta 450 kg. Metodos:
// - void subirPersona(double kg): si kg <= 0, lanza
//   std::invalid_argument("peso no positivo"); si la carga pasaria de 450,
//   lanza std::runtime_error("sobrecarga") sin cambiar la carga. Si no,
//   suma kg a la carga.
// - void bajarPersona(double kg): si kg <= 0, lanza
//   std::invalid_argument("peso no positivo"); si kg es mayor que la carga,
//   lanza std::runtime_error("no hay tanto peso a bordo"). Si no, resta.
// - void irA(int piso): si el piso no esta entre 0 y 10, lanza
//   std::out_of_range("piso inexistente"); si no, cambia pisoActual.
// - int getPiso() y double getCarga().
//
// En main(), cada operacion que puede fallar va dentro de un try, y cada
// catch atrapa por referencia constante e imprime e.what() con los textos
// de la salida esperada:
// 1. Sube a 80, 95 y 120 kg; imprime la carga.
// 2. En un try: sube 200 kg (falla) y despues va al piso 7 (no debe
//    alcanzar a ejecutarse). Un catch para std::runtime_error. Despues del
//    try, imprime el piso actual.
// 3. En un try: va al piso 12. Un catch para std::out_of_range.
// 4. En un try: baja una persona de -60 kg. Atrapa con std::exception.
// 5. Va al piso 4 sin try (no falla) e imprime piso y carga.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio27 ejercicio27_ascensor_excepciones.cpp
// Ejecutar: ./ejercicio27
//
// Salida esperada:
// Carga: 295
// No se pudo: sobrecarga
// Piso actual: 0
// Fuera de rango: piso inexistente
// Error: peso no positivo
// Piso 4, carga 295
