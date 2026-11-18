#include <gtest/gtest.h>

#include "bodega.h"

// Pruebas de la bodega. Escribe una prueba por TODO, cada una con su
// propia Bodega. Los nombres de las pruebas ya estan elegidos: dicen que
// se verifica, para que el reporte de GoogleTest se lea solo.
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio2_test_bodega.cpp -lgtest_main -lgtest -pthread -o bin/test_bodega
// Ejecutar:  ./bin/test_bodega

// TODO 1: TEST(Bodega, IngresarDosVecesAcumula). Ingresa 10 y despues 5
// del codigo 305; el stock de 305 tiene que ser 15.
TEST(Bodega, IngresarDosVecesAcumula) {
    Bodega bodega;
    bodega.ingresar(305, 10);
    bodega.ingresar(305, 5);

    EXPECT_EQ(bodega.stockDe(305), 15);
}

// TODO 2: TEST(Bodega, RetirarTodoElStockLoDejaEnCero). Ingresa 5 del
// codigo 210 y retira 5. El retiro no lanza (EXPECT_NO_THROW) y el stock
// queda en 0.
TEST(Bodega, RetirarTodoElStockLoDejaEnCero) {
    Bodega bodega;
    bodega.ingresar(210, 5);

    EXPECT_NO_THROW(bodega.retirar(210, 5));
    EXPECT_EQ(bodega.stockDe(210), 0);
}

// TODO 3: TEST(Bodega, RetirarMasDelStockLanzaYNoCambiaNada). Con 2
// unidades del codigo 120, retirar 5 lanza std::runtime_error, y despues
// el stock de 120 sigue en 2.
TEST(Bodega, RetirarMasDelStockLanzaYNoCambiaNada) {
    Bodega bodega;
    bodega.ingresar(120, 2);

    EXPECT_THROW(bodega.retirar(120, 5), std::runtime_error);
    EXPECT_EQ(bodega.stockDe(120), 2);
}

// TODO 4: TEST(Bodega, CantidadCeroLanza). Retirar 0 de un codigo que
// existe lanza std::invalid_argument.
TEST(Bodega, CantidadCeroLanza) {
    Bodega bodega;
    bodega.ingresar(120, 10);

    EXPECT_THROW(bodega.retirar(120, 0), std::invalid_argument);
}

// TODO 5: TEST(Bodega, CodigoDesconocidoLanzaYNoSeCrea). En una bodega
// con el codigo 305, retirar 1 del codigo 999 lanza std::out_of_range, y
// despues stockDe(999) tambien lanza std::out_of_range: el retiro
// rechazado no puede haber creado el codigo.
TEST(Bodega, CodigoDesconocidoLanzaYNoSeCrea) {
    Bodega bodega;
    bodega.ingresar(305, 10);

    EXPECT_THROW(bodega.retirar(999, 1), std::out_of_range);
    EXPECT_THROW(bodega.stockDe(999), std::out_of_range);
}