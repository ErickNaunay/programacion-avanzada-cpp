# Semana 4, Sesión 2: Composición y agregación

## Objetivo de la sesión

Aplicar el principio "has-a" frente a "is-a" para refactorizar una jerarquía de herencia forzada hacia una relación de composición.

## Antes de empezar

**Lectura previa:** ["Composition over Inheritance: A Better Way to Write C++ Code", omprakash](https://omprakash524.medium.com/composition-over-inheritance-a-better-way-to-write-c-code-d6468f82353)

**Referencia:** ["Private Inheritance", C++ FAQ, isocpp.org](https://isocpp.org/wiki/faq/private-inheritance)

Según el artículo, ¿qué gana un diseño con composición que un diseño con herencia forzada no tiene, más allá de evitar el problema del diamante de la sesión pasada?

_(tu respuesta)_

La sesión pasada cerré con esta pregunta: un `Carro` no es un `Motor`, pero sí tiene un `Motor`. ¿Sigue siendo el mismo tipo de relación que herencia?

_(tu respuesta)_

## Ejercicio 1: Carro y Motor

Archivo: [`ejercicio1_carro_motor.cpp`](./ejercicio1_carro_motor.cpp). El diseño de partida (`class Carro: public Vehiculo, public Motor`) es forzado.

**Respuesta 1, antes de ver la solución:** si `Carro` heredara de `Motor`, ¿qué método heredaría que no debería tener sentido llamar directamente sobre un carro completo?

_(tu respuesta)_

**Respuesta 2:** ¿qué necesita hacer `arrancar()` con el objeto `motor` que va a tener adentro, en vez de con código propio?

_(tu respuesta)_

**La formulación completa, tal como la resuelvo yo:**

_(anota aquí el diseño refactorizado, mientras se revisa en clase)_

## Ejercicio 2: Dron y Batería

Archivo: [`ejercicio2_dron_bateria.cpp`](./ejercicio2_dron_bateria.cpp).

**Respuesta 1, antes de ver la solución:** ¿qué debería revisar `despegar()` antes de permitir que el dron despegue?

_(tu respuesta)_

**Respuesta 2:** ¿por qué `Dron` no debería heredar de `Bateria`, ni siquiera para reutilizar `estaCargada()`?

_(tu respuesta)_

**La formulación completa, tal como la resuelvo yo:**

_(anota aquí el diseño refactorizado, mientras se revisa en clase)_

## Durante el ConcepTest

**Tu voto, antes de discutir en pareja** (A, B, C o D):

_(tu voto)_

**Tu razonamiento:**

_(tu respuesta)_

**Después de discutir en pareja, ¿cambiaste de voto? ¿Por qué?**

_(tu respuesta)_

## Ejercicio 3: Impresora y Cartucho

Archivo: [`ejercicio3_impresora_cartucho.cpp`](./ejercicio3_impresora_cartucho.cpp). Solo o en pareja.

Tu `Impresora` de la sesión pasada (con herencia virtual de `Dispositivo`, sin cambios hoy) necesita controlar cuánta tinta le queda antes de imprimir. Un compañero propone `class Impresora: public virtual Dispositivo, public Cartucho`.

**Antes de escribir código:** explica por qué ese diseño es forzado, igual que `Carro` heredando de `Motor` en el Ejercicio 1.

_(tu respuesta)_

Diseña en su lugar:

- Una clase `Cartucho`, con `nivelTintaPorc` (empieza en 100), `tieneTinta()`, `consumir(int porcentaje)` (sin bajar de 0) y `getNivelTintaPorc()`.
- `Impresora` con un atributo privado `Cartucho`, y `imprimir(int paginas)`: si no hay tinta, imprime `Sin tinta, no se puede imprimir` y devuelve `false`; si hay, imprime `Imprimiendo <paginas> paginas a <paginasPorMinuto> paginas por minuto`, consume `paginas * 2` de tinta, y devuelve `true`. Agrega también `getNivelTintaPorc()`.

El archivo tiene, en su encabezado, la salida exacta que debe producir cuando esté completo.

## Compilar y ejecutar

```
g++ -std=c++20 -Wall -Wextra -g ejercicio1_carro_motor.cpp -o bin/ejercicio1
./bin/ejercicio1
```

Repite el mismo patrón con `ejercicio2_dron_bateria.cpp` y `ejercicio3_impresora_cartucho.cpp`.

## Qué construcciones nuevas usa este laboratorio

Composición: un atributo de una clase cuyo tipo es otra clase del curso (`Motor motor;`, `Bateria bateria;`, `Cartucho cartucho;`), construido automáticamente junto con el objeto que lo contiene. Delegación: llamar a un método del objeto interno en vez de reimplementar su lógica. Nada de listas de inicialización de miembros, punteros, ni memoria dinámica: el objeto compuesto siempre se crea al mismo tiempo que su contenedor, eso llega en sesiones posteriores.

## Antes de la próxima sesión

Hasta hoy, el objeto compuesto se crea exactamente cuando se crea el objeto que lo contiene. ¿Qué pasaría si necesitaras crear ese objeto interno más tarde, o decidir en tiempo de ejecución qué tipo de objeto crear ahí?

_(tu respuesta)_
