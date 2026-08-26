# Semana 2, Sesión 2: Constructores y destructores

## Objetivo de la sesión

Implementar constructores y destructores simétricos que garanticen la inicialización y liberación correcta de los recursos de un objeto.

## Antes de empezar

La sesión pasada, `Rectangulo` y `CuentaBancaria` se inicializaban en dos pasos: crear el objeto, y después llamar a un setter aparte para cada atributo. Hoy esos mismos objetos ganan un constructor, que inicializa el objeto completo al momento de crearlo, y un destructor, que se ejecuta automáticamente cuando el objeto sale de alcance.

**Lectura previa:** ["C++ Object Oriented Programming: Constructors and Destructors", Sean Oughton](https://medium.com/@seanoughton/c-object-oriented-programming-constructors-and-destructors-af2a505c0a55)

**Referencia:** ["Constructors and member initializer lists", cppreference](https://en.cppreference.com/w/cpp/language/constructor.html)

## Ejercicios

1. **`ejercicio1_rectangulo_constructor.cpp`**: agrega constructor y destructor a `Rectangulo`. Lo resolvemos juntos en clase.
2. **`ejercicio2_cuenta_constructor.cpp`**: agrega constructor y destructor a `CuentaBancaria`. Lo resolvemos juntos en clase.
3. **`ejercicio3_termometro.cpp`**: lo resuelves tú solo o en pareja. A diferencia de los dos anteriores, aquí construyes la clase completa, no solo el constructor y el destructor.

Cada archivo tiene, en su encabezado, la salida exacta que debe producir cuando esté completo.

## Compilar y ejecutar

```
g++ -std=c++20 -Wall -Wextra -g ejercicio1_rectangulo_constructor.cpp -o bin/ejercicio1
./bin/ejercicio1
```

Repite el mismo patrón con `ejercicio2_cuenta_constructor.cpp` y `ejercicio3_termometro.cpp`.

## Qué construcciones nuevas usa este laboratorio

Constructor (método especial con el mismo nombre de la clase, sin tipo de retorno, que se ejecuta al crear el objeto) y destructor (método especial `~NombreClase()`, sin parámetros, que se ejecuta al destruirse el objeto). Nada de listas de inicialización (`:`), constructores múltiples, `new`/`delete` ni gestión dinámica de memoria: eso llega en sesiones posteriores.
