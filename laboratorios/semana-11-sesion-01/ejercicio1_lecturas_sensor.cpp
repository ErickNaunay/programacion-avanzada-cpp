#include <iostream>
#include <vector>
#include <stdexcept>

double lecturaEn(std::vector<double> lecturas, int hora) {
    return lecturas.at(hora);
}

double promedioEntre(std::vector<double> lecturas, int desde, int hasta) {
    if (desde > hasta) {
        throw std::invalid_argument("rango invertido");
    }

    double suma = 0.0;

    for (int hora = desde; hora <= hasta; hora++) {
        suma = suma + lecturaEn(lecturas, hora);
    }

    return suma / (hasta - desde + 1);
}

int main() {
    std::vector<double> lecturas = {18.5, 19.0, 21.5, 23.0, 22.5, 20.0};

    int consultas[4] = {2, 5, 9, 1};

    for (int i = 0; i < 4; i++) {
        try {
            std::cout << "Hora " << consultas[i] << ": "
                      << lecturaEn(lecturas, consultas[i])
                      << std::endl;
        } catch (const std::out_of_range&) {
            std::cout << "Hora " << consultas[i]
                      << ": sin lectura"
                      << std::endl;
        }
    }

    int desdes[3] = {1, 4, 3};
    int hastas[3] = {3, 2, 8};

    for (int i = 0; i < 3; i++) {
        try {
            std::cout << "Promedio de "
                      << desdes[i]
                      << " a "
                      << hastas[i]
                      << ": "
                      << promedioEntre(lecturas, desdes[i], hastas[i])
                      << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << "Promedio de "
                      << desdes[i]
                      << " a "
                      << hastas[i]
                      << ": error, "
                      << e.what()
                      << std::endl;
        } catch (const std::out_of_range&) {
            std::cout << "Promedio de "
                      << desdes[i]
                      << " a "
                      << hastas[i]
                      << ": error, faltan lecturas"
                      << std::endl;
        }
    }

    std::cout << "Fin del reporte" << std::endl;

    return 0;
}