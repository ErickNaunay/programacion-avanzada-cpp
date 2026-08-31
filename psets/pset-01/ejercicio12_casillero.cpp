// Ejercicio 12: Casillero (desde cero)
//
// Este ejercicio no trae código de partida: escribe tú el archivo
// completo, incluyendo los #include y el main().
//
// Diseña una class Casillero con un atributo privado numeroCombinacion
// (entero). Agrega:
// - Un setter que devuelva bool, setNumeroCombinacion(int n), que solo
//   acepte combinaciones de 4 dígitos (entre 1000 y 9999, ambos
//   incluidos). Si n está fuera de ese rango, no modifica el atributo y
//   devuelve false; si es válido, lo asigna y devuelve true.
// - Un getter getNumeroCombinacion().
//
// Tu main() debe:
// 1. Crear un Casillero.
// 2. Intentar asignar la combinación 4821 (válida) e imprimir el
//    resultado del setter y el número actual.
// 3. Intentar asignar la combinación 87 (inválida) e imprimir el
//    resultado del setter y el número actual (que no debió cambiar).
//
// Salida esperada, exactamente:
// Combinacion asignada: true
// Numero: 4821
// Combinacion asignada: false
// Numero: 4821
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio12_casillero.cpp -o bin/ejercicio12
// Ejecutar:  ./bin/ejercicio12
