// Ejercicio 21: Cola (desde cero, RAII con new[] y delete[])
//
// Este archivo no tiene codigo de partida. Escribe tu de tu propia clase,
// tus propios includes y tu propio main().
//
// Disena la clase Cola: atributos privados datos (int*) y capacidad (int).
// Constructor Cola(int c) que asigna capacidad = c, reserva con new[] un
// arreglo de capacidad enteros y lo guarda en datos, e inicializa cada
// posicion en 0. Destructor que libera datos con delete[] y despues
// imprime "Cola liberada" seguido de un salto de linea. Metodo bool
// agregar(int indice, int valor) que valida que indice este entre 0
// (incluido) y capacidad (excluido); si es valido asigna datos[indice] =
// valor y devuelve true, si no devuelve false sin modificar nada. Getter
// int getValor(int indice) que devuelve datos[indice] sin validar.
//
// En main(): crea una Cola con capacidad 4. Llama a agregar(1, 55) e
// imprime su resultado, precedido por "Agregar en 1: ". Llama a
// agregar(9, 99) (un indice fuera de rango) e imprime su resultado,
// precedido por "Agregar en 9: ". Usa std::boolalpha antes de imprimir
// ambos resultados. Despues, en un bucle de 0 a 3, imprime cada posicion
// con el formato "Posicion X: valor" (X es el indice).
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio21 ejercicio21_cola.cpp
// Ejecutar: ./ejercicio21
//
// Salida esperada:
// Agregar en 1: true
// Agregar en 9: false
// Posicion 0: 0
// Posicion 1: 55
// Posicion 2: 0
// Posicion 3: 0
// Cola liberada
