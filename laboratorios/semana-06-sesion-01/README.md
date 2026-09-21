# Semana 6, Sesión 1: Move semantics y rvalue references

## Objetivo de la sesión

Implementar un constructor de movimiento y explicar por qué mover un recurso es más eficiente que copiarlo.

## Antes de empezar

**Lectura previa:** ["Move Semantics & Rvalue References Deep Dive", Amit Kashyap](https://medium.com/@hunkcool1991/move-semantics-rvalue-references-deep-dive-the-most-misunderstood-feature-in-modern-c-6b8b12da143c)

**Referencia:** ["std::move", cppreference](https://en.cppreference.com/w/cpp/utility/move.html)

Según el artículo, ¿qué hace `std::move` exactamente? Las dos opciones a descartar: que reserva memoria nueva, o que copia algo.

_(tu respuesta)_

Copiar un `int` es barato: son 4 bytes. ¿Por qué copiar un arreglo dinámico de un millón de `double` sería mucho más caro, y qué haría falta para evitar esa copia si de todas formas quieres transferir esos datos de un objeto a otro?

_(tu respuesta)_

## Ejercicio 1: copiar es peligroso

Archivo: [`ejercicio1_copiar_es_peligroso.cpp`](./ejercicio1_copiar_es_peligroso.cpp). `RegistroDeVuelo` no declara ningún constructor de copia propio.

**Respuesta 1, antes de ver la solución:** `registro2 = registro1` usa el constructor de copia que el compilador genera por defecto, que copia `alturas` y `capacidad` tal cual están. Si `alturas` es un puntero, ¿qué copia exactamente ese constructor por defecto: el puntero, o el arreglo al que apunta?

_(tu respuesta)_

**Respuesta 2:** si `registro1` y `registro2` terminan con el mismo puntero, ¿qué pasa al final de `main`, cuando los destructores de los dos objetos intentan liberar esa memoria?

_(tu respuesta)_

**La formulación completa, tal como la resuelvo yo:**

_(anota aquí la salida real, mientras se revisa en clase)_

## Ejercicio 2: mover es seguro

Archivo: [`ejercicio2_mover_es_seguro.cpp`](./ejercicio2_mover_es_seguro.cpp), mismo punto de partida que el Ejercicio 1.

**Respuesta 1, antes de ver la solución:** el constructor de movimiento recibe `RegistroDeVuelo&& otro`. En vez de reservar un arreglo nuevo y copiar cada elemento, ¿qué tres pasos bastan para transferir la propiedad de `otro.alturas` sin copiar ningún `double`?

_(tu respuesta)_

**Respuesta 2:** si dejo `otro.alturas` en `nullptr` después de robarlo, ¿por qué eso hace que el destructor de `otro` sea seguro cuando se ejecute más tarde?

_(tu respuesta)_

**La formulación completa, tal como la resuelvo yo:**

_(anota aquí el constructor y el operador de movimiento agregados, y la salida verificada, mientras se revisa en clase)_

## Durante el ConcepTest

**Tu voto, antes de discutir en pareja** (A, B, C o D):

_(tu voto)_

**Tu razonamiento:**

_(tu respuesta)_

**Después de discutir en pareja, ¿cambiaste de voto? ¿Por qué?**

_(tu respuesta)_

## Ejercicio 3: BitacoraDeVuelo

Archivo: [`ejercicio3_bitacora_de_vuelo.cpp`](./ejercicio3_bitacora_de_vuelo.cpp). Solo o en pareja.

Completa `BitacoraDeVuelo`, con el mismo patrón de los Ejercicios 1 y 2, aplicado a un arreglo dinámico de consumos de combustible por tramo en vez de alturas:

- Atributos privados: `double* consumos` y `int capacidad`.
- Constructor `BitacoraDeVuelo(int nuevaCapacidad)`: reserva memoria dinámica con `new[]` e imprime `Bitacora creada para <capacidad> tramos`.
- `void guardarConsumo(int indice, double valor)` y `double getConsumo(int indice)` (si `consumos` es `nullptr`, imprime `Bitacora vacia (fue movida)` y devuelve `0.0`).
- Constructor de movimiento `BitacoraDeVuelo(BitacoraDeVuelo&& otra)`: roba `consumos` y `capacidad` de `otra`, y deja `otra` vacía y segura.
- Operador de asignación de movimiento `BitacoraDeVuelo& operator=(BitacoraDeVuelo&& otra)`: libera lo propio con `delete[]` antes de robar lo de `otra`, comprobando `this != &otra`.
- Destructor `~BitacoraDeVuelo()`: libera con `delete[]` e imprime `Destruyendo bitacora (capacidad <capacidad>)`.

## Compilar y ejecutar

```
g++ -std=c++20 -Wall -Wextra -g ejercicio1_copiar_es_peligroso.cpp -o bin/ejercicio1
./bin/ejercicio1
```

Repite el mismo patrón con `ejercicio2_mover_es_seguro.cpp` y `ejercicio3_bitacora_de_vuelo.cpp`. Para confirmar si un programa tiene doble liberación o fuga de memoria, compílalo también con `-fsanitize=address`:

```
g++ -std=c++20 -Wall -Wextra -g -fsanitize=address ejercicio1_copiar_es_peligroso.cpp -o bin/ejercicio1_asan
./bin/ejercicio1_asan
```

## Qué construcciones nuevas usa este laboratorio

Rvalue reference como tipo de parámetro (`Tipo&& nombre`), constructor de movimiento y operador de asignación de movimiento, y `std::move` (convierte un valor en una referencia rvalue, indicando que su recurso se puede transferir en vez de copiar). El vocabulario de punteros, `new[]`, `delete[]` y RAII es el mismo de la Semana 5. Nada de `unique_ptr` ni `shared_ptr` todavía: eso llega en la próxima sesión.

## Antes de la próxima sesión

Hoy escribiste a mano el constructor de movimiento y el operador de asignación de movimiento, y también viste qué pasa si te olvidas de escribirlos (Ejercicio 1). ¿Existe algo en la biblioteca estándar que ya traiga ese comportamiento resuelto, sin que tengas que escribirlo cada vez que una clase reserva memoria dinámica?

_(tu respuesta)_
