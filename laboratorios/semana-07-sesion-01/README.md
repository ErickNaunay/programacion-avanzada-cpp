# Semana 7, Sesion 1: Laboratorio Integrador I

## Objetivo de la sesion

Integrar POO, herencia, composicion, RAII, move semantics y smart pointers en la solucion de un solo problema, sin exposicion nueva de conceptos.

## Antes de empezar

Sin lectura nueva. Repasa las lecturas y referencias de las Semanas 5 y 6 si algo no esta fresco:

- ["Mastering RAII: How C++ Solves Memory Management Nightmares", Basant C.](https://medium.com/@caring_smitten_gerbil_914/mastering-raii-how-c-solves-memory-management-nightmares-with-real-world-examples-1cf50d5ccef9) y ["RAII", cppreference](https://en.cppreference.com/w/cpp/language/raii.html)
- ["Move Semantics & Rvalue References Deep Dive", Amit Kashyap](https://medium.com/@hunkcool1991/move-semantics-rvalue-references-deep-dive-the-most-misunderstood-feature-in-modern-c-6b8b12da143c) y ["std::move", cppreference](https://en.cppreference.com/w/cpp/utility/move.html)
- ["Understanding C++ Smart Pointers: Unique, Shared, and Weak", Madhawa Polkotuwa](https://madhawapolkotuwa.medium.com/understanding-c-smart-pointers-unique-shared-and-weak-404800726aed) y ["std::unique_ptr", cppreference](https://en.cppreference.com/w/cpp/memory/unique_ptr.html)

## El problema: un sistema de estaciones de carga para una flota de drones

Una flota de drones se reparte entre estaciones de carga, coordinadas por una torre de control compartida. Cada dron es una aeronave con bateria y con su propio historial de vuelo. Cada estacion tiene, como maximo, un dron asignado a la vez, y puede transferirlo a otra estacion sin duplicarlo ni perder su historial.

No hay ejercicios 1 y 2 resueltos antes del tuyo: el archivo completo es tu unico ejercicio de hoy, con tres clases ya dadas (reusan patrones que ya conoces) y tres por completar (donde se combinan los cinco pilares de la sesion).

## De donde viene cada pieza

| Pilar | De que semana | Donde aparece hoy |
|---|---|---|
| POO (encapsulacion, invariantes) | Semanas 1-2 | `Bateria`, `Aeronave`, `TorreControl`, `Estacion` |
| Herencia publica | Semanas 3-4 | `Dron : public Aeronave` |
| Composicion y delegacion | Semana 4 | `Dron` compone `Bateria` y `RegistroVuelo` |
| RAII | Semana 5 | `RegistroVuelo` (constructor reserva con `new[]`, destructor libera con `delete[]`) |
| Move semantics | Semana 6, Sesion 1 | Constructor y operador de asignacion de movimiento de `RegistroVuelo` |
| Smart pointers | Semana 6, Sesion 2 | `unique_ptr<Dron>` y `shared_ptr<TorreControl>` dentro de `Estacion` |

## Archivo: `sistema_flota_drones.cpp`

Ya estan completas `Bateria`, `Aeronave` y `TorreControl`: son patrones que ya escribiste antes y no son el reto de hoy. Te toca completar:

- **`RegistroVuelo`**: el patron completo de RAII y move semantics de la Semana 5 y la Semana 6, Sesion 1 (constructor, `agregar`, `getAltura`, constructor de movimiento, operador de asignacion de movimiento, destructor). El comentario sobre la clase, en el archivo, tiene el detalle exacto de cada mensaje esperado.
- **`Dron`**: hereda de `Aeronave`, compone `Bateria` y `RegistroVuelo`, y expone `realizarVuelo` delegando en ambos.
- **`Estacion`**: guarda un `unique_ptr<Dron>` y un `shared_ptr<TorreControl>`, y transfiere el dron entre estaciones con `std::move`.

`main` ya esta completo: es tu forma de verificar que las tres clases funcionan juntas, no algo que tengas que escribir.

## Rubrica: los cinco pilares que se revisan

- **POO:** `Bateria` y `Aeronave` siguen encapsuladas y sin romper; ningun atributo quedo publico.
- **Herencia:** `Dron` hereda de `Aeronave` con herencia publica, sin `virtual`, y usa `setId`, `despegar` y `aterrizar` heredados en vez de reimplementarlos.
- **Composicion:** `Dron` compone `Bateria` y `RegistroVuelo` por valor (no por puntero) y delega en ellos, sin copiar su logica.
- **RAII:** `RegistroVuelo` reserva en el constructor y libera en el destructor; el programa corre sin fugas bajo AddressSanitizer.
- **Move semantics:** el constructor de movimiento y el operador de asignacion de movimiento de `RegistroVuelo` dejan el objeto de origen vacio y seguro; sin ellos, la demostracion de `main` termina en doble liberacion.
- **Smart pointers:** `Estacion` nunca usa `new`/`delete` directamente sobre un `Dron` ni sobre la `TorreControl`; la transferencia entre estaciones usa `std::move` sobre el `unique_ptr`, y el conteo de `shared_ptr` sube al conectar cada estacion.

## Compilar y ejecutar

```
g++ -std=c++20 -Wall -Wextra -g sistema_flota_drones.cpp -o bin/sistema
./bin/sistema
```

Para confirmar que no queda ninguna fuga ni liberacion doble, compila tambien con `-fsanitize=address`:

```
g++ -std=c++20 -Wall -Wextra -g -fsanitize=address sistema_flota_drones.cpp -o bin/sistema_asan
./bin/sistema_asan
```

## Para pensar mientras completas Dron

Si intentas `Dron copia = *base1.verDron();` despues de completar todo, el programa no compila. `Dron` nunca declara su propio constructor de movimiento ni de copia. ¿Por que, entonces, se vuelve imposible copiarlo apenas `RegistroVuelo` declara su constructor de movimiento?

## Antes de la proxima sesion

La proxima sesion es un repaso de medio semestre, dirigido por tus propias preguntas sobre las primeras 6 semanas, mas una discusion sobre las C++ Core Guidelines. Lectura previa: ["C++ Core Guidelines: Philosophy", Zach Wolpe](https://zachcolinwolpe.medium.com/c-core-guidelines-philosophy-f1359570d6b4).
