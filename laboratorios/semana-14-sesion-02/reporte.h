#pragma once

#include <algorithm>
#include <numeric>
#include <optional>
#include <set>
#include <vector>

#include "pedidos.h"

// Laboratorio Integrador II: el reporte de cierre del dia. Se calcula al
// final, con un solo hilo, sobre la copia de las ventas.

// TODO 8: escribe las cuatro funciones sin ciclos escritos a mano: cada una
// es un algoritmo de <algorithm> o <numeric> con una lambda.

// La suma del total de todas las ventas.
inline double totalVendido(std::vector<Venta> ventas) {
    return 0;
}

// La venta de mayor total, o vacio si no hay ventas.
inline std::optional<Venta> ventaMayor(std::vector<Venta> ventas) {
    return std::nullopt;
}

// Cuantas ventas tienen un total mayor que limite.
inline int ventasSobre(std::vector<Venta> ventas, double limite) {
    return 0;
}

// Cuantas unidades de ese producto se vendieron en total.
inline int unidadesVendidas(std::vector<Venta> ventas, int producto) {
    return 0;
}

// true si ningun id de pedido aparece en dos ventas.
inline bool idsSinRepetir(std::vector<Venta> ventas) {
    std::set<int> ids;
    int total = ventas.size();
    for (int i = 0; i < total; i++) {
        ids.insert(ventas[i].id);
    }
    int distintos = ids.size();
    return distintos == total;
}
