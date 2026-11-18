#include <atomic>
#include <iostream>
#include <thread>

// Ejercicio 1: el contador de visitas, ahora con std::atomic.
//
// El mismo contador de la sesion pasada, con cuatro puertas y un millon de
// personas por puerta. En vez de un mutex, el total es un std::atomic<int>.
// ejercicio1_contador_candado.cpp tiene la version con mutex, completa,
// para comparar tiempos.
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio1_contador_atomico.cpp -o bin/ejercicio1
// Ejecutar:  time ./bin/ejercicio1
//
// Salida esperada (cuando el contador es correcto):
// Visitas registradas: 4000000

class ContadorDeVisitas {
    private:
        // TODO 1: cambia el tipo de total a std::atomic<int>. No cambies todavia
        // registrar().
        std::atomic<int> total;
    public:
        ContadorDeVisitas() {
            total = 0;
        }

        void registrar() {
            // TODO 2: con total atomico, cambia esta linea por una sola operacion
            // atomica: total++ (o total.fetch_add(1)).
            total++;
        }

        int getTotal() {
            return total;
        }
};

void puerta(ContadorDeVisitas* contador, int personas) {
    for (int i = 0; i < personas; i++) {
        contador->registrar();
    }
}

int main() {
    ContadorDeVisitas contador;

    std::thread norte(puerta, &contador, 1000000);
    std::thread sur(puerta, &contador, 1000000);
    std::thread este(puerta, &contador, 1000000);
    std::thread oeste(puerta, &contador, 1000000);
    norte.join();
    sur.join();
    este.join();
    oeste.join();

    std::cout << "Visitas registradas: " << contador.getTotal() << std::endl;
    return 0;
}