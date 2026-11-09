#include <iostream>

#include "cola_impresion.h"

// Salida esperada:
// Cola: 12 20 8 20 20 10 5
// Minutos de 25 paginas: 3
// Minutos totales: 11

int main() {
    ColaDeImpresion cola;
    cola.agregar(12);
    cola.agregar(45);
    cola.agregar(8);
    cola.agregar(30);

    cola.dividirGrandes();

    std::cout << "Cola:";
    for (int i = 0; i < cola.cantidad(); i++) {
        std::cout << " " << cola.paginasDe(i);
    }
    std::cout << std::endl;

    std::cout << "Minutos de 25 paginas: " << minutosDeImpresion(25) << std::endl;
    std::cout << "Minutos totales: " << cola.minutosTotales() << std::endl;

    return 0;
}
