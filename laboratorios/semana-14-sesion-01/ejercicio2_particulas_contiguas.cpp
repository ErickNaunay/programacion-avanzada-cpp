#include <iostream>
#include <vector>

// Ejercicio 2: las mismas particulas, una al lado de la otra.
//
// Misma explosion que ejercicio2_particulas_punteros.cpp, con la misma
// clase Particula. La diferencia es donde viven: aqui, todas dentro de un
// solo std::vector<Particula>, en memoria contigua. Las dos versiones
// tienen que imprimir la misma altura promedio.
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -O2 ejercicio2_particulas_contiguas.cpp -o bin/ejercicio2_contiguas
// Medir:     time ./bin/ejercicio2_contiguas

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
    // TODO 1: un std::vector<Particula> con espacio reservado para todas,
    // y las mismas particulas que la otra version (mismas velocidades),
    // agregadas con push_back(Particula(...)).

    // TODO 2: los CUADROS cuadros, actualizando cada particula con
    // dt = 1 / 60 de segundo.

    // TODO 3: la altura promedio al final, con el mismo mensaje que la otra
    // version.
    return 0;
}
