// Ejercicio 2: CuentaBancaria encapsulada
//
// Mismo patron del ejercicio 1, en un dominio distinto: el invariante es
// "el saldo nunca puede quedar negativo". Sin constructor todavia (eso
// llega en la sesion siguiente), la cuenta se inicializa con un metodo
// comun, igual que cualquier funcion que ya conoces.
//
// Salida esperada:
// Saldo inicial: 100
// depositar(-50) rechazado: true, saldo sigue en: 100
// Saldo despues de depositar 50: 150
// retirar(200) rechazado: true, saldo sigue en: 150
// Saldo despues de retirar 30: 120
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio2_cuenta_bancaria.cpp -o bin/ejercicio2
// Ejecutar:  ./bin/ejercicio2

#include <iostream>

class CuentaBancaria {
private:
    double saldo;

public:
    double getSaldo() { return saldo; }

    bool inicializarSaldo(double saldoInicial) {
        // TODO: si saldoInicial es negativo, devuelve false sin asignar.
        // Si no, asigna saldo = saldoInicial y devuelve true.
        return false;
    }

    bool depositar(double monto) {
        // TODO: si monto no es positivo, devuelve false sin modificar saldo.
        // Si es positivo, suma monto a saldo y devuelve true.
        return false;
    }

    bool retirar(double monto) {
        // TODO: si monto no es positivo, o si monto es mayor que saldo,
        // devuelve false sin modificar saldo. Si no, resta monto de saldo
        // y devuelve true.
        return false;
    }
};

int main() {
    CuentaBancaria cuenta;
    cuenta.inicializarSaldo(100.0);
    std::cout << "Saldo inicial: " << cuenta.getSaldo() << std::endl;

    bool ok1 = cuenta.depositar(-50.0);
    std::cout << "depositar(-50) rechazado: " << (!ok1 ? "true" : "false")
              << ", saldo sigue en: " << cuenta.getSaldo() << std::endl;

    cuenta.depositar(50.0);
    std::cout << "Saldo despues de depositar 50: " << cuenta.getSaldo() << std::endl;

    bool ok2 = cuenta.retirar(200.0);
    std::cout << "retirar(200) rechazado: " << (!ok2 ? "true" : "false")
              << ", saldo sigue en: " << cuenta.getSaldo() << std::endl;

    cuenta.retirar(30.0);
    std::cout << "Saldo despues de retirar 30: " << cuenta.getSaldo() << std::endl;

    return 0;
}
