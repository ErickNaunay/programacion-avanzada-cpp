// Ejercicio 30: la Tienda del campus (desde cero, integrador del PSet)
//
// Este archivo no tiene codigo de partida. Escribe tus propios includes,
// tus propias clases, tu plantilla y tu propio main(). Es el ejercicio mas
// largo del PSet a proposito: junta polimorfismo, una clase abstracta,
// unique_ptr dentro de un vector, una plantilla, algoritmos con lambdas,
// excepciones y std::optional.
//
// Producto: clase abstracta. Atributos privados codigo (int) y precio
// (double). Metodo void setDatos(int c, double p) que los asigna sin
// validar, getters int getCodigo() y double getPrecio(), destructor virtual
// vacio y una funcion virtual pura double precioFinal().
//
// Tres clases derivadas, publicas, cada una con un constructor que llama
// setDatos:
// - ProductoNormal(int codigo, double precio): precioFinal es el precio.
// - ProductoEnOferta(int codigo, double precio, double porcentaje):
//   precioFinal es el precio con el porcentaje de descuento aplicado
//   (precio * (1 - porcentaje / 100)).
// - ProductoPorPeso(int codigo, double precioPorKilo, double kilos): el
//   precio guardado es el precio por kilo, y precioFinal es precio * kilos.
//
// Una plantilla de funcion T mayorDe(std::vector<T> valores) que devuelve
// el mayor valor del vector con std::max_element (o T() si esta vacio).
//
// Tienda: atributo privado std::vector<std::unique_ptr<Producto>>
// productos. Metodos:
// - void agregar(std::unique_ptr<Producto> producto): si el precio del
//   producto es menor o igual a 0, lanza std::invalid_argument("precio no
//   positivo"); si ya hay un producto con el mismo codigo, lanza
//   std::invalid_argument("codigo repetido"). Si no, lo mueve al final del
//   vector con std::move.
// - int cantidad(): cuantos productos hay.
// - std::optional<double> precioDe(int codigo): el precio final del
//   producto con ese codigo, o vacio si no esta.
// - std::vector<double> preciosFinales(): los precios finales, en el orden
//   en que se agregaron.
// - double total(): la suma de los precios finales, con std::accumulate
//   sobre preciosFinales().
// - int cuantosBajo(double limite): cuantos precios finales son menores
//   que limite, con std::count_if y una lambda que captura limite.
// - std::optional<int> codigoMasCaro(): el codigo del producto de mayor
//   precio final, o vacio si no hay productos.
//
// Para recorrer el vector de unique_ptr usa un ciclo por posicion
// (productos[i]->precioFinal()): un for de rango copiaria cada unique_ptr,
// y un unique_ptr no se puede copiar.
//
// En main(), con los textos de la salida esperada:
// 1. Agrega, cada uno en su propio try con un catch de
//    std::invalid_argument por referencia constante que imprime "No se
//    agrego: " y e.what(): un ProductoNormal 101 a 2.5, un ProductoEnOferta
//    205 a 10 con 20% de descuento, un ProductoPorPeso 310 a 4 por kilo con
//    1.5 kilos, un ProductoNormal 101 a 3, y un ProductoNormal 400 a 0. Crea
//    cada uno con std::make_unique y pasalo con std::move.
// 2. Imprime la cantidad de productos, el total, cuantos cuestan menos de
//    7, el codigo del mas caro (con *), el precio del 310 (con value_or(0))
//    y el del 999 (con has_value: si no esta, imprime "no existe").
// 3. Imprime el mayor precio final usando mayorDe sobre preciosFinales().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio30 ejercicio30_tienda_integrador.cpp
// Ejecutar: ./ejercicio30
//
// Salida esperada:
// No se agrego: codigo repetido
// No se agrego: precio no positivo
// Productos: 3
// Total: 16.5
// Cuestan menos de 7: 2
// Mas caro: 205
// Precio del 310: 6
// Precio del 999: no existe
// Mayor precio final: 8

#include <iostream>
#include <optional>
#include <memory>
#include <algorithm>
#include <vector>
#include <numeric>
#include <stdexcept>
#include <utility>

class Producto {
private:
    int codigo;
    double precio;

public:
    void setDatos(int c, double p) {
        codigo = c;
        precio = p;
    }

    int getCodigo() const {
        return codigo;
    }

    double getPrecio() const {
        return precio;
    }

    virtual double precioFinal() = 0;
    virtual ~Producto() = default;
};

class ProductoNormal : public Producto {
public:
    ProductoNormal(int codigo, double precio) {
        setDatos(codigo, precio);
    }

    double precioFinal() override {
        return getPrecio();
    }
};

class ProductoEnOferta : public Producto {
private:
    double porcentaje;

public:
    ProductoEnOferta(int codigo, double precio, double porcentaje)
        : porcentaje(porcentaje) {
        setDatos(codigo, precio);
    }

    double precioFinal() override {
        return getPrecio() * (1 - porcentaje / 100);
    }
};

class ProductoPorPeso : public Producto {
private:
    double kilos;

public:
    ProductoPorPeso(int codigo, double precioPorKilo, double kilos)
        : kilos(kilos) {
        setDatos(codigo, precioPorKilo);
    }

    double precioFinal() override {
        return getPrecio() * kilos;
    }
};

class Tienda {
private:
    std::vector<std::unique_ptr<Producto>> productos;
public:
    void agregar(std::unique_ptr<Producto> producto) {
        if (producto->getPrecio() <= 0) {
            throw std::invalid_argument("precio no positivo");
        }
        for (const auto& p : productos) {   
            if (p->getCodigo() == producto->getCodigo()) {
                throw std::invalid_argument("codigo repetido");
            }
        }
        productos.push_back(std::move(producto));
    }       

    int cantidad() const {
        return static_cast<int>(productos.size());
    }

    std::optional<double> precioDe(int codigo) const {
        for (const auto& producto : productos) {
            if (producto->getCodigo() == codigo) {
                return producto->precioFinal();
            }
        }
        return std::nullopt;
    }

    std::vector<double> preciosFinales() const {
        std::vector<double> precios;
        precios.reserve(productos.size());
        for (std::size_t i = 0; i < productos.size(); ++i) {
            precios.push_back(productos[i]->precioFinal());
        }
        return precios;
    }

    double total() const {
        const std::vector<double> precios = preciosFinales();
        return std::accumulate(precios.begin(), precios.end(), 0.0);
    }

    int cuantosBajo(double limite) const {
        const std::vector<double> precios = preciosFinales();
        return static_cast<int>(std::count_if(
            precios.begin(), precios.end(),
            [limite](double precio) { return precio < limite; }));
    }

    std::optional<int> codigoMasCaro() const {
        if (productos.empty()) {
            return std::nullopt;
        }

        std::size_t indiceMayor = 0;
        for (std::size_t i = 1; i < productos.size(); ++i) {
            if (productos[i]->precioFinal() >
                productos[indiceMayor]->precioFinal()) {
                indiceMayor = i;
            }
        }
        return productos[indiceMayor]->getCodigo();
    }
};

template <typename T>
T mayorDe(std::vector<T> valores) {
    if (valores.empty()) {
        return T();
    }
    return *std::max_element(valores.begin(), valores.end());
}

int main() {
    Tienda tienda;

    try {
        tienda.agregar(std::make_unique<ProductoNormal>(101, 2.5));
    } catch (const std::invalid_argument& e) {
        std::cout << "No se agrego: " << e.what() << std::endl;
    }
    try {
        tienda.agregar(std::make_unique<ProductoEnOferta>(205, 10, 20));
    } catch (const std::invalid_argument& e) {
        std::cout << "No se agrego: " << e.what() << std::endl;
    }
    try {
        tienda.agregar(std::make_unique<ProductoPorPeso>(310, 4, 1.5));
    } catch (const std::invalid_argument& e) {
        std::cout << "No se agrego: " << e.what() << std::endl;
    }
    try {
        tienda.agregar(std::make_unique<ProductoNormal>(101, 3));
    } catch (const std::invalid_argument& e) {
        std::cout << "No se agrego: " << e.what() << std::endl;
    }
    try {
        tienda.agregar(std::make_unique<ProductoNormal>(400, 0));
    } catch (const std::invalid_argument& e) {
        std::cout << "No se agrego: " << e.what() << std::endl;
    }

    std::cout << "Productos: " << tienda.cantidad() << std::endl;
    std::cout << "Total: " << tienda.total() << std::endl;
    std::cout << "Cuestan menos de 7: " << tienda.cuantosBajo(7) << std::endl;
    const auto codigo = tienda.codigoMasCaro();
    if (codigo.has_value()) {
        std::cout << "Mas caro: " << *codigo << std::endl;
    }
    std::cout << "Precio del 310: " << tienda.precioDe(310).value_or(0)
              << std::endl;
    const auto precioInexistente = tienda.precioDe(999);
    if (precioInexistente.has_value()) {
        std::cout << "Precio del 999: " << *precioInexistente << std::endl;
    } else {
        std::cout << "Precio del 999: no existe" << std::endl;
    }
    std::cout << "Mayor precio final: " << mayorDe(tienda.preciosFinales())
              << std::endl;
    return 0;
}