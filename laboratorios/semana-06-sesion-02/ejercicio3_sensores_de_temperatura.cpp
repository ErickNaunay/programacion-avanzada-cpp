#include <iostream>
#include <memory>
#include <utility>

// TODO: completa RegistroTemperaturas reemplazando la memoria dinamica
// manual por un smart pointer:
// - Atributo privado: std::unique_ptr<double[]> lecturas (en vez de
//   double* lecturas) y un int capacidad.
// - Constructor RegistroTemperaturas(int nuevaCapacidad): crea
//   "lecturas" con std::make_unique<double[]>(capacidad) e imprime
//   "Registro de temperaturas creado para <capacidad> lecturas".
// - void guardar(int indice, double valor) y double obtener(int indice).
// - Sin destructor: unique_ptr ya libera la memoria solo.
class RegistroTemperaturas {
};

// TODO: completa SensorRemoto:
// - Atributos privados: std::shared_ptr<RegistroTemperaturas> registro,
//   int idSensor.
// - Constructor SensorRemoto(std::shared_ptr<RegistroTemperaturas>
//   unRegistro, int unId): guarda unRegistro con std::move en "registro",
//   guarda unId en "idSensor", e imprime "Sensor <idSensor> conectado.
//   use_count = <registro.use_count()>".
// - void reportar(int indice): imprime "Sensor <idSensor> lee
//   <registro->obtener(indice)> grados".
// - Destructor ~SensorRemoto(): imprime "Sensor <idSensor> desconectado".
class SensorRemoto {
};

int main() {
    std::shared_ptr<RegistroTemperaturas> compartido = std::make_shared<RegistroTemperaturas>(3);
    compartido->guardar(0, 21.5);
    std::cout << "use_count antes de conectar sensores: " << compartido.use_count() << std::endl;

    {
        SensorRemoto sala(compartido, 1);
        SensorRemoto exterior(compartido, 2);
        std::cout << "use_count con 2 sensores conectados: " << compartido.use_count() << std::endl;
        sala.reportar(0);
        exterior.reportar(0);
    }

    std::cout << "use_count despues de desconectar los sensores: " << compartido.use_count() << std::endl;
    return 0;
}
