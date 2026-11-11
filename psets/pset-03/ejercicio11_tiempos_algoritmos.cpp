// Ejercicio 11: tiempos de respuesta (algoritmos de la STL)
//
// Completa las funciones marcadas con TODO usando el algoritmo que indica
// cada una, no un ciclo escrito a mano. No cambies las firmas ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio11 ejercicio11_tiempos_algoritmos.cpp
// Ejecutar: ./ejercicio11
//
// Salida esperada:
// Hay un tiempo de 90: 1
// Posicion del primer 90: 3
// Hay un tiempo de 55: 0
// Veces que aparece 40: 2
// Tiempo maximo: 210
// Respuestas lentas: 4
// Total: 870
// Ordenados: 15 40 40 65 90 120 125 165 210

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

bool esLenta(int milisegundos) {
    return milisegundos > 100;
}

bool contiene(std::vector<int> tiempos, int valor) {
    // TODO: usa std::find y compara el resultado con end().
    auto it = std::find(tiempos.begin(), tiempos.end(), valor);
    return it != tiempos.end();
}

int posicionDe(std::vector<int> tiempos, int valor) {
    // TODO: usa std::find; si no esta, devuelve -1; si esta, la posicion
    // (resultado - tiempos.begin()).
    auto it = std::find(tiempos.begin(), tiempos.end(), valor);
    if (it == tiempos.end()) {
        return -1;
    }
    return static_cast<int>(it - tiempos.begin());
}

int vecesQueAparece(std::vector<int> tiempos, int valor) {
    // TODO: usa std::count.
    return static_cast<int>(std::count(tiempos.begin(), tiempos.end(), valor));
}

int maximo(std::vector<int> tiempos) {
    // TODO: usa std::max_element. Si el vector esta vacio, devuelve 0.
    if (tiempos.empty()) {
        return 0;
    }
    auto it = std::max_element(tiempos.begin(), tiempos.end());
    return *it;
}

int cuantasLentas(std::vector<int> tiempos) {
    // TODO: usa std::count_if con la funcion esLenta, pasada por su nombre.
    return static_cast<int>(std::count_if(tiempos.begin(), tiempos.end(), esLenta));
}

int total(std::vector<int> tiempos) {
    // TODO: usa std::accumulate, empezando en 0.
    return std::accumulate(tiempos.begin(), tiempos.end(), 0);
}

std::vector<int> ordenados(std::vector<int> tiempos) {
    // TODO: ordena la copia recibida con std::sort, de menor a mayor, y
    // devuelvela.
    std::sort(tiempos.begin(), tiempos.end());
    return tiempos;
}

int main() {
    std::vector<int> tiempos = {120, 40, 15, 90, 210, 40, 65, 165, 125};

    std::cout << "Hay un tiempo de 90: " << contiene(tiempos, 90) << std::endl;
    std::cout << "Posicion del primer 90: " << posicionDe(tiempos, 90) << std::endl;
    std::cout << "Hay un tiempo de 55: " << contiene(tiempos, 55) << std::endl;
    std::cout << "Veces que aparece 40: " << vecesQueAparece(tiempos, 40) << std::endl;
    std::cout << "Tiempo maximo: " << maximo(tiempos) << std::endl;
    std::cout << "Respuestas lentas: " << cuantasLentas(tiempos) << std::endl;
    std::cout << "Total: " << total(tiempos) << std::endl;

    std::vector<int> enOrden = ordenados(tiempos);
    std::cout << "Ordenados:";
    for (int t : enOrden) {
        std::cout << " " << t;
    }
    std::cout << std::endl;
    return 0;
}