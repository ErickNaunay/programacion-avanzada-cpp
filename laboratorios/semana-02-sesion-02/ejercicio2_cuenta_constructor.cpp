// Ejercicio 2: CuentaBancaria con constructor y destructor
//
// depositar() y retirar() ya estan completos: son los mismos de la
// sesion pasada. Completa el constructor y el destructor.
//
// El constructor recibe saldoInicial. Si es negativo, asigna
// saldo = 0.0 y avisa por consola; si no, asigna saldo = saldoInicial
// directamente (a diferencia del ejercicio 1, aqui no hay un setter
// previo que reusar, porque inicializarSaldo() no forma parte de esta
// version).
//
// Salida esperada:
// Saldo inicial: 100
// Saldo despues de depositar 50: 150
// CuentaBancaria destruida, saldo final: 150
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio2_cuenta_constructor.cpp -o bin/ejercicio2
// Ejecutar:  ./bin/ejercicio2

#include <iostream>

class CuentaBancaria {
private:
    double saldo;

public:
    CuentaBancaria(double saldoInicial) {
        // TODO: si saldoInicial es negativo, asigna saldo = 0.0 y avisa
        // por consola: "Aviso: saldo inicial invalido, se uso 0 por defecto"
        // Si no es negativo, asigna saldo = saldoInicial.
    }

    ~CuentaBancaria() {
        // TODO: imprime "CuentaBancaria destruida, saldo final: "
        // seguido del saldo.
    }

    double getSaldo() { return saldo; }

    bool depositar(double monto) {
        if (monto <= 0.0) {
            return false;
        }
        saldo = saldo + monto;
        return true;
    }

    bool retirar(double monto) {
        if (monto <= 0.0 || monto > saldo) {
            return false;
        }
        saldo = saldo - monto;
        return true;
    }
};

int main() {
    CuentaBancaria cuenta(100.0);
    std::cout << "Saldo inicial: " << cuenta.getSaldo() << std::endl;

    cuenta.depositar(50.0);
    std::cout << "Saldo despues de depositar 50: " << cuenta.getSaldo() << std::endl;

    return 0;
}
