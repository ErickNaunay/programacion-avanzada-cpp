// Ejercicio 16: Alarma, AlarmaDeIncendio y AlarmaDeIntrusion (desde cero, funciones virtuales)
//
// Este archivo no tiene codigo de partida. Escribe tus propios includes, tus
// propias clases y tu propio main().
//
// Disena tres clases:
//
// Alarma: destructor virtual con cuerpo vacio. Metodo virtual int
// segundosDeAviso() que devuelve 10. Metodo int prioridad(), NO virtual, que
// devuelve 1.
//
// AlarmaDeIncendio: hereda publicamente de Alarma. Atributo privado pisos
// (int), asignado en un constructor AlarmaDeIncendio(int p). Sobrescribe
// segundosDeAviso() con override: devuelve pisos * 15. Tiene su propio
// metodo int prioridad() (tampoco virtual) que devuelve 3.
//
// AlarmaDeIntrusion: hereda publicamente de Alarma. Atributo privado
// sensores (int), asignado en el constructor. Sobrescribe segundosDeAviso()
// con override: devuelve sensores * 4.
//
// En main(): crea una AlarmaDeIncendio de 4 pisos y una AlarmaDeIntrusion
// de 9 sensores. Con un puntero Alarma* que apunte a la de incendio,
// imprime segundosDeAviso() y prioridad(). Despues imprime prioridad()
// llamada directamente sobre el objeto de incendio. Apunta el mismo puntero
// a la de intrusion e imprime segundosDeAviso(). Por ultimo, crea una Alarma
// comun e imprime su segundosDeAviso() a traves de un puntero Alarma*.
// Usa exactamente los textos de la salida esperada.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio16 ejercicio16_alarmas.cpp
// Ejecutar: ./ejercicio16
//
// Salida esperada:
// Incendio por puntero, aviso: 60
// Incendio por puntero, prioridad: 1
// Incendio directa, prioridad: 3
// Intrusion por puntero, aviso: 36
// Alarma comun por puntero, aviso: 10
