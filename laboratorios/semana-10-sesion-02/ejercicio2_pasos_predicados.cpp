#include <algorithm>
#include <iostream>
#include <vector>

bool esDiaSedentario(int pasosDelDia) {
    return pasosDelDia < 3000;
}

int main() {
    std::vector<int> pasos = {4200, 1800, 3300, 7500, 2900, 10200, 6100};
    int meta = 5000;

    int sedentarios = std::count_if(pasos.begin(), pasos.end(), esDiaSedentario);
    std::cout << "Dias sedentarios: " << sedentarios << std::endl;

    int cumplenMeta = std::count_if(pasos.begin(), pasos.end(), [meta](int p) {
        return p >= meta;
    });
    std::cout << "Dias que cumplieron la meta: " << cumplenMeta << std::endl;

    auto primero = std::find_if(pasos.begin(), pasos.end(), [meta](int p) {
        return p >= meta;
    });

    if (primero != pasos.end()) {
        int dia = primero - pasos.begin() + 1;
        std::cout << "Primer dia que cumplio la meta: dia " << dia << " (" << *primero << " pasos)" << std::endl;
    }

    std::vector<int> ordenados = pasos;

    std::sort(ordenados.begin(), ordenados.end(), [](int a, int b) {
        return a > b;
    });

    std::cout << "Tres mejores dias:";
    for (int i = 0; i < 3; i++) {
        std::cout << " " << ordenados[i];
    }
    std::cout << std::endl;

    std::cout << "Pasos en orden original:";
    for (int p : pasos) {
        std::cout << " " << p;
    }
    std::cout << std::endl;

    return 0;
}