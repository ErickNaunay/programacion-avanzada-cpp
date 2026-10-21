    // Diagnostico 2: Arreglos
    // Objetivo: calcular el minimo, el maximo y el promedio de un arreglo de enteros,
    // usando un solo ciclo, sin funciones de la biblioteca estandar (<algorithm>).
    //
    // Salida esperada:
    // Minimo: 2
    // Maximo: 91
    // Promedio: 30.1667
    //
    // Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio2_arreglos.cpp -o bin/ejercicio2
    // Ejecutar:  ./bin/ejercicio2

    #include <iostream>

    int main() {
        int datos[] = {12, 45, 2, 91, 7, 24};
        int n = sizeof(datos) / sizeof(datos[0]);

        // TODO: recorre 'datos' con un ciclo y calcula minimo, maximo y suma.
        int minimo = datos[0];
        int maximo = datos[0];
        int suma = 0;

        for(int i = 0; i < n; ++i) {
            if (datos[i] < minimo) {
                minimo = datos[i];
            }
            if (datos[i] > maximo) {
                maximo = datos[i];
            }
            suma += datos[i];
        }

        double promedio = static_cast<double>(suma) / n;

        std::cout << "Minimo: " << minimo << std::endl;
        std::cout << "Maximo: " << maximo << std::endl;
        std::cout << "Promedio: " << promedio << std::endl;
        return 0;
    }
