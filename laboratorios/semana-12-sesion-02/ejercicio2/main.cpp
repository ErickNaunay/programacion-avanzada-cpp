#include <iostream>
#include <vector>

#include "lecturas.h"

// Salida esperada:
// Promedios con ventana 3:
// 19
// 20
// 21
// 22

int main() {
    std::vector<double> lecturas = {18.0, 19.0, 20.0, 21.0, 22.0, 23.0};
    std::vector<double> promedios = promedioMovil(lecturas, 3);

    std::cout << "Promedios con ventana 3:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << promedios[i] << std::endl;
    }

    return 0;
}
