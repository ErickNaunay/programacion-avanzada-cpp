#include <iostream>
#include <map>
#include <optional>

// Registro por hora de la camara de frio del laboratorio de biologia. No
// todas las horas tienen lectura: el sensor a veces no reporta.
// buscarTemperatura devuelve -1 cuando no hay lectura a esa hora. Corre el
// archivo antes de cambiar nada.

// TODO 1: cambia el tipo de retorno a std::optional<double> y devuelve
// std::nullopt cuando no hay lectura. Incluye <optional> arriba.
std::optional<double> buscarTemperatura(std::map<int, double> registro, int hora) {
    if (registro.count(hora) == 0) {
        return std::nullopt;
    }
    return registro[hora];
}

int main() {
    std::map<int, double> registro;
    registro[6] = 2.5;
    registro[7] = -1.0;
    registro[9] = -3.5;

    int horas[4] = {6, 7, 8, 9};
    for (int i = 0; i < 4; i++) {
        // TODO 2: con el resultado como std::optional, pregunta si tiene
        // valor antes de leerlo con *.
        std::optional<double> temperatura = buscarTemperatura(registro, horas[i]);
        if (!temperatura.has_value()) {
            std::cout << "Hora " << horas[i] << ": sin lectura" << std::endl;
        } else {
            std::cout << "Hora " << horas[i] << ": " << *temperatura << std::endl;
        }
    }

    // TODO 3: la temperatura de la hora 8 para el reporte, o 4.0 (la
    // temperatura de referencia de la camara) si no hay lectura, con
    // value_or.
    double paraReporte = buscarTemperatura(registro, 8).value_or(4.0);
    std::cout << "Hora 8 para el reporte: " << paraReporte << std::endl;

    // TODO 4: lee la hora 8 con .value() dentro de un try, y atrapa
    // std::bad_optional_access imprimiendo "Hora 8 con value(): " y el
    // mensaje de la excepcion.
    try {
        double temperatura8 = buscarTemperatura(registro, 8).value();
        std::cout << "Hora 8 con value(): " << temperatura8 << std::endl;
    } catch (const std::bad_optional_access& e) {
        std::cout << "Hora 8 con value(): " << e.what() << std::endl;
    }

    return 0;
}