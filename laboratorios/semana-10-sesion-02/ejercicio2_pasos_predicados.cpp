#include <algorithm>
#include <iostream>
#include <vector>

// Salida esperada:
// Dias sedentarios: 2
// Dias que cumplieron la meta: 3
// Primer dia que cumplio la meta: dia 4 (7500 pasos)
// Tres mejores dias: 10200 7500 6100
// Pasos en orden original: 4200 1800 3300 7500 2900 10200 6100

// Un dia es sedentario si tiene menos de 3000 pasos.
bool esDiaSedentario(int pasosDelDia) {
    return pasosDelDia < 3000;
}

int main() {
    std::vector<int> pasos = {4200, 1800, 3300, 7500, 2900, 10200, 6100};
    int meta = 5000;

    int sedentarios = std::count_if(
        pasos.begin(),
        pasos.end(),
        esDiaSedentario
    );
    std::cout << "Dias sedentarios: " << sedentarios << std::endl;

    int diasMeta = std::count_if(
        pasos.begin(),
        pasos.end(),
        [meta](int pasosDelDia) {
            return pasosDelDia >= meta;
        }
    );
    std::cout << "Dias que cumplieron la meta: " << diasMeta << std::endl;

    auto it = std::find_if(
        pasos.begin(),
        pasos.end(),
        [meta](int pasosDelDia) {
            return pasosDelDia >= meta;
        }
    );
    if (it != pasos.end()) {
        int indice = static_cast<int>(std::distance(pasos.begin(), it)) + 1;
        int pasosMeta = *it;
        std::cout << "Primer dia que cumplio la meta: dia " << indice
                  << " (" << pasosMeta << " pasos)" << std::endl;
    }

    std::vector<int> ordenados = pasos;
    std::sort(ordenados.begin(), ordenados.end(), [](int a, int b) {
        return a > b;
    });

    std::cout << "Tres mejores dias:";
    for (int i = 0; i < 3; ++i) {
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
