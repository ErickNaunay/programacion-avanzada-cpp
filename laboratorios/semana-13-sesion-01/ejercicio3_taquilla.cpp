#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

// Ejercicio 3: la taquilla del concierto de fin de semestre.
//
// El teatro tiene 20000 asientos, numerados del 0 al 19999. Cuatro vendedores
// venden al mismo tiempo, cada uno en su propio hilo, y cada uno intenta
// vender todos los asientos a su comprador. Un quinto vendedor vende solo
// pares de asientos juntos (0 y 1, 2 y 3, ...) a un grupo.
//
// TODO: escribe la clase Taquilla, que tiene que funcionar con varios
// hilos a la vez:
//
// - Taquilla(int asientos): todos los asientos empiezan libres.
// - bool reservar(int asiento, int comprador): si el asiento no existe o
//   ya tiene dueno, devuelve false. Si no, lo deja a nombre del comprador
//   y devuelve true.
// - bool reservarPar(int a, int b, int comprador): reserva los dos
//   asientos a nombre del comprador solo si los dos existen y estan
//   libres; si no, no reserva ninguno y devuelve false.
// - int duenoDe(int asiento): el comprador del asiento, o 0 si esta
//   libre (los compradores van del 1 en adelante).
// - int vendidos(): cuantos asientos tienen dueno.
//
// Ningun asiento puede terminar con dos duenos, ni un par a medias. No
// cambies el main: cuenta lo que cada vendedor logro vender y verifica
// esas dos reglas al final.
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio3_taquilla.cpp -o bin/ejercicio3
// Ejecutar:  ./bin/ejercicio3
// Con ThreadSanitizer:
//   g++ -std=c++20 -Wall -Wextra -g -fsanitize=thread ejercicio3_taquilla.cpp -o bin/ejercicio3_tsan
//
// Salida esperada (cuantos asientos vende cada vendedor cambia de una
// corrida a otra; estas tres lineas no):
// Reservas aceptadas: 20000
// Asientos vendidos: 20000
// Pares a medias: 0

// TODO: escribe aqui la clase Taquilla.

void vendedor(Taquilla* taquilla, int comprador, int* logradas) {
    for (int asiento = 0; asiento < 20000; asiento++) {
        if (taquilla->reservar(asiento, comprador)) {
            *logradas = *logradas + 1;
        }
    }
}

void vendedorDePares(Taquilla* taquilla, int comprador, int* logradas) {
    for (int asiento = 0; asiento < 20000; asiento = asiento + 2) {
        if (taquilla->reservarPar(asiento, asiento + 1, comprador)) {
            *logradas = *logradas + 2;
        }
    }
}

int main() {
    Taquilla taquilla(20000);
    int logradas[5] = {0, 0, 0, 0, 0};

    std::thread v1(vendedor, &taquilla, 1, &logradas[0]);
    std::thread v2(vendedor, &taquilla, 2, &logradas[1]);
    std::thread v3(vendedor, &taquilla, 3, &logradas[2]);
    std::thread v4(vendedor, &taquilla, 4, &logradas[3]);
    std::thread v5(vendedorDePares, &taquilla, 5, &logradas[4]);
    v1.join();
    v2.join();
    v3.join();
    v4.join();
    v5.join();

    int total = 0;
    for (int i = 0; i < 5; i++) {
        total = total + logradas[i];
    }

    int aMedias = 0;
    for (int asiento = 0; asiento < 20000; asiento = asiento + 2) {
        bool primero = taquilla.duenoDe(asiento) == 5;
        bool segundo = taquilla.duenoDe(asiento + 1) == 5;
        if (primero != segundo) {
            aMedias = aMedias + 1;
        }
    }

    std::cout << "Reservas aceptadas: " << total << std::endl;
    std::cout << "Asientos vendidos: " << taquilla.vendidos() << std::endl;
    std::cout << "Pares a medias: " << aMedias << std::endl;
    return 0;
}
