#include <iostream>
#include <memory>
#include <vector>

// Ejercicio 2: las particulas de un videojuego, cada una en su propia
// reserva de memoria. No lo modifiques: es la version contra la que
// comparas la tuya.
//
// Un juego a 60 cuadros por segundo tiene 16.7 milisegundos por cuadro para
// todo: la fisica, la logica, el dibujo. Este programa simula 10 segundos
// (600 cuadros) de una explosion con 300000 particulas, cada una creada con
// std::make_unique, como se crean los objetos de un juego a medida que
// aparecen (entre particula y particula, el juego reserva otras cosas: aqui,
// un bloque de relleno).
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -O2 ejercicio2_particulas_punteros.cpp -o bin/ejercicio2_punteros
// Medir:     time ./bin/ejercicio2_punteros

const int PARTICULAS = 300000;
const int CUADROS = 600;

class Particula {
public:
    Particula(float x0, float y0, float vx0, float vy0) {
        x = x0;
        y = y0;
        vx = vx0;
        vy = vy0;
    }

    void actualizar(float dt) {
        vy -= 9.8f * dt;
        x += vx * dt;
        y += vy * dt;
        if (y < 0) {
            y = -y;
            vy = -vy * 0.5f;
        }
    }

    float getY() {
        return y;
    }

private:
    float x;
    float y;
    float vx;
    float vy;
};

int main() {
    std::vector<std::unique_ptr<Particula>> particulas;
    std::vector<std::unique_ptr<char[]>> relleno;
    for (int i = 0; i < PARTICULAS; i++) {
        float vx = (i % 200) - 100.0f;
        float vy = (i % 97) * 1.5f;
        particulas.push_back(std::make_unique<Particula>(0.0f, 10.0f, vx, vy));
        relleno.push_back(std::make_unique<char[]>(32 + (i * 37) % 256));
    }
    for (int cuadro = 0; cuadro < CUADROS; cuadro++) {
        for (int i = 0; i < PARTICULAS; i++) {
            particulas[i]->actualizar(1.0f / 60.0f);
        }
    }
    double alturaTotal = 0;
    for (int i = 0; i < PARTICULAS; i++) {
        alturaTotal += particulas[i]->getY();
    }
    std::cout << "Altura promedio al final: " << alturaTotal / PARTICULAS << std::endl;
    return 0;
}
