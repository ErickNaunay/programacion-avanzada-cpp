// Ejercicio 10: ReservaSala (integrador)
//
// Este ejercicio integra todo lo practicado en PSet 1: atributos
// privados, un getter, un setter que valida un invariante conjunto
// entre dos atributos (horaInicio/horaFin), un constructor con valor
// por defecto ante un dato invalido (capacidadPersonas), y un
// destructor. El programa ya crea tres objetos dentro de un bloque en
// main(); no necesitas tocar main(), solo completar la clase.
//
// Completa ReservaSala:
// - Constructor ReservaSala(int capacidadInicial): si capacidadInicial
//   es invalida (<= 0 o > 50), imprime "Reserva creada, capacidad
//   segura por defecto (5)" y asigna capacidadPersonas = 5. Si es
//   valida, imprime "Reserva creada, capacidad " + capacidadInicial y
//   la asigna.
// - setHorario(double inicio, double fin): mismo invariante conjunto
//   del Ejercicio 6 (inicio >= 0, fin <= 24, inicio < fin).
// - getCapacidadPersonas().
// - Destructor ~ReservaSala(): imprime "Reserva liberada".
//
// Salida esperada:
// Reserva creada, capacidad 20
// Horario aceptado (9 a 11): true
// Reserva creada, capacidad segura por defecto (5)
// Horario aceptado (14 a 13): false
// Reserva creada, capacidad 8
// Horario aceptado (16 a 18): true
// --- fin del bloque, se destruyen en orden inverso ---
// Reserva liberada
// Reserva liberada
// Reserva liberada
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio10_reserva_sala.cpp -o bin/ejercicio10
// Ejecutar:  ./bin/ejercicio10

#include <iostream>

class ReservaSala {
private:
    double horaInicio;
    double horaFin;
    int capacidadPersonas;

public:
    ReservaSala(int capacidadInicial) {
        // TODO
    }

    bool setHorario(double inicio, double fin) {
        // TODO
        return false;
    }

    int getCapacidadPersonas() {
        return capacidadPersonas;
    }

    ~ReservaSala() {
        // TODO
    }
};

int main() {
    {
        ReservaSala r1(20);
        bool ok1 = r1.setHorario(9.0, 11.0);
        std::cout << "Horario aceptado (9 a 11): " << std::boolalpha << ok1 << std::endl;

        ReservaSala r2(-3);
        bool ok2 = r2.setHorario(14.0, 13.0);
        std::cout << "Horario aceptado (14 a 13): " << std::boolalpha << ok2 << std::endl;

        ReservaSala r3(8);
        bool ok3 = r3.setHorario(16.0, 18.0);
        std::cout << "Horario aceptado (16 a 18): " << std::boolalpha << ok3 << std::endl;

        std::cout << "--- fin del bloque, se destruyen en orden inverso ---" << std::endl;
    }

    return 0;
}
