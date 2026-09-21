# PSet 2: Herencia, Sobrecarga de Operadores y Memoria Dinamica

## Contexto

Este PSet cubre todo lo que practicamos entre la Semana 3 y la Semana 6: herencia simple, multinivel y multiple (incluido el problema del diamante), composicion y delegacion, sobrecarga de operadores, punteros y referencias, memoria dinamica con `new`/`delete`, RAII, fugas de memoria, punteros colgantes, y smart pointers (`unique_ptr`, `shared_ptr`, `weak_ptr`). Son 25 ejercicios progresivos, mas retadores que los del PSet 1, pensados para que salgas de este PSet dominando estos conceptos, no solo reconociendolos.

## Ejercicios 1 a 15: con estructura de partida

Cada archivo trae la clase (o las clases) ya declaradas, con la logica de cada metodo marcada con `TODO`, y un `main()` completo que no debes modificar. Completa solo lo marcado.

1. **Vehiculo y Auto.** Herencia simple: una clase derivada usando un setter heredado de su base.
2. **SerVivo, Animal y Perro.** Herencia de tres niveles: una clase que hereda de otra que a su vez hereda de una tercera.
3. **Volador, Nadador y VehiculoAnfibio.** Herencia multiple con dos bases independientes, sin relacion entre ellas.
4. **Maquina, MaquinaElectrica, MaquinaTermica e Hibrida.** Herencia multiple con el problema del diamante, ya resuelto con herencia virtual: fijate como la sintaxis evita que Hibrida termine con dos copias de Maquina.
5. **Motor y Carro.** Composicion: un objeto que contiene a otro y delega en el.
6. **Lapiz y Estuche.** Composicion con dos objetos del mismo tipo dentro de un tercero.
7. **Vector2D.** Sobrecarga de `operator+` como metodo miembro.
8. **Fraccion.** Constructor con valor por defecto ante un dato invalido, combinado con `operator<<` como funcion libre.
9. **Dinero.** `operator+` y `operator<<` trabajando juntos en la misma clase.
10. **Figura y Circulo.** Herencia combinada con `operator<<`, usando un atributo heredado dentro de la funcion de impresion.
11. **Punteros basicos.** Sin clases: declarar un puntero, desreferenciarlo, usarlo para modificar una variable.
12. **new[] y delete[] basico.** Sin clases: el ciclo completo de reservar, usar y liberar un arreglo dinamico.
13. **AlmacenNotas.** El patron RAII: el constructor reserva memoria dinamica, el destructor la libera.
14. **Buffer.** Este no te pide escribir logica nueva: te da una clase con una fuga de memoria real (el destructor no libera lo que el constructor reserva) y te pide encontrarla y corregirla.
15. **RegistroTemperaturas.** Integrador de la seccion: RAII completo, mas un metodo que devuelve un puntero a una posicion dentro del arreglo propio del objeto, nunca la direccion de una variable local (eso seria un puntero colgante).

## Ejercicios 16 a 25: desde cero

Estos diez no traen ninguna estructura. Cada archivo tiene unicamente el enunciado, en comentarios: que clases disenar, que hace cada metodo, sus reglas de validacion, y una descripcion paso a paso de que debe hacer tu `main()`. Escribes el archivo completo, incluidos los `#include`, las clases y el `main()`.

16. **Empleado y Gerente.** Herencia simple, la misma logica del ejercicio 1, ahora sin ningun codigo dado.
17. **Dispositivo, DispositivoConectado y SensorTemperatura.** Herencia de tres niveles.
18. **Componente, ComponenteMecanico, ComponenteDigital y Robot.** Herencia multiple con el problema del diamante: aqui tienes que reconocer tu mismo donde hace falta la herencia virtual y escribirla.
19. **Bateria y Dron.** Composicion con delegacion.
20. **Temperatura.** `operator+` y `operator<<` combinados, desde cero.
21. **Cola.** RAII con `new[]`/`delete[]`, desde cero.
22. **Historial.** El mismo riesgo de fuga de memoria del ejercicio 14, pero ahora eres tu quien tiene que evitarla al disenar la clase, no corregirla despues.
23. **Llave y Cerradura.** `std::unique_ptr` y `std::move`: una cerradura que toma posesion exclusiva de una llave.
24. **Documento, Propietario y Observador.** `std::shared_ptr` y `std::weak_ptr`: varios duenos compartiendo un recurso, y un observador que lo mira sin ser dueno de el.
25. **Motor, TituloPropiedad, Vehiculo y Concesionario.** El integrador final del PSet: composicion, `operator<<`, `unique_ptr` y `shared_ptr` en un mismo sistema, incluida la transferencia de un recurso exclusivo de un objeto a otro.

## Compilar y ejecutar

Cada ejercicio es un archivo independiente. Compila y ejecuta uno a la vez:

```
g++ -std=c++20 -Wall -Wextra -g -o ejercicioN ejercicioN_nombre.cpp
./ejercicioN
```

En los ejercicios 1 a 15, mientras no hayas completado los `TODO`, vas a ver advertencias de parametro sin usar (`-Wunused-parameter`). Son esperadas: van a desaparecer a medida que completes cada metodo. En los ejercicios 16 a 25, el archivo no compila hasta que escribas tu propio codigo (vas a ver un error de `undefined reference to 'main'` si intentas compilarlo tal como esta).

## Formato y donde entregar

Todo en tu fork del repositorio del curso, carpeta `psets/pset-02/`, un archivo `.cpp` por ejercicio con el mismo nombre que recibiste. Pull Request al repositorio del curso antes de la fecha de entrega.

## Fecha de entrega

Semana 8, Sesion 1.

## Que reviso

- Que cada ejercicio compile sin errores y que su salida coincida exactamente con la documentada en el comentario del archivo.
- En los ejercicios de herencia multiple con diamante (4 y 18), que la clase final tenga una sola copia del ancestro comun, no dos copias ambiguas.
- En los ejercicios de memoria dinamica (13 a 15, 21 a 22), que todo lo reservado con `new`/`new[]` se libere con `delete`/`delete[]` en el destructor correspondiente, sin fugas.
- En el ejercicio 15, que el puntero que devuelve `buscarValor` nunca apunte a una variable local: tiene que apuntar siempre a memoria que el objeto sigue administrando.
- En los ejercicios de smart pointers (23 a 25), que uses `std::move` para transferir la posesion de un `unique_ptr` (nunca copiarlo, porque no se puede) y que entiendas la diferencia entre un `shared_ptr` (que mantiene vivo el recurso mientras exista al menos uno) y un `weak_ptr` (que observa sin mantenerlo vivo).
- En los ejercicios 16 a 25, que el diseno sea tuyo: la logica debe ser equivalente a la que aprendiste en los ejercicios con estructura, pero escrita por ti desde el primer `#include`.

## Una recomendacion

Los ejercicios 1 a 15 estan ahi para que veas el patron correcto antes de tener que producirlo tu solo. Si un ejercicio desde cero se te resiste, vuelve al ejercicio con estructura del mismo tema (por ejemplo, si te trabas en el 21, revisa el 13) y fijate en como esta resuelto, no en la respuesta final sino en el patron: donde valida, donde asigna, donde libera. El ejercicio 25 es el mas dificil del PSet a proposito: si llegas ahi habiendo resuelto los otros 24, ya tienes todas las piezas que necesitas, solo falta que las combines en un solo sistema.
