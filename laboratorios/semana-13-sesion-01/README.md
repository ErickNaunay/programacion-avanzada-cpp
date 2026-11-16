# Semana 13, Sesión 1: Concurrencia I: threads, mutex, condiciones de carrera

## Objetivo de la sesión

Identificar una condición de carrera en código concurrente y protegerla con un mutex.

## Antes de empezar

**Lectura previa:** ["Race Condition: The Invisible Bug That Breaks Your Code", Varbolean](https://medium.com/@varboleansh/race-condition-c5d038870f83)

**Referencia:** [std::mutex (cppreference)](https://en.cppreference.com/w/cpp/thread/mutex.html)

Según el artículo, ¿qué es una condición de carrera, y por qué es tan difícil de encontrar probando el programa?

_(tu respuesta)_

En la sesión pasada te pregunté por un programa que falla una de cada mil ejecuciones con los mismos datos. ¿Qué tendría que estar pasando? ¿Te serviría gdb para encontrarlo?

_(tu respuesta)_

Entra a esta carpeta y crea la carpeta de los ejecutables:

```
cd laboratorios/semana-13-sesion-01
mkdir -p bin
```

Los tres programas usan `<thread>` y `<mutex>`, que ya vienen con el compilador. Cada archivo trae su comando de compilación en el encabezado, y el de ThreadSanitizer (`-fsanitize=thread`), el sanitizer de la Semana 12 para hilos.

## Ejercicio 1: el contador de visitas de la biblioteca

Archivo: [`ejercicio1_contador_visitas.cpp`](./ejercicio1_contador_visitas.cpp). Compílalo y córrelo una vez antes de cambiar nada: las dos puertas registran una después de la otra, y la cuenta da bien.

**Respuesta 1 (antes del TODO 1):** con las dos puertas en dos hilos, al mismo tiempo, cada una registra un millón de visitas. ¿Qué número crees que imprime? ¿El mismo cada vez?

_(tu respuesta)_

**Respuesta 2 (después del TODO 1):** corre el programa cinco veces y anota los cinco resultados. `total = total + 1` es una sola línea. ¿Por qué se pierden visitas?

_(tu respuesta)_

**Respuesta 3 (después del TODO 2):** con el `lock_guard`, ¿qué imprime? ¿Qué reporta ThreadSanitizer antes y después del mutex?

_(tu respuesta)_

**La versión completa, tal como la resuelvo yo:**

_(anota aquí los dos hilos, el mutex, y lo que reportó ThreadSanitizer)_

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

## Ejercicio 2: la tarjeta del comedor

Archivo: [`ejercicio2_tarjeta_comedor.cpp`](./ejercicio2_tarjeta_comedor.cpp). Solo o en pareja.

Dos cajas cobran de la misma tarjeta prepago al mismo tiempo. El encabezado dice qué tiene que quedar al final.

1. Completa el TODO 1 (los dos hilos), sin mutex todavía. Corre tres veces y anota el saldo final y los cobros.

_(tu respuesta)_

2. Agrega el mutex (TODO 2), pero toma el candado solo alrededor de la resta y de cada contador, dentro de los dos lados del `if`, no alrededor de la pregunta `saldo >= monto`. Corre diez veces. ¿Algún saldo final fue negativo? ¿Por qué puede pasar, si la resta está protegida?

_(tu respuesta)_

3. Completa el TODO 3: un solo `lock_guard` al inicio de `cobrar`, que proteja la pregunta y el cambio juntos. Corre diez veces y con ThreadSanitizer.

_(tu respuesta)_

Responde: `getSaldo()` no toma el candado. ¿Es un problema en este programa? ¿En qué programa sí lo sería?

_(tu respuesta)_

## Ejercicio 3: la taquilla del concierto

Archivo: [`ejercicio3_taquilla.cpp`](./ejercicio3_taquilla.cpp). Solo o en pareja.

Cinco vendedores venden los asientos del mismo teatro al mismo tiempo. El encabezado describe la clase `Taquilla`; esta vez no hay código de partida para la clase: la escribes tú. El `main` ya está escrito y verifica las reglas al final. Mientras no escribas la clase, el archivo no compila.

1. Escribe `Taquilla` y corre el programa diez veces: las tres líneas finales tienen que salir siempre iguales a las del encabezado.
2. Córrelo con ThreadSanitizer: no tiene que reportar nada.
3. Responde: ¿qué partes de `Taquilla` son sección crítica? ¿Por qué `reservarPar` no puede llamar dos veces a `reservar`?

_(tu respuesta)_

4. Responde: un compañero propone poner un solo mutex en `main`, alrededor de los cinco `std::thread`. ¿Funcionaría? ¿Qué se perdería?

_(tu respuesta)_

## Qué construcciones nuevas usa este laboratorio

`#include <thread>` y `std::thread hilo(funcion, argumento1, argumento2)`, con argumentos por valor o como puntero; `join()`. `#include <mutex>`, `std::mutex` como atributo, y `std::lock_guard<std::mutex> guardia(candado);`, que toma el candado al crearse y lo suelta al salir del bloque. Compilar con `-fsanitize=thread`.

## Antes de la próxima sesión

**Lectura:** ["Beyond the Mutex: A Practical Guide to High-Performance Concurrency in C++", Mansi Maheshwari](https://medium.com/@mansi_maheshwari/beyond-the-mutex-a-practical-guide-to-high-performance-concurrency-in-c-a73a0755293e)

Hoy el mutex arregló el contador de visitas. Imagina que, en vez de dos puertas, son 16 hilos y cada uno registra un millón de visitas. Cada `registrar` toma y suelta el candado. ¿Dónde pasa el tiempo el programa? ¿Hace falta un candado completo para sumar 1 a un número?

_(tu respuesta)_
