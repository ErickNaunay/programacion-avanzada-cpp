# Semana 11, Sesión 2: Tipado moderno y manejo de errores explícito

## Objetivo de la sesión

Refactorizar una función que retorna códigos de error hacia el uso de std::optional, y justificar por qué reduce el riesgo de acceso nulo.

## Antes de empezar

**Lectura previa:** ["Optional Is Not Optional in C++ (and Definitely Not a Pointer)", Kyrylo Rud](https://medium.com/@kyrylo.rud/optional-is-not-optional-in-c-and-definitely-not-a-pointer-a1074f160c3e)

**Referencia:** ["std::optional", cppreference](https://en.cppreference.com/w/cpp/utility/optional.html)

Según el artículo, ¿por qué un `std::optional` "no es un puntero"? ¿Dónde vive el valor que guarda?

_(tu respuesta)_

Una función `buscarTemperatura(registro, hora)` no encuentra lectura para una hora. ¿Lanzarías una excepción? ¿Devolverías -1? ¿Y si la cámara de frío registra temperaturas bajo cero?

_(tu respuesta)_

## Ejercicio 1: la cámara de frío

Archivo: [`ejercicio1_camara_de_frio.cpp`](./ejercicio1_camara_de_frio.cpp). Córrelo una vez antes de cambiar nada.

**Respuesta 1 (antes del TODO 1):** el registro tiene lectura a las 7. ¿Qué imprime el programa para la hora 7, y por qué?

_(tu respuesta)_

**Respuesta 2 (TODO 1 y 2):** con `std::optional<double>` como tipo de retorno, ¿qué pasa si dejas `double temperatura = buscarTemperatura(registro, horas[i]);` sin cambiarla? ¿Es un error al compilar o al ejecutar?

_(tu respuesta)_

**Respuesta 3 (TODO 3 y 4):** `value_or(4.0)` y `.value()` sobre la hora 8, que no tiene lectura. ¿Qué devuelve cada uno?

_(tu respuesta)_

**La versión completa, tal como la resuelvo yo:**

_(anota aquí la firma nueva de buscarTemperatura, cómo se revisa el resultado y la salida final)_

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

## Ejercicio 2: el catálogo sin punteros

Archivo: [`ejercicio2_catalogo_optional.cpp`](./ejercicio2_catalogo_optional.cpp). Solo o en pareja.

`buscar` devuelve un puntero al producto dentro del vector, o `nullptr`. Corre el archivo sin cambios: termina antes de tiempo. Resuelve los tres `TODO`: `buscar` devuelve `std::optional<Producto>`, `main` revisa cada resultado, y el descuento de un producto pasa a ser un atributo `std::optional<double>`. La salida esperada exacta está en el encabezado.

Antes de resolverlo, compila y corre la versión sin cambios con `-fsanitize=address`. ¿Qué dos problemas distintos reporta, y en qué líneas?

_(tu respuesta)_

Antes de dar el ejercicio por terminado, responde: `encontrado` se busca antes de agregar dos productos al catálogo. ¿Por qué con el puntero eso era un problema y con el `std::optional` ya no lo es?

_(tu respuesta)_

## Ejercicio 3: el estacionamiento de la facultad

Archivo: [`ejercicio3_estacionamiento.cpp`](./ejercicio3_estacionamiento.cpp). Solo o en pareja.

`asignarPuesto`, `puestoDe` y `liberar` devuelven -1 o -2 en vez de un número de puesto, y `main` imprime esos códigos como si fueran puestos. Refactoriza las tres funciones para que ninguna devuelva un código. Para cada caso, tú decides si es una ausencia esperada (`std::optional`) o un error de quien llama (una excepción), y ajustas `main` para producir la salida esperada exacta del encabezado.

Antes de dar el ejercicio por terminado, completa la tabla con tu decisión para cada caso:

| Función | Caso | `std::optional` o excepción | Por qué |
|---|---|---|---|
| `asignarPuesto` | No hay puestos libres | _(…)_ | _(…)_ |
| `asignarPuesto` | La placa ya está adentro | _(…)_ | _(…)_ |
| `puestoDe` | La placa no está | _(…)_ | _(…)_ |
| `liberar` | La placa no está | _(…)_ | _(…)_ |

Responde también: la placa 4521 queda en el puesto 0. Si escribes `if (puesto)` sobre un `std::optional<int>` que guarda 0, ¿entra al `if`? ¿Por qué eso no pasaba con el puntero ni con el código -1, y por qué con el `optional` es lo correcto?

_(tu respuesta)_

## Compilar y ejecutar

```
g++ -std=c++20 -Wall -Wextra -g ejercicio1_camara_de_frio.cpp -o bin/ejercicio1
./bin/ejercicio1
```

Repite el mismo patrón con `ejercicio2_catalogo_optional.cpp` y `ejercicio3_estacionamiento.cpp`. Para el sanitizer del Ejercicio 2:

```
g++ -std=c++20 -g -fsanitize=address ejercicio2_catalogo_optional.cpp -o bin/ejercicio2_asan
./bin/ejercicio2_asan
```

## Qué construcciones nuevas usa este laboratorio

`std::optional<T>` (de `<optional>`) como tipo de retorno y como atributo; `std::nullopt` para devolver un `optional` vacío; `has_value()` y la conversión a `bool` (`if (resultado)`) para preguntar si hay valor; `*resultado` y `resultado->metodo()` para usarlo; `value_or(valorPorDefecto)`; `value()`, que lanza `std::bad_optional_access` si está vacío; asignar un valor a un `optional` ya declarado (`descuento = fraccion;`).

## Antes de la próxima sesión

**Lectura:** ["The Illusion of Safety: Why Passing Tests Don't Guarantee Bug-Free Code", Tshegofatsoseane](https://medium.com/@tshegofatsoseane98/the-illusion-of-safety-why-passing-tests-dont-guarantee-bug-free-code-0ce44fd5c43b)

En este laboratorio, cada ejercicio trae su salida esperada y la comparas a ojo con la que imprime tu programa. ¿Qué tendría que hacer un programa para comparar esa salida por ti, cada vez que cambias el código? ¿Qué no podría detectar aunque todas las líneas coincidan?

_(tu respuesta)_
