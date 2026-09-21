// Ejercicio 18: Componente, ComponenteMecanico, ComponenteDigital y Robot
// (desde cero, herencia multiple con el problema del diamante)
//
// Este archivo no tiene codigo de partida. Escribe tu de tu propia clase,
// tus propios includes y tu propio main().
//
// Disena esta jerarquia:
//
// Componente: atributo privado codigoSerie (int). Setter bool
// setCodigoSerie(int c) valido si c esta entre 1000 y 9999 (ambos
// incluidos). Getter int getCodigoSerie().
//
// ComponenteMecanico: hereda de Componente. Agrega atributo privado pesoKg
// (double). Setter bool setPesoKg(double p) valido si p es mayor a 0 y
// menor o igual a 50. Getter double getPesoKg().
//
// ComponenteDigital: hereda de Componente. Agrega atributo privado version
// (int). Setter bool setVersion(int v) valido si v esta entre 1 y 99
// (ambos incluidos). Getter int getVersion().
//
// Robot: hereda de ComponenteMecanico y de ComponenteDigital a la vez.
// Agrega atributo privado autonomo (bool), con setter void
// setAutonomo(bool a) sin validacion (asignacion directa) y getter bool
// getAutonomo().
//
// Robot hereda de dos clases que a su vez heredan de un mismo ancestro
// (Componente), asi que tienes el problema del diamante: usa herencia
// virtual en ComponenteMecanico y en ComponenteDigital para que Robot
// termine con una sola copia de Componente, en vez de dos copias ambiguas.
//
// En main(): crea un Robot. Asignale codigoSerie = 4821 (setter heredado,
// una sola vez, no dos), pesoKg = 12.5, version = 3, y autonomo = true.
// Imprime los cuatro valores, cada uno en su propia linea, con las
// etiquetas "Codigo serie: ", "Peso: ", "Version: " y "Autonomo: " (usa
// std::boolalpha antes de imprimir el ultimo).
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio18 ejercicio18_componente_robot.cpp
// Ejecutar: ./ejercicio18
//
// Salida esperada:
// Codigo serie: 4821
// Peso: 12.5
// Version: 3
// Autonomo: true
