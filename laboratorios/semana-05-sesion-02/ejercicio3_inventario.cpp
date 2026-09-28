#include <iostream>

int* crearInventario(int cantidadProductos) {
    int* stock = new int[cantidadProductos];
    for (int i = 0; i < cantidadProductos; i++) {
        stock[i] = 0;
    }
    return stock;
}

void mostrarInventario(int* stock, int cantidadProductos) {
    for (int i = 0; i < cantidadProductos; i++) {
        std::cout << "Producto " << i << ": " << stock[i] << " unidades" << std::endl;
    }
}

int contarProductosAgotados(int* stock, int cantidadProductos) {
    int* agotados = new int[cantidadProductos];
    int totalAgotados = 0;
    for (int i = 0; i < cantidadProductos; i++) {
        if (stock[i] == 0) {
            agotados[totalAgotados] = i;
            totalAgotados++;
        }
    }
    delete[] agotados;
    // TODO BUG 1: identifica que falta aqui antes de que la funcion
    // termine, y corrigelo.
    return totalAgotados;
}

int obtenerReporteFinal(int* stock, int cantidadProductos) {
    int totalUnidades = 0;
    for (int i = 0; i < cantidadProductos; i++) {
        totalUnidades += stock[i];
    }
    // TODO BUG 2: esta funcion devuelve la direccion de una variable
    // local. Corrigelo (revisa si de verdad necesitas devolver un
    // puntero para esto).
    return totalUnidades;
}

int main() {
    int cantidadProductos = 5;
    int* stock = crearInventario(cantidadProductos);
    stock[0] = 10;
    stock[1] = 5;
    stock[3] = 8;

    mostrarInventario(stock, cantidadProductos);

    int agotados = contarProductosAgotados(stock, cantidadProductos);
    std::cout << "Productos agotados: " << agotados << std::endl;

    int total = obtenerReporteFinal(stock, cantidadProductos);
    std::cout << "Total de unidades: " << total << std::endl;

    delete[] stock;
    return 0;
}
