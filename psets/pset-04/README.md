# PSet 4: Proyecto Final, *Invasores*

## Contexto

Vas a construir *Invasores*, un juego de naves que corre en la terminal. Usas lo que vimos en el semestre: clases con invariantes, sobrecarga de operadores, herencia, composición, RAII, movimiento, smart pointers, polimorfismo, plantillas, la STL, excepciones, `std::optional`, GoogleTest, CMake, sanitizers, hilos y atomics. Es individual y tiene dos partes que valen lo mismo: el código (50%) y su defensa (50%).

Toda la clase hace el mismo juego, con las mismas reglas. Lo que cambia entre un proyecto y otro es el diseño, que es tuyo, y una extensión que inventas tú.

## Fechas

| Qué | Cuándo |
|---|---|
| Hito | Pull Request antes de la Semana 15, Sesión 2 |
| Entrega final | Pull Request antes de la Semana 16, Sesión 1 |
| Defensa | Semana 16, en el horario que te asigne |

## El juego

### El campo

El campo mide 60 columnas por 20 filas. La columna 0 está a la izquierda y la fila 0 arriba. Encima del campo se muestran los puntos, las vidas y la oleada; debajo, una línea con los controles o con el resultado de la partida.

### La nave

Se dibuja con `A`. Empieza en la columna 30 de la fila 19 con 3 vidas, y nunca sale de la fila 19.

| Tecla | Comando |
|---|---|
| `a` o `A` | Una columna a la izquierda, sin salir del campo |
| `d` o `D` | Una columna a la derecha, sin salir del campo |
| espacio | Disparar |
| `r` o `R` | Con la partida terminada, empezar otra |
| `q` o `Q` | Salir del programa |

Cualquier otra tecla se ignora. Con la partida terminada, solo funcionan `r` y `q`.

La nave dispara con un arma que tiene una cadencia de 5 cuadros: después de un disparo en el cuadro `c`, el siguiente se permite desde el cuadro `c + 5`. Un disparo que no cumple la cadencia no hace nada. La cadencia nunca puede ser menor que 1.

### Los proyectiles

| Símbolo | De quién | Nace en | Movimiento |
|---|---|---|---|
| `\|` | La nave | La celda de arriba de la nave | Sube una fila por cuadro |
| `!` | Un enemigo | La celda de abajo del enemigo | Baja una fila por cuadro |

Un proyectil que sale del campo desaparece.

### Los enemigos

| Símbolo | Nombre | Vidas | Puntos | Movimiento | Disparo |
|---|---|---|---|---|---|
| `W` | Raso | 1 | 10 | Cada 10 cuadros avanza una columna. Si esa columna queda fuera del campo, en vez de avanzar baja una fila y cambia de dirección. Empieza hacia la derecha. | En cada cuadro en que `(cuadro + columna inicial)` sea múltiplo de 60 |
| `M` | Zigzag | 1 | 20 | Cada 5 cuadros avanza una columna. Después de 4 avances seguidos en la misma dirección, cambia de dirección y baja una fila. Si la columna siguiente queda fuera del campo, cambia de dirección sin avanzar ni bajar, y la cuenta de avances vuelve a 0. Empieza hacia la derecha. | No dispara |
| `N` | Nodriza | 3 | 100 | Cada 3 cuadros avanza una columna. En el borde rebota y avanza en la otra dirección. Nunca baja. Empieza hacia la derecha. | Cada 15 cuadros |
| | Tu enemigo | Tú decides | Tú decides | Tú decides | Tú decides |

La nodriza se dibuja `N` mientras tiene sus 3 vidas y `n` después del primer impacto. Los puntos de un enemigo se suman cuando pierde su última vida.

### Los búnkeres

Cada celda de búnker empieza con resistencia 3 y se dibuja según la que le queda: `#` con 3, `+` con 2 y `.` con 1. Con 0 desaparece. Un proyectil, de la nave o de un enemigo, que entra a una celda de búnker le quita 1 de resistencia y desaparece. Un enemigo que entra a una celda de búnker la deja en 0.

### Un cuadro, en orden

El juego avanza a 20 cuadros por segundo (una pausa de 50 ms después de cada cuadro). El primer cuadro de una partida es el 1. En cada cuadro, en este orden:

1. Se aplican todas las teclas que llegaron desde el cuadro anterior, en el orden en que llegaron. Un disparo usa el número del último cuadro completado.
2. Aumenta en 1 el número de cuadro.
3. Cada proyectil se mueve.
4. Cada enemigo se mueve y, si le toca, dispara. El proyectil nuevo nace en ese momento y no se mueve hasta el cuadro siguiente.
5. Colisiones, revisadas por celda ocupada:
   - un proyectil fuera del campo desaparece;
   - un proyectil sobre un búnker en pie lo gasta y desaparece;
   - un proyectil de la nave sobre un enemigo le quita una vida al enemigo y desaparece;
   - un proyectil enemigo sobre la nave le quita una vida a la nave y desaparece;
   - un enemigo sobre un búnker lo deja en 0;
   - un enemigo que llega a la fila 19 destruye la nave.
6. Se retira todo lo que quedó destruido.
7. Si la nave no tiene vidas, la partida termina y pierdes. Si no quedan enemigos, empieza la oleada siguiente; si era la última, la partida termina y ganas.
8. Se dibuja el cuadro.

Al empezar una oleada, los proyectiles que quedaban en el campo desaparecen, y la nave conserva su posición, sus vidas y su puntaje.

### Partidas y puntajes

Una partida nueva (con `r`) empieza en la oleada 1, con la nave en su posición inicial, 3 vidas y 0 puntos. El programa guarda el puntaje final de cada partida terminada mientras está abierto. Al salir con `q` imprime, ya con la terminal restaurada, algo como:

```
Cuadros: 1843
Promedio por cuadro: 151 us
Peor cuadro: 912 us
Cuadros sobre 16,7 ms: 0
Mejor puntaje: 460
```

Si no terminó ninguna partida, la última línea es `Mejor puntaje: ninguna partida terminada`. El tiempo de un cuadro va desde que empieza a aplicar teclas hasta que termina de imprimir, sin la pausa de 50 ms.

## Los niveles

Cada oleada se describe con un `std::vector<std::string>`: cada texto es una fila del campo, empezando por la fila 0.

| Carácter | Significado |
|---|---|
| espacio | Celda vacía |
| `#` | Celda de búnker |
| `W`, `M`, `N` | Un enemigo de ese tipo en esa celda |
| el que elijas | Tu enemigo |

Leer una descripción lanza `std::invalid_argument` en estos casos:

| Caso | Mensaje |
|---|---|
| Ninguna fila, o más de 18 | `cantidad de filas invalida` |
| Una fila que no mide exactamente 60 caracteres | `fila de largo distinto a 60` |
| Un carácter que no está en la tabla | `caracter desconocido en el nivel` |

El juego tiene al menos 3 oleadas, diseñadas por ti, y entre las tres usan todos los tipos de enemigo y búnkeres. Todas se validan al construir el juego, antes de la primera partida.

## Lo que te doy

`src/terminal.h`. No lo modifiques. Solo lo incluye `main.cpp`: la lógica del juego, la simulación y las pruebas no dependen de él.

| Función | Qué hace |
|---|---|
| `activarModoCrudo()` | Cada tecla llega apenas se presiona, sin eco ni Enter, y se oculta el cursor |
| `restaurarTerminal()` | Deja la terminal como estaba antes de `activarModoCrudo()` |
| `leerTecla(ms)` | Espera hasta `ms` milisegundos una tecla y la devuelve en un `std::optional<char>`, vacío si no llegó ninguna |
| `limpiarPantalla()` | Borra la pantalla |
| `irAlInicio()` | Lleva el cursor arriba a la izquierda sin borrar, para imprimir el cuadro encima del anterior |
| `esperarMilisegundos(ms)` | Detiene el hilo que la llama |
| `microsegundos()` | Microsegundos desde un instante fijo, para restar dos lecturas |

## Lo que construyes

### Estructura

```
psets/pset-04/
├── CMakeLists.txt
├── README.md        cómo compilar, cómo jugar y qué es tu extensión
├── DISENO.md
├── src/
│   ├── terminal.h   el que te doy
│   ├── main.cpp
│   ├── simulacion.cpp
│   └── tus cabeceras (.h)
└── tests/
    └── tus pruebas (.cpp)
```

Cómo repartes las clases entre cabeceras lo decides tú.

### Clases obligatorias

| Clase | Qué hace | Qué debe cumplir |
|---|---|---|
| `Vector2D` | Una posición o un desplazamiento | `operator+`, `operator==` y `operator<<` |
| `Grilla<T>` | Una grilla de ancho por alto celdas de tipo `T` | Un solo bloque reservado con `new[]` y liberado con `delete[]` en el destructor. Constructor y asignación de movimiento. `at(x, y)` lanza `std::out_of_range` fuera de la grilla, y el constructor lanza `std::invalid_argument` con dimensiones no positivas. La pantalla es una `Grilla<char>` y los búnkeres una `Grilla<int>` |
| `Dibujable` y `Colisionable` | Dos interfaces: dibujarse en la pantalla; tener una posición y recibir un impacto | Solo funciones virtuales puras y destructor virtual, sin atributos |
| `Entidad` | Base de todo lo que se mueve | Implementa las dos interfaces. Abstracta |
| `NaveJugador`, `Proyectil` | La nave y los proyectiles | Derivan de `Entidad`. La nave tiene un `Arma` por composición |
| `Arma` | La cadencia de disparo | El invariante de la cadencia (nunca menor que 1, `std::invalid_argument` sin cambiar la cadencia) |
| `Enemigo` | Base de los enemigos | Abstracta, deriva de `Entidad`. Cada enemigo decide cómo se mueve, si dispara y cuántos puntos vale, con funciones virtuales |
| `EnemigoRaso`, `EnemigoZigzag`, `Nodriza` | Los tres enemigos de la tabla | La nodriza redefine cómo se dibuja |
| `Nivel` | Lee la descripción de una oleada | Las excepciones de la tabla de niveles. Se mueve, no se copia |
| `Marcador` | El puntaje de la partida y el de cada partida terminada | Sumar puntos negativos lanza `std::invalid_argument` sin cambiar el puntaje. El mejor puntaje es un `std::optional<int>`, vacío sin partidas terminadas |
| `ColaDeComandos` | Las teclas que deja el hilo del teclado y saca el hilo del juego | Un `std::mutex` y `std::lock_guard` en cada operación. Sacar una tecla devuelve un `std::optional<char>` |
| `Juego` | La partida completa | Es dueño de los enemigos y los proyectiles con `std::unique_ptr`. No incluye `terminal.h`. Traduce teclas en comandos con un `std::map` |
| `ModoTerminal` | El modo crudo de la terminal | El constructor lo activa y el destructor lo restaura, también si una excepción atraviesa el bloque donde vive |

Puedes agregar las clases que necesites. Los nombres de esta tabla son obligatorios.

### Más requisitos

- Ningún `new` ni `delete` fuera de `Grilla<T>`. Todo lo demás se crea con `std::make_unique`, o vive como atributo o variable local.
- El ciclo del juego recorre enemigos y proyectiles a través de sus bases (`Enemigo`, `Entidad`, `Dibujable`), sin preguntar de qué tipo es cada uno.
- El estado de la partida y lo que se le muestra al jugador se calculan con algoritmos de `<algorithm>` y `<numeric>` donde corresponda, no con ciclos escritos a mano: el mejor puntaje, los tiempos por cuadro y al menos una búsqueda en `Juego`.
- Quitar del contenedor lo que se destruyó sin usar un iterador invalidado.
- Cada búsqueda que puede no encontrar nada devuelve un `std::optional`, nunca -1 ni un puntero nulo.
- `main.cpp` tiene dos hilos: el del teclado deja las teclas en la `ColaDeComandos`, y el principal corre el juego. Un `std::atomic<bool>` le avisa al hilo del teclado que debe terminar, y el principal le hace `join()` antes de salir, también si el ciclo del juego lanzó una excepción.
- Compila sin errores ni advertencias con `-Wall -Wextra`.

Puedes usar construcciones del lenguaje que no vimos en el curso, siempre que puedas explicarlas en la defensa.

### Tu extensión

Agrega un enemigo nuevo, inventado por ti, con su propio carácter en los niveles y su propio movimiento, disparo o puntaje. Para agregarlo, `Juego` no cambia: solo cambian tu clase nueva y el lugar donde un carácter del nivel se convierte en un enemigo. Usa tu enemigo en al menos una oleada y descríbelo en tu `README.md`.

## Los tres ejecutables

| Ejecutable | Qué es |
|---|---|
| `invasores` | El juego |
| `simulacion` | La misma lógica sin terminal, para correrla con sanitizers |
| `pruebas` | Tus pruebas de GoogleTest |

### La simulación

`simulacion.cpp` no incluye `terminal.h`. Construye un `Juego` con tus oleadas y arranca un hilo que deja en una `ColaDeComandos` un guion fijo de al menos 2000 teclas, que incluya movimientos, disparos y `r`. Mientras ese hilo trabaja, el hilo principal juega 3000 cuadros seguidos, sin pausa: en cada uno saca todas las teclas que haya en la cola, las aplica y avanza un cuadro. Después hace `join()` al hilo del guion y aplica las teclas que quedaron. Al final imprime:

```
Teclas enviadas: 5400
Teclas procesadas: 5400
Partidas terminadas: 1
Oleada actual: 1
Cuadra
```

`Cuadra` si las dos cantidades son iguales, con código de salida 0; `No cuadra` si no, con código de salida 1. Cuenta las teclas enviadas con un `std::atomic<int>`. Las otras dos cantidades dependen de tus oleadas y de tu guion.

### Las pruebas

Al menos 15 pruebas, que cubran como mínimo:

- los tres operadores de `Vector2D`;
- `Grilla<T>`: leer y escribir, fuera de rango, dimensiones inválidas, y que el objeto de origen quede vacío después de moverlo;
- la cadencia del `Arma`;
- el movimiento de cada enemigo, incluido el del borde del campo;
- las tres excepciones de `Nivel`;
- en `Juego`: un proyectil que destruye a un enemigo y suma sus puntos, un proyectil enemigo que le quita una vida a la nave, el paso a la oleada siguiente y el fin de la partida cuando un enemigo llega a la fila 19;
- `ColaDeComandos` con dos hilos que agregan a la vez, sin perder teclas.

### CMake

Tu `CMakeLists.txt` define los tres ejecutables, las opciones `CON_SANITIZERS` (AddressSanitizer y UBSan) y `CON_TSAN` (ThreadSanitizer), apagadas por defecto, y registra las pruebas con `gtest_discover_tests`. Estos comandos tienen que funcionar en el devcontainer del curso:

```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/invasores
./build/simulacion
ctest --test-dir build --output-on-failure

cmake -S . -B build-asan -DCMAKE_BUILD_TYPE=Debug -DCON_SANITIZERS=ON
cmake --build build-asan
./build-asan/simulacion
ctest --test-dir build-asan

cmake -S . -B build-tsan -DCMAKE_BUILD_TYPE=Debug -DCON_TSAN=ON
cmake --build build-tsan
./build-tsan/simulacion
ctest --test-dir build-tsan
```

Las carpetas `build*` no se suben al repositorio.

## `DISENO.md`

Una página como máximo, con tres decisiones de tu diseño. Para cada una: qué elegiste, qué alternativa descartaste y por qué.

1. En qué contenedores guardas enemigos y proyectiles, y cómo retiras los destruidos.
2. Qué protege el candado de la `ColaDeComandos` y qué pasaría sin él.
3. Por qué cada dueño de memoria es un `std::unique_ptr`, o, si usaste `std::shared_ptr` en algún lugar, por qué ahí hace falta propiedad compartida.

## El hito

Antes de la Semana 15, Sesión 2, abre un Pull Request con:

- `Vector2D`, `Grilla<T>`, las dos interfaces, `Entidad`, `Enemigo` y al menos dos enemigos;
- `Nivel` con sus tres excepciones;
- un `CMakeLists.txt` que compile el objetivo `pruebas`;
- al menos 8 pruebas en verde con `ctest`.

En esa sesión revisas el hito de un compañero y un compañero revisa el tuyo, con los criterios de la clase. Los comentarios que recibas son para mejorar tu entrega final.

## La entrega final

Todo en tu fork del repositorio del curso, carpeta `psets/pset-04/`, con la estructura de arriba. Pull Request antes de la Semana 16, Sesión 1.

## La defensa

Es individual y dura 15 minutos, en tu computador, con el devcontainer listo y tu proyecto ya compilado. Puedes consultar tu código; no puedes usar internet ni asistentes de IA.

| Parte | Minutos | Qué pasa |
|---|---|---|
| Demostración | 3 | Juegas una partida, corres `ctest` y corres `simulacion` compilada con `CON_TSAN` |
| Preguntas | 7 | Elijo partes de tu código y te pregunto qué hacen, por qué están así y qué pasaría si cambiaran |
| Cambio en vivo | 5 | Te pido un cambio pequeño en el juego. Lo escribes, compila y las pruebas siguen en verde |

## Qué reviso

La nota es sobre 100: 50 puntos de código y 50 de defensa. En cada criterio, el nivel que cumples da ese porcentaje de sus puntos.

| Nivel | Porcentaje |
|---|---|
| Completo | 100% |
| Con detalles | 70% |
| Incompleto | 40% |
| No cumple | 0% |

**Lo que no puedes explicar no cuenta.** Si en la defensa no puedes explicar una parte de tu código, el criterio de código al que pertenece esa parte baja a No cumple.

### Código: 50 puntos

| Criterio | Puntos | Completo | Con detalles | Incompleto | No cumple |
|---|---|---|---|---|---|
| Hito | 5 | Llegó a tiempo con todo lo pedido y las 8 pruebas en verde | Llegó a tiempo, le falta una pieza o alguna prueba falla | Llegó tarde o le faltan varias piezas | No llegó |
| El juego funciona | 10 | Cumple todas las reglas de la sección *El juego*; compila sin advertencias con `-Wall -Wextra` | Una o dos reglas no se cumplen, o hay advertencias | Se puede jugar, pero varias reglas no se cumplen | No compila o no se puede jugar |
| Orientación a objetos y polimorfismo | 8 | Todas las clases obligatorias con sus invariantes; las interfaces y las bases abstractas no se pueden instanciar; `virtual` en la base, `override` en cada derivada, destructores virtuales; la nave compone su arma; la extensión no toca `Juego` | Falta un `override` o un destructor virtual, o un invariante sin validar | El ciclo del juego pregunta el tipo de cada entidad, o la extensión obliga a cambiar `Juego` | Sin jerarquía ni polimorfismo |
| Memoria y propiedad | 7 | `Grilla<T>` con RAII y movimiento; ningún `new` ni `delete` fuera de ella; dueños con `unique_ptr`; `ModoTerminal` restaura la terminal; cero reportes de AddressSanitizer en `simulacion` y en `pruebas` | Un detalle: el origen de un movimiento no queda vacío, o un `new` suelto que no fuga | Un reporte de AddressSanitizer, o propiedad confusa entre clases | Fugas o accesos inválidos en varios lugares |
| Plantillas, contenedores y algoritmos | 6 | Una sola `Grilla<T>` para `char` y para `int`; cada contenedor elegido por su uso; algoritmos donde los pide el enunciado; los destruidos se retiran sin iteradores invalidados | Un ciclo escrito a mano donde iba un algoritmo, o un contenedor sin justificar | Dos versiones de `Grilla` en vez de una plantilla, o varios ciclos a mano | Sin plantilla ni algoritmos |
| Errores: excepciones y `optional` | 4 | Las excepciones del enunciado con su tipo y su mensaje; una operación rechazada no cambia el objeto; los `catch` por referencia constante; cada búsqueda sin resultado devuelve un `optional` vacío | Un mensaje distinto, o un `optional` leído sin revisar que tenga valor | Valores centinela como -1, o excepciones atrapadas y descartadas en silencio | Sin manejo de errores |
| Concurrencia | 5 | Dos hilos en el juego; la cola protegida en cada operación; `atomic<bool>` para terminar y `join()` en todos los caminos; `simulacion` cuadra; cero reportes de ThreadSanitizer | Cuadra y TSan sale limpio, pero el `join()` falta en el camino de una excepción | Un reporte de ThreadSanitizer, o una tecla perdida a veces | Sin hilos, o el programa se cuelga al salir |
| Pruebas y CMake | 5 | Al menos 15 pruebas que cubren la lista de *Las pruebas*, todas en verde; los tres ejecutables y las dos opciones de sanitizers funcionan con los comandos del enunciado | Falta cubrir un punto de la lista, o una opción de CMake no funciona | Menos de 15 pruebas, o pruebas que no fallarían aunque el código estuviera mal | Sin pruebas o sin `CMakeLists.txt` |

### Defensa: 50 puntos

| Criterio | Puntos | Completo | Con detalles | Incompleto | No cumple |
|---|---|---|---|---|---|
| Demostración | 5 | Juego, `ctest` y `simulacion` con `CON_TSAN` corren sin tropiezos en los 3 minutos | Algo falla y lo resuelves en el momento | Solo funciona una parte | Nada corre |
| Explicación de tu código | 15 | Explicas cualquier parte que elijo: qué hace, por qué está ahí y qué la llama | Explicas casi todo, con una parte que no recuerdas bien | Explicas lo general pero no las líneas que te señalo | No puedes explicar tu código |
| Justificación de tus decisiones | 10 | Defiendes las tres decisiones de `DISENO.md` y otras que te pregunte, comparando con una alternativa | Justificas la decisión, pero sin alternativa | Describes lo que hiciste, sin por qué | Sin justificación |
| Los conceptos del curso en tu código | 10 | Respondes con precisión qué pasaría si cambiara algo de tu código: sin el candado, si `Grilla` se copiara, si falta un destructor virtual, si una excepción atraviesa el ciclo del juego | Una respuesta imprecisa | Varias respuestas imprecisas | No relacionas los conceptos con tu código |
| Cambio en vivo | 10 | El cambio funciona, compila sin advertencias y las pruebas siguen en verde dentro de los 5 minutos | Funciona con un detalle pendiente, o con una advertencia | Empezaste en el lugar correcto pero no compila | No sabes dónde hacer el cambio |

## Una recomendación

Empieza por lo que no depende de la terminal: `Vector2D`, `Grilla<T>`, las entidades y `Nivel`, con sus pruebas. Es justo lo que pide el hito. `Juego` se puede probar entero sin dibujar nada, cuadro por cuadro, con niveles de una o dos filas armados en la misma prueba. Deja `main.cpp` y el hilo del teclado para el final: si la lógica ya pasa sus pruebas y la simulación cuadra con ThreadSanitizer, conectar la terminal toma una tarde.
