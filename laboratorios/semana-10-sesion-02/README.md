# Semana 10, Sesión 2: Plantillas y STL III: algoritmos STL

## Objetivo de la sesión

Resolver problemas usando algoritmos de la biblioteca STL en lugar de loops manuales, y explicar por qué funcionan con cualquier contenedor compatible.

## Antes de empezar

**Lectura previa:** ["C++ STL: Overview of <algorithm>", Michael Spagna](https://mjspagna.medium.com/c-stl-overview-of-algorithm-a0d94342253e)

**Referencia:** ["Algorithms library", cppreference](https://en.cppreference.com/w/cpp/algorithm.html)

Según el artículo, ¿qué reciben como argumento los algoritmos de `<algorithm>`: el contenedor, o otra cosa? ¿Qué devuelve `std::find` cuando no encuentra el valor?

_(tu respuesta)_

Si necesitas sumar, buscar el máximo y contar valores en un `vector` y en una `list`, ¿cuántas funciones escribirías con lo que sabías la sesión pasada? ¿Qué tendría que recibir una sola función para servir a los dos?

_(tu respuesta)_

## Ejercicio 1: de loops a algoritmos

Archivo: [`ejercicio1_lecturas_algoritmos.cpp`](./ejercicio1_lecturas_algoritmos.cpp). Las temperaturas de una semana, con cuatro loops escritos a mano.

**Respuesta 1, antes de ver la solución:** `std::max_element` no devuelve un `double`. ¿Qué devuelve, y por qué esa es la decisión correcta si el vector pudiera estar vacío?

_(tu respuesta)_

**Respuesta 2:** en el paso 5, las mismas llamadas pasan a recibir `lista.begin()` y `lista.end()`. ¿Compilan sin cambios? ¿Qué tiene que saber hacer el iterador de una lista para que `std::count` funcione?

_(tu respuesta)_

**Respuesta 3:** en el paso 6, `std::accumulate` recibe `0` en vez de `0.0`. ¿Qué número esperas que imprima?

_(tu respuesta)_

**La formulación completa, tal como la resuelvo yo:**

_(anota aquí cada llamada, lo que imprimió la lista y la suma con 0)_

## Durante los ConcepTests

**ConcepTest 1. Tu voto, antes de discutir en pareja** (A, B, C o D):

_(tu voto)_

**Tu razonamiento:**

_(tu respuesta)_

**Después de discutir en pareja, ¿cambiaste de voto? ¿Por qué?**

_(tu respuesta)_

**ConcepTest 2. Tu voto, antes de discutir en pareja** (A, B, C o D):

_(tu voto)_

**Tu razonamiento:**

_(tu respuesta)_

## Ejercicio 2: predicados sobre los pasos de una semana

Archivo: [`ejercicio2_pasos_predicados.cpp`](./ejercicio2_pasos_predicados.cpp). Solo o en pareja.

Escribe la función `esDiaSedentario` y resuelve cada `TODO` del `main` con `std::count_if`, `std::find_if` y `std::sort`, usando la función con nombre en el primero y lambdas en los demás. La salida esperada exacta está en el encabezado del archivo.

Antes de dar el ejercicio por terminado, responde: ¿qué error da el compilador si la lambda de la meta no escribe `[meta]`? ¿Por qué el ejercicio ordena una copia y no el vector `pasos`?

_(tu respuesta)_

## Ejercicio 3: las ventas de la tienda

Archivo: [`ejercicio3_ventas_algoritmos.cpp`](./ejercicio3_ventas_algoritmos.cpp). Solo o en pareja.

Responde las cuatro preguntas del `main` sobre un `std::vector<Venta>` con algoritmos de la STL, sin escribir ningún loop propio. Tú eliges qué algoritmo resuelve cada una. La salida esperada exacta está en el encabezado.

Antes de dar el ejercicio por terminado, responde: si `ventas` fuera una `std::list<Venta>`, ¿cuál de tus llamadas deja de compilar? ¿Con qué la reemplazarías?

_(tu respuesta)_

Responde también: ¿qué imprime "Total recaudado" si el valor inicial de tu suma es `0` en vez de `0.0`? Pruébalo.

_(tu respuesta)_

## Compilar y ejecutar

```
g++ -std=c++20 -Wall -Wextra -g ejercicio1_lecturas_algoritmos.cpp -o bin/ejercicio1
./bin/ejercicio1
```

Repite el mismo patrón con `ejercicio2_pasos_predicados.cpp` y `ejercicio3_ventas_algoritmos.cpp`.

## Qué construcciones nuevas usa este laboratorio

Los algoritmos `std::accumulate` (de `<numeric>`, con y sin operación propia), `std::max_element`, `std::count`, `std::count_if`, `std::find`, `std::find_if` y `std::sort` (de `<algorithm>`), siempre sobre un rango `[begin, end)`; la resta de dos iteradores de un vector para obtener una posición; pasar una función por su nombre como argumento; lambdas sin captura (`[](int p) { ... }`) y con captura por valor (`[meta](int p) { ... }`); y construir una `std::list` a partir del rango de un vector.

## Antes de la próxima sesión

**Lectura:** ["Why I've soured on exceptions in C++", Jordan Edmunds Chetty](https://medium.com/@jordan.l.edmunds/why-ive-soured-on-exceptions-in-c-ea10b8ad10e8)

La `Bodega` de la sesión pasada devuelve `false` cuando no puede retirar, y `*std::max_element(v.begin(), v.end())` con un vector vacío lee una posición que no existe. ¿Cómo se entera hoy quien llama a esas funciones de que algo salió mal? ¿Qué pasa si no revisa el valor devuelto?

_(tu respuesta)_
