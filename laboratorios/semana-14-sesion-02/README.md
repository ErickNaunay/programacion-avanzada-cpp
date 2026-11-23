# Semana 14, Sesión 2: Laboratorio Integrador II

## Objetivo de la sesión

Integrar en la solución de un solo problema los temas de la Semana 8, Sesión 2 a la Semana 13, Sesión 2: polimorfismo, interfaces y clases abstractas, plantillas, contenedores y algoritmos de la STL, excepciones, `std::optional`, pruebas con GoogleTest, CMake y sanitizers, hilos, mutex y atomics.

## Para hacer en casa

Esta sesión no tiene clase. El laboratorio completo se hace en casa y vence el **domingo de la Semana 14**: súbelo a tu fork, en esta carpeta, antes de esa fecha.

No hay lectura nueva. Si algo no está fresco, vuelve a las referencias de cada semana:

- [Funciones virtuales](https://en.cppreference.com/w/cpp/language/virtual) y [clases abstractas](https://en.cppreference.com/w/cpp/language/abstract_class) (Semanas 8 y 9)
- [Plantillas de clase](https://en.cppreference.com/w/cpp/language/class_template) y [algoritmos](https://en.cppreference.com/w/cpp/algorithm) (Semanas 9 y 10)
- [`std::optional`](https://en.cppreference.com/w/cpp/utility/optional) (Semana 11)
- [GoogleTest Primer](https://google.github.io/googletest/primer.html) y [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html) (Semana 12)
- [std::mutex](https://en.cppreference.com/w/cpp/thread/mutex.html) y [std::atomic](https://en.cppreference.com/w/cpp/atomic/atomic.html) (Semana 13)

## El problema: un día en la cafetería del campus

La cafetería vende cinco productos: un café, un jugo grande, un almuerzo, un combo de jugo grande con almuerzo, y galletas. Del café, el jugo, el almuerzo y el combo hay unidades de sobra; de las galletas, pocas. Cada producto calcula su precio a su manera y vive en un catálogo.

Durante el día, tres cajas toman 60000 pedidos al mismo tiempo y los dejan en una cola. Después, dos cocineros sacan pedidos de la cola al mismo tiempo. Cada cocinero busca el precio en el catálogo, descuenta el inventario, registra la venta y anota el resultado. Un pedido puede despacharse, quedar sin stock o ser inválido (uno de cada 50 pide un producto que no existe). Al cierre, el reporte del día calcula el total vendido, la venta mayor y cuántas ventas pasaron de 10 dólares.

Al final, todo tiene que cuadrar: ningún pedido perdido ni repetido, ningún producto con unidades negativas, y para cada producto, las unidades vendidas más las que quedan dan las unidades con que empezó el día.

## De dónde viene cada pieza

| Tema | De qué semana | Dónde aparece |
|---|---|---|
| Funciones virtuales y `override` | Semana 8, Sesión 2 | `precio()` en `Bebida`, `Plato` y `Combo` |
| Clases abstractas | Semana 9, Sesión 1 | `Producto`, guardado en el catálogo como `std::unique_ptr<Producto>` |
| Composición | Semana 4, Sesión 2 | `Combo` tiene una `Bebida` y un `Plato` |
| Plantillas de clase | Semana 9, Sesión 2 | `ColaSegura<T>` |
| Contenedores e iteradores | Semana 10, Sesión 1 | `std::map` en `Catalogo` e `Inventario`, `std::vector` en la cola y en el registro, `std::set` en el reporte |
| Algoritmos y lambdas | Semana 10, Sesión 2 | `reporte.h` |
| Excepciones | Semana 11, Sesión 1 | `Catalogo::agregar` e `Inventario::descontar` |
| `std::optional` | Semana 11, Sesión 2 | `ColaSegura::tomar`, `Catalogo::precioDe`, `ventaMayor` |
| GoogleTest | Semana 12, Sesión 1 | `test_pedidos.cpp` |
| CMake y sanitizers | Semana 12, Sesión 2 | `CMakeLists.txt`, con `CON_SANITIZERS` y la opción nueva `CON_TSAN` |
| Hilos, mutex y `lock_guard` | Semana 13, Sesión 1 | `ColaSegura`, `Inventario`, `RegistroDeVentas` |
| `std::atomic` | Semana 13, Sesión 2 | `Estadisticas` |

## Archivos

- [`productos.h`](./productos.h): `Producto`, `Bebida`, `Plato`, `Combo` y `Catalogo`. `Producto` y `Plato` ya están. Te tocan los `TODO 1` y `2`.
- [`pedidos.h`](./pedidos.h): `Pedido`, `Venta`, `ColaSegura`, `Inventario`, `Estadisticas` y `RegistroDeVentas`. Te tocan los `TODO 3` a `7`.
- [`reporte.h`](./reporte.h): el reporte de cierre. `idsSinRepetir` ya está. Te toca el `TODO 8`.
- [`main.cpp`](./main.cpp): un día de la cafetería. No lo cambies: al final imprime `Cuadra: si` o `Cuadra: no`.
- [`test_pedidos.cpp`](./test_pedidos.cpp): dos pruebas ya escritas y tres funciones de ayuda. Te toca el `TODO 9`: trece pruebas más, descritas en el archivo, incluidas dos con dos hilos.
- [`CMakeLists.txt`](./CMakeLists.txt): el programa y las pruebas, con la opción `CON_SANITIZERS` de la Semana 12. Te toca el `TODO 10`: una opción `CON_TSAN` para ThreadSanitizer.

Empieza por el `TODO 3`. Hasta que `ColaSegura` sea una plantilla, el proyecto no compila.

## Compilar y ejecutar

Desde esta carpeta:

```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/cafeteria
ctest --test-dir build --output-on-failure
```

Mientras no completes los `TODO`, vas a ver advertencias de parámetro sin usar (`-Wunused-parameter`). Desaparecen a medida que completas cada uno.

Con el `TODO 3` listo y antes de tocar el `TODO 4`, corre el programa tres veces. Lo más probable es que termine con un error de memoria (`double free or corruption`, `Segmentation fault` o `malloc(): ...`). ¿Por qué un programa que nunca usa `new` ni `delete` puede romper la memoria?

_(tu respuesta)_

Cuando tengas el `TODO 10`, compila en dos carpetas más, una con cada sanitizer:

```
cmake -S . -B build-asan -DCON_SANITIZERS=ON -DCMAKE_BUILD_TYPE=Debug
cmake --build build-asan
./build-asan/cafeteria
./build-asan/pruebas

cmake -S . -B build-tsan -DCON_TSAN=ON -DCMAKE_BUILD_TYPE=Debug
cmake --build build-tsan
./build-tsan/cafeteria
./build-tsan/pruebas
```

## Salida esperada

```
No se agrego: codigo repetido
No se agrego: precio no positivo
Productos en el catalogo: 5
Pedidos en la cola: 60000
Pedidos atendidos: 60000
Pedidos invalidos: 1197
Pedidos sin stock: (cambia un poco de una corrida a otra)
Total vendido: 370863.00
Venta mayor: 20.25
Ventas sobre 10: 11760
Cuadra: si
```

Y `ctest`: las 15 pruebas pasan en las tres carpetas, sin ningún reporte de AddressSanitizer en `build-asan` ni de ThreadSanitizer en `build-tsan`.

## Rúbrica

- **Polimorfismo y composición:** `precio()` es virtual pura en `Producto` y lleva `override` en cada derivada; `Combo` guarda su bebida y su plato como atributos y calcula su precio llamando al precio de cada uno.
- **Catálogo:** `agregar` lanza `std::invalid_argument` con el mensaje exacto en los dos casos, y un producto rechazado no queda guardado; `precioDe` no crea claves y devuelve un `optional` vacío para un código que no está.
- **Plantilla:** una sola `ColaSegura<T>`, que funciona igual con `Pedido`, `int` y `double`.
- **Concurrencia, la cola y el registro:** `agregar` y `tomar` toman el candado de la clase; en `tomar`, mirar si quedan elementos y avanzar `siguiente` pasan dentro de la misma sección crítica. `RegistroDeVentas::anotar` también toma su candado.
- **Concurrencia, el inventario:** en `descontar`, preguntar si alcanza y restar pasan con el candado tomado; las excepciones se lanzan con el candado tomado, y el `lock_guard` lo suelta al salir.
- **Atomics:** los tres contadores de `Estadisticas` son `std::atomic<int>`, empiezan en 0 en el constructor y no usan mutex.
- **Reporte:** las cuatro funciones usan un algoritmo de `<algorithm>` o `<numeric>` con una lambda, sin ciclos escritos a mano; `ventaMayor` devuelve un `optional` vacío sin ventas.
- **Pruebas:** las trece pruebas del `TODO 9`, cada una con un nombre que dice lo que verifica. Si se quita el candado de `descontar`, la de dos hilos, compilada con `CON_TSAN`, hace que ThreadSanitizer reporte un data race.
- **Build:** `CON_TSAN` apagada por defecto; con ella encendida, el programa y las pruebas corren sin reportes de ThreadSanitizer.

## Para pensar mientras completas el laboratorio

`Estadisticas` usa atomics y no un mutex. `Inventario` usa un mutex y no atomics. ¿Por qué no al revés? ¿Qué tendría que pasar con `descontar` para que un `std::atomic<int>` por producto alcanzara?

_(tu respuesta)_

Los dos cocineros consultan el `Catalogo` al mismo tiempo, y el `Catalogo` no tiene candado. ¿Por qué no hace falta? ¿Qué cambio en `main` lo haría necesario?

_(tu respuesta)_

## Antes de la próxima sesión

La próxima sesión es de Tópicos Avanzados: un repaso de todo el curso guiado por tus preguntas, sin lectura nueva. Trae por escrito dos preguntas: una sobre un tema del curso que todavía no te cierra, y una sobre algo de C++ que el curso no vio y te gustaría entender.

_(tus dos preguntas)_
