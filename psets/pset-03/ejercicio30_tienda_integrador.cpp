// Ejercicio 30: la Tienda del campus (desde cero, integrador del PSet)
//
// Este archivo no tiene codigo de partida. Escribe tus propios includes,
// tus propias clases, tu plantilla y tu propio main(). Es el ejercicio mas
// largo del PSet a proposito: junta polimorfismo, una clase abstracta,
// unique_ptr dentro de un vector, una plantilla, algoritmos con lambdas,
// excepciones y std::optional.
//
// Producto: clase abstracta. Atributos privados codigo (int) y precio
// (double). Metodo void setDatos(int c, double p) que los asigna sin
// validar, getters int getCodigo() y double getPrecio(), destructor virtual
// vacio y una funcion virtual pura double precioFinal().
//
// Tres clases derivadas, publicas, cada una con un constructor que llama
// setDatos:
// - ProductoNormal(int codigo, double precio): precioFinal es el precio.
// - ProductoEnOferta(int codigo, double precio, double porcentaje):
//   precioFinal es el precio con el porcentaje de descuento aplicado
//   (precio * (1 - porcentaje / 100)).
// - ProductoPorPeso(int codigo, double precioPorKilo, double kilos): el
//   precio guardado es el precio por kilo, y precioFinal es precio * kilos.
//
// Una plantilla de funcion T mayorDe(std::vector<T> valores) que devuelve
// el mayor valor del vector con std::max_element (o T() si esta vacio).
//
// Tienda: atributo privado std::vector<std::unique_ptr<Producto>>
// productos. Metodos:
// - void agregar(std::unique_ptr<Producto> producto): si el precio del
//   producto es menor o igual a 0, lanza std::invalid_argument("precio no
//   positivo"); si ya hay un producto con el mismo codigo, lanza
//   std::invalid_argument("codigo repetido"). Si no, lo mueve al final del
//   vector con std::move.
// - int cantidad(): cuantos productos hay.
// - std::optional<double> precioDe(int codigo): el precio final del
//   producto con ese codigo, o vacio si no esta.
// - std::vector<double> preciosFinales(): los precios finales, en el orden
//   en que se agregaron.
// - double total(): la suma de los precios finales, con std::accumulate
//   sobre preciosFinales().
// - int cuantosBajo(double limite): cuantos precios finales son menores
//   que limite, con std::count_if y una lambda que captura limite.
// - std::optional<int> codigoMasCaro(): el codigo del producto de mayor
//   precio final, o vacio si no hay productos.
//
// Para recorrer el vector de unique_ptr usa un ciclo por posicion
// (productos[i]->precioFinal()): un for de rango copiaria cada unique_ptr,
// y un unique_ptr no se puede copiar.
//
// En main(), con los textos de la salida esperada:
// 1. Agrega, cada uno en su propio try con un catch de
//    std::invalid_argument por referencia constante que imprime "No se
//    agrego: " y e.what(): un ProductoNormal 101 a 2.5, un ProductoEnOferta
//    205 a 10 con 20% de descuento, un ProductoPorPeso 310 a 4 por kilo con
//    1.5 kilos, un ProductoNormal 101 a 3, y un ProductoNormal 400 a 0. Crea
//    cada uno con std::make_unique y pasalo con std::move.
// 2. Imprime la cantidad de productos, el total, cuantos cuestan menos de
//    7, el codigo del mas caro (con *), el precio del 310 (con value_or(0))
//    y el del 999 (con has_value: si no esta, imprime "no existe").
// 3. Imprime el mayor precio final usando mayorDe sobre preciosFinales().
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio30 ejercicio30_tienda_integrador.cpp
// Ejecutar: ./ejercicio30
//
// Salida esperada:
// No se agrego: codigo repetido
// No se agrego: precio no positivo
// Productos: 3
// Total: 16.5
// Cuestan menos de 7: 2
// Mas caro: 205
// Precio del 310: 6
// Precio del 999: no existe
// Mayor precio final: 8
