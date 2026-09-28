// Ejercicio 6: Lapiz y Estuche (composicion con dos miembros)
//
// Completa los metodos marcados con TODO. No cambies las firmas ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio6 ejercicio6_lapiz_estuche.cpp
// Ejecutar: ./ejercicio6
//
// Salida esperada:
// Lapiz 1 es el mas largo: false

#include <iostream>

class Lapiz {
private:
    double longitudCm;
public:
    bool setLongitudCm(double l) {
        if (l <= 1 || l > 30) {
            return false;
        }

        longitudCm = l;
        return true;
    }

    double getLongitudCm() {
        return longitudCm;
    }
};

class Estuche {
private:
    Lapiz lapiz1;
    Lapiz lapiz2;
public:
    bool configurarLapiz1(double l) {
        return lapiz1.setLongitudCm(l);
    }

    bool configurarLapiz2(double l) {
        return lapiz2.setLongitudCm(l);
    }

    bool lapizMasLargo() {
        return lapiz1.getLongitudCm() >= lapiz2.getLongitudCm();
    }
};

int main() {
    Estuche estuche1;
    estuche1.configurarLapiz1(12.5);
    estuche1.configurarLapiz2(18.0);
    std::cout << "Lapiz 1 es el mas largo: " << std::boolalpha << estuche1.lapizMasLargo() << std::endl;
    return 0;
}
