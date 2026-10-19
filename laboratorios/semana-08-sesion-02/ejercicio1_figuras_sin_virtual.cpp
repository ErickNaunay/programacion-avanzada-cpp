#include <iostream>

class Figura {
    public:
        // TODO (paso 2): antepone "virtual" a este metodo y vuelve a
        // compilar y ejecutar. Compara la salida con la del paso 1.
        double area() {
            return 0.0;
        }

        void describir() {
            std::cout << "Figura de area " << area() << std::endl;
        }
};

class Circulo : public Figura {
    private:
        double radio;
    public:
        Circulo(double nuevoRadio) {
            radio = nuevoRadio;
        }

        double area() {
            return 3.14159 * radio * radio;
        }
};

class Rectangulo : public Figura {
    private:
        double base;
        double altura;
    public:
        Rectangulo(double nuevaBase, double nuevaAltura) {
            base = nuevaBase;
            altura = nuevaAltura;
        }

        double area() {
            return base * altura;
        }
};

int main() {
    Circulo circulo(1.0);
    Rectangulo rectangulo(2.0, 3.0);

    std::cout << "Llamada directa:" << std::endl;
    std::cout << "Circulo: " << circulo.area() << std::endl;
    std::cout << "Rectangulo: " << rectangulo.area() << std::endl;

    // TODO (paso 1): declara un arreglo "Figura* figuras[2];", guarda en
    // figuras[0] la direccion de circulo y en figuras[1] la direccion de
    // rectangulo. Imprime "A traves de Figura*:" y, con un for, llama a
    // figuras[i]->describir() para cada posicion. Compila y ejecuta
    // antes de tocar la clase Figura.

    return 0;
}
