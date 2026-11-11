#include <iostream>
#include <vector>
#include <optional>

// Salida esperada:
// Producto 210: precio 3.5, precio final 3.5
// Producto 120: precio 28, precio final 25.2
// Producto 999: no existe en el catalogo
// Producto 305: precio 0.25, precio final 0.25
// Productos en el catalogo: 4

// El catalogo del laboratorio de electronica. buscar devuelve un puntero al
// producto dentro del vector, o nullptr si no existe. Corre el archivo
// antes de cambiar nada.

class Producto {
    private:
        int codigo;
        double precio;
        // TODO 3: agrega un atributo std::optional<double> descuento: la
        // fraccion de descuento del producto (0.1 es 10%), que la mayoria
        // de los productos no tiene. Empieza vacio.
        std::optional<double> descuento;

    public:
        Producto(int nuevoCodigo, double nuevoPrecio) {
            codigo = nuevoCodigo;
            precio = nuevoPrecio;
            descuento = std::nullopt;
        }

        int getCodigo() {
            return codigo;
        }

        double getPrecio() {
            return precio;
        }

        // TODO 3: escribe void setDescuento(double fraccion), y cambia
        // precioFinal para que aplique el descuento si existe, con
        // value_or.
        void setDescuento(double fraccion) {
            descuento = fraccion;
        }

        double precioFinal() {
            double fraccionDescuento = descuento.value_or(0.0);
            return precio * (1.0 - fraccionDescuento);
        }
};

class Catalogo {
    private:
        std::vector<Producto> productos;
    public:
        void agregar(Producto producto) {
            productos.push_back(producto);
        }

        int cantidad() {
            return productos.size();
        }

        // TODO 1: devuelve std::optional<Producto> en vez de un puntero:
        // una copia del producto si existe, std::nullopt si no.
        std::optional<Producto> buscar(int codigo) {
            for (int i = 0; i < cantidad(); i++) {
                if (productos[i].getCodigo() == codigo) {
                    return productos[i];
                }
            }
            return std::nullopt;
        }
};

int main() {
    Catalogo catalogo;
    catalogo.agregar(Producto(305, 0.25));
    catalogo.agregar(Producto(210, 3.5));

    std::optional<Producto> encontrado = catalogo.buscar(210);

    Producto cable(120, 28.0);
    // TODO 3: antes de agregarlo, dale a cable un descuento de 0.1.
    cable.setDescuento(0.1);
    catalogo.agregar(cable);
    catalogo.agregar(Producto(410, 12.0));

    // TODO 2: con buscar devolviendo std::optional, pregunta si hay valor
    // antes de usarlo en cada consulta, e imprime "Producto N: no existe en
    // el catalogo" si no lo hay.
    if (encontrado.has_value()) {
        std::cout << "Producto 210: precio " << encontrado->getPrecio() << ", precio final " << encontrado->precioFinal() << std::endl;
    } else {
        std::cout << "Producto 210: no existe en el catalogo" << std::endl;
    }

    int consultas[3] = {120, 999, 305};
    for (int i = 0; i < 3; i++) {
        std::optional<Producto> producto = catalogo.buscar(consultas[i]);
        if (producto.has_value()) {
            std::cout << "Producto " << consultas[i] << ": precio " << producto->getPrecio() << ", precio final " << producto->precioFinal() << std::endl;
        } else {
            std::cout << "Producto " << consultas[i] << ": no existe en el catalogo" << std::endl;
        }
    }

    std::cout << "Productos en el catalogo: " << catalogo.cantidad() << std::endl;
    return 0;
}