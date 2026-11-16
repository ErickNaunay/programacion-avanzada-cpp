// Ejercicio 28: Gimnasio (desde cero, at(), propagacion y orden de los catch)
//
// Este archivo no tiene codigo de partida. Escribe tus propios includes, tu
// propia clase, tu funcion y tu propio main().
//
// Disena la clase Gimnasio, con dos atributos privados:
// - std::vector<int> cuposPorHorario, que el constructor llena con
//   {12, 0, 6, 20, 3} (horarios 0 a 4).
// - std::map<int, double> precioPorPlan, que el constructor llena con el
//   plan 1 a 30, el plan 2 a 45 y el plan 3 a 60.
// Metodos:
// - int cuposEn(int horario): con at(); lanza std::out_of_range si el
//   horario no existe.
// - double precioDe(int plan): con at() del map; lanza std::out_of_range si
//   el plan no existe, sin crearlo.
// - double inscribir(int horario, int plan, int personas): en este orden,
//   lee los cupos y el precio (con los dos metodos anteriores); si personas
//   <= 0, lanza std::invalid_argument("personas no positivas"); si no hay
//   cupos suficientes, lanza std::runtime_error("sin cupos"). Si todo esta
//   bien, descuenta los cupos y devuelve personas * precio.
//
// Una funcion libre void atender(Gimnasio* gimnasio, int horario, int plan,
// int personas) que llama inscribir dentro de un try e imprime el resultado
// con los textos de la salida esperada. Tiene cuatro catch, por referencia
// constante, ordenados del mas especifico al mas general:
// std::out_of_range (imprime "Rechazada: horario o plan inexistente", sin
// e.what(), porque el mensaje de at() depende del compilador),
// std::invalid_argument y std::runtime_error (imprimen "Rechazada: " y
// e.what()), y por ultimo std::exception (imprime "Rechazada: error
// inesperado").
//
// En main(): atiende estas solicitudes, en orden (horario, plan, personas):
// (0, 2, 4), (1, 1, 1), (9, 1, 1), (3, 5, 2), (2, 3, -1), (2, 3, 6),
// (2, 3, 1). Despues imprime los cupos del horario 0 y del horario 2.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio28 ejercicio28_gimnasio_at.cpp
// Ejecutar: ./ejercicio28
//
// Salida esperada:
// Inscritas 4 personas, total 180
// Rechazada: sin cupos
// Rechazada: horario o plan inexistente
// Rechazada: horario o plan inexistente
// Rechazada: personas no positivas
// Inscritas 6 personas, total 360
// Rechazada: sin cupos
// Cupos en el horario 0: 8
// Cupos en el horario 2: 0

#include <exception>
#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>

class Gimnasio {
private:
    std::vector<int> cuposPorHorario;
    std::map<int, double> precioPorPlan;

public:
    Gimnasio() {
        cuposPorHorario = {12, 0, 6, 20, 3};
        precioPorPlan[1] = 30.0;
        precioPorPlan[2] = 45.0;
        precioPorPlan[3] = 60.0;
    }

    int cuposEn(int horario) const {
        return cuposPorHorario.at(horario);
    }

    double precioDe(int plan) const {
        return precioPorPlan.at(plan);
    }

    double inscribir(int horario, int plan, int personas) {
        int disponibles = cuposEn(horario);
        double precio = precioDe(plan);

        if (personas <= 0) {
            throw std::invalid_argument("personas no positivas");
        }
        if (personas > disponibles) {
            throw std::runtime_error("sin cupos");
        }

        cuposPorHorario.at(horario) -= personas;
        return personas * precio;
    }
};

void atender(Gimnasio* gimnasio, int horario, int plan, int personas) {
    try {
        double total = gimnasio->inscribir(horario, plan, personas);
        std::cout << "Inscritas " << personas << " personas, total " << total << std::endl;
    } catch (const std::out_of_range&) {
        std::cout << "Rechazada: horario o plan inexistente" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Rechazada: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Rechazada: " << e.what() << std::endl;
    } catch (const std::exception&) {
        std::cout << "Rechazada: error inesperado" << std::endl;
    }
}

int main() {
    Gimnasio gimnasio;

    atender(&gimnasio, 0, 2, 4);
    atender(&gimnasio, 1, 1, 1);
    atender(&gimnasio, 9, 1, 1);
    atender(&gimnasio, 3, 5, 2);
    atender(&gimnasio, 2, 3, -1);
    atender(&gimnasio, 2, 3, 6);
    atender(&gimnasio, 2, 3, 1);

    std::cout << "Cupos en el horario 0: " << gimnasio.cuposEn(0) << std::endl;
    std::cout << "Cupos en el horario 2: " << gimnasio.cuposEn(2) << std::endl;

    return 0;
}