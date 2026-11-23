#pragma once

// terminal.h: entrada y salida de la terminal para el juego.
//
// Este archivo te lo doy hecho. No lo modifiques. Solo main.cpp lo incluye:
// la logica del juego, la simulacion y las pruebas no deben depender de el.
//
// Funciona en Linux y macOS (y en el devcontainer del curso).

#include <chrono>
#include <iostream>
#include <optional>
#include <thread>

#include <poll.h>
#include <termios.h>
#include <unistd.h>

inline termios& configuracionOriginalDeLaTerminal() {
    static termios original;
    return original;
}

// Apaga el eco y la espera de Enter: cada tecla llega apenas se presiona.
// Tambien oculta el cursor. Llamala una sola vez, al inicio.
inline void activarModoCrudo() {
    tcgetattr(STDIN_FILENO, &configuracionOriginalDeLaTerminal());
    termios crudo = configuracionOriginalDeLaTerminal();
    crudo.c_lflag &= ~(ICANON | ECHO);
    crudo.c_cc[VMIN] = 1;
    crudo.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &crudo);
    std::cout << "\033[?25l" << std::flush;
}

// Deja la terminal como estaba antes de activarModoCrudo().
inline void restaurarTerminal() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &configuracionOriginalDeLaTerminal());
    std::cout << "\033[?25h\033[0m" << std::endl;
}

// Espera hasta milisegundos a que se presione una tecla. Devuelve la tecla,
// o std::nullopt si no se presiono ninguna en ese tiempo.
inline std::optional<char> leerTecla(int milisegundos) {
    pollfd entrada;
    entrada.fd = STDIN_FILENO;
    entrada.events = POLLIN;
    entrada.revents = 0;
    if (poll(&entrada, 1, milisegundos) > 0) {
        char tecla;
        if (read(STDIN_FILENO, &tecla, 1) == 1) {
            return tecla;
        }
    }
    return std::nullopt;
}

// Borra la pantalla completa.
inline void limpiarPantalla() {
    std::cout << "\033[2J\033[H" << std::flush;
}

// Lleva el cursor a la esquina superior izquierda, sin borrar. Imprimir el
// cuadro nuevo encima del anterior evita el parpadeo.
inline void irAlInicio() {
    std::cout << "\033[H";
}

// Detiene el hilo que la llama durante milisegundos.
inline void esperarMilisegundos(int milisegundos) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milisegundos));
}

// Microsegundos transcurridos desde un instante fijo. Solo sirve para
// restar dos lecturas: microsegundos() - inicio.
inline long long microsegundos() {
    return std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now().time_since_epoch()).count();
}
