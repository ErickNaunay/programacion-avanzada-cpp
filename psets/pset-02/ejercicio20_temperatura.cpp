// Ejercicio 20: Temperatura (desde cero, operator+ y operator<<)
//
// Este archivo no tiene codigo de partida. Escribe tu de tu propia clase,
// tus propios includes y tu propio main().
//
// Disena la clase Temperatura: atributo privado grados (double).
// Constructor Temperatura(double gradosIniciales) que asigna grados por
// asignacion directa (sin validar, sin setter). Getter double getGrados().
// operator+ como metodo miembro, que recibe otro Temperatura por valor y
// devuelve un Temperatura nuevo con la suma de los grados de ambos.
// operator<< como funcion libre (fuera de la clase), que recibe
// std::ostream& y un Temperatura por valor, e imprime el valor de grados
// seguido de " grados". Debe devolver el std::ostream& recibido.
//
// En main(): crea dos objetos Temperatura, uno con 20.5 grados y otro con
// 5.5 grados. Crea un tercero sumando los dos primeros con operator+.
// Imprime los tres objetos, cada uno en su propia linea, usando cout con
// tu operator<<.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio20 ejercicio20_temperatura.cpp
// Ejecutar: ./ejercicio20
//
// Salida esperada:
// 20.5 grados
// 5.5 grados
// 26 grados

#include <iostream>

class Temperatura {
private:
    double grados;
public:
    Temperatura(double gradosIniciales) : grados(gradosIniciales) {}
    double getGrados() const {
        return grados;
    }
    Temperatura operator+(const Temperatura& otra) const {
        return Temperatura(grados + otra.grados);
    }
};

std::ostream& operator<<(std::ostream& os, const Temperatura& t) {
    os << t.getGrados() << " grados";
    return os;
}

int main() {
    Temperatura t1(20.5);
    Temperatura t2(5.5);
    Temperatura t3 = t1 + t2;
    std::cout << t1 << std::endl;
    std::cout << t2 << std::endl;
    std::cout << t3 << std::endl;
    return 0;
}
