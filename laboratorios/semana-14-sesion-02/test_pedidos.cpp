#include <gtest/gtest.h>

#include <atomic>
#include <stdexcept>
#include <thread>
#include <vector>

#include "pedidos.h"
#include "productos.h"
#include "reporte.h"

void agregarMil(ColaSegura<int>* cola) {
    for (int i = 0; i < 1000; i++) {
        cola->agregar(i);
    }
}

void venderMil(Inventario* inventario, int* logradas) {
    for (int i = 0; i < 1000; i++) {
        if (inventario->descontar(1, 1)) {
            (*logradas)++;
        }
    }
}

Venta crearVenta(int id, int producto, int cantidad, double total) {
    Venta venta;
    venta.id = id;
    venta.producto = producto;
    venta.cantidad = cantidad;
    venta.total = total;
    return venta;
}

TEST(ColaSegura, EntregaEnElOrdenEnQueLlegaron) {
    ColaSegura<int> cola;
    cola.agregar(7);
    cola.agregar(9);
    EXPECT_EQ(cola.tomar().value(), 7);
    EXPECT_EQ(cola.tomar().value(), 9);
}

TEST(Inventario, DescuentaCuandoAlcanza) {
    Inventario inventario;
    inventario.registrar(1, 10);
    EXPECT_TRUE(inventario.descontar(1, 4));
    EXPECT_EQ(inventario.unidades(1), 6);
}

TEST(ColaDePedidos, VaciaDevuelveNullopt) {
    ColaDePedidos cola;
    EXPECT_FALSE(cola.tomar().has_value());
    EXPECT_EQ(cola.pendientes(), 0);
}

TEST(Inventario, NoDescuentaSiNoAlcanza) {
    Inventario inventario;
    inventario.registrar(1, 3);
    EXPECT_FALSE(inventario.descontar(1, 5));
    EXPECT_EQ(inventario.unidades(1), 3);
}

TEST(Inventario, ProductoDesconocidoLanza) {
    Inventario inventario;
    EXPECT_THROW(inventario.descontar(99, 1), std::invalid_argument);
}

TEST(Inventario, CantidadNoPositivaLanza) {
    Inventario inventario;
    inventario.registrar(1, 10);
    EXPECT_THROW(inventario.descontar(1, 0), std::invalid_argument);
    EXPECT_THROW(inventario.descontar(1, -2), std::invalid_argument);
}

TEST(Inventario, DosHilosNoVendenDeMas) {
    Inventario inventario;
    inventario.registrar(1, 1000);
    std::atomic<int> exitosos{0};

    auto trabajador = [&]() {
        for (int i = 0; i < 1000; i++) {
            if (inventario.descontar(1, 1)) {
                exitosos++;
            }
        }
    };

    std::thread t1(trabajador);
    std::thread t2(trabajador);
    t1.join();
    t2.join();

    EXPECT_EQ(inventario.unidades(1), 0);
    EXPECT_EQ(exitosos.load(), 1000);
}
