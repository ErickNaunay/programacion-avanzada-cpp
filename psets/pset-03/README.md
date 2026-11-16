# PSet 3: Polimorfismo, Plantillas, STL y Manejo de Errores

## Contexto

Este PSet cubre lo que practicamos entre la Semana 8, Sesion 2 y la Semana 11, Sesion 2: funciones virtuales y despacho dinamico, `override`, destructor virtual, clases abstractas e interfaces, plantillas de funcion y de clase, contenedores de la STL (`vector`, `list`, `set`, `map`) con sus iteradores, algoritmos de `<algorithm>` y `<numeric>` con lambdas, excepciones (`throw`, `try`, `catch`, `at()`) y `std::optional`. Son 30 ejercicios: los 15 primeros traen la estructura de partida y los 15 siguientes se escriben desde cero, cada uno sobre el mismo tema que su par con estructura (el 16 practica lo del 1, el 17 lo del 2, y asi).

## Ejercicios 1 a 15: con estructura de partida

Cada archivo trae las clases (o las funciones) ya declaradas, con la logica marcada con `TODO`, y un `main()` completo que no debes modificar. Completa solo lo marcado.

1. **Instrumento, Guitarra y Bateria.** `virtual` y `override`: la misma llamada a traves de un puntero a la base, con un metodo virtual y otro que no lo es.
2. **Empleado, Docente y Administrativo.** Un arreglo de punteros a la base: cada elemento calcula su pago a su manera.
3. **Conexion y ConexionSegura.** Destructor virtual: un `unique_ptr<Conexion>` que apunta a una derivada con memoria dinamica propia.
4. **Figura, Rectangulo y Triangulo.** Clase abstracta: `area()` como funcion virtual pura, y funciones que trabajan con cualquier `Figura*`.
5. **Cargable, Localizable y Scooter.** Una clase que implementa dos interfaces, usada a traves de cada una por separado.
6. **Plantillas de funcion.** `mayorDeTres<T>` y `contarEnRango<T>` con `int`, `double` y `char`, y un argumento de plantilla explicito.
7. **Intervalo<T>.** Una plantilla de clase con `int` y con `double`.
8. **RegistroDeNotas.** `std::vector` con `push_back`, `back()` y el `for` de rango.
9. **ContadorDeVisitas.** `std::map`: contar sin crear claves por accidente, y recorrer con un iterador.
10. **TurnosDeLaboratorio.** `std::list` como cola con urgentes por delante, `std::set` para responder rapido, y `erase` con un iterador.
11. **Tiempos de respuesta.** `find`, `count`, `max_element`, `count_if` con una funcion por su nombre, `accumulate` y `sort`.
12. **Precios de la cafeteria.** Los mismos algoritmos con lambdas, con y sin captura.
13. **TarjetaDeTransporte.** Lanzar `std::invalid_argument` y `std::runtime_error`, y una operacion rechazada que no cambia el saldo.
14. **Teatro.** `at()` en un `vector` y en un `map`, propagacion de una excepcion hacia quien llamo, y varios `catch` en orden.
15. **Biblioteca.** `std::optional` en lugar de un valor centinela: `std::nullopt`, `has_value()`, `*` y `value_or`.

## Ejercicios 16 a 30: desde cero

Estos quince no traen ninguna estructura. Cada archivo tiene unicamente el enunciado, en comentarios: que clases o funciones disenar, que hace cada metodo, sus reglas, y que debe hacer tu `main()`. Escribes el archivo completo, incluidos los `#include`.

16. **Alarma, AlarmaDeIncendio y AlarmaDeIntrusion.** Funciones virtuales y un metodo que no lo es, como en el 1.
17. **Vehiculo, Camion y Bus en el peaje.** Un arreglo de punteros a la base, como en el 2.
18. **Sensor y SensorDeHumedad.** Destructor virtual con `new[]` y `delete[]` en la derivada, como en el 3.
19. **Envio, EnvioNacional y EnvioInternacional.** Clase abstracta, como en el 4.
20. **Encendible, Regulable y LamparaInteligente.** Dos interfaces que disenas tu, como en el 5.
21. **Plantillas de funcion.** `menorDeTres<T>`, `sumarArreglo<T>` e `intercambiar<T>` con punteros, como en el 6.
22. **Acumulador<T>.** Una plantilla de clase, como en el 7.
23. **HistorialDePasos.** `std::vector`, incluida la racha mas larga de dias que cumplen una meta, como en el 8.
24. **Inventario.** `std::map`, como en el 9.
25. **ListaDeReproduccion.** `std::list` y `std::set`, y borrar varios elementos de una lista sin usar un iterador invalidado, como en el 10.
26. **Puntajes del concurso.** Algoritmos y lambdas sin ciclos escritos a mano, como en el 11 y el 12.
27. **Ascensor.** Lanzar y atrapar excepciones, como en el 13.
28. **Gimnasio.** `at()`, propagacion y orden de los `catch`, incluido uno final de `std::exception`, como en el 14.
29. **AgendaDelConsultorio.** `std::optional`, incluido `value()` y la excepcion que lanza sobre un vacio, como en el 15.
30. **La Tienda del campus.** El integrador del PSet: una clase abstracta con tres derivadas guardadas en un `vector` de `unique_ptr`, una plantilla, algoritmos con lambdas, excepciones y `std::optional` en el mismo sistema.

## Compilar y ejecutar

Cada ejercicio es un archivo independiente. Compila y ejecuta uno a la vez:

```
g++ -std=c++20 -Wall -Wextra -g -o ejercicioN ejercicioN_nombre.cpp
./ejercicioN
```

En los ejercicios 1 a 15, mientras no hayas completado los `TODO`, vas a ver advertencias de parametro sin usar (`-Wunused-parameter`). Son esperadas: desaparecen a medida que completas cada metodo. En los ejercicios 16 a 30, el archivo no compila hasta que escribas tu propio codigo (vas a ver `undefined reference to 'main'` si lo compilas tal como esta).

## Formato y donde entregar

Todo en tu fork del repositorio del curso, carpeta `psets/pset-03/`, un archivo `.cpp` por ejercicio con el mismo nombre que recibiste. Pull Request al repositorio del curso antes de la fecha de entrega.

## Fecha de entrega

Semana 11, Sesion 1.

## Que reviso

- Que cada ejercicio compile sin errores ni advertencias con `-Wall -Wextra`, y que su salida coincida exactamente con la documentada en el comentario del archivo.
- En los ejercicios de polimorfismo (1 a 5 y 16 a 20), que cada metodo que se llama a traves de un puntero a la base sea `virtual` en la base y lleve `override` en la derivada; que toda clase base usada a traves de punteros tenga destructor virtual; y que `Figura`, `Envio` y las interfaces no se puedan instanciar.
- En los ejercicios de plantillas (6, 7, 21 y 22), una sola plantilla por funcion o clase, no una version por tipo.
- En los ejercicios de contenedores (8 a 10 y 23 a 25), que consultar un `map` o un `set` no cree claves que no existian, y que ningun iterador se use despues de un `erase` que lo invalido.
- En los ejercicios de algoritmos (11, 12 y 26), que uses el algoritmo indicado y no un ciclo escrito a mano, y que compares con `end()` antes de desreferenciar el resultado de una busqueda.
- En los ejercicios de excepciones (13, 14, 27 y 28), que cada metodo lance el tipo de excepcion indicado con el mensaje exacto, que una operacion rechazada no deje el objeto cambiado, y que los `catch` atrapen por referencia constante y vayan del mas especifico al mas general.
- En los ejercicios de `std::optional` (15, 29 y 30), que ningun metodo devuelva -1 ni 0 para decir "no hay", y que no se desreferencie un `optional` sin saber que tiene valor.
- En los ejercicios 16 a 30, que el diseno sea tuyo, escrito desde el primer `#include`.

## Una recomendacion

Los ejercicios 1 a 15 estan para que veas el patron antes de producirlo solo. Si un ejercicio desde cero se te resiste, vuelve a su par con estructura (el 25 con el 10, el 28 con el 14) y fijate en el patron, no en la respuesta: donde se valida, donde se lanza, donde se compara con `end()`. El ejercicio 30 es el mas largo a proposito: si llegas ahi con los otros 29 resueltos, ya tienes todas las piezas, y solo falta combinarlas.
