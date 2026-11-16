#include <atomic>
#include <iostream>
#include <thread>

// Ejercicio 2: la tarjeta del comedor sin mutex.
//
// Las 2000 tarjetas de los estudiantes de primer anio, con 50 centavos
// cada una. Dos cajas recorren todas las tarjetas, en el mismo orden, e
// intentan cobrar 1 centavo 40 veces de cada una: 80 intentos por tarjeta,
// de los que solo alcanzan 50. Alguien propone cambiar el mutex de la
// sesion pasada por un std::atomic<int>, "que es mas rapido".
// cobrarIngenuo ya esta escrito asi. Tu escribes cobrar, que tiene que ser
// correcto sin mutex.
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio2_tarjeta_atomica.cpp -o bin/ejercicio2
// Ejecutar:  ./bin/ejercicio2
//
// Salida esperada (el numero de la primera linea cambia de una corrida a
// otra, y casi nunca es 0; las tres ultimas lineas no cambian):
// Ingenuo, tarjetas en negativo: 338
// Correcto, tarjetas en negativo: 0
// Correcto, cobros aceptados: 100000
// Correcto, cobros rechazados: 60000

class TarjetaAtomica {
    private:
        std::atomic<int> saldo;
        std::atomic<int> aceptados;
        std::atomic<int> rechazados;
    public:
        TarjetaAtomica() {
            saldo = 50;
            aceptados = 0;
            rechazados = 0;
        }

        // Cada linea es atomica por separado. El metodo completo, no.
        void cobrarIngenuo(int monto) {
            if (saldo >= monto) {
                saldo -= monto;
                aceptados++;
            } else {
                rechazados++;
            }
        }

        // Cobra monto solo si alcanza, sin mutex.
        void cobrar(int monto) {
            // TODO 1: lee el saldo en una variable local (int actual = saldo;).
            // 2: en un ciclo: si actual < monto, cuenta un rechazo y sale.
            // Si no, intenta saldo.compare_exchange_weak(actual, actual - monto):
            // cambia el saldo solo si sigue valiendo actual. Si lo logra,
            // cuenta un cobro aceptado y sale. Si no, compare_exchange_weak
            // ya dejo en actual el saldo nuevo: el ciclo vuelve a decidir.
        }

        int getSaldo() {
            return saldo;
        }

        int getAceptados() {
            return aceptados;
        }

        int getRechazados() {
            return rechazados;
        }
};

const int TARJETAS = 2000;

void cajaIngenua(TarjetaAtomica* tarjetas, int intentos) {
    for (int t = 0; t < TARJETAS; t++) {
        for (int i = 0; i < intentos; i++) {
            tarjetas[t].cobrarIngenuo(1);
        }
    }
}

void caja(TarjetaAtomica* tarjetas, int intentos) {
    for (int t = 0; t < TARJETAS; t++) {
        for (int i = 0; i < intentos; i++) {
            tarjetas[t].cobrar(1);
        }
    }
}

int enNegativo(TarjetaAtomica* tarjetas) {
    int total = 0;
    for (int t = 0; t < TARJETAS; t++) {
        if (tarjetas[t].getSaldo() < 0) {
            total = total + 1;
        }
    }
    return total;
}

TarjetaAtomica ingenuas[TARJETAS];
TarjetaAtomica tarjetas[TARJETAS];

int main() {
    std::thread a(cajaIngenua, ingenuas, 40);
    std::thread b(cajaIngenua, ingenuas, 40);
    a.join();
    b.join();
    std::cout << "Ingenuo, tarjetas en negativo: " << enNegativo(ingenuas) << std::endl;

    std::thread c(caja, tarjetas, 40);
    std::thread d(caja, tarjetas, 40);
    c.join();
    d.join();
    int aceptados = 0;
    int rechazados = 0;
    for (int t = 0; t < TARJETAS; t++) {
        aceptados = aceptados + tarjetas[t].getAceptados();
        rechazados = rechazados + tarjetas[t].getRechazados();
    }
    std::cout << "Correcto, tarjetas en negativo: " << enNegativo(tarjetas) << std::endl;
    std::cout << "Correcto, cobros aceptados: " << aceptados << std::endl;
    std::cout << "Correcto, cobros rechazados: " << rechazados << std::endl;
    return 0;
}
