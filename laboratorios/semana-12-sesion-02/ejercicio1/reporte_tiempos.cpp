#include <iostream>
#include <vector>

// Reporte de cuanto tiempo estuvo cada placa en el estacionamiento, a
// partir del registro de entradas y salidas del dia (en minutos desde las
// 7:00). Compila sin advertencias, y termina antes de tiempo.
//
// Salida esperada:
// Placa 4521: 95 minutos
// Placa 7788: 40 minutos
// Placa 5555: sin registro hoy
// Placa 3011: 210 minutos

class Estadia {
    private:
        int placa;
        int entrada;
        int salida;
    public:
        Estadia(int p, int e, int s) {
            placa = p;
            entrada = e;
            salida = s;
        }

        int getPlaca() {
            return placa;
        }

        int getEntrada() {
            return entrada;
        }

        int getSalida() {
            return salida;
        }
};

class RegistroDelDia {
    private:
        std::vector<Estadia> estadias;
    public:
        void agregar(Estadia estadia) {
            estadias.push_back(estadia);
        }

        int cantidad() {
            return estadias.size();
        }

        // Devuelve la ultima estadia de la placa, o nullptr si no hay.
        Estadia* ultimaDe(int placa) {
            Estadia* encontrada = nullptr;
            for (int i = 0; i < cantidad(); i++) {
                if (estadias[i].getPlaca() == placa) {
                    encontrada = &estadias[i];
                }
            }
            return encontrada;
        }
};

int minutosDe(RegistroDelDia* registro, int placa) {
    Estadia* estadia = registro->ultimaDe(placa);
    return estadia->getSalida() - estadia->getEntrada();
}

int main() {
    RegistroDelDia registro;
    registro.agregar(Estadia(4521, 10, 105));
    registro.agregar(Estadia(7788, 30, 70));
    registro.agregar(Estadia(3011, 60, 270));

    int placas[4] = {4521, 7788, 5555, 3011};
    for (int i = 0; i < 4; i++) {
        int minutos = minutosDe(&registro, placas[i]);
        std::cout << "Placa " << placas[i] << ": " << minutos << " minutos" << std::endl;
    }

    return 0;
}
