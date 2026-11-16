#include <iostream>
#include <mutex>
#include <thread>

// Ejercicio 1, para comparar: el mismo contador con mutex, como quedo la
// sesion pasada, con cuatro puertas. Ya esta completo: no lo cambies.
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio1_contador_candado.cpp -o bin/ejercicio1_candado
// Ejecutar:  time ./bin/ejercicio1_candado
//
// Salida esperada:
// Visitas registradas: 4000000

class ContadorDeVisitas {
    private:
        int total;
        std::mutex candado;
    public:
        ContadorDeVisitas() {
            total = 0;
        }

        void registrar() {
            std::lock_guard<std::mutex> guardia(candado);
            total = total + 1;
        }

        int getTotal() {
            std::lock_guard<std::mutex> guardia(candado);
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
