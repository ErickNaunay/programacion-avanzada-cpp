// Ejercicio 18: Sensor y SensorDeHumedad (desde cero, destructor virtual y unique_ptr)
//
// Este archivo no tiene codigo de partida. Escribe tus propios includes
// (necesitas <memory>), tus propias clases y tu propio main().
//
// Disena dos clases:
//
// Sensor: destructor virtual que imprime "Sensor apagado". Metodo virtual
// double promedio() que devuelve 0.
//
// SensorDeHumedad: hereda publicamente de Sensor. Atributo privado
// lecturas, un double* que apunta a un arreglo dinamico de 3 doubles
// reservado con new[] en el constructor SensorDeHumedad(double a, double b,
// double c), que guarda a, b y c en las posiciones 0, 1 y 2. Su destructor
// libera el arreglo con delete[] e imprime "Lecturas liberadas". promedio()
// con override devuelve el promedio de las tres lecturas.
//
// En main(): dentro de un bloque { }, crea un std::unique_ptr<Sensor> con
// std::make_unique<SensorDeHumedad>(60, 72, 81) e imprime su promedio.
// Despues de cerrar el bloque, imprime "Fin del programa". La salida tiene
// que mostrar que se ejecutaron los dos destructores, en el orden correcto:
// si falta el de SensorDeHumedad, hay una fuga de memoria.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio18 ejercicio18_sensor_humedad.cpp
// Ejecutar: ./ejercicio18
//
// Salida esperada:
// Humedad promedio: 71
// Lecturas liberadas
// Sensor apagado
// Fin del programa
