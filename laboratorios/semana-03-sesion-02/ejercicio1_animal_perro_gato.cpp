// Ejercicio 1: Animal, Perro y Gato
//
// Sin herencia, Perro y Gato repetirían, línea por línea, los mismos
// atributos, setters, getters y describir(). Animal agrupa eso una
// sola vez; Perro y Gato heredan de Animal (`: public Animal`, ya
// escrito abajo) y solo agregan lo que de verdad es propio de cada uno.
//
// Completa los TODO en Animal: el mismo patrón de setters con
// invariante que ya conoces de sesiones anteriores.
//
// Salida esperada:
// Animal de 3 anios, 12 kg
// Guau!
// Animal de 2 anios, 4.5 kg
// Miau!
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio1_animal_perro_gato.cpp -o bin/ejercicio1
// Ejecutar:  ./bin/ejercicio1

#include <iostream>
using namespace std;
class Animal {
private:
    double edad;
    double pesoKg;

public:
    Animal() {
        edad = 0.0;
        pesoKg = 0.0;
    }

    bool setedad(double nuevaEdad) {
        
        if(nuevaEdad<0){
            return false;
        }
        edad=nuevaEdad;
        return true;
        
        // TODO: si nuevaEdad es negativa, devuelve false sin modificar edad.
        // Si no, asigna edad = nuevaEdad y devuelve true.
    }

    bool setpesoKg(double nuevoPeso) {
        if(nuevoPeso<=0){
            return false;
}else{
        pesoKg=nuevoPeso;
        return true; }
        // TODO: mismo patron que setEdad(), pero para pesoKg (debe ser mayor que 0).
    }

    double getedad() { return edad; }
    double getpesoKg() { return pesoKg; }

    void describir() {
        cout<<"Animal de: "<<getedad()<<" anios, "<<getpesoKg()<<"kg"<<endl;
        
        
        // TODO: imprime "Animal de " + edad + " anios, " + pesoKg + " kg"
    }

};

/// asi se hace para heredar : public animal, privado tambien se hereda pero no tiene acceso ///

class Perro : public Animal {

public:
    void ladrar() {
        std::cout << "Guau!" << std::endl;
    }
};

class Gato : public Animal {
public:
    void maullar() {
        std::cout << "Miau!" << std::endl;
    }
};

int main() {
    Perro p;
    p.setedad(3.0);
    p.setpesoKg(12.0);
    p.describir();
    p.ladrar();

    Gato g;
    g.setedad(2.0);
    g.setpesoKg(4.5);
    g.describir();
    g.maullar();

    return 0;
}
