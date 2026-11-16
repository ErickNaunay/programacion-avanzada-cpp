#include <iostream>
#include <stdexcept>
#include <thread>

#include "pedidos.h"

// Laboratorio Integrador II: un dia de la cafeteria. No cambies este main:
// al final verifica que no se perdio ni se duplico ningun pedido, y que el
// inventario cuadra.

const int CAJAS = 3;
const int PEDIDOS_POR_CAJA = 20000;
const int PRODUCTOS = 5;
const int UNIDADES_INICIALES[PRODUCTOS] = {30000, 30000, 30000, 30000, 900};

// Cada caja genera sus pedidos con su propia semilla: los mismos en cada
// corrida. Uno de cada 50 pide el producto 99, que no existe.
void caja(ColaDePedidos* cola, int numero) {
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

void cocinero(ColaDePedidos* cola, Inventario* inventario, Estadisticas* estadisticas) {
    std::optional<Pedido> pedido = cola->tomar();
    while (pedido) {
        try {
            if (inventario->descontar(pedido->producto, pedido->cantidad)) {
                estadisticas->anotarDespachado();
            } else {
                estadisticas->anotarSinStock();
            }
        } catch (const std::invalid_argument& e) {
            estadisticas->anotarInvalido();
        }
        pedido = cola->tomar();
    }
}

int main() {
    ColaDePedidos cola;
    Inventario inventario;
    Estadisticas estadisticas;
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
    std::thread k1(cocinero, &cola, &inventario, &estadisticas);
    std::thread k2(cocinero, &cola, &inventario, &estadisticas);
    k1.join();
    k2.join();

    int atendidos = estadisticas.getDespachados() + estadisticas.getSinStock() + estadisticas.getInvalidos();
    std::cout << "Pedidos atendidos: " << atendidos << std::endl;
    std::cout << "Pedidos invalidos: " << estadisticas.getInvalidos() << std::endl;
    std::cout << "Pedidos sin stock: " << estadisticas.getSinStock() << std::endl;
    bool negativo = false;
    for (int p = 1; p <= PRODUCTOS; p++) {
        if (inventario.unidades(p) < 0) {
            negativo = true;
        }
    }
    if (atendidos == CAJAS * PEDIDOS_POR_CAJA && cola.pendientes() == 0 && !negativo) {
        std::cout << "Cuadra: si" << std::endl;
    } else {
        std::cout << "Cuadra: no" << std::endl;
    }
    return 0;
}
