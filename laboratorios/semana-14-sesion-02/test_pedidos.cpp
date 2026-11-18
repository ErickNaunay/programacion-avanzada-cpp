#include <gtest/gtest.h>

#include <stdexcept>
#include <thread>

#include "pedidos.h"

// Pruebas de las tres clases. Las dos primeras ya estan escritas; las
// demas te tocan (ver el README).

TEST(ColaDePedidos, EntregaEnElOrdenEnQueLlegaron) {
    ColaDePedidos cola;
    Pedido primero;
    primero.id = 1;
    primero.producto = 2;
    primero.cantidad = 1;
    Pedido segundo;
    segundo.id = 2;
    segundo.producto = 3;
    segundo.cantidad = 2;
    cola.agregar(primero);
    cola.agregar(segundo);
    EXPECT_EQ(cola.tomar()->id, 1);
    EXPECT_EQ(cola.tomar()->id, 2);
}

TEST(Inventario, DescuentaCuandoAlcanza) {
    Inventario inventario;
    inventario.registrar(1, 10);
    EXPECT_TRUE(inventario.descontar(1, 4));
    EXPECT_EQ(inventario.unidades(1), 6);
}

// TODO 5: escribe estas pruebas.
// - ColaDePedidos, VaciaDevuelveNullopt: tomar() en una cola vacia no
//   tiene valor, y pendientes() es 0.
// - Inventario, NoDescuentaSiNoAlcanza: con 3 unidades, descontar 5
//   devuelve false y las unidades siguen en 3.
// - Inventario, ProductoDesconocidoLanza: EXPECT_THROW con
//   std::invalid_argument.
// - Inventario, CantidadNoPositivaLanza: con 0 y con -2.
// - Inventario, DosHilosNoVendenDeMas: un producto con 1000 unidades, dos
//   hilos que intentan descontar 1 unidad 1000 veces cada uno; al final
//   quedan 0 unidades, y entre los dos lograron exactamente 1000.
