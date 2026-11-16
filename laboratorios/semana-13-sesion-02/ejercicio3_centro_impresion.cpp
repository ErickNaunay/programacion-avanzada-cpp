#include <atomic>
#include <iostream>
#include <map>
#include <mutex>
#include <thread>

// Ejercicio 3: el centro de impresion de la biblioteca.
//
// Cuatro computadoras envian trabajos de impresion al mismo tiempo, cada
// una en su propio hilo. Cada estudiante tiene una cuota de 100 paginas.
//
// TODO: escribe la clase CentroDeImpresion. Para cada dato, decide si va
// en un std::atomic o protegido por un std::mutex, y justificalo en el
// README:
//
// - bool enviar(int estudiante, int paginas): si el centro esta cerrado,
//   o paginas no es positivo, devuelve false. Si con este trabajo el
//   estudiante pasaria de 100 paginas, cuenta un rechazo por cuota y
//   devuelve false. Si no, suma las paginas al estudiante, cuenta un
//   trabajo aceptado, suma las paginas al total del centro y devuelve
//   true.
// - void cerrar(): desde ese momento, enviar devuelve false.
// - bool estaCerrado().
// - int trabajosAceptados(), int rechazadosPorCuota(), int paginasTotales().
// - int paginasDe(int estudiante): las paginas aceptadas de ese estudiante,
//   o 0 si no tiene ninguna.
//
// No cambies el main: cada computadora envia, para cada estudiante del 1
// al 50, 10 trabajos de 5 paginas, y al final se verifica que las cuentas
// cuadren.
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio3_centro_impresion.cpp -o bin/ejercicio3
// Ejecutar:  ./bin/ejercicio3
// Con ThreadSanitizer:
//   g++ -std=c++20 -Wall -Wextra -g -fsanitize=thread ejercicio3_centro_impresion.cpp -o bin/ejercicio3_tsan
//
// Salida esperada:
// Trabajos aceptados: 1000
// Rechazados por cuota: 1000
// Paginas impresas: 5000
// Suma por estudiante: 5000
// Estudiantes sobre la cuota: 0
// Despues de cerrar, se acepta un trabajo: 0

// TODO: escribe aqui la clase CentroDeImpresion.

void computadora(CentroDeImpresion* centro) {
    for (int estudiante = 1; estudiante <= 50; estudiante++) {
        for (int i = 0; i < 10; i++) {
            centro->enviar(estudiante, 5);
        }
    }
}

int main() {
    CentroDeImpresion centro;

    std::thread pc1(computadora, &centro);
    std::thread pc2(computadora, &centro);
    std::thread pc3(computadora, &centro);
    std::thread pc4(computadora, &centro);
    pc1.join();
    pc2.join();
    pc3.join();
    pc4.join();

    int suma = 0;
    int sobreCuota = 0;
    for (int estudiante = 1; estudiante <= 50; estudiante++) {
        suma = suma + centro.paginasDe(estudiante);
        if (centro.paginasDe(estudiante) > 100) {
            sobreCuota = sobreCuota + 1;
        }
    }

    std::cout << "Trabajos aceptados: " << centro.trabajosAceptados() << std::endl;
    std::cout << "Rechazados por cuota: " << centro.rechazadosPorCuota() << std::endl;
    std::cout << "Paginas impresas: " << centro.paginasTotales() << std::endl;
    std::cout << "Suma por estudiante: " << suma << std::endl;
    std::cout << "Estudiantes sobre la cuota: " << sobreCuota << std::endl;

    centro.cerrar();
    std::cout << "Despues de cerrar, se acepta un trabajo: " << centro.enviar(7, 1) << std::endl;
    return 0;
}
