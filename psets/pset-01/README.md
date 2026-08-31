# PSet 1: Fundamentos de POO

## Contexto

En las últimas dos sesiones pasamos de `struct` a `class`, agregamos encapsulación con `public`/`private`, getters, setters que validan un invariante, y por último constructores y destructores. Este PSet es tu turno de resolver, solo, 15 ejercicios progresivos que practican exactamente esos conceptos.

No necesitas nada de sesiones posteriores a esta: todo lo que resuelves aquí sale de lo que ya viste hasta Semana 2, Sesión 2.

## Ejercicios 1 a 10: con estructura de partida

Cada archivo trae la clase o struct ya declarado, con los atributos y las firmas de los métodos dados, `TODO` marcados en los cuerpos que te toca completar, y el `main()` ya escrito. Resuélvelos en orden: cada uno construye sobre el anterior.

1. **`ejercicio1_circulo.cpp`**: `struct` con un método que calcula un valor a partir de un atributo.
2. **`ejercicio2_contador_regresivo.cpp`**: un método que reasigna un atributo del propio `struct`, con una condición.
3. **`ejercicio3_punto_cartesiano.cpp`**: un método que recibe otro `struct` del mismo tipo como parámetro por valor.
4. **`ejercicio4_termostato.cpp`**: primer paso a `class`, atributo privado con un getter.
5. **`ejercicio5_bateria.cpp`**: setter que devuelve `bool` y valida un invariante de un solo atributo.
6. **`ejercicio6_horario_atencion.cpp`**: setter que valida un invariante conjunto entre dos atributos.
7. **`ejercicio7_cronometro.cpp`**: constructor simple, que asigna un valor recibido directamente.
8. **`ejercicio8_extintor.cpp`**: constructor con valor por defecto ante un dato inválido.
9. **`ejercicio9_vela_encendida.cpp`**: constructor y destructor en la misma clase.
10. **`ejercicio10_reserva_sala.cpp`**: integrador. Combina el invariante conjunto, el constructor con valor por defecto y el destructor, y verifica el orden de destrucción LIFO con tres objetos.

## Ejercicios 11 a 15: desde cero

Estos 5 no traen código de partida: cada archivo tiene solo el enunciado en comentarios (qué clase diseñar, qué debe hacer cada método, qué debe hacer tu `main()`, y la salida exacta esperada). El archivo, el `#include`, la clase completa y el `main()` los escribes tú desde la primera línea. Mismos conceptos que los ejercicios 1 a 10, pero ahora sin ningún andamiaje.

11. **`ejercicio11_escalera.cpp`**: `struct` con un método que calcula un valor a partir de un atributo.
12. **`ejercicio12_casillero.cpp`**: `class` con encapsulación y un setter que valida un invariante de un solo atributo.
13. **`ejercicio13_ascensor.cpp`**: setter que valida un invariante conjunto entre dos atributos.
14. **`ejercicio14_bombilla.cpp`**: constructor con valor por defecto ante un dato inválido.
15. **`ejercicio15_sesion_estudio.cpp`**: integrador. Invariante conjunto, constructor con valor por defecto y destructor, verificando el orden de destrucción LIFO con tres objetos, igual que el Ejercicio 10 pero construido por completo desde cero.

## Compilar y ejecutar

```
g++ -std=c++20 -Wall -Wextra -g ejercicio1_circulo.cpp -o bin/ejercicio1
./bin/ejercicio1
```

Repite el mismo patrón con cada ejercicio, cambiando el nombre del archivo y del binario.

## Formato y dónde entregar

Sube tus 15 archivos `.cpp` completos a tu fork del repositorio, en esta misma carpeta (`psets/pset-01/`). Pull Request al repositorio del curso antes de la fecha de entrega.

## Fecha de entrega

Semana 4, Sesión 2.

## Qué reviso

- Que cada programa compile sin advertencias (`-Wall -Wextra`) y produzca exactamente la salida esperada del encabezado.
- Que los atributos que deben ser privados lo sean, y que cada método use el mecanismo correcto para el concepto de esa sesión (getter, setter con `bool`, constructor, destructor, según el ejercicio).
- Que el invariante conjunto de los ejercicios 6, 10, 13 y 15 se valide junto, en un solo método, no atributo por atributo por separado.
- En los ejercicios 11 a 15, que el diseño sea tuyo: nombres de clase, atributos y métodos coherentes con el enunciado, sin depender de ningún código dado.
- Que no uses `const`, paso por referencia (`&`), listas de inicialización de miembros, punteros o `std::string`: no está mal si los usas bien, pero ninguno es necesario aquí, y si tu solución los necesita para funcionar es señal de que algo se resolvió con una construcción que no hemos visto todavía.

## Una recomendación

Los ejercicios 10 y 15 no te piden nada nuevo: cada uno junta un invariante conjunto, un constructor con valor por defecto y un destructor en una sola clase. Si alguno de los dos te cuesta, vuelve primero a los ejercicios más simples que practican esa misma pieza por separado.
