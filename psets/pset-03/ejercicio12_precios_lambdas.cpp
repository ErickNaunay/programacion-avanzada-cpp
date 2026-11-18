// Ejercicio 12: precios de la cafeteria (algoritmos con lambdas)
//
// Completa las funciones marcadas con TODO, cada una con el algoritmo que
// indica y una lambda. Donde la lambda necesita un parametro de la funcion
// (como presupuesto), capturalo por valor: [presupuesto].
// No cambies las firmas ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio12 ejercicio12_precios_lambdas.cpp
// Ejecutar: ./ejercicio12
//
// Salida esperada:
// Productos de hasta 2.5: 4
// Primer producto sobre 4: 4.75
// Primer producto sobre 10: -1
// De mayor a menor: 6.5 4.75 3.25 2.5 2 1.5 1.25
// Total con 10% de recargo: 23.925
// Productos con precio mayor a 1.5 y menor a 5: 4

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int cuantosAlcanzan(std::vector<double> precios, double presupuesto) {
    // TODO: std::count_if con una lambda que captura presupuesto: precio menor o
    // igual al presupuesto.
    return static_cast<int>(std::count_if(precios.begin(), precios.end(), [presupuesto](double precio) {
        return precio <= presupuesto;
    }));
}

double primeroSobre(std::vector<double> precios, double limite) {
    // TODO: std::find_if con una lambda que captura limite (precio > limite).
    // Si no hay ninguno, devuelve -1.
    auto it = std::find_if(precios.begin(), precios.end(), [limite](double precio) {
        return precio > limite;
    });
    if (it == precios.end()) {
        return -1;
    }
    return *it;
}

std::vector<double> deMayorAMenor(std::vector<double> precios) {
    // TODO: std::sort con una lambda comparadora (a > b). Devuelve la copia
    // ordenada.
    std::sort(precios.begin(), precios.end(), [](double a, double b) {
        return a > b;
    });
    return precios;
}

double totalConRecargo(std::vector<double> precios, double recargo) {
    // TODO: std::accumulate desde 0.0 con una lambda de dos parametros (acumulado
    // y precio) que captura recargo y suma precio * (1 + recargo).
    return std::accumulate(precios.begin(), precios.end(), 0.0, [recargo](double acumulado, double precio) {
        return acumulado + precio * (1.0 + recargo);
    });
}

int cuantosEntre(std::vector<double> precios, double minimo, double maximo) {
    // TODO: std::count_if con una lambda que captura minimo y maximo: precio
    // mayor que minimo y menor que maximo (sin incluirlos).
    return static_cast<int>(std::count_if(precios.begin(), precios.end(), [minimo, maximo](double precio) {
        return precio > minimo && precio < maximo;
    }));
}

int main() {
    std::vector<double> precios = {2.5, 1.25, 4.75, 3.25, 6.5, 2.0, 1.5};

    std::cout << "Productos de hasta 2.5: " << cuantosAlcanzan(precios, 2.5) << std::endl;
    std::cout << "Primer producto sobre 4: " << primeroSobre(precios, 4) << std::endl;
    std::cout << "Primer producto sobre 10: " << primeroSobre(precios, 10) << std::endl;

    std::vector<double> ordenados = deMayorAMenor(precios);
    std::cout << "De mayor a menor:";
    for (double p : ordenados) {
        std::cout << " " << p;
    }
    std::cout << std::endl;

    std::cout << "Total con 10% de recargo: " << totalConRecargo(precios, 0.10) << std::endl;
    std::cout << "Productos con precio mayor a 1.5 y menor a 5: " << cuantosEntre(precios, 1.5, 5) << std::endl;
    return 0;
}