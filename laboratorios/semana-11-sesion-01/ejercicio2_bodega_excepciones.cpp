#include <iostream>
#include <map>

// Salida esperada:
// Stock: 120=2 210=5 305=10
// Pedido de 1 x 120: despachado
// Pedido de 0 x 305: rechazado, cantidad no positiva
// Pedido de 1 x 999: rechazado, codigo desconocido
// Pedido de 5 x 120: rechazado, stock insuficiente
// Pedido de 5 x 210: despachado
// Stock: 120=1 210=0 305=10
// Stock de 305: 10
// Stock de 999: no registrado

// La bodega de la Semana 10, reducida al stock. retirar devuelve false
// cuando no puede retirar, y quien llama no sabe por que.

class Bodega {
    private:
        std::map<int, int> stock;
    public:
        void ingresar(int codigo, int cantidad) {
            stock[codigo] = stock[codigo] + cantidad;
        }

        // TODO 1: cambia retirar para que devuelva void y lance una
        // excepcion en cada caso en que hoy devuelve false:
        // - cantidad menor o igual a 0: std::invalid_argument, "cantidad no positiva";
        // - codigo que no existe: std::out_of_range, "codigo desconocido";
        // - stock menor que cantidad: std::runtime_error, "stock insuficiente".
        // Ningun caso rechazado puede modificar el stock.
        bool retirar(int codigo, int cantidad) {
            if (cantidad <= 0) {
                return false;
            }
            if (stock.count(codigo) == 0) {
                return false;
            }
            if (stock[codigo] < cantidad) {
                return false;
            }
            stock[codigo] = stock[codigo] - cantidad;
            return true;
        }

        // TODO 2: lee el stock con stock.at(codigo), sin revisar antes con
        // count: si el codigo no existe, que la excepcion salga de aqui.
        int stockDe(int codigo) {
            if (stock.count(codigo) == 0) {
                return -1;
            }
            return stock[codigo];
        }

        void imprimirStock() {
            std::cout << "Stock:";
            for (auto par : stock) {
                std::cout << " " << par.first << "=" << par.second;
            }
            std::cout << std::endl;
        }
};

int main() {
    Bodega bodega;
    bodega.ingresar(305, 10);
    bodega.ingresar(120, 2);
    bodega.ingresar(210, 5);
    bodega.imprimirStock();

    int codigos[5] = {120, 305, 999, 120, 210};
    int cantidades[5] = {1, 0, 1, 5, 5};
    for (int i = 0; i < 5; i++) {
        // TODO 3: con try/catch, imprime "despachado" si retirar no lanza
        // nada, o "rechazado, " y el mensaje de la excepcion si lanza.
        std::cout << "Pedido de " << cantidades[i] << " x " << codigos[i] << ": ";
        if (bodega.retirar(codigos[i], cantidades[i])) {
            std::cout << "despachado" << std::endl;
        } else {
            std::cout << "rechazado" << std::endl;
        }
    }

    bodega.imprimirStock();

    // TODO 4: imprime el stock de 305 y el de 999. Si stockDe lanza
    // std::out_of_range, imprime "no registrado" en vez del numero.
    std::cout << "Stock de 305: " << bodega.stockDe(305) << std::endl;
    std::cout << "Stock de 999: " << bodega.stockDe(999) << std::endl;

    return 0;
}
