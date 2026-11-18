#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>

// Temperaturas de una semana en el laboratorio. Cada calculo esta escrito
// con un loop a mano. Corre el archivo antes de cambiar nada.

int main() {
    std::vector<double> temperaturas = {21.5, 23.0, 19.5, 23.0, 25.5, 22.0, 18.5};

    // TODO (paso 1): reemplaza este loop por std::accumulate, de
    // <numeric>, con 0.0 como valor inicial.
    double sumaTotal = std::accumulate(temperaturas.begin(), temperaturas.end(), 0.0);
    std::cout << "Suma: " << sumaTotal << std::endl;

    // TODO (paso 2): reemplaza este loop por std::max_element, de
    // <algorithm>. Ojo: devuelve un iterador, no un valor.
    auto maximaIter = std::max_element(temperaturas.begin(), temperaturas.end());
    double maxima = *maximaIter;
    std::cout << "Maxima: " << maxima << std::endl;

    // TODO (paso 3): reemplaza este loop por std::count.
    int vecesEn23 = std::count(temperaturas.begin(), temperaturas.end(), 23.0);
    std::cout << "Dias en 23.0: " << vecesEn23 << std::endl;

    // TODO (paso 4): reemplaza este loop por std::find. Si encuentra
    // 25.5, la posicion es la distancia entre el iterador encontrado y
    // temperaturas.begin().
    auto posicionIter = std::find(temperaturas.begin(), temperaturas.end(), 25.5);
    int posicion = std::distance(temperaturas.begin(), posicionIter);
    if (posicionIter == temperaturas.end()) {
        std::cout << "25.5 no aparece" << std::endl;
    } else {
        std::cout << "25.5 aparece en la posicion " << posicion << std::endl;
    }

    // TODO (paso 5): crea una std::list<double> llamada lista con los
    // mismos valores, copiandolos del vector:
    //     std::list<double> lista(temperaturas.begin(), temperaturas.end());
    // y repite los pasos 1, 2 y 3 sobre lista, con las mismas llamadas.
    // Imprime "Suma (lista): ", "Maxima (lista): " y "Dias en 23.0 (lista): ".
    std::list<double> lista(temperaturas.begin(), temperaturas.end());
    double sumaLista = std::accumulate(lista.begin(), lista.end(), 0.0);
    std::cout << "Suma (lista): " << sumaLista << std::endl;
    auto maximaIterLista = std::max_element(lista.begin(), lista.end());
    double maximaLista = *maximaIterLista;
    std::cout << "Maxima (lista): " << maximaLista << std::endl;
    int vecesEn23Lista = std::count(lista.begin(), lista.end(), 23.0);
    std::cout << "Dias en 23.0 (lista): " << vecesEn23Lista << std::endl;

    // TODO (paso 6): imprime "Suma con 0 como valor inicial: " con
    // std::accumulate(temperaturas.begin(), temperaturas.end(), 0).
    double sumaConCero = std::accumulate(temperaturas.begin(), temperaturas.end(), 0);
    std::cout << "Suma con 0 como valor inicial: " << sumaConCero << std::endl;

    return 0;
}
