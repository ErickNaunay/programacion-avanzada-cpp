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
// TODO: escribe la funcion bool esDiaSedentario(int pasosDelDia).
bool esDiaSedentario(int pasosDelDia) {
    return pasosDelDia < 3000;
}

int main() {
    std::vector<int> pasos = {4200, 1800, 3300, 7500, 2900, 10200, 6100};
    int meta = 5000;

    // TODO: cuenta los dias sedentarios con std::count_if y la funcion
    // esDiaSedentario. Imprime "Dias sedentarios: ".
    int diasSedentarios = std::count_if(pasos.begin(), pasos.end(), esDiaSedentario);
    std::cout << "Dias sedentarios: " << diasSedentarios << std::endl;

    // TODO: cuenta los dias con al menos "meta" pasos con std::count_if y
    // una lambda que capture meta. Imprime "Dias que cumplieron la meta: ".
    int diasQueCumplieronLaMeta = std::count_if(pasos.begin(), pasos.end(), [meta](int pasosDelDia) {
        return pasosDelDia >= meta;
    });
    std::cout << "Dias que cumplieron la meta: " << diasQueCumplieronLaMeta << std::endl;

    // TODO: con std::find_if y una lambda, busca el primer dia con al
    // menos "meta" pasos. Imprime "Primer dia que cumplio la meta: dia N
    // (P pasos)", con N contando desde 1.
    auto primerDiaQueCumplioLaMetaIter = std::find_if(pasos.begin(), pasos.end(), [meta](int pasosDelDia) {
        return pasosDelDia >= meta;
    });
    if (primerDiaQueCumplioLaMetaIter != pasos.end()) {
        int primerDiaQueCumplioLaMeta = std::distance(pasos.begin(), primerDiaQueCumplioLaMetaIter) + 1;
        int pasosDelPrimerDia = *primerDiaQueCumplioLaMetaIter;
        std::cout << "Primer dia que cumplio la meta: dia " << primerDiaQueCumplioLaMeta << " (" << pasosDelPrimerDia << " pasos)" << std::endl;
    } else {
        std::cout << "Ningun dia cumplio la meta" << std::endl;
    }

    // TODO: copia pasos en un vector nuevo llamado ordenados, ordenalo de
    // mayor a menor con std::sort y una lambda de comparacion, e imprime
    // "Tres mejores dias:" con sus tres primeros elementos, cada uno
    // precedido de un espacio.
    std::vector<int> ordenados = pasos;
    std::sort(ordenados.begin(), ordenados.end(), [](int a, int b) {
        return a > b;
    });
    std::cout << "Tres mejores dias:";
    for (int i = 0; i < 3 && i < ordenados.size(); i++) {
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
