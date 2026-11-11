#include <gtest/gtest.h>

#include "estacionamiento.h"

// Pruebas del estacionamiento de la Semana 11. Cada TEST es una prueba
// independiente: crea su propio estacionamiento, hace algo y verifica el
// resultado. El primero ya esta escrito como modelo.
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio1_test_estacionamiento.cpp -lgtest_main -lgtest -pthread -o bin/test_estacionamiento
// Ejecutar:  ./bin/test_estacionamiento

TEST(Estacionamiento, PrimeraPlacaRecibePuestoCero) {
    Estacionamiento estacionamiento(3);

    std::optional<int> puesto = estacionamiento.asignarPuesto(4521);

    ASSERT_TRUE(puesto.has_value());
    EXPECT_EQ(*puesto, 0);
}

TEST(Estacionamiento, LlenoDevuelveVacio) {
    Estacionamiento estacionamiento(3);

    estacionamiento.asignarPuesto(1111);
    estacionamiento.asignarPuesto(2222);
    estacionamiento.asignarPuesto(3333);

    std::optional<int> puesto = estacionamiento.asignarPuesto(4444);

    EXPECT_FALSE(puesto.has_value());
}

TEST(Estacionamiento, PlacaRepetidaLanza) {
    Estacionamiento estacionamiento(3);

    estacionamiento.asignarPuesto(7788);

    EXPECT_THROW(estacionamiento.asignarPuesto(7788), std::invalid_argument);
}

TEST(Estacionamiento, PuestoLiberadoSeReusa) {
    Estacionamiento estacionamiento(3);

    estacionamiento.asignarPuesto(1111);
    estacionamiento.asignarPuesto(2222);
    estacionamiento.asignarPuesto(3333);

    estacionamiento.liberar(2222);

    std::optional<int> puesto = estacionamiento.asignarPuesto(4444);

    ASSERT_TRUE(puesto.has_value());
    EXPECT_EQ(*puesto, 1);
}