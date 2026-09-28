// Ejercicio 25: Motor, TituloPropiedad, Vehiculo y Concesionario
// (desde cero, integrador final: composicion + operator<< + unique_ptr +
// shared_ptr en el mismo sistema)
//
// Este archivo no tiene codigo de partida. Escribe tu de tu propia clase,
// tus propios includes (necesitas <memory> ademas de <iostream>) y tu
// propio main(). Este es el ejercicio mas exigente del PSet: junta todo lo
// que practicaste en los ejercicios anteriores en un solo sistema.
//
// Disena cuatro clases:
//
// Motor: atributo privado potenciaHP (double). Setter bool
// setPotenciaHP(double p) valido si p es mayor a 0 y menor o igual a 1000.
// Getter double getPotenciaHP(). operator<< como funcion libre que recibe
// std::ostream& y un Motor por valor, e imprime "Motor de " seguido de la
// potencia y " HP".
//
// TituloPropiedad: atributo privado numeroRegistro (int). Setter bool
// setNumeroRegistro(int n) valido si n esta entre 1000 y 999999 (ambos
// incluidos). Getter int getNumeroRegistro().
//
// Vehiculo: un motor propio, exclusivo de este vehiculo (nunca dos
// vehiculos comparten el mismo motor), representado como
// std::unique_ptr<Motor>. Un titulo de propiedad compartido, representado
// como std::shared_ptr<TituloPropiedad> (el mismo titulo puede estar
// registrado en el vehiculo y en el concesionario a la vez). Necesitas dos
// constructores: uno sin parametros (el vehiculo empieza sin motor, con el
// unique_ptr en su valor por defecto, que ya es nullptr sin que tengas que
// hacer nada) y otro Vehiculo(std::unique_ptr<Motor> motorInicial) que
// mueve motorInicial hacia el motor propio del vehiculo con std::move.
// Metodo void registrarTitulo(std::shared_ptr<TituloPropiedad> t) que
// asigna el titulo propio del vehiculo. Metodo bool tieneMotor() que
// devuelve true si el motor propio no es nullptr. Metodo void
// mostrarMotor() que imprime el motor con cout (usando tu operator<<,
// desreferenciando el unique_ptr) si tieneMotor() es true, o "Vehiculo sin
// motor" seguido de un salto de linea si es false. Metodo
// std::unique_ptr<Motor> extraerMotor() que devuelve std::move(motor
// propio) (el vehiculo se queda sin motor despues de llamar a este
// metodo). Metodo void recibirMotor(std::unique_ptr<Motor> nuevoMotor) que
// mueve nuevoMotor hacia el motor propio del vehiculo.
//
// Concesionario: un titulo de propiedad compartido, representado como
// std::shared_ptr<TituloPropiedad>. Metodo void
// archivarTitulo(std::shared_ptr<TituloPropiedad> t) que asigna su
// titulo. Metodo int referenciasTitulo() que devuelve
// tituloEnRegistro.use_count().
//
// En main(), en este orden exacto:
// 1. Crea un std::shared_ptr<TituloPropiedad> con std::make_shared,
//    llamalo titulo, y asignale numeroRegistro = 4521.
// 2. Crea un std::unique_ptr<Motor> con std::make_unique, llamalo motor1,
//    y asignale potenciaHP = 180.
// 3. Crea un Vehiculo llamado vehiculo1, pasando motor1 movido con
//    std::move al constructor que recibe un motor.
// 4. Llama a vehiculo1.registrarTitulo(titulo).
// 5. Crea un Concesionario llamado concesionario1 y llama a
//    concesionario1.archivarTitulo(titulo).
// 6. Imprime concesionario1.referenciasTitulo(), precedido por
//    "Referencias al titulo: ".
// 7. Imprime "Motor del vehiculo 1: " (sin salto de linea) y despues
//    llama a vehiculo1.mostrarMotor().
// 8. Crea un segundo Vehiculo llamado vehiculo2, con el constructor sin
//    parametros (sin motor). Imprime "Motor del vehiculo 2 antes: " (sin
//    salto de linea) y despues llama a vehiculo2.mostrarMotor().
// 9. Llama a vehiculo2.recibirMotor(vehiculo1.extraerMotor()) (el motor
//    pasa del vehiculo 1 al vehiculo 2).
// 10. Imprime "Motor del vehiculo 1 despues: " (sin salto de linea) y
//     llama a vehiculo1.mostrarMotor(). Imprime "Motor del vehiculo 2
//     despues: " (sin salto de linea) y llama a vehiculo2.mostrarMotor().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio25 ejercicio25_vehiculo_titulo.cpp
// Ejecutar: ./ejercicio25
//
// Salida esperada:
// Referencias al titulo: 3
// Motor del vehiculo 1: Motor de 180 HP
// Motor del vehiculo 2 antes: Vehiculo sin motor
// Motor del vehiculo 1 despues: Vehiculo sin motor
// Motor del vehiculo 2 despues: Motor de 180 HP

#include <iostream>
#include <memory>

class Motor {
private:
    double potenciaHP;
public:
    bool setPotenciaHP(double p) {
        if (p > 0 && p <= 1000) {
            potenciaHP = p;
            return true;
        }
        return false;
    }
    double getPotenciaHP() const {
        return potenciaHP;
    }
    friend std::ostream& operator<<(std::ostream& os, const Motor& m) {
        os << "Motor de " << m.getPotenciaHP() << " HP";
        return os;
    }
};

class TituloPropiedad {
private:
    int numeroRegistro;
public:
    bool setNumeroRegistro(int n) { 
        if (n >= 1000 && n <= 999999) {
            numeroRegistro = n;
            return true;
        }
        return false;
    }
    int getNumeroRegistro() const {
        return numeroRegistro;
    }
};

class Vehiculo {
private:
    std::unique_ptr<Motor> motor;
    std::shared_ptr<TituloPropiedad> titulo;
public:
    Vehiculo() : motor(nullptr) {}
    Vehiculo(std::unique_ptr<Motor> motorInicial) : motor(std::move(motorInicial)) {}
    void registrarTitulo(std::shared_ptr<TituloPropiedad> t) {
        titulo = t;
    }
    bool tieneMotor() const {
        return motor != nullptr;
    }
    void mostrarMotor() const {
        if (tieneMotor()) {
            std::cout << *motor << std::endl;
        } else {
            std::cout << "Vehiculo sin motor" << std::endl;
        }
    }
    std::unique_ptr<Motor> extraerMotor() {
        return std::move(motor);
    }
    void recibirMotor(std::unique_ptr<Motor> nuevoMotor) {
        motor = std::move(nuevoMotor);
    }
};

class Concesionario {
private:
    std::shared_ptr<TituloPropiedad> tituloEnRegistro;
public:
    void archivarTitulo(std::shared_ptr<TituloPropiedad> t) {
        tituloEnRegistro = t;
    }
    int referenciasTitulo() const {
        return tituloEnRegistro.use_count();
    }
};

int main() {
    auto titulo = std::make_shared<TituloPropiedad>();
    titulo->setNumeroRegistro(4521);

    auto motor1 = std::make_unique<Motor>();
    motor1->setPotenciaHP(180);

    Vehiculo vehiculo1(std::move(motor1));
    vehiculo1.registrarTitulo(titulo);

    Concesionario concesionario1;
    concesionario1.archivarTitulo(titulo);

    std::cout << "Referencias al titulo: " << concesionario1.referenciasTitulo() << std::endl;

    std::cout << "Motor del vehiculo 1: ";
    vehiculo1.mostrarMotor();

    Vehiculo vehiculo2;
    std::cout << "Motor del vehiculo 2 antes: ";
    vehiculo2.mostrarMotor();

    vehiculo2.recibirMotor(vehiculo1.extraerMotor());

    std::cout << "Motor del vehiculo 1 despues: ";
    vehiculo1.mostrarMotor();
    
    std::cout << "Motor del vehiculo 2 despues: ";
    vehiculo2.mostrarMotor();

    return 0;
}