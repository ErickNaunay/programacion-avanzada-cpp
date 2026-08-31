# Semana 3, Sesión 2: Herencia I, jerarquías y reutilización

## Objetivo de la sesión

Refactorizar código duplicado entre clases relacionadas usando herencia, e identificar cuándo una jerarquía reduce la duplicación sin introducir acoplamiento excesivo.

## Antes de empezar

**Lectura previa:** ["Foundations of Inheritance in C++", Abdilah CH](https://devabdilah.medium.com/foundations-of-inheritance-in-c-06ddfd062ca1)

**Referencia:** ["Derived classes", cppreference](https://en.cppreference.com/w/cpp/language/derived_class.html)

## Ejercicios

Los tres ejercicios usan el mismo patrón: una clase base agrupa los atributos, setters, getters y métodos que dos o más clases relacionadas comparten; cada clase derivada hereda de la base (`class Derivada : public Base`) y solo agrega lo que es propio de ella.

1. **`ejercicio1_animal_perro_gato.cpp`**: `Animal`, con `Perro` y `Gato` heredando de ella. Lo resolvemos juntos en clase.
2. **`ejercicio2_vehiculo_carro_moto.cpp`**: `Vehiculo`, con `Carro` y `Moto`. Lo resolvemos juntos en clase.
3. **`ejercicio3_empleado_gerente_vendedor.cpp`**: `Empleado`, con `Gerente` y `Vendedor`. Lo resuelves tú solo o en pareja.

Cada archivo tiene, en su encabezado, la salida exacta que debe producir cuando esté completo.

## Compilar y ejecutar

```
g++ -std=c++20 -Wall -Wextra -g ejercicio1_animal_perro_gato.cpp -o bin/ejercicio1
./bin/ejercicio1
```

Repite el mismo patrón con `ejercicio2_vehiculo_carro_moto.cpp` y `ejercicio3_empleado_gerente_vendedor.cpp`.

## Qué construcciones nuevas usa este laboratorio

Herencia pública (`class Derivada : public Base`). Un método público de la clase base queda disponible en cualquier objeto de la clase derivada sin volver a escribirlo; un atributo privado de la base sigue sin ser accesible directamente desde la derivada, igual que no lo es desde fuera de la base. Nada de listas de inicialización de miembros, `virtual`, ni punteros: eso llega en sesiones posteriores.
