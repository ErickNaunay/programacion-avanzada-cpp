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
        if (nuevaEdad>0){
            edad=nuevaEdad;
            return true;
        }
        // TODO: si nuevaEdad es negativa, devuelve false sin modificar edad.
        // Si no, asigna edad = nuevaEdad y devuelve true.
        else{
        return false;}
    }

    bool setPesoKg(double nuevoPeso) {
        if(nuevoPeso>0){
            pesoKg=nuevoPeso;
            return true;
        }
        // TODO: mismo patron que setEdad(), pero para pesoKg (debe ser mayor que 0).
        else{
        return false;}
    }

    double getEdad() { return edad; }
    double getPesoKg() { return pesoKg; }

    void describir() {
        // TODO: imprime "Animal de " + edad + " anios, " + pesoKg + " kg "
        std::cout<<"Animal de "<<edad<<" anios, "<<pesoKg<<" kg "; 
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