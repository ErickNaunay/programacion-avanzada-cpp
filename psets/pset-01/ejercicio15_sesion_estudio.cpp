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

class sesion_estudio{
    private:
    double hora_inicio{0};
    double hora_fin{0};
    int minuto_descanso_asignado{0};
    public:
    sesion_estudio(int minutos_descanso){
        if(minutos_descanso <= 0 or minutos_descanso > 60){
            cout<<"Descanso invalido, se asignan 10 minutos por defecto"<<endl;
            minuto_descanso_asignado = 10.0;
        }else{
            minuto_descanso_asignado = minutos_descanso;
        }
    }

    bool set_horario(double inicio, double fin){
        if(inicio >= 0, fin <= 24, fin > inicio){
            hora_inicio = inicio;
            hora_fin = fin;
            return true;
        }
        return false;
    }

    int get_minutos_descanso(){
        return minuto_descanso_asignado;
    }

    ~sesion_estudio(){
        cout<<"Sesion de estudio finalizada"<<endl;
    }

};

int main(){

    sesion_estudio s1(20);
    cout<<boolalpha;
    cout<< "Horario 1 aceptado: "<< s1.set_horario(8.0, 10.0)<<endl;
    sesion_estudio s2(90);
    cout<< "Horario 2 aceptado: "<< s2.set_horario(23.0,22.0)<<endl;
    sesion_estudio s3(15);
    cout<<"Horario 3 aceptado: "<< s3.set_horario(14.0,16.0)<<endl;
    cout<<"--- fin del bloque ---"<<endl;


}