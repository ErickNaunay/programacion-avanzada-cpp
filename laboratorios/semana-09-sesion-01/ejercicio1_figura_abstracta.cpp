#include <iostream>
#include <memory>

class Figura {
    public:
        // TODO (paso 1): ninguna Figura "generica" tiene un area ni un
        // nombre que tenga sentido. Convierte estos dos metodos en
        // funciones virtuales puras.
        virtual double area() {
            return 0.0;
        }

        virtual void imprimirNombre() {
            std::cout << "Figura";
        }

        void describir() {
            imprimirNombre();
            std::cout << " de area " << area() << std::endl;
        }

        virtual ~Figura() {
        }
};

class Circulo : public Figura {
    private:
        double radio;
    public:
        Circulo(double nuevoRadio) {
            radio = nuevoRadio;
        }

        double area() override {
            return 3.14159 * radio * radio;
        }

        void imprimirNombre() override {
            std::cout << "Circulo";
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

        double area() override {
            return base * altura;
        }

        void imprimirNombre() override {
            std::cout << "Rectangulo";
        }
};

class Triangulo : public Figura {
    private:
        double base;
        double altura;
    public:
        Triangulo(double nuevaBase, double nuevaAltura) {
            base = nuevaBase;
            altura = nuevaAltura;
        }

        void imprimirNombre() override {
            std::cout << "Triangulo";
        }

        // TODO (paso 3): despues del paso 1, compila y lee el error que
        // aparece en main. Agrega lo que le falta a Triangulo.
};

int main() {
    // TODO (paso 2): despues del paso 1, quita el comentario de la
    // siguiente linea, compila, lee el error y vuelve a comentarla.
    // Figura generica;

    std::unique_ptr<Figura> figuras[3];
    figuras[0] = std::make_unique<Circulo>(1.0);
    figuras[1] = std::make_unique<Rectangulo>(2.0, 3.0);
    figuras[2] = std::make_unique<Triangulo>(4.0, 3.0);

    for (int i = 0; i < 3; i++) {
        figuras[i]->describir();
    }

    return 0;
}
