// Ejercicio 3: Conexion y ConexionSegura (destructor virtual)
//
// Completa lo marcado con TODO. No cambies el main().
//
// Uno de los TODO no es un cuerpo de metodo: es el destructor de la base.
// Sin lo que falta, el programa compila y corre, pero el objeto se destruye
// a medias: compara tu salida con la esperada.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio3 ejercicio3_conexion_segura.cpp
// Ejecutar: ./ejercicio3
//
// Salida esperada:
// Puerto: 443
// Certificado: 2048
// Certificado liberado
// Conexion cerrada
// Fin del programa

#include <iostream>
#include <memory>

class Conexion {
public:
    // TODO: la base se usa a traves de un unique_ptr<Conexion>: agrega lo que le
    // falta a este destructor para que tambien se ejecute el de la derivada.
    ~Conexion() {
        std::cout << "Conexion cerrada" << std::endl;
    }
    virtual int puerto() {
        return 80;
    }
    virtual int bitsDeCertificado() {
        return 0;
    }
};

class ConexionSegura : public Conexion {
private:
    int* certificado;
public:
    ConexionSegura(int bits) {
        // TODO: reserva con new un int, guardalo en certificado y asignale bits.
        certificado = nullptr;
    }
    ~ConexionSegura() {
        // TODO: libera certificado con delete e imprime "Certificado liberado".
    }
    int puerto() override {
        return 443;
    }
    int bitsDeCertificado() override {
        // TODO: devuelve el valor al que apunta certificado.
        return 0;
    }
};

int main() {
    {
        std::unique_ptr<Conexion> conexion = std::make_unique<ConexionSegura>(2048);
        std::cout << "Puerto: " << conexion->puerto() << std::endl;
        std::cout << "Certificado: " << conexion->bitsDeCertificado() << std::endl;
    }
    std::cout << "Fin del programa" << std::endl;
    return 0;
}
