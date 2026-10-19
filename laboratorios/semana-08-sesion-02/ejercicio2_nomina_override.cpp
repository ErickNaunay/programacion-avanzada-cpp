#include <iostream>

class Empleado {
    private:
        int codigo;
    public:
        void setCodigo(int nuevoCodigo) {
            codigo = nuevoCodigo;
        }

        int getCodigo() {
            return codigo;
        }

        virtual double salarioMensual() {
            return 0.0;
        }

        virtual void imprimirRol() {
            std::cout << "Empleado sin rol";
        }
};

class Docente : public Empleado {
    private:
        double sueldoFijo;
    public:
        Docente(int nuevoCodigo, double nuevoSueldo) {
            setCodigo(nuevoCodigo);
            sueldoFijo = nuevoSueldo;
        }

        // TODO (paso 2): agrega "override" despues de "()" en los dos
        // metodos de esta clase.
        double salarioMensual() {
            return sueldoFijo;
        }

        void imprimirRol() {
            std::cout << "Docente";
        }
};

class Contratista : public Empleado {
    private:
        double tarifaPorHora;
        int horasDelMes;
    public:
        Contratista(int nuevoCodigo, double nuevaTarifa, int nuevasHoras) {
            setCodigo(nuevoCodigo);
            tarifaPorHora = nuevaTarifa;
            horasDelMes = nuevasHoras;
        }

        // TODO (paso 2): agrega "override" despues de la lista de
        // parametros en los dos metodos de esta clase y compila. Lee el
        // mensaje de error del compilador antes de corregir nada.
        //
        // TODO (paso 3): corrige el metodo que el compilador rechaza para
        // que de verdad redefina al de Empleado. Las horas ya estan
        // guardadas en el atributo horasDelMes.
        double salarioMensual(int horas) {
            return tarifaPorHora * horas;
        }

        void imprimirRol() {
            std::cout << "Contratista";
        }
};

int main() {
    Docente ana(101, 1800.0);
    Contratista luis(202, 25.0, 40);

    Empleado* nomina[2];
    nomina[0] = &ana;
    nomina[1] = &luis;

    double total = 0.0;
    for (int i = 0; i < 2; i++) {
        std::cout << "Codigo " << nomina[i]->getCodigo() << " (";
        nomina[i]->imprimirRol();
        std::cout << "): " << nomina[i]->salarioMensual() << std::endl;
        total = total + nomina[i]->salarioMensual();
    }
    std::cout << "Total de la nomina: " << total << std::endl;

    return 0;
}
