# Semana 4, Sesión 1: Herencia II, extensibilidad y diseño

## Objetivo de la sesión

Evaluar los riesgos de la herencia múltiple, incluido el problema del diamante, y decidir cuándo una jerarquía extensible es la solución adecuada.

## Antes de empezar

**Lectura previa:** ["Multiple Inheritance in C++ and the Diamond Problem", Onur Tuna](https://medium.com/free-code-camp/multiple-inheritance-in-c-and-the-diamond-problem-7c12a9ddbbec)

**Referencia:** ["Multiple Inheritance", C++ FAQ, isocpp.org](https://isocpp.org/wiki/faq/multiple-inheritance)

Según el artículo, ¿qué hace que el problema del diamante sea un problema real, y no simplemente "otro caso más" de herencia múltiple?

que 2 clases tengan el mismo atributo, y eso hace que su descendencia no sepa de donde coger esa accion 

La sesión pasada terminó con un ConcepTest sobre `Impresora` y `Escaner`, dos clases sin relación conceptual que necesitaban el mismo método. Si en cambio las dos heredaran de una clase común, `Dispositivo`, y las combináramos en una tercera clase `ImpresoraMultifuncion`, ¿qué le pasaría a `numeroSerie`?

_(tu respuesta)_

## Ejercicio 1: reproducir el diamante

Archivo: [`ejercicio1_dispositivo_multifuncion.cpp`](./ejercicio1_dispositivo_multifuncion.cpp). `Impresora` y `Escaner` heredan cada una de `Dispositivo`, y `ImpresoraMultifuncion` hereda de las dos.

**Respuesta 1, antes de ver la solución:** ¿por qué `ImpresoraMultifuncion` termina con dos copias de `numeroSerie` en vez de una sola?

_(tu respuesta)_

**Respuesta 2:** antes de descomentar las líneas marcadas con TODO en el archivo, ¿qué mensaje esperas que dé el compilador, y sobre qué palabra exactamente?

_(tu respuesta)_

**La formulación completa, tal como la resuelvo yo:**

_(anota aquí el mensaje de error real y qué significa, mientras se revisa en clase)_

## Ejercicio 2: arreglar con herencia virtual

Archivo: [`ejercicio2_dispositivo_multifuncion_virtual.cpp`](./ejercicio2_dispositivo_multifuncion_virtual.cpp), mismo punto de partida que el Ejercicio 1.

**Respuesta 1, antes de ver la solución:** si agrego `virtual` a las dos declaraciones de herencia, ¿cuántas copias de `numeroSerie` tiene ahora un objeto `ImpresoraMultifuncion`?

solo una

**Respuesta 2:** ¿qué costo tiene la herencia virtual, más allá de resolver la ambigüedad?

se hace mas lento

**La formulación completa, tal como la resuelvo yo:**

lass Dispositivo {
    private:
        int numeroSerie;
        bool encendido;
    public:
        Dispositivo() {
            numeroSerie = 0;
            encendido = false;
        }

        bool setNumeroSerie(int nuevoNumero) {
            if (nuevoNumero <= 0) { return false; }
            numeroSerie = nuevoNumero;
            return true;
        }

        void encender() {
            encendido = true;
        }

        void describir() {
            std::cout << "Dispositivo #" << numeroSerie << ", encendido: " << (encendido ? "si" : "no") << std::endl;
        }
};

class Impresora: public virtual Dispositivo {
    private:
        int paginasPorMinuto;
    public:
        Impresora() {
            paginasPorMinuto = 0;
        }

        bool setPaginasPorMinuto(int nuevasPpm) {
            if (nuevasPpm <= 0) { return false; }
            paginasPorMinuto = nuevasPpm;
            return true;
        }

        void imprimir() {
            std::cout << "Imprimiendo a " << paginasPorMinuto << " paginas por minuto" << std::endl;
        }
};

// TODO: lo mismo aqui.
class Escaner: public virtual Dispositivo {
    private:
        int resolucionDPI;
    public:
        Escaner() {
            resolucionDPI = 0;
        }

        bool setResolucionDPI(int nuevaResolucion) {
            if (nuevaResolucion <= 0) { return false; }
            resolucionDPI = nuevaResolucion;
            return true;
        }

        void escanear() {
            std::cout << "Escaneando a " << resolucionDPI << " DPI" << std::endl;
        }
};



## Durante el ConcepTest

**Tu voto, antes de discutir en pareja** (A, B, C o D):

_(tu voto)_

**Tu razonamiento:**

_(tu respuesta)_

**Después de discutir en pareja, ¿cambiaste de voto? ¿Por qué?**

_(tu respuesta)_

## Ejercicio 3: RobotAspiradora

Archivo: [`ejercicio3_robot_aspiradora.cpp`](./ejercicio3_robot_aspiradora.cpp). Solo o en pareja.

**Antes de escribir código:** un compañero propone que `RobotAspiradora` herede de dos clases nuevas, `Aspiradora` y `RobotMovil`, y que ambas hereden de `DispositivoElectronico` para reutilizar `numeroSerie`. Explica por qué ese diseño reproduciría el problema del diamante, y qué miembro quedaría ambiguo.

Ambas clases heredarían por separado de DispositivoElectronico, así que RobotAspiradora terminaría con dos copias de esa clase

Diseña en su lugar `RobotAspiradora` con herencia simple, heredando directamente de `DispositivoElectronico` (ya dado en el archivo), y agrega:

- `void aspirar()`: imprime `Aspirando el polvo del piso`.
- `void moverse(int distanciaCm)`: imprime `Moviendose <distanciaCm> cm hacia adelante`.

El archivo tiene, en su encabezado, la salida exacta que debe producir cuando esté completo.

## Compilar y ejecutar

```
g++ -std=c++20 -Wall -Wextra -g ejercicio1_dispositivo_multifuncion.cpp -o bin/ejercicio1
./bin/ejercicio1
```

Repite el mismo patrón con `ejercicio2_dispositivo_multifuncion_virtual.cpp` y `ejercicio3_robot_aspiradora.cpp`.

## Qué construcciones nuevas usa este laboratorio

Herencia múltiple (`class Derivada: public Base1, public Base2`) y herencia virtual (`class Derivada: public virtual Base`), para eliminar la ambigüedad cuando dos bases comparten un ancestro común. El Ejercicio 3 no usa ninguna de las dos: es, a propósito, el ejemplo de que una jerarquía de herencia simple bien diseñada suele bastar. Nada de listas de inicialización de miembros, `protected`, `virtual` sobre métodos (polimorfismo), ni punteros: eso llega en sesiones posteriores.

## Antes de la próxima sesión

`RobotAspiradora` resolvió todo con una sola relación "es un". Pero ¿qué pasa cuando la clase de verdad necesita algo de una segunda clase con la que no tiene esa relación? Por ejemplo, un `Carro` no es un `Motor`, pero sí tiene un `Motor`.

se usaria una composicion 
