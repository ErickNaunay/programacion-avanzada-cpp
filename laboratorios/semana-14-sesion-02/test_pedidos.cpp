#include <gtest/gtest.h>

#include <memory>
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

// TODO 9: escribe estas pruebas. Las funciones de ayuda de arriba ya estan.
// - Bebida, GrandeCuestaUnaVezYMedia: la misma base de 2.0, chica y grande.
// - Combo, DescuentaDiezPorCientoATravesDeLaBase: un Combo de una bebida
//   grande de 2.0 y un plato de 4.5, guardado en un
//   std::unique_ptr<Producto>, cuesta 6.75 (EXPECT_NEAR).
// - Catalogo, CodigoRepetidoLanzaSinAgregar: el segundo producto con el
//   mismo codigo lanza std::invalid_argument, la cantidad sigue en 1 y el
//   precio es el del primero.
// - Catalogo, PrecioNoPositivoLanza: con precio 0, y el catalogo queda
//   vacio.
// - Catalogo, ProductoDesconocidoNoTienePrecio: precioDe(99) esta vacio.
// - ColaSegura, VaciaDevuelveNullopt: con double; tomar() no tiene valor y
//   pendientes() es 0.
// - Inventario, NoDescuentaSiNoAlcanza: con 3 unidades, descontar 5
//   devuelve false y las unidades siguen en 3.
// - Inventario, ProductoDesconocidoLanza.
// - Inventario, CantidadNoPositivaLanza: con 0 y con -2, y las unidades no
//   cambian.
// - Reporte, TotalMayorYVentasSobre: tres ventas de 13.5, 3.0 y 20.25;
//   el total, el id de la mayor, cuantas pasan de 10 y las unidades
//   vendidas de un producto.
// - Reporte, SinVentasNoHayMayor: con un vector vacio.
// - ColaSegura, DosHilosNoPierdenElementos: dos hilos con agregarMil a la
//   vez; al final quedan 2000 pendientes.
// - Inventario, DosHilosNoVendenDeMas: un producto con 1000 unidades, dos
//   hilos con venderMil a la vez; al final quedan 0 unidades, y entre los
//   dos lograron exactamente 1000.
