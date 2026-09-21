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
        if (nuevaEdad<0){ return false; }
        else { 
            edad=nuevaEdad;
            return true;
        }
    }

    bool setPesoKg(double nuevoPeso) {
        // TODO: mismo patron que setEdad(), pero para pesoKg (debe ser mayor que 0).
        if (nuevoPeso<=0){ return false;}
        else{
            pesoKg=nuevoPeso;
            return true;
        }
    }

    double getEdad() { return edad; }
    double getPesoKg() { return pesoKg; }

    void describir() {
        // TODO: imprime "Animal de " + edad + " anios, " + pesoKg + " kg"
        std::cout<<"Animal de "<<getEdad()<<" anios, "<<getPesoKg()<<" kg"<<std::endl;
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