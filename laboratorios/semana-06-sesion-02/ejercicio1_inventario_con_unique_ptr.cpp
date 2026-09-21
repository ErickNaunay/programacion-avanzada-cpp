#include <iostream>

// TODO: cambia el tipo de retorno a std::unique_ptr<int[]>, y crea el
// arreglo con std::make_unique<int[]>(cantidadProductos) en vez de
// "new int[cantidadProductos]" directo.
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
    int totalAgotados = 0;
    for (int i = 0; i < cantidadProductos; i++) {
        if (stock[i] == 0) totalAgotados++;
    }
    return totalAgotados;
}

int obtenerReporteFinal(int* stock, int cantidadProductos) {
    int totalUnidades = 0;
    for (int i = 0; i < cantidadProductos; i++) totalUnidades += stock[i];
    return totalUnidades;
}

int main() {
    int cantidadProductos = 5;
    // TODO: declara "stock" como std::unique_ptr<int[]> en vez de int*.
    // Las tres funciones de abajo siguen recibiendo int*: pasales
    // stock.get(), el puntero crudo que unique_ptr administra por
    // dentro, sin ceder la propiedad del recurso.
    int* stock = crearInventario(cantidadProductos);
    stock[0] = 10;
    stock[1] = 5;
    stock[3] = 8;

    mostrarInventario(stock, cantidadProductos);
    std::cout << "Productos agotados: " << contarProductosAgotados(stock, cantidadProductos) << std::endl;
    std::cout << "Total de unidades: " << obtenerReporteFinal(stock, cantidadProductos) << std::endl;

    // TODO: elimina este delete[] por completo. Con unique_ptr, "stock"
    // libera su memoria solo cuando sale de alcance al terminar main.
    delete[] stock;
    return 0;
}
