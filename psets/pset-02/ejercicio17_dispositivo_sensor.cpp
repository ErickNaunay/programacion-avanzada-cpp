// Ejercicio 17: Dispositivo, DispositivoConectado y SensorTemperatura
// (desde cero, herencia de tres niveles)
//
// Este archivo no tiene codigo de partida. Escribe tu de tu propia clase,
// tus propios includes y tu propio main().
//
// Disena tres clases en cadena:
//
// Dispositivo: atributo privado consumoWatts (double). Setter bool
// setConsumoWatts(double c) valido si c es mayor a 0 y menor o igual a 100.
// Getter double getConsumoWatts().
//
// DispositivoConectado: hereda publicamente de Dispositivo. Agrega atributo
// privado canalRed (int). Setter bool setCanalRed(int c) valido si c esta
// entre 1 y 11 (ambos incluidos). Getter int getCanalRed().
//
// SensorTemperatura: hereda publicamente de DispositivoConectado. Agrega
// atributo privado lecturaActual (double). Setter bool
// setLecturaActual(double l) valido si l esta entre -40 y 125 (ambos
// incluidos). Getter double getLecturaActual(). Metodo bool alertaCritica()
// que devuelve true si lecturaActual es mayor a 100, false en cualquier
// otro caso.
//
// En main(): crea un SensorTemperatura. Asignale consumoWatts = 5.5 (setter
// heredado de Dispositivo), canalRed = 6 (setter heredado de
// DispositivoConectado), y lecturaActual = 45.0 (setter propio). Imprime el
// resultado de alertaCritica() con esa lectura, precedido por "Alerta con
// 45.0: ". Despues cambia lecturaActual a 110.0 e imprime alertaCritica()
// otra vez, precedido por "Alerta con 110.0: ". Imprime consumoWatts
// precedido por "Consumo: " y canalRed precedido por "Canal: ". Los valores
// booleanos se imprimen como "true" o "false" (usa std::boolalpha antes de
// imprimirlos).
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio17 ejercicio17_dispositivo_sensor.cpp
// Ejecutar: ./ejercicio17
//
// Salida esperada:
// Alerta con 45.0: false
// Alerta con 110.0: true
// Consumo: 5.5
// Canal: 6

#include <iostream>

class Dispositivo{
    private:
    double consumoWatts;
    public:

    bool setConsumoWats(double c){
        if(c > 0 and c <= 100){
            consumoWatts = c;
            return true;
        }
        return false;
    }

    double getConsumo(){
        return consumoWatts;
    }

};

class DispositivoConectado: public Dispositivo{
    private:
    int canalRed;

    public:

    bool setCanal(int c){
        if(c >= 1 and c <= 11){
            canalRed = c;
            return true;
        }
        return false;
    }

    int getCanal(){
        return canalRed;
    }
};

class SensorTemperatura: public DispositivoConectado{
    private:
    double LecturaActual;

    public:
    bool setLecturaActual(int l){
        if(l >= -40 and l <= 125){
            LecturaActual = l;
            return true;
        }
        return false;
    }

    double getLectura(){
        return LecturaActual;
    }

    bool AlertaCritica(){
        if(LecturaActual > 100){
            return true;
        }
        return false;
    }
};


int main(){
    std::cout<<std::boolalpha;

    SensorTemperatura s1;
    s1.setConsumoWats(5.5);
    s1.setCanal(6);
    s1.setLecturaActual(45);
    std::cout<<"Alerta con "<<s1.getLectura()<<": "<<s1.AlertaCritica()<<std::endl;
    s1.setLecturaActual(110.0);
    std::cout<<"Alerta con "<<s1.getLectura()<<": "<<s1.AlertaCritica()<<std::endl;
    std::cout<<"Consumo: "<<s1.getConsumo()<<std::endl;
    std::cout<<"Canal: "<<s1.getCanal()<<std::endl;

}