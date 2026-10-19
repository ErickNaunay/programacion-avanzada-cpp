#include <iostream>
#include <memory>

// Salida esperada:
// Pasos guardados: 3 de 5
// Ultimo dia: 3300
// Temperaturas guardadas: 3 de 3
// Agregar una cuarta temperatura: rechazado
// Primera temperatura: 20.5
// Teclas guardadas: 2 de 4
// Ultima tecla: s

// TODO: escribe la plantilla de clase Historial, que guarda hasta
// "capacidad" valores de cualquier tipo T.
// - Atributos privados: los valores, en un std::unique_ptr a un arreglo de
//   T creado en el constructor; la capacidad; cuantos valores ya se usaron.
// - Constructor que recibe la capacidad (int).
// - bool agregar(T valor): guarda el valor en la siguiente posicion libre
//   y devuelve true; si ya esta lleno, devuelve false sin guardar nada.
// - T obtener(int indice) y T ultimo() (el ultimo valor agregado).
// - int getUsadas() e int getCapacidad().
// - Sin destructor.

int main() {
    Historial<int> pasos(5);
    pasos.agregar(4200);
    pasos.agregar(1800);
    pasos.agregar(3300);
    std::cout << "Pasos guardados: " << pasos.getUsadas() << " de " << pasos.getCapacidad() << std::endl;
    std::cout << "Ultimo dia: " << pasos.ultimo() << std::endl;

    Historial<double> temperaturas(3);
    temperaturas.agregar(20.5);
    temperaturas.agregar(21.5);
    temperaturas.agregar(22.5);
    bool aceptada = temperaturas.agregar(23.5);
    std::cout << "Temperaturas guardadas: " << temperaturas.getUsadas() << " de " << temperaturas.getCapacidad() << std::endl;
    std::cout << "Agregar una cuarta temperatura: ";
    if (aceptada) {
        std::cout << "aceptado" << std::endl;
    } else {
        std::cout << "rechazado" << std::endl;
    }
    std::cout << "Primera temperatura: " << temperaturas.obtener(0) << std::endl;

    Historial<char> teclas(4);
    teclas.agregar('w');
    teclas.agregar('s');
    std::cout << "Teclas guardadas: " << teclas.getUsadas() << " de " << teclas.getCapacidad() << std::endl;
    std::cout << "Ultima tecla: " << teclas.ultimo() << std::endl;

    return 0;
}
