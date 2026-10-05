#include <iostream>
#include <memory>
#include <utility>

class RegistroDeVuelo {
    private:
        // TODO: cambia "double* alturas" por std::unique_ptr<double[]>.
        std::unique_ptr<double[]> alturas;
        int capacidad;
    public:
        RegistroDeVuelo(int nuevaCapacidad) {
            capacidad = nuevaCapacidad;
            // TODO: crea "alturas" con std::make_unique<double[]>(capacidad)
            // en vez de "new double[capacidad]".
            alturas =std::make_unique<double[]>(capacidad);
            std::cout << "Registro de vuelo creado para " << capacidad << " lecturas" << std::endl;
        }

        void guardarAltura(int indice, double valor) {
            alturas[indice] = valor;
        }

        double getAltura(int indice) {
            return alturas[indice];
        }

        // TODO: con unique_ptr como atributo, ya no hace falta nada de
        // esto. Borra el destructor completo (unique_ptr libera solo).
};

class MonitorDeVuelo {
    private:
        // TODO: declara "registro" como std::shared_ptr<RegistroDeVuelo>.
        std::shared_ptr<RegistroDeVuelo> registro;
        int idMonitor;
    public:
        // TODO: el constructor recibe std::shared_ptr<RegistroDeVuelo>
        // unRegistro por valor, y lo guarda con
        // registro = std::move(unRegistro); (mover el shared_ptr local
        // hacia el atributo evita una copia de mas, aunque la clase ya
        // permite copiar shared_ptr sin ningun riesgo).
        MonitorDeVuelo(int unId, std::shared_ptr<RegistroDeVuelo> nuevoRegistro) {
            idMonitor = unId;
            registro=std::move(nuevoRegistro);
            std::cout<<"Monitor"<<idMonitor<<" conectado. Cuenta: "<<registro.use_count()<<std::endl;
        }

        void reportar(int indice) {
            std::cout << "Monitor " << idMonitor << " ve altura " << 0.0 << std::endl;
            (void)indice;
        }

        ~MonitorDeVuelo() {
            std::cout << "Monitor " << idMonitor << " desconectado" << std::endl;
        }
};

int main() {
    RegistroDeVuelo registroSolo(3);
    registroSolo.guardarAltura(0, 100.0);
    std::cout << "registroSolo.getAltura(0) = " << registroSolo.getAltura(0) << std::endl;

    std::cout << "---" << std::endl;

    std::shared_ptr<RegistroDeVuelo> compartido=std::make_shared<RegistroDeVuelo>(5);
    compartido->guardarAltura(0,200.0);
    std::cout<<"Cuenta inicial: "<<compartido.use_count()<<std::endl;

    {
        MonitorDeVuelo torre_1(1, compartido);
        MonitorDeVuelo torre_2(2, compartido);
        MonitorDeVuelo torre_3(3, compartido);

        std::cout<<"Cuenta despues de monitores: "<<compartido.use_count()<<std::endl;

        torre_1.reportar(0);
        torre_2.reportar(0);
        torre_3.reportar(0);

    }
    std::cout<<"Cuenta final: "<<compartido.use_count()<<std::endl;

    // TODO: crea "compartido" con
    // std::make_shared<RegistroDeVuelo>(5) en vez de un objeto local.
    // Guarda una lectura en el indice 0 y muestra compartido.use_count().
    //
    // Despues, dentro de un bloque { }, crea dos MonitorDeVuelo pasandoles
    // "compartido" (torre con id 1, cabina con id 2), muestra
    // compartido.use_count() con los dos monitores activos, y llama a
    // reportar(0) en cada uno. Al cerrar el bloque, los monitores se
    // destruyen; muestra compartido.use_count() una vez mas para
    // confirmar que volvio a bajar.

    return 0;
}
