// Ejercicio 6: HorarioAtencion
//
// Completa la clase HorarioAtencion: dos atributos privados,
// horaApertura y horaCierre, y un setter que devuelva bool,
// setHorario(double apertura, double cierre), que valide un invariante
// conjunto entre los dos: apertura debe ser mayor o igual a 0, cierre
// menor o igual a 24, y apertura estrictamente menor que cierre. Si el
// invariante se rompe, no modifica ningun atributo y devuelve false.
// Agrega tambien getHoraApertura() y getHoraCierre().
//
// Salida esperada:
// Horario aceptado (8 a 18): true
// Apertura: 8
// Cierre: 18
// Horario aceptado (20 a 10): false
// Apertura: 8
// Cierre: 18
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio6_horario_atencion.cpp -o bin/ejercicio6
// Ejecutar:  ./bin/ejercicio6

#include <iostream>

class HorarioAtencion {
private:
    double horaApertura;
    double horaCierre;

public:
    bool setHorario(double apertura, double cierre) {
        // TODO: valida apertura >= 0, cierre <= 24, apertura < cierre.
        // Si algo falla, retorna false sin modificar los atributos. Si
        // todo es valido, asigna los dos atributos juntos y retorna true.
        return false;
    }

    double getHoraApertura() {
        return horaApertura;
    }

    double getHoraCierre() {
        return horaCierre;
    }
};

int main() {
    HorarioAtencion h;

    bool resultado1 = h.setHorario(8.0, 18.0);
    std::cout << "Horario aceptado (8 a 18): " << std::boolalpha << resultado1 << std::endl;
    std::cout << "Apertura: " << h.getHoraApertura() << std::endl;
    std::cout << "Cierre: " << h.getHoraCierre() << std::endl;

    bool resultado2 = h.setHorario(20.0, 10.0);
    std::cout << "Horario aceptado (20 a 10): " << std::boolalpha << resultado2 << std::endl;
    std::cout << "Apertura: " << h.getHoraApertura() << std::endl;
    std::cout << "Cierre: " << h.getHoraCierre() << std::endl;

    return 0;
}
