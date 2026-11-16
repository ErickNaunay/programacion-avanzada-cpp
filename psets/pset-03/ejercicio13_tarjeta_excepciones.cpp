// Ejercicio 13: TarjetaDeTransporte (lanzar excepciones)
//
// Completa los metodos marcados con TODO: cada uno lanza la excepcion de
// <stdexcept> que se indica, con el mensaje exacto. El main ya atrapa
// cada una; no lo cambies.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio13 ejercicio13_tarjeta_excepciones.cpp
// Ejecutar: ./ejercicio13
//
// Salida esperada:
// Saldo: 5
// Pago aceptado, saldo: 4.55
// Error de dato: monto no positivo
// Error de operacion: saldo insuficiente
// Saldo sin cambios: 4.55
// Error de dato: tarifa no positiva
// Fin

#include <iostream>
#include <stdexcept>

class TarjetaDeTransporte {
private:
    double saldo;
public:
    TarjetaDeTransporte() {
        saldo = 0;
    }
    void recargar(double monto) {
        // TODO: si monto <= 0, lanza std::invalid_argument("monto no positivo").
        // Si no, suma monto al saldo.
    }
    void pagar(double tarifa) {
        // TODO: si tarifa <= 0, lanza std::invalid_argument("tarifa no positiva").
        // Si tarifa > saldo, lanza std::runtime_error("saldo insuficiente")
        // sin cambiar el saldo. Si no, resta la tarifa.
    }
    double getSaldo() {
        return saldo;
    }
};

int main() {
    TarjetaDeTransporte tarjeta;
    tarjeta.recargar(5);
    std::cout << "Saldo: " << tarjeta.getSaldo() << std::endl;

    try {
        tarjeta.pagar(0.45);
        std::cout << "Pago aceptado, saldo: " << tarjeta.getSaldo() << std::endl;
        tarjeta.recargar(-2);
        std::cout << "Esta linea no debe imprimirse" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Error de dato: " << e.what() << std::endl;
    }

    try {
        tarjeta.pagar(20);
    } catch (const std::invalid_argument& e) {
        std::cout << "Error de dato: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error de operacion: " << e.what() << std::endl;
    }
    std::cout << "Saldo sin cambios: " << tarjeta.getSaldo() << std::endl;

    try {
        tarjeta.pagar(-1);
    } catch (const std::exception& e) {
        std::cout << "Error de dato: " << e.what() << std::endl;
    }
    std::cout << "Fin" << std::endl;
    return 0;
}
