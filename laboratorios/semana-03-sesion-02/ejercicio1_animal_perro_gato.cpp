#include <iostream>

class Animal {
private:
    double edad;
    double pesoKg;

public:
    Animal() {
        edad = 0.0;
        pesoKg = 0.0;
    }

    bool setEdad(double nuevaEdad) {
        // TODO: si nuevaEdad es negativa, devuelve false sin modificar edad.
        // Si no, asigna edad = nuevaEdad y devuelve true.
        if (nuevaEdad < 0) {
            return false;
        } else {
            edad = nuevaEdad;
            return true;
        }
        return false;
    }

    bool setPesoKg(double nuevoPeso) {
        // TODO: mismo patron que setEdad(), pero para pesoKg (debe ser mayor que 0).
        if (nuevoPeso <= 0) {
            return false;
        } else {
            pesoKg = nuevoPeso;
            return true;
        }
        return false;
    }

    double getEdad() { return edad; }
    double getPesoKg() { return pesoKg; }

    void describir() {
        // TODO: imprime "Animal de " + edad + " anios, " + pesoKg + " kg"
        std::cout << "Animal de " << edad << " anios, " << pesoKg << " kg" << std::endl;
    }
};
    private:
        int edad;
        double peso;
    public:
        
        Animal() {
            edad = 0;
            peso = 0;
        }

        Animal(int edad_inicial, double peso_inicial){
            if (!setEdad(edad_inicial)) { edad = 0; }
            if (!setPeso(peso_inicial)) { peso = 0.0; }
        }

        bool setEdad(double nueva_edad){
            if(nueva_edad < 0) { return false; }
            edad = nueva_edad;
            return true;
        }

        bool setPeso(double nuevo_peso){
            if(nuevo_peso <= 0) { return false; }
            peso = nuevo_peso;
            return true;
        }

        double getPeso(){ return peso; }
        int getEdad(){ return edad; }

        void describir(){
            std::cout << "Animal de: " << edad << " anios, " << peso << " kg" << std::endl;
        }

};
class Perro: public Animal {
    public:
        void ladrar() {
            std::cout << "Guau!" << std::endl;
        }
};

class Gato: public Animal {
    public:
        void maullar() {
            std::cout << "Miuau!" << std::endl;
        }

};


int main(){

    Animal a;
    a.describir();

    Perro p;
    p.setEdad(4);
    p.setPeso(10);

    p.describir();
    p.ladrar();

    Gato g;
    g.setEdad(3);
    g.setPeso(3);
    
    g.describir();
    g.maullar();

    return 0;
}