// Ejercicio 1: Rectangulo con constructor y destructor
//
// getBase(), getAltura(), setBase() y setAltura() ya estan completos:
// son los mismos de la sesion pasada. Lo nuevo hoy es el constructor y
// el destructor, completa sus dos TODO.
//
// El constructor recibe baseInicial y alturaInicial, y debe usar los
// setters ya existentes para validarlos antes de asignarlos (no asignes
// base/altura directamente dentro del constructor: reusa setBase() y
// setAltura(), que ya verifican el invariante). Si un setter rechaza el
// valor, el constructor debe usar 1.0 como valor por defecto y avisar
// por consola.
//
// Salida esperada:
// Creando r1...
// Area r1: 50
// Creando r2 con base invalida...
// Aviso: base invalida, se uso 1.0 por defecto
// Area r2: 5
// Fin de main
// Rectangulo destruido: base=1, altura=5
// Rectangulo destruido: base=10, altura=5
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio1_rectangulo_constructor.cpp -o bin/ejercicio1
// Ejecutar:  ./bin/ejercicio1

#include <iostream>


class rectangulo {

        private:
                double base;
                double altura;
        public: 
                rectangulo(double base_i,double altura_i){
                if(!set_base(base_i)){base = 1;
                std:: cout<< "base invalida";}
                if(!set_altura(altura_i)){altura = 1;}
                base =base_i;
                altura= altura_i;
                }

                bool set_base(double n_base){
                    if (n_base <= 0){return false;}
                    base = n_base; 
                    return true;
                }
                
                bool set_altura(double n_altura){
                    if (n_altura <= 0){return false;}
                    base = n_altura; 
                    return true;
                }

                double area (){
                    return base * altura;
                }
                double perimetro() {
                    return 2 * (base + altura);
                }
            
};

int main() {
    std::cout << "Creando r1..." << std::endl;
    rectangulo r1(10.0, 5.0);
    std::cout << "Area r1: " << r1.area() << std::endl;

    std::cout << "Creando r2 con base invalida..." << std::endl;
    rectangulo r2(-3.0, 5.0);
    std::cout << "Area r2: " << r2.area() << std::endl;

    std::cout << "Fin de main" << std::endl;
    return 0;
}


