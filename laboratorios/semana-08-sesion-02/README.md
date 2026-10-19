# Semana 8, Sesión 2: Polimorfismo I, funciones virtuales

## Objetivo de la sesión

Explicar el mecanismo de despacho dinámico mediante funciones virtuales, y predecir el comportamiento de un programa que invoca una función virtual a través de un puntero a la clase base.

## Antes de empezar

**Lectura previa:** ["Demystifying Dynamic Dispatch: A Deep Dive into Virtual Functions, vptr, and vtable", Satya Dirisala](https://medium.com/@satyadirisala/demystifying-dynamic-dispatch-a-deep-dive-into-virtual-functions-vptr-and-vtable-9574c1ad9bed)

**Referencia:** ["virtual function specifier", cppreference](https://en.cppreference.com/w/cpp/language/virtual.html)

Según el artículo, ¿por qué el compilador no puede decidir, al compilar, qué versión de una función virtual se va a ejecutar? ¿Qué guarda el vptr de cada objeto?

_(tu respuesta)_

En el examen, `Camion` hereda de `Vehiculo`. Si escribes `Vehiculo* vehiculo = &camion;` y ambas clases tienen su propio método `describir()`, ¿cuál se ejecuta con `vehiculo->describir()`? ¿De qué depende tu respuesta?

_(tu respuesta)_

## Ejercicio 1: figuras sin virtual y con virtual

Archivo: [`ejercicio1_figuras_sin_virtual.cpp`](./ejercicio1_figuras_sin_virtual.cpp). `Circulo` y `Rectangulo` heredan de `Figura` y cada una tiene su propio `area()`.

**Respuesta 1, antes de ver la solución:** llamado directamente, `circulo.area()` da 3.14159 y `rectangulo.area()` da 6. Si guardas ambos en `Figura* figuras[2]` y llamas `figuras[i]->describir()`, ¿qué área imprime cada uno?

_(tu respuesta)_

**Respuesta 2:** después de anteponer `virtual` a `area()` en `Figura`, sin tocar las derivadas, ¿qué cambia en la salida? `describir()` no es virtual: ¿afecta eso a la llamada a `area()` que hace adentro?

_(tu respuesta)_

**La formulación completa, tal como la resuelvo yo:**

_(anota aquí la salida del paso 1 y la del paso 2, mientras se revisa en clase)_

## Ejercicio 2: nómina con override

Archivo: [`ejercicio2_nomina_override.cpp`](./ejercicio2_nomina_override.cpp). `Docente` y `Contratista` heredan de `Empleado`, que declara `salarioMensual()` e `imprimirRol()` como virtuales.

**Respuesta 1, antes de ver la solución:** el docente gana 1800 y el contratista trabaja 40 horas a 25 por hora. Corre el programa sin cambiar nada: ¿cuánto imprime para el contratista, y por qué, si `salarioMensual` sí es virtual en la base?

_(tu respuesta)_

**Respuesta 2:** al agregar `override` a los métodos de `Contratista`, ¿qué línea rechaza el compilador y qué dice el mensaje?

_(tu respuesta)_

**La formulación completa, tal como la resuelvo yo:**

_(anota aquí la corrección de `Contratista` y la salida final)_

## Durante el ConcepTest

**Tu voto, antes de discutir en pareja** (A, B, C o D):

_(tu voto)_

**Tu razonamiento:**

_(tu respuesta)_

**Después de discutir en pareja, ¿cambiaste de voto? ¿Por qué?**

_(tu respuesta)_

## Ejercicio 3: cola de notificaciones

Archivo: [`ejercicio3_notificaciones.cpp`](./ejercicio3_notificaciones.cpp). Solo o en pareja.

`main` guarda tres notificaciones distintas en `std::unique_ptr<Notificacion> cola[3]` y llama `cola[i]->enviar()` en cada una. Completa:

- `Notificacion`: decide qué le falta a `enviar()` y a `~Notificacion()` para que el envío y la destrucción se resuelvan según el tipo real de cada objeto.
- `NotificacionCorreo`, `NotificacionSMS` y `NotificacionPush`: herencia pública de `Notificacion`, constructor, `enviar()` y destructor, ambos marcados con `override`. `NotificacionSMS` reserva su arreglo de intentos con `std::make_unique<int[]>`.

La salida esperada exacta está en el encabezado del archivo.

Antes de dar el ejercicio por terminado, responde: si quitas `virtual` del destructor de `Notificacion` y vuelves a compilar con `-fsanitize=address`, ¿qué destructores se imprimen al final, y qué reporta AddressSanitizer?

_(tu respuesta)_

## Compilar y ejecutar

```
g++ -std=c++20 -Wall -Wextra -g ejercicio1_figuras_sin_virtual.cpp -o bin/ejercicio1
./bin/ejercicio1
```

Repite el mismo patrón con `ejercicio2_nomina_override.cpp` y `ejercicio3_notificaciones.cpp`. Para el Ejercicio 3, compila también con AddressSanitizer:

```
g++ -std=c++20 -Wall -Wextra -g -fsanitize=address ejercicio3_notificaciones.cpp -o bin/ejercicio3_asan
./bin/ejercicio3_asan
```

En Mac, el comando `g++` es en realidad Clang: con el Ejercicio 2 sin corregir, Clang muestra una advertencia `-Woverloaded-virtual` que el GCC del Dev Container no muestra. Una advertencia no detiene la compilación; `override` la convierte en un error.

## Qué construcciones nuevas usa este laboratorio

Un puntero a la clase base que apunta a un objeto derivado (`Figura* figura = &circulo;`) y `->` sobre ese puntero; `virtual` antepuesto a un método de la base; `override` después de la lista de parámetros de un método de la derivada; y el destructor `virtual` en una base que se usa a través de punteros o smart pointers.

## Antes de la próxima sesión

**Lectura:** ["SOLID Design Principles with Example Code (C++)", Suresh Jangale](https://medium.com/@sureshjangale137/solid-design-principles-with-examples-e6e8baf5f85f)

`Figura::area()` devuelve 0 solo porque algo tenía que devolver. ¿Tiene sentido crear un objeto que sea solo una `Figura`, sin ser círculo ni rectángulo? ¿Qué debería hacer el compilador si alguien lo intenta?

_(tu respuesta)_
