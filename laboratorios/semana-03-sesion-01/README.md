# Semana 3, Sesión 1: Sobrecarga de operadores

## Objetivo de la sesión

Sobrecargar operadores aritméticos y de flujo en una clase propia, y justificar la diferencia entre implementarlos como miembro o como función libre.

## Antes de empezar

**Lectura previa:** ["Operator Overloading in C++: Teaching Objects to Behave Like Natural Data Types", Afzal Badshah](https://afzalbadshah.medium.com/operator-overloading-in-c-teaching-objects-to-behave-like-natural-data-types-1b1e6510ce6c)

**Referencia:** ["Operator overloading", cppreference](https://en.cppreference.com/w/cpp/language/operators.html)

## Ejercicios

Los tres ejercicios usan el mismo patrón: `operator+` como método miembro de la clase, y `operator<<` como función libre que recibe el stream por referencia.

1. **`ejercicio1_vector2d.cpp`**: `Vector2D`, sin invariante. Lo resolvemos juntos en clase.
2. **`ejercicio2_fraccion.cpp`**: `Fraccion`, con invariante (denominador != 0). Lo resolvemos juntos en clase.
3. **`ejercicio3_numero_complejo.cpp`**: `NumeroComplejo`. Lo resuelves tú solo o en pareja.

Cada archivo tiene, en su encabezado, la salida exacta que debe producir cuando esté completo.

## Compilar y ejecutar

```
g++ -std=c++20 -Wall -Wextra -g ejercicio1_vector2d.cpp -o bin/ejercicio1
./bin/ejercicio1
```

Repite el mismo patrón con `ejercicio2_fraccion.cpp` y `ejercicio3_numero_complejo.cpp`.

## Qué construcciones nuevas usa este laboratorio

`operator+` como método miembro (`operator+(Tipo otro)`), `operator<<` como función libre, y paso por referencia (`&`) acotado a `std::ostream&`: un stream no se puede copiar, así que toda función que lo reciba o lo devuelva lo hace por referencia. El objeto de tu propia clase (`Vector2D`, `Fraccion`, `NumeroComplejo`) se sigue pasando por valor, igual que en las sesiones anteriores.
