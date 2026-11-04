#include <iostream>
#include <vector>

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
    public:
        Producto(int nuevoCodigo, double nuevoPrecio) {
            codigo = nuevoCodigo;
            precio = nuevoPrecio;
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
        double precioFinal() {
            return precio;
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
        Producto* buscar(int codigo) {
            for (int i = 0; i < cantidad(); i++) {
                if (productos[i].getCodigo() == codigo) {
                    return &productos[i];
                }
            }
            return nullptr;
        }
};

int main() {
    Catalogo catalogo;
    catalogo.agregar(Producto(305, 0.25));
    catalogo.agregar(Producto(210, 3.5));

    Producto* encontrado = catalogo.buscar(210);

    Producto cable(120, 28.0);
    // TODO 3: antes de agregarlo, dale a cable un descuento de 0.1.
    catalogo.agregar(cable);
    catalogo.agregar(Producto(410, 12.0));

    // TODO 2: con buscar devolviendo std::optional, pregunta si hay valor
    // antes de usarlo en cada consulta, e imprime "Producto N: no existe en
    // el catalogo" si no lo hay.
    std::cout << "Producto 210: precio " << encontrado->getPrecio() << ", precio final " << encontrado->precioFinal() << std::endl;

    int consultas[3] = {120, 999, 305};
    for (int i = 0; i < 3; i++) {
        Producto* producto = catalogo.buscar(consultas[i]);
        std::cout << "Producto " << consultas[i] << ": precio " << producto->getPrecio() << ", precio final " << producto->precioFinal() << std::endl;
    }

    std::cout << "Productos en el catalogo: " << catalogo.cantidad() << std::endl;
    return 0;
}
