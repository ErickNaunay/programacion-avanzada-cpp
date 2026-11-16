// Ejercicio 15: Biblioteca (std::optional)
//
// Completa los metodos marcados con TODO. Ninguno devuelve -1 ni 0 para
// decir "no hay": cuando no hay respuesta, devuelven std::nullopt. No
// cambies las firmas ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio15 ejercicio15_biblioteca_optional.cpp
// Ejecutar: ./ejercicio15
//
// Salida esperada:
// Anio del libro 5521: 1967
// Anio del libro 9999: desconocido
// Mas antiguo: 1605
// Prestar 5521: devolver el dia 14
// Prestar 5521 otra vez: no disponible
// Prestar 9999: no disponible
// Biblioteca vacia, mas antiguo: 0

#include <iostream>
#include <map>
#include <optional>
#include <set>

class Biblioteca {
private:
    std::map<int, int> anioPorCodigo;
    std::set<int> prestados;
public:
    void agregar(int codigo, int anio) {
        anioPorCodigo[codigo] = anio;
    }
    std::optional<int> anioDe(int codigo) {
        // TODO: si el codigo no esta, devuelve std::nullopt; si esta, su anio.
        return std::nullopt;
    }
    std::optional<int> masAntiguo() {
        // TODO: devuelve el anio mas antiguo de todos los libros, o std::nullopt
        // si no hay libros.
        return std::nullopt;
    }
    std::optional<int> prestar(int codigo, int hoy) {
        // TODO: si el libro no existe o ya esta prestado, devuelve std::nullopt.
        // Si no, lo marca como prestado y devuelve el dia de devolucion,
        // hoy + 7.
        return std::nullopt;
    }
};

void imprimirPrestamo(std::optional<int> devolucion) {
    if (devolucion) {
        std::cout << "devolver el dia " << *devolucion << std::endl;
    } else {
        std::cout << "no disponible" << std::endl;
    }
}

int main() {
    Biblioteca biblioteca;
    biblioteca.agregar(5521, 1967);
    biblioteca.agregar(1200, 1605);
    biblioteca.agregar(7310, 2004);

    std::optional<int> anio = biblioteca.anioDe(5521);
    std::cout << "Anio del libro 5521: " << *anio << std::endl;
    std::optional<int> otro = biblioteca.anioDe(9999);
    if (otro.has_value()) {
        std::cout << "Anio del libro 9999: " << *otro << std::endl;
    } else {
        std::cout << "Anio del libro 9999: desconocido" << std::endl;
    }
    std::cout << "Mas antiguo: " << biblioteca.masAntiguo().value_or(0) << std::endl;

    std::cout << "Prestar 5521: ";
    imprimirPrestamo(biblioteca.prestar(5521, 7));
    std::cout << "Prestar 5521 otra vez: ";
    imprimirPrestamo(biblioteca.prestar(5521, 8));
    std::cout << "Prestar 9999: ";
    imprimirPrestamo(biblioteca.prestar(9999, 8));

    Biblioteca vacia;
    std::cout << "Biblioteca vacia, mas antiguo: " << vacia.masAntiguo().value_or(0) << std::endl;
    return 0;
}
