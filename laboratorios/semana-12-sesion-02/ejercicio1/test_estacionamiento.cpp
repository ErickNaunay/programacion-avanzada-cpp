// Las cuatro pruebas del estacionamiento de la Sesion 1. Desde esta
// sesion se compilan con CMake (ver CMakeLists.txt).

#include <gtest/gtest.h>

#include "estacionamiento.h"

TEST(Estacionamiento, PrimeraPlacaRecibePuestoCero) {
    Estacionamiento estacionamiento(3);

    std::optional<int> puesto = estacionamiento.asignarPuesto(4521);

    ASSERT_TRUE(puesto.has_value());
    EXPECT_EQ(*puesto, 0);
}

TEST(Estacionamiento, LlenoDevuelveVacio) {
    Estacionamiento estacionamiento(3);
    estacionamiento.asignarPuesto(4521);
    estacionamiento.asignarPuesto(7788);
    estacionamiento.asignarPuesto(3011);

    std::optional<int> cuarta = estacionamiento.asignarPuesto(9090);

    EXPECT_FALSE(cuarta.has_value());
}

TEST(Estacionamiento, PlacaRepetidaLanza) {
    Estacionamiento estacionamiento(3);
    estacionamiento.asignarPuesto(7788);

    EXPECT_THROW(estacionamiento.asignarPuesto(7788), std::invalid_argument);
}

TEST(Estacionamiento, PuestoLiberadoSeReusa) {
    Estacionamiento estacionamiento(3);
    estacionamiento.asignarPuesto(4521);
    estacionamiento.asignarPuesto(7788);
    estacionamiento.asignarPuesto(3011);
    estacionamiento.liberar(7788);

    std::optional<int> nueva = estacionamiento.asignarPuesto(9090);

    ASSERT_TRUE(nueva.has_value());
    EXPECT_EQ(*nueva, 1);
}
