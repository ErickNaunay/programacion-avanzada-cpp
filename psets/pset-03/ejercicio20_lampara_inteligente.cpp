// Ejercicio 20: Encendible, Regulable y LamparaInteligente (desde cero, dos interfaces)
//
// Este archivo no tiene codigo de partida. Escribe tus propios includes, tus
// propias clases y tu propio main().
//
// Disena dos interfaces (clases con destructor virtual vacio y solo
// funciones virtuales puras, sin atributos) y una clase que implementa las
// dos:
//
// Encendible: void encender(), void apagar(), bool estaEncendido().
//
// Regulable: int nivel(), void subir(), void bajar().
//
// LamparaInteligente: hereda publicamente de Encendible y de Regulable.
// Atributos privados encendida (bool) y brillo (int), que el constructor
// sin parametros pone en false y 0. Reglas:
// - encender() la enciende y, si el brillo esta en 0, lo pone en 5.
// - apagar() la apaga y pone el brillo en 0.
// - subir() suma 1 al brillo, sin pasar de 10, solo si esta encendida.
// - bajar() resta 1 al brillo, sin bajar de 1, solo si esta encendida.
// - nivel() devuelve el brillo; estaEncendido(), encendida.
//
// Una funcion libre void subirAlMaximo(Regulable* r) que llama subir()
// hasta que nivel() sea 10, y una funcion libre void apagarSiEstaEncendido(
// Encendible* e) que apaga solo si esta encendido.
//
// En main(): crea una LamparaInteligente y dos punteros a ella, uno
// Encendible* y uno Regulable*. Imprime el estado con los textos de la
// salida esperada: encendida al inicio; llama subir() estando apagada e
// imprime el nivel; enciende e imprime el nivel; sube al maximo con la
// funcion libre e imprime el nivel; baja una vez e imprime el nivel; apaga
// con la funcion libre e imprime si esta encendida y el nivel. Usa
// std::boolalpha para los bool.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio20 ejercicio20_lampara_inteligente.cpp
// Ejecutar: ./ejercicio20
//
// Salida esperada:
// Encendida al inicio: false
// Nivel tras subir apagada: 0
// Nivel al encender: 5
// Nivel al maximo: 10
// Nivel tras bajar: 9
// Encendida al final: false
// Nivel al final: 0
