#include <iostream>
#include <vector>

// Ejercicio 2: las mismas particulas, una al lado de la otra.
//
// Misma explosion que ejercicio2_particulas_punteros.cpp, con la misma
// clase Particula. La diferencia es donde viven: aqui, todas dentro de un
// solo std::vector<Particula>, en memoria contigua. Las dos versiones
// tienen que imprimir la misma altura promedio.
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -O2 ejercicio2_particulas_contiguas.cpp -o ejercicio2_contiguas
// Medir:     time ./ejercicio2_contiguas

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
    std::vector<Particula> particulas;
    particulas.reserve(PARTICULAS);

    unsigned int semilla = 12345;
    for (int i = 0; i < PARTICULAS; i++) {
        semilla = semilla * 1103515245 + 12345;
        float vx = -10.0f + ((semilla >> 8) % 2000) / 100.0f;
        semilla = semilla * 1103515245 + 12345;
        float vy = 10.0f + ((semilla >> 8) % 2000) / 100.0f;
        particulas.push_back(Particula(0.0f, 0.0f, vx, vy));
    }

    float dt = 1.0f / 60.0f;
    for (int c = 0; c < CUADROS; c++) {
        for (int i = 0; i < PARTICULAS; i++) {
            particulas[i].actualizar(dt);
        }
    }

    double sumaY = 0.0;
    for (int i = 0; i < PARTICULAS; i++) {
        sumaY += particulas[i].getY();
    }

    std::cout << "Altura promedio: " << sumaY / PARTICULAS << std::endl;
    return 0;
}