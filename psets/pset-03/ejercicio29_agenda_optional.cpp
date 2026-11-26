// Ejercicio 29: AgendaDelConsultorio (desde cero, std::optional)
//
// Este archivo no tiene codigo de partida. Escribe tus propios includes
// (necesitas <optional>), tu propia clase y tu propio main().
//
// El consultorio atiende una cita por hora, de las 8 a las 17 (la ultima
// cita empieza a las 17). Disena la clase AgendaDelConsultorio, con un
// atributo privado std::map<int, int> pacientePorHora (hora y numero de
// paciente). Ningun metodo devuelve -1 ni 0 para decir "no hay": devuelven
// std::nullopt. Metodos:
// - std::optional<int> pacienteEn(int hora): el paciente de esa hora, o
//   vacio si no hay cita (sin crear la hora en el map).
// - std::optional<int> primeraLibreDesde(int hora): la primera hora libre
//   desde hora (incluida) hasta las 17, o vacio si no hay ninguna. Si hora
//   es menor que 8, empieza en 8.
// - std::optional<int> agendar(int paciente, int desde): agenda al paciente
//   en la primera hora libre desde desde, y devuelve esa hora; si no hay,
//   devuelve vacio sin agendar nada.
// - bool cancelar(int hora): si hay cita a esa hora la borra y devuelve
//   true; si no, false.
//
// En main(): agenda al paciente 501 desde las 8, al 502 desde las 8, al 503
// desde las 16, al 504 desde las 16, y otra vez al 504 desde las 16,
// imprimiendo cada hora asignada o "sin hora" (con has_value). Imprime el paciente de las 9 con *, y el de
// las 12 con value_or(0). Dentro de un try, imprime pacienteEn(13).value();
// atrapa std::bad_optional_access por referencia constante e imprime "Nadie
// a las 13". Cancela la cita de las 8 y agenda al 505 desde las 7. Usa los
// textos de la salida esperada.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio29 ejercicio29_agenda_optional.cpp
// Ejecutar: ./ejercicio29
//
// Salida esperada:
// Paciente 501: 8
// Paciente 502: 9
// Paciente 503: 16
// Paciente 504: 17
// Paciente 504 otra vez: sin hora
// A las 9: 502
// A las 12: 0
// Nadie a las 13
// Paciente 505: 8

#include <iostream>
#include <map>
#include <optional>

class AgendaDelConsultorio {
private:
    std::map<int, int> pacientePorHora;

public:
    std::optional<int> pacienteEn(int hora) const {
        auto it = pacientePorHora.find(hora);
        if (it == pacientePorHora.end()) {
            return std::nullopt;
        }
        return it->second;
    }

    std::optional<int> primeraLibreDesde(int hora) const {
        int inicio = (hora < 8) ? 8 : hora;
        for (int h = inicio; h <= 17; ++h) {
            if (pacientePorHora.find(h) == pacientePorHora.end()) {
                return h;
            }
        }
        return std::nullopt;
    }

    std::optional<int> agendar(int paciente, int desde) {
        std::optional<int> libre = primeraLibreDesde(desde);
        if (!libre.has_value()) {
            return std::nullopt;
        }
        pacientePorHora[*libre] = paciente;
        return *libre;
    }

    bool cancelar(int hora) {
        return pacientePorHora.erase(hora) > 0;
    }
};

void imprimirAsignacion(const char* etiqueta, std::optional<int> horaAsignada) {
    std::cout << etiqueta << ": ";
    if (horaAsignada.has_value()) {
        std::cout << *horaAsignada << std::endl;
    } else {
        std::cout << "sin hora" << std::endl;
    }
}

int main() {
    AgendaDelConsultorio agenda;

    imprimirAsignacion("Paciente 501", agenda.agendar(501, 8));
    imprimirAsignacion("Paciente 502", agenda.agendar(502, 8));
    imprimirAsignacion("Paciente 503", agenda.agendar(503, 16));
    imprimirAsignacion("Paciente 504", agenda.agendar(504, 16));
    imprimirAsignacion("Paciente 504 otra vez", agenda.agendar(504, 16));

    std::cout << "A las 9: " << *agenda.pacienteEn(9) << std::endl;
    std::cout << "A las 12: " << agenda.pacienteEn(12).value_or(0) << std::endl;

    try {
        std::cout << agenda.pacienteEn(13).value() << std::endl;
    } catch (const std::bad_optional_access&) {
        std::cout << "Nadie a las 13" << std::endl;
    }

    agenda.cancelar(8);
    imprimirAsignacion("Paciente 505", agenda.agendar(505, 7));

    return 0;
}