#include <iostream>

class LecturaSensor {
    private:
        int valor;
    public:
        LecturaSensor(int v){
            valor = v;
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
    std::cout << std::endl;
    demostrarAlcance();
    LecturaSensor* sensor_ptr = demostrarAlcanceMemoriaDinamica();
    std::cout << sensor_ptr <<  std::endl;

    return 0;
}
