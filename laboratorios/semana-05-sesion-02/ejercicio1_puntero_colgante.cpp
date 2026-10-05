#include <iostream>

// TODO: predice antes de compilar. ¿que advertencia esperas que de
// el compilador sobre esta funcion? una advertencia sobre la memoria stack
int* obtenerLecturaInsegura(int valorSensor) {
    int lectura = valorSensor * 2;
    return &lectura;
}

void demostrarAlcance(){
    LecturaSensor sensor(50);
    std::cout << "Valor: " << sensor.getValor() << std::endl;
}

LecturaSensor* demostrarAlcanceMemoriaDinamica(){
    LecturaSensor *sensor = new LecturaSensor(80);
    std::cout << "Valor: " << sensor->getValor() << std::endl;
    delete sensor;

    sensor = nullptr;

    return sensor;
}

int main() {
    int* resultado = obtenerLecturaInsegura(10);
    std::cout << "Lectura (puntero colgante): " << *resultado << std::endl;

    return 0;
}
