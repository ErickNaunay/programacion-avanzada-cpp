// Ejercicio 17: Vehiculo, Camion y Bus en el peaje (desde cero, arreglo de punteros a la base)
//
// Este archivo no tiene codigo de partida. Escribe tus propios includes, tus
// propias clases y tu propio main().
//
// Disena tres clases:
//
// Vehiculo: atributo privado tarifaBase (double). Constructor sin
// parametros que la pone en 0, y metodo void setTarifaBase(double t) que la
// asigna sin validar. Getter double getTarifaBase(). Destructor virtual con
// cuerpo vacio. Metodo virtual double peaje() que devuelve tarifaBase.
//
// Camion: hereda publicamente de Vehiculo. Atributo privado ejes (int).
// Constructor Camion(double tarifa, int e) que llama setTarifaBase(tarifa)
// y asigna ejes. peaje() con override: tarifa base mas 1.5 por cada eje.
//
// Bus: hereda publicamente de Vehiculo. Atributo privado pasajeros (int).
// Constructor Bus(double tarifa, int p), igual que Camion. peaje() con
// override: el doble de la tarifa base si lleva mas de 30 pasajeros; si no,
// la tarifa base.
//
// Una funcion libre double recaudacion(Vehiculo* fila[], int cantidad) que
// suma el peaje de cada vehiculo de la fila, llamandolo a traves del
// puntero.
//
// En main(): crea un Vehiculo comun con tarifa base 1, un Camion con tarifa
// 2 y 4 ejes, un Bus con tarifa 2 y 45 pasajeros, y un Bus con tarifa 2 y
// 12 pasajeros. Ponlos en un arreglo de 4 punteros Vehiculo*, en ese orden.
// Imprime el peaje de cada uno con un ciclo, y despues la recaudacion total.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio17 ejercicio17_peaje.cpp
// Ejecutar: ./ejercicio17
//
// Salida esperada:
// Vehiculo 0 paga: 1
// Vehiculo 1 paga: 8
// Vehiculo 2 paga: 4
// Vehiculo 3 paga: 2
// Recaudacion: 15
