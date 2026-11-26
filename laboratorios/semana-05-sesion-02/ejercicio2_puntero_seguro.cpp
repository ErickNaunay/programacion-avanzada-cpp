#include <iostream>

// TODO: cambia esta funcion para que no devuelva la direccion de una
// variable local. Usa memoria dinamica en su lugar, con new.
int* obtenerLecturaSegura(int valorSensor) {
    int* lectura = new int(valorSensor * 2);
    return lectura;
}

int main() {
    int* resultado = obtenerLecturaSegura(10);
    std::cout << "Lectura: " << *resultado << std::endl;

    // TODO: despues de terminar con "resultado", libera la memoria con
    // delete y asignale nullptr, para dejar constancia de que ya no
    // apunta a memoria valida.
    
    delete resultado;
    resultado = nullptr;

    return 0;
}
