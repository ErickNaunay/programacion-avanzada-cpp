#pragma once

#include <atomic>
#include <map>
#include <mutex>
#include <optional>
#include <stdexcept>
#include <vector>

// Laboratorio Integrador II: los pedidos de la cafeteria del campus.
//
// Tres cajas toman pedidos al mismo tiempo y los dejan en una cola. Despues,
// dos cocineros sacan pedidos de la cola al mismo tiempo, descuentan los
// productos del inventario y anotan el resultado en las estadisticas.
// Cada clase de este archivo la usan varios hilos a la vez.

struct Pedido {
    int id;
    int producto;
    int cantidad;
};

class ColaDePedidos {
public:
    ColaDePedidos() {
        siguiente = 0;
    }

    // Deja un pedido al final de la cola.
    void agregar(Pedido pedido) {
        // TODO 1: la cola la usan tres cajas a la vez. Protege el push_back
        // con el candado de la clase.
        pedidos.push_back(pedido);
    }

    // Saca el pedido mas antiguo que no se haya sacado todavia, o
    // std::nullopt si ya no quedan.
    std::optional<Pedido> tomar() {
        // TODO 2: dos cocineros toman a la vez. Mirar si quedan pedidos y
        // avanzar siguiente tienen que pasar juntos, sin que otro hilo
        // se meta en medio.
        int total = pedidos.size();
        if (siguiente >= total) {
            return std::nullopt;
        }
        Pedido pedido = pedidos[siguiente];
        siguiente++;
        return pedido;
    }

    // Cuantos pedidos quedan sin tomar.
    int pendientes() {
        std::lock_guard<std::mutex> guardia(candado);
        int total = pedidos.size();
        return total - siguiente;
    }

private:
    std::vector<Pedido> pedidos;
    int siguiente;
    std::mutex candado;
};

class Inventario {
public:
    // Registra un producto con sus unidades iniciales.
    void registrar(int producto, int unidades) {
        std::lock_guard<std::mutex> guardia(candado);
        stock[producto] = unidades;
    }

    // Descuenta la cantidad del producto si alcanza, y devuelve true. Si no
    // alcanza, no descuenta nada y devuelve false. Lanza
    // std::invalid_argument si el producto no existe o si la cantidad no es
    // positiva.
    bool descontar(int producto, int cantidad) {
        // TODO 3: escribe descontar. Dos cocineros pueden descontar el mismo
        // producto a la vez: preguntar si alcanza y restar son una sola
        // seccion critica. Si lanzas una excepcion con el candado tomado,
        // ¿quien lo suelta?
        return false;
    }

    // Unidades que quedan del producto (0 si no existe).
    int unidades(int producto) {
        std::lock_guard<std::mutex> guardia(candado);
        if (stock.count(producto) == 0) {
            return 0;
        }
        return stock[producto];
    }

private:
    std::map<int, int> stock;
    std::mutex candado;
};

class Estadisticas {
public:
    Estadisticas() {
        // TODO 4: los tres contadores empiezan en 0.
    }

    void anotarDespachado() {
        despachados++;
    }

    void anotarSinStock() {
        sinStock++;
    }

    void anotarInvalido() {
        invalidos++;
    }

    int getDespachados() {
        return despachados;
    }

    int getSinStock() {
        return sinStock;
    }

    int getInvalidos() {
        return invalidos;
    }

private:
    // TODO 4: los dos cocineros anotan a la vez, y cada anotacion es una
    // sola operacion sobre un numero: cambia el tipo de los tres contadores
    // para que no se pierda ninguna.
    int despachados;
    int sinStock;
    int invalidos;
};
