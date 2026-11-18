#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Salida esperada:
// Total recaudado: 146.5
// Ventas de al menos 20: 3
// Primera venta de 210: 4 unidades
// No hay ventas de 999
// Ordenadas por total: 120 (56) 410 (36) 120 (28) 210 (14) 305 (10) 305 (2.5)

// Las ventas de la tienda del laboratorio de electronica. Resuelve cada
// TODO con un algoritmo de la STL, sin escribir ningun loop propio salvo
// el que ya imprime las ventas ordenadas. Incluye arriba los encabezados
// que necesites.

class Venta {
    private:
        int codigo;
        int cantidad;
        double precioUnitario;
    public:
        Venta(int nuevoCodigo, int nuevaCantidad, double nuevoPrecio) {
            codigo = nuevoCodigo;
            cantidad = nuevaCantidad;
            precioUnitario = nuevoPrecio;
        }

        // Se agregan const qualifiers para poder invocar los getters en objetos const
        int getCodigo() const {
            return codigo;
        }

        int getCantidad() const {
            return cantidad;
        }

        double getTotal() const {
            return cantidad * precioUnitario;
        }
};

int main() {
    std::vector<Venta> ventas = {
        Venta(305, 10, 0.25),
        Venta(120, 2, 28.0),
        Venta(210, 4, 3.5),
        Venta(120, 1, 28.0),
        Venta(410, 3, 12.0),
        Venta(305, 40, 0.25),
    };
    double umbral = 20.0;

    // TODO: el total recaudado (la suma de getTotal() de todas las
    // ventas). Imprime "Total recaudado: ".
    double totalRecaudado = std::accumulate(ventas.begin(), ventas.end(), 0.0, [](double acc, const Venta& v) {
        return acc + v.getTotal();
    });
    std::cout << "Total recaudado: " << totalRecaudado << std::endl;

    // TODO: cuantas ventas tienen un total de al menos umbral. Imprime
    // "Ventas de al menos 20: ".
    int ventasDeAlMenos20 = std::count_if(ventas.begin(), ventas.end(), [umbral](const Venta& v) {
        return v.getTotal() >= umbral;
    });
    std::cout << "Ventas de al menos 20: " << ventasDeAlMenos20 << std::endl;

    // TODO: busca la primera venta del producto 210 e imprime
    // "Primera venta de 210: N unidades". Despues busca una venta del
    // producto 999: si no existe, imprime "No hay ventas de 999". Escribe
    // la busqueda de modo que el codigo buscado sea una variable, no un
    // numero escrito dentro de la lambda.
    int codigoBuscado = 210;
    auto primeraVenta210 = std::find_if(ventas.begin(), ventas.end(), [codigoBuscado](const Venta& v) {
        return v.getCodigo() == codigoBuscado;
    });
    if (primeraVenta210 != ventas.end()) {
        std::cout << "Primera venta de " << codigoBuscado << ": " << primeraVenta210->getCantidad() << " unidades" << std::endl;
    }

    int codigoBuscado2 = 999;
    auto primeraVenta999 = std::find_if(ventas.begin(), ventas.end(), [codigoBuscado2](const Venta& v) {
        return v.getCodigo() == codigoBuscado2;
    });
    if (primeraVenta999 == ventas.end()) {
        std::cout << "No hay ventas de " << codigoBuscado2 << std::endl;
    }   

    // TODO: ordena ventas de mayor a menor total.
    std::sort(ventas.begin(), ventas.end(), [](const Venta& a, const Venta& b) {
        return a.getTotal() > b.getTotal();
    });

    std::cout << "Ordenadas por total:";
    for (Venta v : ventas) {
        std::cout << " " << v.getCodigo() << " (" << v.getTotal() << ")";
    }
    std::cout << std::endl;

    return 0;
}