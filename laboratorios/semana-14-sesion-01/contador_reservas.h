#pragma once

#include <cstdlib>
#include <new>

// Cuenta cuantas veces el programa pide memoria dinamica. No lo modifiques:
// usa construcciones que el curso no vio (reemplazar el operator new de
// todo el programa), y solo sirve para medir.
//
// Cada new, make_unique, push_back que hace crecer un vector o nodo nuevo
// de una lista o un map pasa por aqui y suma 1 a reservasHechas.

inline long long reservasHechas = 0;

void* operator new(std::size_t bytes) {
    reservasHechas++;
    void* memoria = std::malloc(bytes == 0 ? 1 : bytes);
    if (memoria == nullptr) {
        throw std::bad_alloc();
    }
    return memoria;
}

void operator delete(void* memoria) noexcept {
    std::free(memoria);
}

void operator delete(void* memoria, std::size_t) noexcept {
    std::free(memoria);
}
