#include <gtest/gtest.h>

#include "estacionamiento.h"

// Pruebas del estacionamiento de la Semana 11. Cada TEST es una prueba
// independiente: crea su propio estacionamiento, hace algo y verifica el
// resultado. El primero ya esta escrito como modelo.
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio1_test_estacionamiento.cpp -lgtest_main -lgtest -pthread -o test_estacionamiento
// Ejecutar:  ./bin/test_estacionamiento

TEST(Estacionamiento, PrimeraPlacaRecibePuestoCero) {
    Estacionamiento estacionamiento(3);

    std::optional<int> puesto = estacionamiento.asignarPuesto(4521);

    ASSERT_TRUE(puesto.has_value());
    EXPECT_EQ(*puesto, 0);
}

// TODO 1: prueba LlenoDevuelveVacio. Con 3 puestos, asigna tres placas
// distintas; la cuarta tiene que recibir un optional vacio
// (EXPECT_FALSE sobre has_value()).
TEST(Estacionamiento, LlenoDevuelveVacio) {
    Estacionamiento estacionamiento(3);

    std::optional<int> puesto1 = estacionamiento.asignarPuesto(123);
    std::optional<int> puesto2 = estacionamiento.asignarPuesto(456);
    std::optional<int> puesto3 = estacionamiento.asignarPuesto(789);
    std::optional<int> puesto4 = estacionamiento.asignarPuesto(1121);

    ASSERT_TRUE(puesto1.has_value());
    ASSERT_TRUE(puesto2.has_value());
    ASSERT_TRUE(puesto3.has_value());
    EXPECT_FALSE(puesto4.has_value());
}

// TODO 2: prueba PlacaRepetidaLanza. Asigna la placa 7788 y verifica que
// asignarla otra vez lanza std::invalid_argument (EXPECT_THROW).
TEST(Estacionamiento, PlacaRepetidaLanza) {
    Estacionamiento estacionamiento(3);

    estacionamiento.asignarPuesto(7788);

    EXPECT_THROW(estacionamiento.asignarPuesto(7788), std::invalid_argument);
}

// TODO 3: prueba PuestoLiberadoSeReusa. Llena los 3 puestos, libera la
// placa del puesto 1 y verifica que la siguiente placa recibe el puesto 1.
TEST(Estacionamiento, PuestoLiberadoSeReusa) {
    Estacionamiento estacionamiento(3);

    estacionamiento.asignarPuesto(1001); // Puesto 0
    estacionamiento.asignarPuesto(1002); // Puesto 1
    estacionamiento.asignarPuesto(1003); // Puesto 2

    std::optional<int> liberado = estacionamiento.liberar(1002);
    ASSERT_TRUE(liberado.has_value());
    EXPECT_EQ(*liberado, 1);

    std::optional<int> nuevoPuesto = estacionamiento.asignarPuesto(1004);
    ASSERT_TRUE(nuevoPuesto.has_value());
    EXPECT_EQ(*nuevoPuesto, 1);
}