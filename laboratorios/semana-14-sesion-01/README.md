# Semana 14, Sesión 1: C++ en la industria: casos reales

## Objetivo de la sesión

Argumentar, con casos reales de la industria, por qué C++ sigue siendo la opción dominante en sistemas, trading de alta frecuencia, videojuegos y sistemas embebidos.

## Antes de empezar

**Lectura previa:** ["Why C++ Still Dominates High-Frequency Trading (And It's Not Just Speed)", Rishi Jain](https://medium.com/@beingrishijain/why-cpp-still-dominates-high-frequency-trading-and-its-not-just-speed-ad15d6a1a256)

**Referencia:** [C++ Applications (Bjarne Stroustrup)](https://www.stroustrup.com/applications.html)

Según el artículo, si no es solo la velocidad, ¿qué hace que las firmas de trading de alta frecuencia sigan eligiendo C++?

_(tu respuesta)_

En la sesión pasada te pregunté qué características de C++ que vimos en el semestre importan en un sistema que compra y vende acciones, además de la velocidad. ¿Cuáles anotaste?

_(tu respuesta)_

Entra a esta carpeta y crea la carpeta de los ejecutables:

```
cd laboratorios/semana-14-sesion-01
mkdir -p bin
```

Hoy los programas se compilan con optimización (`-O2`), como se compila lo que llega a producción, y se miden con `time`, igual que en la Semana 13. Cada archivo trae su comando en el encabezado.

## Ejercicio 1: el libro de órdenes de una bolsa

Archivos: [`ejercicio1_libro_mapa.cpp`](./ejercicio1_libro_mapa.cpp) (no lo modifiques) y [`ejercicio1_libro_arreglo.cpp`](./ejercicio1_libro_arreglo.cpp). Un libro de órdenes guarda cuántas acciones hay ofrecidas a cada precio. Llegan 20 millones de eventos (órdenes nuevas y cancelaciones), y después de cada uno el programa de trading consulta cuánto hay en ese precio. La versión del mapa ya funciona. La del arreglo guarda cada precio en una casilla fija de un `std::vector`. Compila y mide la del mapa antes de tocar nada.

**Respuesta 1 (antes de los TODO):** ¿cuánto tardó la versión del mapa? Antes de escribir la del arreglo: ¿cuántas veces más rápida crees que va a ser? ¿Por qué?

_(tu respuesta)_

**Respuesta 2 (después de los TODO):** ¿imprimen lo mismo las dos versiones? ¿Cuánto tardó cada una? Si el libro procesara 20 millones de eventos por hora, ¿cuánto tiempo de procesador por evento gasta cada versión?

_(tu respuesta)_

**Respuesta 3:** la versión del arreglo funciona porque los precios son 1000 y se conocen de antemano. ¿Qué pasaría si los precios pudieran ser cualquier número? ¿Qué te dice eso sobre de dónde sale la ventaja?

_(tu respuesta)_

**La versión completa, tal como la resuelvo yo:**

_(anota aquí el constructor, las tres funciones y los dos tiempos)_

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

**Después de discutir en pareja, ¿cambiaste de voto? ¿Por qué?**

_(tu respuesta)_

## Ejercicio 2: el presupuesto de un cuadro

Archivos: [`ejercicio2_particulas_punteros.cpp`](./ejercicio2_particulas_punteros.cpp) (no lo modifiques) y [`ejercicio2_particulas_contiguas.cpp`](./ejercicio2_particulas_contiguas.cpp). Solo o en pareja.

Un juego a 60 cuadros por segundo tiene 16.7 milisegundos por cuadro para todo. La versión de punteros simula 600 cuadros de una explosión de 300000 partículas, cada una creada con `std::make_unique`. La tuya guarda las mismas partículas, con la misma clase, dentro de un `std::vector<Particula>`.

1. Compila y mide la versión de punteros. Divide el tiempo por 600: ¿qué parte del presupuesto de un cuadro se lleva la física de las partículas?
2. Resuelve los tres `TODO` de la versión contigua. Tiene que imprimir la misma altura promedio.
3. Mídela, y calcula lo mismo que en el paso 1.
4. Responde: las dos versiones hacen exactamente las mismas cuentas. ¿De dónde sale la diferencia?

_(tu respuesta)_

5. Responde: un motor de juegos escrito en un lenguaje con recolector de basura podría pausar el juego unos milisegundos en cualquier cuadro. ¿Por qué eso es un problema, aunque el promedio de tiempo por cuadro sea bueno?

_(tu respuesta)_

## Ejercicio 3: el sensor del motor de un dron

Archivo: [`ejercicio3_buffer_sensor.cpp`](./ejercicio3_buffer_sensor.cpp). Solo o en pareja.

El microcontrolador del motor de un dron lee la temperatura 1000 veces por segundo y recuerda las últimas 64 lecturas. En ese tipo de sistema hay una regla: una vez que el programa arranca, no se pide memoria dinámica nunca más. El encabezado describe la clase `BufferCircular`; esta vez no hay código de partida para la clase. [`contador_reservas.h`](./contador_reservas.h) cuenta cada vez que el programa pide memoria dinámica (no lo modifiques). El `main` ya está escrito. Mientras no escribas la clase, el archivo no compila.

1. Escribe `BufferCircular` y corre el programa: las cinco líneas tienen que salir iguales a las del encabezado, incluida la última, `0`.
2. Compila y corre [`ejercicio3_buffer_lista.cpp`](./ejercicio3_buffer_lista.cpp), que hace lo mismo con una `std::list`. ¿Cuántas reservas de memoria hizo? ¿De dónde salen?
3. Responde: ¿por qué un sistema embebido prohíbe pedir memoria después de arrancar, si la versión con `std::list` también da los números correctos?

_(tu respuesta)_

4. Responde: corre tu programa con `-fsanitize=address,undefined` y sin. ¿Lo usarías en el dron? ¿Dónde sí?

_(tu respuesta)_

## Qué construcciones nuevas usa este laboratorio

Ninguna en el código que escribes: `std::vector`, `std::map`, `std::unique_ptr`, clases y arreglos ya los conoces. Lo nuevo es compilar con `-O2` y medir. `contador_reservas.h` reemplaza el `operator new` de todo el programa, algo que el curso no vio: se usa solo para medir.

## Antes de la próxima sesión

La próxima sesión es el Laboratorio Integrador II, sin lectura nueva: vas a trabajar en el Proyecto Final (PSet 5), que se asigna hoy, con concurrencia, pruebas y CMake en el mismo programa.

Hoy cada ventaja de C++ salió de controlar algo: dónde vive la memoria, cuándo se pide, qué hace el procesador en cada paso. Ese control también es la fuente de los errores que viste en el semestre (un puntero colgante, un data race). En el sistema de tu Proyecto Final, ¿qué tendrías que controlar tú, y cómo vas a comprobar que no rompiste nada?

_(tu respuesta)_
