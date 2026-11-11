#pragma once

#include <stdexcept>

int tarifaEnCentavos(int minutos) {
    if (minutos < 0) {
        throw std::invalid_argument("minutos negativos");
    }
    if (minutos < 15) {
        return 0;
    }
    int horas = (minutos + 59) / 60;
    int total = horas * 50;
    if (total > 500) {
        total = 500;
    }
    return total;
}
