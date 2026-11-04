#include <iostream>
#include <vector>

// Lecturas por hora del sensor de temperatura del laboratorio, de la hora 0
// a la hora 5. El programa responde consultas sobre esas lecturas. Corre el
// archivo antes de cambiar nada.

double lecturaEn(std::vector<double> lecturas, int hora) {
    // TODO 1: lee la lectura con lecturas.at(hora) en vez de lecturas[hora].
    return lecturas[hora];
}

double promedioEntre(std::vector<double> lecturas, int desde, int hasta) {
    // TODO 3: si desde es mayor que hasta, lanza std::invalid_argument con
    // el mensaje "rango invertido". Incluye <stdexcept> arriba.
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
        // TODO 2: atrapa la excepcion que lanza lecturaEn, para que una hora
        // sin lectura no detenga las consultas siguientes. En ese caso
        // imprime "Hora N: sin lectura".
        std::cout << "Hora " << consultas[i] << ": " << lecturaEn(lecturas, consultas[i]) << std::endl;
    }

    int desdes[3] = {1, 4, 3};
    int hastas[3] = {3, 2, 8};
    for (int i = 0; i < 3; i++) {
        // TODO 4: un try con dos catch. Para std::invalid_argument imprime
        // "Promedio de D a H: error, " y el mensaje de la excepcion; para
        // std::out_of_range, "Promedio de D a H: error, faltan lecturas".
        std::cout << "Promedio de " << desdes[i] << " a " << hastas[i] << ": " << promedioEntre(lecturas, desdes[i], hastas[i]) << std::endl;
    }

    std::cout << "Fin del reporte" << std::endl;
    return 0;
}
