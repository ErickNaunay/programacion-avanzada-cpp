#pragma once

#include <atomic>
#include <map>
#include <mutex>
#include <optional>
#include <stdexcept>
#include <vector>

// Laboratorio Integrador II: los pedidos de la cafeteria del campus.
//
// Tres cajas dejan pedidos en una cola al mismo tiempo. Despues, dos
// cocineros sacan pedidos de la cola al mismo tiempo, descuentan el
// inventario, registran cada venta y anotan el resultado. Cada clase de este
// archivo la usan varios hilos a la vez.

struct Pedido {
    int id;
    int producto;
    int cantidad;
};

struct Venta {
    int id;
    int producto;
    int cantidad;
    double total;
};

// Una cola que pueden usar varios hilos a la vez.
//
// TODO 3: hoy la cola solo guarda Pedido. main la usa como
// ColaSegura<Pedido> y las pruebas como ColaSegura<int> y
// ColaSegura<double>: conviertela en una plantilla de clase. Hasta que lo
// hagas, el proyecto no compila.
class ColaSegura {
public:
    ColaSegura() {
        siguiente = 0;
    }

    // Deja un elemento al final de la cola.
    void agregar(Pedido elemento) {
        // TODO 4: tres cajas agregan a la vez. Protege el push_back con el
        // candado de la clase.
        elementos.push_back(elemento);
    }

    // Saca el elemento mas antiguo que no se haya sacado todavia, o
    // std::nullopt si ya no quedan.
    std::optional<Pedido> tomar() {
        // TODO 4: dos cocineros toman a la vez. Mirar si quedan elementos y
        // avanzar siguiente tienen que pasar juntos, sin que otro hilo se
        // meta en medio.
        int total = elementos.size();
        if (siguiente >= total) {
            return std::nullopt;
        }
        Pedido elemento = elementos[siguiente];
        siguiente++;
        return elemento;
    }

    // Cuantos elementos quedan sin tomar.
    int pendientes() {
        std::lock_guard<std::mutex> guardia(candado);
        int total = elementos.size();
        return total - siguiente;
    }

private:
    std::vector<Pedido> elementos;
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
        // TODO 5: escribe descontar. Dos cocineros pueden descontar el mismo
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
        // TODO 6: los tres contadores empiezan en 0.
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
    // TODO 6: los dos cocineros anotan a la vez, y cada anotacion es una
    // sola operacion sobre un numero: cambia el tipo de los tres contadores
    // para que no se pierda ninguna, sin usar un mutex.
    int despachados;
    int sinStock;
    int invalidos;
};

class RegistroDeVentas {
public:
    void anotar(Venta venta) {
        // TODO 7: los dos cocineros anotan ventas a la vez.
        ventas.push_back(venta);
    }

    // Una copia de todas las ventas anotadas hasta ahora.
    std::vector<Venta> todas() {
        std::lock_guard<std::mutex> guardia(candado);
        return ventas;
    }

private:
    std::vector<Venta> ventas;
    std::mutex candado;
};
