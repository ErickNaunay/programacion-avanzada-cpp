# Semana 10, Sesión 1: Plantillas y STL II: contenedores e iteradores

## Objetivo de la sesión

Elegir el contenedor de la STL adecuado según el patrón de acceso e inserción que exige un problema dado.

## Antes de empezar

**Lectura previa:** ["STL Containers: Vector, Set and Map", Megha B H](https://medium.com/@megha_bh/stl-containers-vector-set-and-map-7a90e0b1e19f)

**Referencia:** ["Containers library", cppreference](https://en.cppreference.com/w/cpp/container.html)

Según el artículo, ¿qué diferencia a un `set` de un `vector` cuando insertas un valor que ya estaba? ¿Y en qué orden quedan los elementos de un `map` al recorrerlo?

_(tu respuesta)_

`Historial` tiene una capacidad fija y rechaza el valor que no cabe. ¿Qué tendría que hacer para crecer cuando se llena?

_(tu respuesta)_

## Ejercicio 1: Historial sobre un vector

Archivo: [`ejercicio1_historial_vector.cpp`](./ejercicio1_historial_vector.cpp). El `Historial<T>` de la sesión pasada, con capacidad 3, recibe 6 valores.

**Respuesta 1, antes de ver la solución:** con un `std::vector<int>` y `reserve(3)`, ¿qué capacidad esperas ver después de agregar el cuarto valor? ¿Qué tuvo que pasar con los tres valores que ya estaban guardados?

_(tu respuesta)_

**Respuesta 2:** en el paso 4, `semana.end()` no apunta al último elemento. ¿A qué apunta, y por qué el loop se detiene con `it != semana.end()` en vez de `it <= semana.end()`?

_(tu respuesta)_

**La formulación completa, tal como la resuelvo yo:**

_(anota aquí la clase con el vector, la secuencia de capacidades y la salida del paso 4)_

## Durante el caso comparativo

Una fila de impresión recibe trabajos urgentes al frente y cancela trabajos en cualquier posición. Un registro de lecturas solo agrega al final y se consulta por posición. ¿Qué contenedor usarías para cada uno, y qué operación decide la elección?

_(tu respuesta)_

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

## Ejercicio 2: la fila de la impresora

Archivo: [`ejercicio2_cola_impresion.cpp`](./ejercicio2_cola_impresion.cpp). Solo o en pareja.

Completa los métodos de `ColaDeImpresion`, que guarda los trabajos en una `std::list<int>`. `main` ya está completo y la salida esperada exacta está en el encabezado del archivo.

Antes de dar el ejercicio por terminado, responde: en `cancelar`, ¿qué pasaría si después de `trabajos.erase(it)` siguieras el loop con `++it`? ¿Qué operación de esta clase sería más barata con un `std::vector`, y por qué igual conviene la lista para este problema?

_(tu respuesta)_

## Ejercicio 3: la bodega de componentes

Archivo: [`ejercicio3_bodega.cpp`](./ejercicio3_bodega.cpp). Solo o en pareja.

Escribe la clase `Bodega` a partir de la especificación del archivo. La especificación no dice qué contenedor usa cada atributo: lo eliges tú. `main` ya está completo y la salida esperada exacta está en el encabezado.

Antes de dar el ejercicio por terminado, responde por cada atributo: ¿qué contenedor elegiste, qué operación de la especificación decidió esa elección, y qué se rompería o se volvería más caro con otro contenedor?

_(stock)_

_(historial de retiros)_

_(agotados)_

Responde también: ¿por qué `stockDe(999)` no puede escribirse como `return stock[999];` si `stock` es un `map`? ¿Qué línea de la salida esperada lo delataría?

_(tu respuesta)_

## Compilar y ejecutar

```
g++ -std=c++20 -Wall -Wextra -g ejercicio1_historial_vector.cpp -o bin/ejercicio1
./bin/ejercicio1
```

Repite el mismo patrón con `ejercicio2_cola_impresion.cpp` y `ejercicio3_bodega.cpp`.

## Qué construcciones nuevas usa este laboratorio

Los contenedores `std::vector<T>` (`push_back`, `size`, `[]`, `back`, `reserve`, `capacity`, inicialización con llaves), `std::list<T>` (`push_front`, `push_back`, `front`, `pop_front`, `erase`), `std::set<T>` (`insert`, `count`) y `std::map<K, V>` (`[]`, `count`, `size`, recorrido con `.first` y `.second`); iteradores (`begin()`, `end()`, `*it`, `++it`); `auto` para el tipo de un iterador; y el `for` de rango (`for (int valor : semana)`).

## Antes de la próxima sesión

**Lectura:** ["C++ STL: Overview of <algorithm>", Michael Spagna](https://mjspagna.medium.com/c-stl-overview-of-algorithm-a0d94342253e)

Hoy recorriste un `vector` y una `list` con el mismo patrón de iterador. Si mañana necesitas sumar, buscar el máximo y contar valores en los dos contenedores, ¿cuántas funciones escribirías con lo que sabes hoy? ¿Qué tendría que recibir una sola función para servir a los dos?

_(tu respuesta)_
