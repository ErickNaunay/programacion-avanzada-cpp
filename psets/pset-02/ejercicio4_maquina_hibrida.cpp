// Ejercicio 4: Maquina, MaquinaElectrica, MaquinaTermica e Hibrida
// (herencia multiple con el problema del diamante, ya resuelto con herencia virtual)
//
// Completa los metodos marcados con TODO. No cambies las firmas, la jerarquia
// de herencia ni el main(). Fijate que MaquinaElectrica y MaquinaTermica heredan
// de Maquina con "public virtual": por eso Hibrida termina con una sola copia
// de Maquina en vez de dos copias ambiguas.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio4 ejercicio4_maquina_hibrida.cpp
// Ejecutar: ./ejercicio4
//
// Salida esperada:
// Potencia: 3200
// Voltaje: 220
// Temperatura maxima: 450
// Modo electrico: true

#include <iostream>

class Maquina {
private:
    double potenciaWatts;
public:
    bool setPotenciaWatts(double p) {
        // TODO: valida que p sea mayor a 0 y menor o igual a 5000.
        if (p > 0 && p <= 5000) {
            potenciaWatts = p;
            return true;
        }
        return false;
    }
    double getPotenciaWatts() {
        // TODO: devuelve potenciaWatts.
        return potenciaWatts;
    }
};

class MaquinaElectrica : public virtual Maquina {
private:
    double voltaje;
public:
    bool setVoltaje(double v) {
        // TODO: valida que v sea mayor a 0 y menor o igual a 240.
        if (v > 0 && v <= 240) {
            voltaje = v;
            return true;
        }
        return false;
    }
    double getVoltaje() {
        // TODO: devuelve voltaje.
        return voltaje;
    }
};

class MaquinaTermica : public virtual Maquina {
private:
    double temperaturaMaxima;
public:
    bool setTemperaturaMaxima(double t) {
        // TODO: valida que t sea mayor a 0 y menor o igual a 1000.
        if (t > 0 && t <= 1000) {
            temperaturaMaxima = t;
            return true;
        }
        return false;
    }
    double getTemperaturaMaxima() {
        // TODO: devuelve temperaturaMaxima.
        return temperaturaMaxima;
    }
};

class Hibrida : public MaquinaElectrica, public MaquinaTermica {
private:
    bool modoElectrico;
public:
    void setModoElectrico(bool m) {
        // TODO: asigna modoElectrico. No hay invariante que validar.
        modoElectrico = m;
    }
    bool getModoElectrico() {
        // TODO: devuelve modoElectrico.
        return modoElectrico;
    }
};

int main() {
    Hibrida h1;
    h1.setPotenciaWatts(3200);
    h1.setVoltaje(220);
    h1.setTemperaturaMaxima(450);
    h1.setModoElectrico(true);
    std::cout << "Potencia: " << h1.getPotenciaWatts() << std::endl;
    std::cout << "Voltaje: " << h1.getVoltaje() << std::endl;
    std::cout << "Temperatura maxima: " << h1.getTemperaturaMaxima() << std::endl;
    std::cout << "Modo electrico: " << std::boolalpha << h1.getModoElectrico() << std::endl;
    return 0;
}
