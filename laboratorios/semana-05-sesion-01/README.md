# Semana 5, Sesión 1: Punteros y memoria dinámica I (RAII)

## Objetivo de la sesión

Aplicar el patrón RAII para atar la vida de un recurso dinámico al ciclo de vida de un objeto, evitando fugas de memoria.

## Antes de empezar

**Lectura previa:** ["Mastering RAII: How C++ Solves Memory Management Nightmares", Basant C.](https://medium.com/@caring_smitten_gerbil_914/mastering-raii-how-c-solves-memory-management-nightmares-with-real-world-examples-1cf50d5ccef9)

**Referencia:** ["RAII", cppreference](https://en.cppreference.com/w/cpp/language/raii.html)

Según el artículo, ¿qué significa "atar" la vida de un recurso a la vida de un objeto, y qué evita exactamente ese amarre?

_(significa que se maneja al recurso como un objeto, evita un memory leak)_

La sesión pasada, el `motor` dentro de `Carro` se creaba siempre junto con su contenedor, con un tamaño y una cantidad fijos desde que se escribe el código. ¿Qué pasaría si necesitaras un arreglo cuyo tamaño no se conoce hasta que el programa corre?

_(se puede crear al objeto con un puntero dentro del constructor para manejar el espacio al correr el programa )_

## Ejercicio 1: reproducir la fuga

Archivo: [`ejercicio1_registro_temperaturas_fuga.cpp`](./ejercicio1_registro_temperaturas_fuga.cpp). `RegistroTemperaturas` reserva memoria dinámica en el constructor con `new`, pero no tiene destructor.

**Respuesta 1, antes de ver la solución:** si `registrarDia` crea un `RegistroTemperaturas` local y la función termina, ¿qué pasa con la memoria que reservó ese objeto?

_(se pierde)_

**Respuesta 2:** si `main` llama a `registrarDia` tres veces seguidas, ¿cuántas veces esperas ver "Memoria liberada" en la salida?

_(3 veces)_

**La formulación completa, tal como la resuelvo yo:**

_(sale 3 veces)_

## Ejercicio 2: arreglar con RAII

Archivo: [`ejercicio2_registro_temperaturas_raii.cpp`](./ejercicio2_registro_temperaturas_raii.cpp), mismo punto de partida que el Ejercicio 1.

**Respuesta 1, antes de ver la solución:** ¿qué necesita hacer el destructor de `RegistroTemperaturas` para que la memoria se libere sola, sin que nadie tenga que acordarse de llamar `delete[]` a mano?

_(colocar delete dentro del destructor)_

**Respuesta 2:** después de agregar el destructor, ¿en qué momento exacto se ejecuta, si `registro` es una variable local de `registrarDia`?

_(al terminar el ciclo de vida)_

**La formulación completa, tal como la resuelvo yo:**

_(anota aquí el destructor agregado y la salida verificada, mientras se revisa en clase)_

## Durante el ConcepTest

**Tu voto, antes de discutir en pareja** (A, B, C o D):

_(tu voto)_

**Tu razonamiento:**

_(tu respuesta)_

**Después de discutir en pareja, ¿cambiaste de voto? ¿Por qué?**

_(tu respuesta)_

## Ejercicio 3: RegistroDeVuelo

Archivo: [`ejercicio3_registro_de_vuelo.cpp`](./ejercicio3_registro_de_vuelo.cpp). Solo o en pareja.

Define la clase `RegistroDeVuelo` completa, con el mismo patrón de RAII de los Ejercicios 1 y 2, aplicado a un arreglo dinámico de alturas (`double`) en vez de temperaturas:

- Atributos privados: `double* alturas` y `int capacidad`.
- Constructor `RegistroDeVuelo(int nuevaCapacidad)`: reserva memoria dinámica con `new[]` para `capacidad` valores `double`, e imprime `Registro de vuelo creado para <capacidad> lecturas`.
- `void guardarAltura(int indice, double valor)` y `double getAltura(int indice)`.
- Destructor `~RegistroDeVuelo()`: libera la memoria con `delete[]` e imprime `Registro de vuelo destruido, memoria liberada`.

`procesarVuelo`, ya dado en el archivo, tiene dos caminos de salida distintos (`return false` si la altura no alcanza el mínimo, `return true` si la acepta). Con RAII, el destructor se ejecuta en los dos caminos sin que tengas que llamar `delete[]` en cada uno por separado.

## Compilar y ejecutar

```
g++ -std=c++20 -Wall -Wextra -g ejercicio1_registro_temperaturas_fuga.cpp -o bin/ejercicio1
./bin/ejercicio1
```

Repite el mismo patrón con `ejercicio2_registro_temperaturas_raii.cpp` y `ejercicio3_registro_de_vuelo.cpp`.

## Qué construcciones nuevas usa este laboratorio

Punteros (`Tipo* variable`, `&` para obtener una dirección, `*` para desreferenciar), memoria dinámica (`new`, `new[]`) y su liberación manual (`delete`, `delete[]`), y el patrón RAII: el constructor reserva el recurso, el destructor lo libera, usando el mismo mecanismo de destrucción automática visto desde la Semana 2, Sesión 2. Nada de `nullptr`, punteros colgantes, ni listas de inicialización de miembros: eso llega en sesiones posteriores.

## Antes de la próxima sesión

Hoy até la vida de la memoria reservada al ciclo de vida del objeto que la reserva, con RAII. Pero ¿qué pasa si alguien más guarda un puntero a esa memoria, y sigue usando ese puntero después de que el objeto dueño ya se destruyó?

_(tu respuesta)_
