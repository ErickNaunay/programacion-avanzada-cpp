    #include <iostream>

    class Vehiculo {
        private:
            double velocidadKmh;
            double kilometraje;
        public:
            Vehiculo() {
                velocidadKmh = 0;
                kilometraje = 0;
            }

            bool setVelocidadKmh(double nuevaVelocidad) {
                if (nuevaVelocidad < 0) { return false; }
                velocidadKmh = nuevaVelocidad;
                return true;
            }

            bool setKilometraje(double nuevoKilometraje) {
                if (nuevoKilometraje < 0) { return false; }
                kilometraje = nuevoKilometraje;
                return true;
            }

            void describir() {
                std::cout << "Vehiculo a " << velocidadKmh << " km/h, " << kilometraje << " km recorridos" << std::endl;
            }
    };

    class Motor {
        private:
            int potenciaHP;
            bool encendido;
        public:
            Motor() {
                potenciaHP = 0;
                encendido = false;
            }

            bool setPotenciaHP(int nuevaPotencia) {
                if (nuevaPotencia <= 0) { return false; }
                potenciaHP = nuevaPotencia;
                return true;
            }

            void encender() {
                encendido = true;
                std::cout << "Motor de " << potenciaHP << " HP encendido" << std::endl;
            }

            void apagar() {
                encendido = false;
            }

            bool estaEncendido() {
                return encendido;
            }
    };

    // TODO: Carro sigue heredando de Vehiculo (relacion "es un", correcta).
    // En vez de heredar tambien de Motor, agrega un atributo privado "Motor motor;"
    // (relacion "tiene un", composicion) y escribe arrancar() delegando en el.
    class Carro: public Vehiculo {
        private:
             Motor motor;

        public:
            bool arrancar(int potenciaHP) {

                motor.setPotenciaHP(potenciaHP);

                motor.encender();
                return motor.estaEncendido();
            }

            void tocarBocina() {

                std::cout << "Piii!" << std::endl;
            }
};

    int main() {
        Carro c;
        c.setVelocidadKmh(120);
        c.setKilometraje(45000);
        c.describir();
        c.arrancar(150);
        c.tocarBocina();
        return 0;
    }                       
