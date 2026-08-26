# Semana 2, Sesión 1: Clases, objetos y encapsulación

## Objetivo de la sesión

Diseñar una clase con atributos privados e invariantes protegidas, y explicar por qué la encapsulación previene estados inválidos.

## Antes de empezar

Repasa el `struct Rectangulo` de la sesión pasada (`laboratorios/semana-01-sesion-02/`). Hoy ese mismo rectángulo se convierte en `class`, con `base` y `altura` privados: la única forma de cambiarlos es a través de métodos que verifican que el valor tenga sentido antes de aceptarlo.

**Lectura previa:** ["Inside C++ Classes and Objects: How They Really Work", Alexander Obregon](https://medium.com/@AlexanderObregon/inside-c-classes-and-objects-how-they-really-work-9da4ec5586b9)

**Referencia:** ["Classes", cppreference](https://en.cppreference.com/w/cpp/language/classes.html)

## Ejercicios

Los tres ejercicios usan el mismo patrón (atributos privados protegidos por métodos que verifican un invariante), en tres dominios distintos:

1. **`ejercicio1_class_rectangulo.cpp`**: encapsula `Rectangulo`. Lo resolvemos juntos en clase.
2. **`ejercicio2_cuenta_bancaria.cpp`**: el mismo patrón, aplicado a una cuenta bancaria cuyo saldo nunca puede quedar negativo. Lo resolvemos juntos en clase.
3. **`ejercicio3_rango_notas.cpp`**: lo resuelves tú solo o en pareja. El invariante aquí junta dos atributos a la vez (`minima <= maxima`), no uno solo.

Cada archivo tiene, en su encabezado, la salida exacta que debe producir cuando esté completo.

## Compilar y ejecutar

```
g++ -std=c++20 -Wall -Wextra -g ejercicio1_class_rectangulo.cpp -o bin/ejercicio1
./bin/ejercicio1
```

Repite el mismo patrón con `ejercicio2_cuenta_bancaria.cpp` y `ejercicio3_rango_notas.cpp`.

## Qué construcciones nuevas usa este laboratorio

`class`, `public:`/`private:`, y métodos que leen o modifican los atributos privados del propio objeto. Nada de paso por referencia (`&`), `const` en métodos, constructores explícitos ni punteros: eso llega en sesiones posteriores.
