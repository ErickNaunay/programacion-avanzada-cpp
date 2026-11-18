#include <iostream>
#include <mutex>
#include <thread>

// Ejercicio 1: el contador de visitas de la biblioteca, desde dos puertas.
//
// Cada puerta tiene un sensor que llama registrar() una vez por persona.
// Las dos puertas trabajan al mismo tiempo, cada una en su propio hilo.
// Hoy entran 1000000 personas por cada puerta.
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio1_contador_visitas.cpp -o bin/ejercicio1
// Ejecutar:  ./bin/ejercicio1
// Con ThreadSanitizer:
//   g++ -std=c++20 -Wall -Wextra -g -fsanitize=thread ejercicio1_contador_visitas.cpp -o bin/ejercicio1_tsan
//
// Salida esperada (cuando el contador es correcto):
// Visitas registradas: 2000000

class ContadorDeVisitas {
    private:
        int total;
        // TODO 2: un std::mutex que proteja total.
    public:
        ContadorDeVisitas() {
            total = 0;
        }

        void registrar() {
            // TODO 2: antes de tocar total, toma el candado con
            // std::lock_guard<std::mutex> guardia(candado);
            total = total + 1;
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

    // TODO 1: reemplaza las dos llamadas por dos std::thread que ejecuten
    // puerta(&contador, 1000000) al mismo tiempo, y espera a que terminen
    // los dos con join() antes de imprimir.
    puerta(&contador, 1000000);
    puerta(&contador, 1000000);

    std::cout << "Visitas registradas: " << contador.getTotal() << std::endl;
    return 0;
}
