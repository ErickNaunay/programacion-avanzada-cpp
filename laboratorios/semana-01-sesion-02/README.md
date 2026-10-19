# Semana 1, Sesión 2: Fundamentos de POO

> Objetivo de la sesión: distinguir el paradigma orientado a objetos de la programación estructurada, y justificar cuándo modelar un problema con clases aporta valor sobre usar funciones sueltas.

**Lectura previa de esta sesión:** ["Object Oriented Programming"](https://medium.com/@dnyaneshwalwadkar/object-oriented-programming-c2f2e0952e06), Dnyanesh Walwadkar.

**Referencia de esta sesión:** ["Classes"](https://en.cppreference.com/w/cpp/language/classes.html), cppreference.

## Antes de empezar

Este laboratorio construye directamente sobre el diagnóstico de la sesión 1

Verifica que tu ambiente compile correctamente.

```
cd laboratorios/semana-01-sesion-02
```

## Ejercicios

Resuélvelos en orden.

1. **`ejercicio1_funciones_sueltas.cpp`**: implementar `area`, `perimetro`, `nuevaBase` y `nuevaAltura` de un rectángulo con funciones sueltas que reciben `base` y `altura` por separado.
2. **`ejercicio2_struct_rectangulo.cpp`**: implementar la misma lógica, ahora como métodos de un `struct Rectangulo` que agrupa `base` y `altura` en un solo objeto.
3. **`ejercicio3_dos_rectangulos.cpp`**: la Parte A ya está resuelta y tiene un bug plantado a propósito; tu primera tarea es identificarlo. La Parte B es tuya: usa dos objetos `Rectangulo` para el mismo resumen, y comprueba que ese tipo de bug deja de ser posible.

Compila y ejecuta cada uno así (los binarios se generan en `bin/`, que no se sube al repositorio):

```
g++ -std=c++20 -Wall -Wextra -g ejercicio1_funciones_sueltas.cpp -o bin/ejercicio1
./bin/ejercicio1
```

## Antes de la próxima sesión

Ven a clase listo para discutir, con tus propias palabras:

- Con qué criterio decidirías, para un problema nuevo, si conviene modelarlo con una clase o con funciones sueltas.
- Qué problema tendríamos si el atributo `balance` de una `CuentaBancaria` pudiera modificarse directamente desde fuera de la clase, sin pasar por ningún método (la pregunta de apertura de la próxima sesión).
