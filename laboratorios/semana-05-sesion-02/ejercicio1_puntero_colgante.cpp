#include <iostream>

class LecturaSensor {
    private:
        int valor;
    public:
        LecturaSensor(int v){
            valor = v;
            std::cout << "Se llamo al constructor: " << valor << std::endl;
        }
        ~LecturaSensor(){
            std::cout << "Llamando al destructor: " << valor << std::endl;
            std::cout << std::endl;
        }
        int getValor() {
            std::cout << "Se llamo al constructor" << std::endl;
        }
        ~LecturaSensor(){
            std::cout << "Llamando al destructor" << std::endl;
        }
        int getValor(){
            return valor;
        }
};

// TODO: predice antes de compilar. ¿que advertencia esperas que de
// el compilador sobre esta funcion?
// La direccion de memoria que se retorna es de una variable local, por lo que al salir de la función, esa 
// direccion de memoria ya no es válida. Esto puede causar un comportamiento indefinido cuando se intenta 
// acceder a esa dirección desde el main.

int* obtenerLecturaInsegura(int valorSensor) {
    int lectura = valorSensor * 2;
    return &lectura;
}

void demostrarAlcance () {
void demostrarAlcance(){
    LecturaSensor sensor(50);
    std::cout << "Valor: " << sensor.getValor() << std::endl;
}

LecturaSensor *  demostrarAlcanceMemoriaDinamica () {
    LecturaSensor* sensor = new LecturaSensor(80);
    std::cout << "Valor: " << sensor->getValor() << std::endl;
    delete sensor; // Liberar la memoria asignada dinámicamente
    sensor = nullptr; // Evitar puntero colgante
LecturaSensor* demostrarAlcanceMemoriaDinamica(){
    LecturaSensor *sensor = new LecturaSensor(80);
    std::cout << "Valor: " << sensor->getValor() << std::endl;
    delete sensor;

    sensor = nullptr;

    return sensor;
}

int main() {
    // int* resultado = obtenerLecturaInsegura(10);
    // std::cout << "Lectura (puntero colgante): " << *resultado << std::endl;
    std::cout << std::endl;
    demostrarAlcance();
    LecturaSensor* sensor_ptr = demostrarAlcanceMemoriaDinamica();
    std::cout << sensor_ptr << std::endl;
    int* resultado = obtenerLecturaInsegura(10);
    std::cout << "Lectura (puntero colgante): " << *resultado << std::endl;
    std::cout << std::endl;
    demostrarAlcance();
    LecturaSensor* sensor_ptr = demostrarAlcanceMemoriaDinamica();
    std::cout << sensor_ptr <<  std::endl;

    return 0;
}
