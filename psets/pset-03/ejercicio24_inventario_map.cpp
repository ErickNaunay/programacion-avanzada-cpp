// Ejercicio 24: Inventario (desde cero, std::map)
//
// Este archivo no tiene codigo de partida. Escribe tus propios includes, tu
// propia clase y tu propio main().
//
// Disena la clase Inventario, con un atributo privado std::map<int, int>
// stockPorCodigo (codigo de producto y unidades). Metodos:
// - void ingresar(int codigo, int unidades): suma unidades al stock del
//   codigo (si no existe, empieza en 0). Si unidades no es positivo, no
//   hace nada.
// - bool retirar(int codigo, int unidades): si el codigo no existe, o no
//   hay suficientes unidades, devuelve false sin cambiar nada (y sin crear
//   el codigo). Si no, resta y devuelve true.
// - int stockDe(int codigo): las unidades del codigo, o 0 si no existe
//   (sin crearlo).
// - int agotados(): cuantos codigos tienen 0 unidades.
// - int codigos(): cuantos codigos distintos hay.
// - void imprimir(): cada codigo con sus unidades, en orden de codigo,
//   recorriendo el map con un iterador.
//
// En main(): ingresa 40 del 300, 15 del 120, 5 del 450 y -3 del 999.
// Retira 15 del 120, 10 del 450 y 1 del 777, imprimiendo cada resultado.
// Imprime el stock del 999, la cantidad de codigos, los agotados, y el
// inventario completo, con los textos de la salida esperada.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio24 ejercicio24_inventario_map.cpp
// Ejecutar: ./ejercicio24
//
// Salida esperada:
// Retirar 15 del 120: 1
// Retirar 10 del 450: 0
// Retirar 1 del 777: 0
// Stock del 999: 0
// Codigos registrados: 3
// Agotados: 1
// 120: 0
// 300: 40
// 450: 5
