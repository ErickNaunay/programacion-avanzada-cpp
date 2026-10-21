#include <iostream>
#include <utility>

// TODO: completa BitacoraDeVuelo con el mismo patron de RegistroDeVuelo
// (Ejercicios 1 y 2), aplicado a un arreglo dinamico de consumos de
// combustible por tramo, en vez de alturas:
// - Atributos privados: double* consumos y int capacidad.
// - Constructor BitacoraDeVuelo(int nuevaCapacidad): reserva memoria con
//   new[] e imprime "Bitacora creada para <capacidad> tramos".
// - void guardarConsumo(int indice, double valor) y
//   double getConsumo(int indice) (si "consumos" es nullptr, imprime
//   "Bitacora vacia (fue movida)" y devuelve 0.0, igual que en el
//   Ejercicio 2).
// - Constructor de movimiento BitacoraDeVuelo(BitacoraDeVuelo&& otra):
//   roba "consumos" y "capacidad" de "otra", y deja "otra" vacia y segura
//   (consumos = nullptr, capacidad = 0).
// - Operador de asignacion de movimiento
//   BitacoraDeVuelo& operator=(BitacoraDeVuelo&& otra): libera lo propio
//   con delete[] antes de robar lo de "otra" (comprobando this != &otra).
// - Destructor ~BitacoraDeVuelo(): libera con delete[] e imprime
//   "Destruyendo bitacora (capacidad <capacidad>)".
class BitacoraDeVuelo {
    private:
        double* consumos;
        int capacidad;
    public:
        BitacoraDeVuelo(int nuevaCapacidad) {
            capacidad = nuevaCapacidad;
            consumos = new double[capacidad];
            std::cout << "Bitacora creada para " << capacidad << " tramos" << std::endl;
        }

        void guardarConsumo(int indice, double valor) {
            consumos[indice] = valor;
        }

        double getConsumo(int indice) {
            if (consumos == nullptr) {
                std::cout << "Bitacora vacia (fue movida)" << std::endl;
                return 0.0;
            }
            return consumos[indice];
        }

        BitacoraDeVuelo(BitacoraDeVuelo&& otra) : consumos(otra.consumos), capacidad(otra.capacidad) {
            otra.consumos = nullptr;
            otra.capacidad = 0;
        }

        BitacoraDeVuelo& operator=(BitacoraDeVuelo&& otra) {
            if (this != &otra) {
                delete[] consumos;
                consumos = otra.consumos;
                capacidad = otra.capacidad;
                otra.consumos = nullptr;
                otra.capacidad = 0;
            }
            return *this;
        }

        ~BitacoraDeVuelo() {
            std::cout << "Destruyendo bitacora (capacidad " << capacidad << ")" << std::endl;
            delete[] consumos;
        }
};

int main() {
    BitacoraDeVuelo original(4);
    original.guardarConsumo(0, 850.5);

    BitacoraDeVuelo trasladada = std::move(original);
    std::cout << "original.getConsumo(0) = " << original.getConsumo(0) << std::endl;
    std::cout << "trasladada.getConsumo(0) = " << trasladada.getConsumo(0) << std::endl;

    BitacoraDeVuelo otra(2);
    otra = std::move(trasladada);
    std::cout << "otra.getConsumo(0) = " << otra.getConsumo(0) << std::endl;

    return 0;
}
