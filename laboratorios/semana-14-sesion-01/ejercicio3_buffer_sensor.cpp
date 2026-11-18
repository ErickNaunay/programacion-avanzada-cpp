#include <iostream>

#include "contador_reservas.h"

// Ejercicio 3: el buffer del sensor de temperatura del motor de un dron.
//
// El microcontrolador del motor lee el sensor 1000 veces por segundo y tiene
// que recordar las ultimas 64 lecturas (en grados) para calcular su promedio
// y su minimo.
// En ese tipo de sistema hay una regla: una vez que el programa arranca,
// no se pide memoria dinamica nunca mas. Pedir memoria puede tardar un
// tiempo que nadie puede acotar, puede fallar cuando la memoria esta
// fragmentada, y un dron en el aire no se puede reiniciar.
//
// TODO: escribe la clase BufferCircular, sin new, sin make_unique y sin
// contenedores de la STL. Guarda las lecturas en un arreglo de tamano fijo
// (double lecturas[CAPACIDAD];), dentro del objeto.
//
// - BufferCircular(): el buffer empieza vacio.
// - void agregar(double valor): guarda la lectura. Si ya hay CAPACIDAD
//   lecturas, la nueva reemplaza a la mas antigua.
// - int getCantidad(): cuantas lecturas hay guardadas (como maximo, CAPACIDAD).
// - double masAntigua(): la lectura mas antigua que sigue guardada.
// - double promedio(): el promedio de las lecturas guardadas (0 si no hay).
// - double minimo(): la menor de las lecturas guardadas (0 si no hay).
//
// No cambies el main: lee un millon de valores, y cuenta cuantas reservas
// de memoria dinamica hubo mientras el sensor corria.
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -O2 ejercicio3_buffer_sensor.cpp -o bin/ejercicio3
// Ejecutar:  ./bin/ejercicio3
//
// Salida esperada:
// Lecturas guardadas: 64
// Mas antigua: 75.92
// Promedio de las ultimas 64: 72.1662
// Minimo de las ultimas 64: 60.43
// Reservas de memoria mientras corria el sensor: 0

const int CAPACIDAD = 64;
const int LECTURAS = 1000000;

// TODO: escribe aqui la clase BufferCircular.

int main() {
    BufferCircular buffer;
    long long reservasAntes = reservasHechas;

    unsigned int semilla = 2026;
    for (int i = 0; i < LECTURAS; i++) {
        semilla = semilla * 1103515245 + 12345;
        double lectura = 60.0 + ((semilla >> 8) % 2400) / 100.0;
        buffer.agregar(lectura);
    }

    long long reservasDurante = reservasHechas - reservasAntes;
    std::cout << "Lecturas guardadas: " << buffer.getCantidad() << std::endl;
    std::cout << "Mas antigua: " << buffer.masAntigua() << std::endl;
    std::cout << "Promedio de las ultimas 64: " << buffer.promedio() << std::endl;
    std::cout << "Minimo de las ultimas 64: " << buffer.minimo() << std::endl;
    std::cout << "Reservas de memoria mientras corria el sensor: " << reservasDurante << std::endl;
    return 0;
}
