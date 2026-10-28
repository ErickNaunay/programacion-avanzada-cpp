#include <iostream>
#include <map>
#include <vector>
#include <set>

class Bodega {
private:
    std::map<int, int> stock;
    std::vector<int> retiros;
    std::set<int> agotados;

public:
    void ingresar(int codigo, int cantidad) {
        stock[codigo] += cantidad;
    }

    bool retirar(int codigo, int cantidad) {
        auto it = stock.find(codigo);

        if (it == stock.end()) {
            return false;
        }

        if (it->second < cantidad) {
            return false;
        }

        it->second -= cantidad;
        retiros.push_back(codigo);

        if (it->second == 0) {
            agotados.insert(codigo);
        }

        return true;
    }

    int stockDe(int codigo) {
        auto it = stock.find(codigo);

        if (it == stock.end()) {
            return 0;
        }

        return it->second;
    }

    int cantidadDeProductos() {
        return static_cast<int>(stock.size());
    }

    int retiroNumero(int posicion) {
        return retiros[posicion];
    }

    void imprimirStock() {
        std::cout << "Stock:";

        for (auto par : stock) {
            std::cout << " "
                      << par.first
                      << "="
                      << par.second;
        }

        std::cout << std::endl;
    }

    void imprimirRetiros() {
        std::cout << "Retiros:";

        for (int codigo : retiros) {
            std::cout << " " << codigo;
        }

        std::cout << std::endl;
    }

    void imprimirAgotados() {
        std::cout << "Agotados alguna vez:";

        for (int codigo : agotados) {
            std::cout << " " << codigo;
        }

        std::cout << std::endl;
    }
};


void informarRetiro(int codigo, int cantidad, bool aceptado) {
    std::cout << "Retirar " << cantidad << " de " << codigo << ": ";
    if (aceptado) {
        std::cout << "aceptado" << std::endl;
    } else {
        std::cout << "rechazado" << std::endl;
    }
}

int main() {
    Bodega bodega;
    bodega.ingresar(305, 10);
    bodega.ingresar(120, 2);
    bodega.ingresar(210, 5);
    bodega.imprimirStock();

    informarRetiro(120, 1, bodega.retirar(120, 1));
    informarRetiro(305, 4, bodega.retirar(305, 4));
    informarRetiro(120, 1, bodega.retirar(120, 1));
    informarRetiro(120, 1, bodega.retirar(120, 1));
    informarRetiro(999, 1, bodega.retirar(999, 1));
    informarRetiro(210, 5, bodega.retirar(210, 5));

    bodega.ingresar(120, 3);
    std::cout << "Reingreso de 3 unidades de 120" << std::endl;
    informarRetiro(120, 3, bodega.retirar(120, 3));

    bodega.imprimirStock();
    std::cout << "Stock de 999: " << bodega.stockDe(999) << std::endl;
    std::cout << "Productos registrados: " << bodega.cantidadDeProductos() << std::endl;
    bodega.imprimirRetiros();
    std::cout << "Tercer retiro: " << bodega.retiroNumero(2) << std::endl;
    bodega.imprimirAgotados();

    return 0;
}
