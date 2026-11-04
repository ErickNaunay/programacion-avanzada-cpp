#include <iostream>
#include <map>
#include <vector>
#include <set>

// Salida esperada:
// Stock: 120=2 210=5 305=10
// Retirar 1 de 120: aceptado
// Retirar 4 de 305: aceptado
// Retirar 1 de 120: aceptado
// Retirar 1 de 120: rechazado
// Retirar 1 de 999: rechazado
// Retirar 5 de 210: aceptado
// Reingreso de 3 unidades de 120
// Retirar 3 de 120: aceptado
// Stock: 120=0 210=0 305=6
// Stock de 999: 0
// Productos registrados: 3
// Retiros: 120 305 120 210 120
// Tercer retiro: 120
// Agotados alguna vez: 120 210

// TODO: escribe la clase Bodega, la bodega de componentes del laboratorio
// de electronica. Cada producto se identifica con un codigo (int).
// Tu decides que contenedor de la STL usa cada atributo: elige segun
// como se consulta y como se modifica cada dato, e incluye arriba los
// encabezados que necesites.
//
// Atributos privados:
// - El stock de cada codigo.
// - El historial de retiros: el codigo de cada retiro aceptado, en el
//   orden en que ocurrio, con repeticiones.
// - Los codigos que se quedaron en 0 alguna vez, sin repetir, ordenados
//   de menor a mayor.
//
// Metodos publicos:
// - void ingresar(int codigo, int cantidad): suma cantidad al stock del
//   codigo (si el codigo es nuevo, empieza en 0).
// - bool retirar(int codigo, int cantidad): si el codigo no existe, o su
//   stock es menor que cantidad, devuelve false sin cambiar nada (y sin
//   registrar el codigo). Si alcanza, resta, agrega el codigo al
//   historial de retiros, y si el stock queda en 0 lo agrega a los
//   agotados. Devuelve true.
// - int stockDe(int codigo): el stock del codigo, o 0 si no existe, sin
//   registrar el codigo.
// - int cantidadDeProductos(): cuantos codigos distintos tienen stock
//   registrado.
// - int retiroNumero(int posicion): el codigo del retiro en esa posicion
//   del historial, contando desde 0.
// - void imprimirStock(): "Stock:" y, por cada codigo de menor a mayor,
//   un espacio y "codigo=cantidad". Termina la linea.
// - void imprimirRetiros(): "Retiros:" y cada codigo del historial
//   precedido de un espacio. Termina la linea.
// - void imprimirAgotados(): "Agotados alguna vez:" y cada codigo
//   precedido de un espacio. Termina la linea.

class Bodega {
    private:
        // std::map mantiene las claves (códigos) ordenadas automáticamente de menor a mayor.
        std::map<int, int> stock;

        // std::vector permite guardar los retiros en orden secuencial con acceso por índice.
        std::vector<int> historialRetiros;

        // std::set garantiza elementos únicos sin repetición y ordenados de menor a mayor.
        std::set<int> agotados;

    public:
        void ingresar(int codigo, int cantidad) {
            stock[codigo] += cantidad;
        }

        bool retirar(int codigo, int cantidad) {
            auto it = stock.find(codigo);
            // Si el código no existe en el mapa o el stock es insuficiente, se rechaza.
            if (it == stock.end() || it->second < cantidad) {
                return false;
            }

            it->second -= cantidad;
            historialRetiros.push_back(codigo);

            if (it->second == 0) {
                agotados.insert(codigo);
            }

            return true;
        }

        int stockDe(int codigo) const {
            auto it = stock.find(codigo);
            if (it != stock.end()) {
                return it->second;
            }
            return 0;
        }

        int cantidadDeProductos() const {
            return stock.size();
        }

        int retiroNumero(int posicion) const {
            return historialRetiros[posicion];
        }

        void imprimirStock() const {
            std::cout << "Stock:";
            for (const auto& par : stock) {
                std::cout << " " << par.first << "=" << par.second;
            }
            std::cout << std::endl;
        }

        void imprimirRetiros() const {
            std::cout << "Retiros:";
            for (int codigo : historialRetiros) {
                std::cout << " " << codigo;
            }
            std::cout << std::endl;
        }

        void imprimirAgotados() const {
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