# Semana 9, Sesión 1: Polimorfismo II: interfaces y clases abstractas

## Objetivo de la sesión

Diseñar una interfaz común mediante clases abstractas y funciones virtuales puras para un conjunto de clases heterogéneas.

## Antes de empezar

**Lectura previa:** ["SOLID Design Principles with Example Code (C++)", Suresh Jangale](https://medium.com/@sureshjangale137/solid-design-principles-with-examples-e6e8baf5f85f)

**Referencia:** ["Abstract class", cppreference](https://en.cppreference.com/w/cpp/language/abstract_class.html)

Según el artículo, ¿qué dice el principio de inversión de dependencias sobre de quién debe depender una clase de alto nivel? ¿Qué problema describe el principio de segregación de interfaces?

_(tu respuesta)_

La sesión pasada, `Figura::area()` devolvía 0 solo porque algo tenía que devolver. ¿Tiene sentido crear un objeto que sea solo una `Figura`? Si no, ¿qué debería hacer el compilador cuando alguien lo intenta?

_(tu respuesta)_

## Ejercicio 1: Figura abstracta

Archivo: [`ejercicio1_figura_abstracta.cpp`](./ejercicio1_figura_abstracta.cpp). La misma jerarquía de la sesión pasada, ahora con `imprimirNombre()` y un `Triangulo`. Compila y córrelo antes de cambiar nada: el triángulo imprime área 0.

**Respuesta 1, antes de ver la solución:** después de convertir `area()` e `imprimirNombre()` en virtuales puras, ¿qué pasa con la línea `Figura generica;` si le quitas el comentario?

_(tu respuesta)_

**Respuesta 2:** `Triangulo` no implementa `area()`. ¿En qué línea aparece el error, y qué le falta a `Triangulo` para que se pueda crear?

_(tu respuesta)_

**La formulación completa, tal como la resuelvo yo:**

_(anota aquí los dos mensajes de error y la salida final)_

## Durante el ConcepTest

**Tu voto, antes de discutir en pareja** (A, B, C o D):

_(tu voto)_

**Tu razonamiento:**

_(tu respuesta)_

**Después de discutir en pareja, ¿cambiaste de voto? ¿Por qué?**

_(tu respuesta)_

## Ejercicio 2: estación meteorológica

Archivo: [`ejercicio2_estacion_meteorologica.cpp`](./ejercicio2_estacion_meteorologica.cpp). Solo o en pareja.

`EstacionMeteorologica` guarda hasta 3 medidores en `std::unique_ptr<IMedidor> medidores[3]` y arma un reporte con todos. Diseña la interfaz `IMedidor`, implementa `Termometro`, `Barometro` y `Anemometro`, y completa `agregar()` y `reportar()`. `EstacionMeteorologica` no puede mencionar ninguna clase concreta. La salida esperada exacta está en el encabezado del archivo.

Antes de dar el ejercicio por terminado, responde: si mañana agregas un `Higrometro` (humedad en %), ¿qué líneas de `EstacionMeteorologica` tienes que cambiar?

_(tu respuesta)_

## Ejercicio 3: dispositivos de oficina

Archivo: [`ejercicio3_dispositivos_oficina.cpp`](./ejercicio3_dispositivos_oficina.cpp). Solo o en pareja.

El archivo compila y corre tal como está, con una sola interfaz `IDispositivoOficina` que obliga a `ImpresoraBasica` a responder a `escanear()` y a `enviarFax()`. Divídela en `IImpresora`, `IEscaner` e `IFax`, haz que cada clase implemente solo las que soporta, y ajusta `imprimirLote`, `escanearLote` y `main`. Las dos salidas, la de antes y la esperada después del cambio, están en el encabezado del archivo.

Antes de escribir código, responde: `Multifuncional` va a heredar de tres clases a la vez. En la Semana 4, una herencia así terminó en el problema del diamante. ¿Por qué aquí no aparece?

_(tu respuesta)_

Al terminar, prueba guardar `&basica` en el arreglo de escáneres. ¿Qué dice el compilador?

_(tu respuesta)_

## Compilar y ejecutar

```
g++ -std=c++20 -Wall -Wextra -g ejercicio1_figura_abstracta.cpp -o bin/ejercicio1
./bin/ejercicio1
```

Repite el mismo patrón con `ejercicio2_estacion_meteorologica.cpp` y `ejercicio3_dispositivos_oficina.cpp`.

## Qué construcciones nuevas usa este laboratorio

Función virtual pura (`virtual tipo nombre(parámetros) = 0;`) y clase abstracta; la convención de interfaz del curso (solo virtuales puras públicas y un destructor virtual con cuerpo vacío, sin atributos); e implementar varias interfaces a la vez con la herencia múltiple de la Semana 4, Sesión 1.

## Antes de la próxima sesión

**Lectura:** ["Function and Class Templates in C++: A Practical Guide to Generic Programming", Murat Toğunçhan Düzgün](https://medium.com/@togunchan/function-and-class-templates-in-c-enhancing-flexibility-and-reusability-894bd3d0c84e)

Necesitas una función `mayor` que devuelva el mayor de dos valores para `int`, para `double` y para `char`. Con lo que sabes hoy, ¿cuántas funciones escribes, y qué cambia entre ellas además del tipo?

_(tu respuesta)_
