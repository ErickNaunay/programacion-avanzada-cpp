// Ejercicio 15: SesionEstudio (integrador, desde cero)
//
// Este ejercicio no trae código de partida: escribe tú el archivo
// completo, incluyendo los #include y el main(). Integra todo lo
// practicado en PSet 1: invariante conjunto, constructor con valor por
// defecto ante un dato inválido, y destructor.
//
// Diseña una class SesionEstudio con:
// - Atributos privados horaInicio, horaFin (double) y
//   minutosDescansoAsignado (entero).
// - Constructor SesionEstudio(int minutosDescanso): si minutosDescanso
//   es menor o igual a 0, o mayor a 60, imprime exactamente "Descanso
//   invalido, se asignan 10 minutos por defecto" y asigna
//   minutosDescansoAsignado = 10. Si es válido, lo asigna directamente,
//   sin imprimir nada.
// - Un setter que devuelva bool, setHorario(double inicio, double fin),
//   con el mismo invariante conjunto de otros ejercicios de este PSet:
//   inicio >= 0, fin <= 24, inicio < fin.
// - El getter getMinutosDescanso().
// - Un destructor que imprima exactamente "Sesion de estudio
//   finalizada".
//
// Tu main() debe, dentro de un bloque `{ }` (para que los objetos se
// destruyan al salir de él, en orden LIFO):
// 1. Crear s1 con SesionEstudio(20) (válido, no imprime nada). Llamar a
//    s1.setHorario(8.0, 10.0) (válido) e imprimir "Horario 1 aceptado: "
//    seguido del resultado con std::boolalpha.
// 2. Crear s2 con SesionEstudio(90) (inválido, dispara el mensaje del
//    constructor). Llamar a s2.setHorario(23.0, 22.0) (inválido) e
//    imprimir "Horario 2 aceptado: " seguido del resultado.
// 3. Crear s3 con SesionEstudio(15) (válido). Llamar a
//    s3.setHorario(14.0, 16.0) (válido) e imprimir "Horario 3
//    aceptado: " seguido del resultado.
// 4. Imprimir exactamente "--- fin del bloque ---".
//
// Salida esperada, exactamente:
// Horario 1 aceptado: true
// Descanso invalido, se asignan 10 minutos por defecto
// Horario 2 aceptado: false
// Horario 3 aceptado: true
// --- fin del bloque ---
// Sesion de estudio finalizada
// Sesion de estudio finalizada
// Sesion de estudio finalizada
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio15_sesion_estudio.cpp -o bin/ejercicio15
// Ejecutar:  ./bin/ejercicio15
#include <iostream>
using namespace std;

class SesionEstudio {

private:
    double horaInicio;
    double horaFin;
    int minutosDescansoAsignado;

public:

    // Constructor
    SesionEstudio(int minutosDescanso) {

        if (minutosDescanso <= 0 || minutosDescanso > 60) {
            cout << "Descanso invalido, se asignan 10 minutos por defecto" << endl;
            minutosDescansoAsignado = 10;
        } else {
            minutosDescansoAsignado = minutosDescanso;
        }
    }

    // Setter
    bool setHorario(double inicio, double fin) {

        if (inicio >= 0 && fin <= 24 && inicio < fin) {
            horaInicio = inicio;
            horaFin = fin;
            return true;
        }

        return false;
    }

    // Getter
    int getMinutosDescanso() {
        return minutosDescansoAsignado;
    }

    // Destructor
    ~SesionEstudio() {
        cout << "Sesion de estudio finalizada" << endl;
    }
};

int main() {

    {
        SesionEstudio s1(20);

        bool resultado1 = s1.setHorario(8.0, 10.0);

        cout << "Horario 1 aceptado: "
             << boolalpha << resultado1 << endl;


        SesionEstudio s2(90);

        bool resultado2 = s2.setHorario(23.0, 22.0);

        cout << "Horario 2 aceptado: "
             << boolalpha << resultado2 << endl;


        SesionEstudio s3(15);

        bool resultado3 = s3.setHorario(14.0, 16.0);

        cout << "Horario 3 aceptado: "
             << boolalpha << resultado3 << endl;


        cout << "--- fin del bloque ---" << endl;
    }

    return 0;
}