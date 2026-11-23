#include <iomanip>
#include <iostream>
#include <memory>
#include <optional>
#include <stdexcept>
#include <thread>
#include <vector>

#include "pedidos.h"
#include "productos.h"
#include "reporte.h"

// Laboratorio Integrador II: un dia de la cafeteria. No cambies este main:
// al final verifica que no se perdio ni se repitio ningun pedido, y que el
// inventario y las ventas cuadran.

const int CAJAS = 3;
const int PEDIDOS_POR_CAJA = 20000;
const int PRODUCTOS = 5;
const int UNIDADES_INICIALES[PRODUCTOS] = {30000, 30000, 30000, 30000, 900};

void armarCatalogo(Catalogo* catalogo) {
    std::unique_ptr<Bebida> cafe = std::make_unique<Bebida>();
    cafe->setDatos(1, 1.5, false);
    std::unique_ptr<Bebida> jugo = std::make_unique<Bebida>();
    jugo->setDatos(2, 2.0, true);
    std::unique_ptr<Plato> almuerzo = std::make_unique<Plato>();
    almuerzo->setDatos(3, 4.5);
    std::unique_ptr<Plato> galleta = std::make_unique<Plato>();
    galleta->setDatos(5, 1.0);

    Bebida jugoDelCombo;
    jugoDelCombo.setDatos(0, 2.0, true);
    Plato almuerzoDelCombo;
    almuerzoDelCombo.setDatos(0, 4.5);

    catalogo->agregar(std::move(cafe));
    catalogo->agregar(std::move(jugo));
    catalogo->agregar(std::move(almuerzo));
    catalogo->agregar(std::make_unique<Combo>(4, jugoDelCombo, almuerzoDelCombo));
    catalogo->agregar(std::move(galleta));

    // Dos productos que el catalogo tiene que rechazar.
    std::unique_ptr<Plato> repetido = std::make_unique<Plato>();
    repetido->setDatos(3, 5.0);
    std::unique_ptr<Plato> gratis = std::make_unique<Plato>();
    gratis->setDatos(6, 0);
    try {
        catalogo->agregar(std::move(repetido));
    } catch (const std::invalid_argument& e) {
        std::cout << "No se agrego: " << e.what() << std::endl;
    }
    try {
        catalogo->agregar(std::move(gratis));
    } catch (const std::invalid_argument& e) {
        std::cout << "No se agrego: " << e.what() << std::endl;
    }
}

// Cada caja genera sus pedidos con su propia semilla: los mismos en cada
// corrida. Uno de cada 50 pide el producto 99, que no existe.
void caja(ColaSegura<Pedido>* cola, int numero) {
    unsigned int semilla = 1000 + numero;
    for (int i = 0; i < PEDIDOS_POR_CAJA; i++) {
        semilla = semilla * 1103515245 + 12345;
        Pedido pedido;
        pedido.id = numero * PEDIDOS_POR_CAJA + i;
        pedido.producto = 1 + (semilla >> 8) % PRODUCTOS;
        pedido.cantidad = 1 + (semilla >> 16) % 3;
        if ((semilla >> 4) % 50 == 0) {
            pedido.producto = 99;
        }
        cola->agregar(pedido);
    }
}

void cocinero(ColaSegura<Pedido>* cola, Catalogo* catalogo, Inventario* inventario,
              Estadisticas* estadisticas, RegistroDeVentas* registro) {
    std::optional<Pedido> pedido = cola->tomar();
    while (pedido) {
        std::optional<double> precio = catalogo->precioDe(pedido->producto);
        if (!precio) {
            estadisticas->anotarInvalido();
        } else {
            try {
                if (inventario->descontar(pedido->producto, pedido->cantidad)) {
                    Venta venta;
                    venta.id = pedido->id;
                    venta.producto = pedido->producto;
                    venta.cantidad = pedido->cantidad;
                    venta.total = *precio * pedido->cantidad;
                    registro->anotar(venta);
                    estadisticas->anotarDespachado();
                } else {
                    estadisticas->anotarSinStock();
                }
            } catch (const std::invalid_argument& e) {
                estadisticas->anotarInvalido();
            }
        }
        pedido = cola->tomar();
    }
}

int main() {
    Catalogo catalogo;
    ColaSegura<Pedido> cola;
    Inventario inventario;
    Estadisticas estadisticas;
    RegistroDeVentas registro;

    armarCatalogo(&catalogo);
    std::cout << "Productos en el catalogo: " << catalogo.cantidad() << std::endl;
    for (int p = 0; p < PRODUCTOS; p++) {
        inventario.registrar(p + 1, UNIDADES_INICIALES[p]);
    }

    // Primero, las tres cajas a la vez.
    std::thread c1(caja, &cola, 0);
    std::thread c2(caja, &cola, 1);
    std::thread c3(caja, &cola, 2);
    c1.join();
    c2.join();
    c3.join();
    std::cout << "Pedidos en la cola: " << cola.pendientes() << std::endl;

    // Despues, los dos cocineros a la vez.
    std::thread k1(cocinero, &cola, &catalogo, &inventario, &estadisticas, &registro);
    std::thread k2(cocinero, &cola, &catalogo, &inventario, &estadisticas, &registro);
    k1.join();
    k2.join();

    int atendidos = estadisticas.getDespachados() + estadisticas.getSinStock() + estadisticas.getInvalidos();
    std::cout << "Pedidos atendidos: " << atendidos << std::endl;
    std::cout << "Pedidos invalidos: " << estadisticas.getInvalidos() << std::endl;
    std::cout << "Pedidos sin stock: " << estadisticas.getSinStock() << std::endl;

    // El reporte de cierre, ya con un solo hilo.
    std::vector<Venta> ventas = registro.todas();
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total vendido: " << totalVendido(ventas) << std::endl;
    std::optional<Venta> mayor = ventaMayor(ventas);
    if (mayor) {
        std::cout << "Venta mayor: " << mayor->total << std::endl;
    } else {
        std::cout << "Venta mayor: ninguna" << std::endl;
    }
    std::cout << "Ventas sobre 10: " << ventasSobre(ventas, 10) << std::endl;

    int totalVentas = ventas.size();
    bool cuadra = atendidos == CAJAS * PEDIDOS_POR_CAJA && cola.pendientes() == 0 &&
                  totalVentas == estadisticas.getDespachados() && idsSinRepetir(ventas);
    for (int p = 1; p <= PRODUCTOS; p++) {
        int restantes = inventario.unidades(p);
        if (restantes < 0 || restantes + unidadesVendidas(ventas, p) != UNIDADES_INICIALES[p - 1]) {
            cuadra = false;
        }
    }
    if (cuadra) {
        std::cout << "Cuadra: si" << std::endl;
    } else {
        std::cout << "Cuadra: no" << std::endl;
    }
    return 0;
}
