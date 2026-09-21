# Semana 6, Sesión 2: Smart pointers

## Objetivo de la sesión

Reemplazar manejo manual de memoria con `new` y `delete` por smart pointers, y justificar cuándo usar `unique_ptr` frente a `shared_ptr`.

## Antes de empezar

**Lectura previa:** ["Understanding C++ Smart Pointers: Unique, Shared, and Weak", Madhawa Polkotuwa](https://madhawapolkotuwa.medium.com/understanding-c-smart-pointers-unique-shared-and-weak-404800726aed)

**Referencia:** ["std::unique_ptr", cppreference](https://en.cppreference.com/w/cpp/memory/unique_ptr.html)

Según el artículo, ¿qué tienen en común `unique_ptr`, `shared_ptr` y `weak_ptr` que los distingue de un puntero crudo administrado con `new` y `delete`?

_(tu respuesta)_

La sesión pasada escribiste a mano un constructor de movimiento y un operador de asignación de movimiento, para que copiar un objeto con memoria dinámica no terminara en un doble free. ¿Qué pasaría si esa lógica ya viniera resuelta dentro de un tipo de la biblioteca estándar, en vez de tener que escribirla en cada clase que reserva memoria?

_(tu respuesta)_

## Ejercicio 1: inventario con unique_ptr

Archivo: [`ejercicio1_inventario_con_unique_ptr.cpp`](./ejercicio1_inventario_con_unique_ptr.cpp). Mismo inventario de la Semana 5, Sesión 2, ya corregido, pero todavía con memoria administrada a mano.

**Respuesta 1, antes de ver la solución:** `crearInventario` reserva memoria con `new[]` y `main` la libera con `delete[] stock;` al final. Si cambias el tipo de retorno a `std::unique_ptr<int[]>`, ¿en qué momento exacto se liberaría esa memoria, sin que nadie escriba `delete[]`?

_(tu respuesta)_

**Respuesta 2:** las funciones `mostrarInventario`, `contarProductosAgotados` y `obtenerReporteFinal` reciben `int*`, no `std::unique_ptr<int[]>`. ¿Qué método de `unique_ptr` te da acceso a ese puntero crudo, sin cederle la propiedad del recurso?

_(tu respuesta)_

**La formulación completa, tal como la resuelvo yo:**

_(anota aquí la salida real, mientras se revisa en clase)_

## Ejercicio 2: registro compartido

Archivo: [`ejercicio2_registro_compartido.cpp`](./ejercicio2_registro_compartido.cpp). `RegistroDeVuelo` administra su memoria a mano, igual que en la Semana 5, Sesión 1.

**Respuesta 1, antes de ver la solución:** si cambias `double* alturas` por `std::unique_ptr<double[]> alturas`, ¿por qué el destructor de `RegistroDeVuelo` deja de hacer falta por completo?

_(tu respuesta)_

**Respuesta 2:** `MonitorDeVuelo` necesita que dos objetos distintos (torre y cabina) lean el mismo `RegistroDeVuelo`, sin que ninguno de los dos sea el único dueño. Entre `unique_ptr` y `shared_ptr`, ¿cuál permite esto, y qué te dice `.use_count()` en cada momento?

_(tu respuesta)_

**La formulación completa, tal como la resuelvo yo:**

_(anota aquí la salida real, con los valores de `use_count()` en cada paso, mientras se revisa en clase)_

## Durante el ConcepTest

**Tu voto, antes de discutir en pareja** (A, B, C o D):

_(tu voto)_

**Tu razonamiento:**

_(tu respuesta)_

**Después de discutir en pareja, ¿cambiaste de voto? ¿Por qué?**

_(tu respuesta)_

## Ejercicio 3: sensores de temperatura

Archivo: [`ejercicio3_sensores_de_temperatura.cpp`](./ejercicio3_sensores_de_temperatura.cpp). Solo o en pareja.

Completa `RegistroTemperaturas` con `std::unique_ptr<double[]>` en vez de memoria manual, y `SensorRemoto` con `std::shared_ptr<RegistroTemperaturas>`, con el mismo patrón del Ejercicio 2:

- `RegistroTemperaturas`: atributo `std::unique_ptr<double[]> lecturas` y `int capacidad`; constructor que crea `lecturas` con `std::make_unique<double[]>(capacidad)`; `guardar` y `obtener`; sin destructor.
- `SensorRemoto`: atributos `std::shared_ptr<RegistroTemperaturas> registro` (guardado con `std::move` desde el parámetro) e `int idSensor`; constructor que imprime `use_count()` al conectar; `reportar(int indice)`; destructor que imprime la desconexión.

## Compilar y ejecutar

```
g++ -std=c++20 -Wall -Wextra -g ejercicio1_inventario_con_unique_ptr.cpp -o bin/ejercicio1
./bin/ejercicio1
```

Repite el mismo patrón con `ejercicio2_registro_compartido.cpp` y `ejercicio3_sensores_de_temperatura.cpp`. Para confirmar que no queda ninguna fuga, compílalo también con `-fsanitize=address`:

```
g++ -std=c++20 -Wall -Wextra -g -fsanitize=address ejercicio1_inventario_con_unique_ptr.cpp -o bin/ejercicio1_asan
./bin/ejercicio1_asan
```

## Qué construcciones nuevas usa este laboratorio

`std::unique_ptr<Tipo>` (propiedad exclusiva, no se puede copiar, se crea con `std::make_unique`), `std::shared_ptr<Tipo>` (propiedad compartida con conteo de referencias, se crea con `std::make_shared`, `.use_count()` consulta el conteo), y el método `.get()` de `unique_ptr` para obtener el puntero crudo sin ceder la propiedad. Cabecera `<memory>`. El vocabulario de `std::move`, del constructor de movimiento y del operador de asignación de movimiento es el de la Semana 6, Sesión 1: hoy se usan (`std::move` al guardar un `shared_ptr` en un atributo), pero ya no hace falta escribir un constructor ni un operador de movimiento propios, porque los smart pointers ya los traen resueltos.

## Antes de la próxima sesión

La próxima sesión (Semana 7, Sesión 1) es un laboratorio integrador: no trae lectura nueva, junta en un solo problema todo lo visto hasta hoy (POO, herencia, composición, RAII, move semantics y smart pointers). Antes de llegar, repasa qué parte de tus laboratorios anteriores todavía usa `new`/`delete` manual, y qué pasaría si la reemplazas por lo de hoy.
