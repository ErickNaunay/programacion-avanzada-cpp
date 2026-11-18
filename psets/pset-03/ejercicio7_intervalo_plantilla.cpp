// Ejercicio 7: Intervalo<T> (plantilla de clase)
//
// Completa los metodos marcados con TODO. No cambies las firmas ni el main().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio7 ejercicio7_intervalo_plantilla.cpp
// Ejecutar: ./ejercicio7
//
// Salida esperada:
// Horario: 8 a 17, ancho 9
// Contiene 12: 1
// Contiene 18: 0
// Temperatura: 15.5 a 24, ancho 8.5
// Contiene 15.5: 1
// Se cruzan: 1
// Se cruzan: 0

#include <iostream>

template <typename T>
class Intervalo {
private:
    T inicio;
    T fin;
public:
    Intervalo(T a, T b) {
        // TODO: guarda el menor de a y b en inicio y el mayor en fin, en ese orden,
        // aunque quien llama los pase al reves.
        inicio = a;
        fin = b;
    }
    T getInicio() {
        return inicio;
    }
    T getFin() {
        return fin;
    }
    T ancho() {
        // TODO: devuelve fin - inicio.
        return inicio;
    }
    bool contiene(T valor) {
        // TODO: true si valor esta entre inicio y fin, ambos incluidos.
        return false;
    }
    bool seCruzaCon(Intervalo<T> otro) {
        // TODO: true si los dos intervalos comparten al menos un valor: inicio de
        // cada uno menor o igual que el fin del otro.
        return false;
    }
};

int main() {
    Intervalo<int> horario(17, 8);
    std::cout << "Horario: " << horario.getInicio() << " a " << horario.getFin() << ", ancho " << horario.ancho() << std::endl;
    std::cout << "Contiene 12: " << horario.contiene(12) << std::endl;
    std::cout << "Contiene 18: " << horario.contiene(18) << std::endl;

    Intervalo<double> temperatura(15.5, 24.0);
    std::cout << "Temperatura: " << temperatura.getInicio() << " a " << temperatura.getFin() << ", ancho " << temperatura.ancho() << std::endl;
    std::cout << "Contiene 15.5: " << temperatura.contiene(15.5) << std::endl;

    Intervalo<int> almuerzo(12, 14);
    Intervalo<int> noche(19, 22);
    std::cout << "Se cruzan: " << horario.seCruzaCon(almuerzo) << std::endl;
    std::cout << "Se cruzan: " << horario.seCruzaCon(noche) << std::endl;
    return 0;
}
