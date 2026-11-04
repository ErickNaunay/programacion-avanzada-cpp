# Semana 11, Sesión 1: Manejo de excepciones

## Objetivo de la sesión

Agregar manejo robusto de errores con try, catch y throw a un programa que originalmente falla sin control de excepciones.

## Antes de empezar

**Lectura previa:** ["Why I've soured on exceptions in C++", Jordan Edmunds Chetty](https://medium.com/@jordan.l.edmunds/why-ive-soured-on-exceptions-in-c-ea10b8ad10e8)

**Referencia:** ["Exceptions", cppreference](https://en.cppreference.com/w/cpp/language/exceptions.html)

Según el artículo, ¿qué problema resuelven las excepciones frente a devolver un código de error? ¿Qué le cuesta al programador usarlas, según el autor?

_(tu respuesta)_

La `Bodega` de la Semana 10 devuelve `false` cuando no puede retirar, y `*std::max_element(v.begin(), v.end())` con un vector vacío lee una posición que no existe. ¿Cómo se entera quien llama de que algo salió mal? ¿Qué pasa si no revisa el valor devuelto?

_(tu respuesta)_

## Ejercicio 1: el reporte del sensor

Archivo: [`ejercicio1_lecturas_sensor.cpp`](./ejercicio1_lecturas_sensor.cpp). Seis lecturas por hora y un programa que responde consultas sobre ellas. Córrelo una vez antes de cambiar nada y lee la salida completa.

**Respuesta 1 (antes del TODO 1):** la consulta de la hora 9 y el promedio de 3 a 8 piden lecturas que no existen. ¿El programa avisó? ¿Qué números imprimió en esas dos líneas?

_(tu respuesta)_

**Respuesta 2 (TODO 1):** con `lecturas.at(hora)` en vez de `lecturas[hora]`, ¿qué esperas que pase al llegar a la hora 9? ¿Se imprime "Fin del reporte"?

_(tu respuesta)_

**Respuesta 3 (TODO 2 y 4):** la excepción de la hora 9 se lanza dentro de `lecturaEn`. En el promedio de 3 a 8, `lecturaEn` la lanza dentro de `promedioEntre`, que fue llamada desde `main`. ¿Dónde tiene que estar el `catch` para atraparla, y qué pasa con el resto del cuerpo de `promedioEntre`?

_(tu respuesta)_

**La versión completa, tal como la resuelvo yo:**

_(anota aquí dónde quedó cada throw, cada try y cada catch, y la salida final)_

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

## Ejercicio 2: una bodega que explica por qué rechaza

Archivo: [`ejercicio2_bodega_excepciones.cpp`](./ejercicio2_bodega_excepciones.cpp). Solo o en pareja.

`retirar` devuelve `false` en tres casos distintos, y quien llama no sabe cuál ocurrió. Resuelve los cuatro `TODO`: `retirar` lanza una excepción distinta por cada motivo, `stockDe` deja salir la de `map::at`, y `main` atrapa cada una. La salida esperada exacta está en el encabezado del archivo.

Antes de dar el ejercicio por terminado, responde: ¿en qué orden quedaron las tres verificaciones de `retirar` y la resta del stock? ¿Qué le pasaría al stock de un pedido rechazado si la resta estuviera antes de la última verificación?

_(tu respuesta)_

Responde también: en el `TODO 3`, ¿usaste un `catch` o tres? Si pones un `catch (const std::exception& e)` antes de un `catch (const std::out_of_range& e)`, ¿qué te dice el compilador, y por qué?

_(tu respuesta)_

## Ejercicio 3: el lote del horno

Archivo: [`ejercicio3_horno_lote.cpp`](./ejercicio3_horno_lote.cpp). Solo o en pareja.

El horno corre todos los pasos del lote sin validar nada. El comentario del archivo describe dos reglas con consecuencias distintas: una rechaza un paso y deja seguir el lote, la otra detiene el lote completo. Tú decides qué excepción lanza cada regla, dónde se lanza y dónde se atrapa cada una. La salida esperada exacta está en el encabezado; fíjate en qué línea aparece "Ventilacion apagada".

Antes de dar el ejercicio por terminado, responde: ¿qué tipo pusiste en el `catch` del loop de `ejecutarLote`? ¿Qué imprime el programa si lo cambias por `std::exception`? Pruébalo.

_(tu respuesta)_

Responde también: ningún `catch` apaga la ventilación. ¿Por qué "Ventilacion apagada" se imprime antes que "Lote detenido"? ¿Qué pasa con esa línea si borras el `try` de `main`? Pruébalo.

_(tu respuesta)_

## Compilar y ejecutar

```
g++ -std=c++20 -Wall -Wextra -g ejercicio1_lecturas_sensor.cpp -o bin/ejercicio1
./bin/ejercicio1
```

Repite el mismo patrón con `ejercicio2_bodega_excepciones.cpp` y `ejercicio3_horno_lote.cpp`.

## Qué construcciones nuevas usa este laboratorio

`throw` con las excepciones de `<stdexcept>` (`std::invalid_argument`, `std::out_of_range`, `std::runtime_error`), cada una con un mensaje; `try` con uno o varios `catch`; atrapar con `catch (const std::tipo& e)` y leer el mensaje con `e.what()`; `std::exception` como base común de todas ellas; `at()` de `std::vector` y de `std::map`, que lanzan `std::out_of_range` en vez de leer fuera del contenedor.

## Antes de la próxima sesión

**Lectura:** ["Optional Is Not Optional in C++ (and Definitely Not a Pointer)", Kyrylo Rud](https://medium.com/@kyrylo.rud/optional-is-not-optional-in-c-and-definitely-not-a-pointer-a1074f160c3e)

Una función `buscarTemperatura(registro, hora)` no encuentra lectura para una hora. ¿Lanzarías una excepción? ¿Devolverías -1? ¿Y si la cámara de frío registra temperaturas bajo cero?

_(tu respuesta)_
