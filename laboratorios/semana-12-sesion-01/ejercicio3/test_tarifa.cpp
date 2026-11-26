#include <gtest/gtest.h>
#include <stdexcept>

#include "tarifa.h"

// Tarifa del estacionamiento de visitas de la universidad. Las cuatro
// carpetas version_a a version_d tienen cada una su tarifa.h con una
// implementacion distinta de la misma funcion:
//
//     int tarifaEnCentavos(int minutos)
//
// Lo que tiene que cumplir:
// - Con minutos negativos lanza std::invalid_argument.
// - Hasta 15 minutos, inclusive, no se cobra.
// - Desde el minuto 16, se cobran 50 centavos por cada hora o fraccion,
//   contadas desde el minuto 0: 16 minutos son una hora, 60 minutos son
//   una hora, 61 minutos son dos horas.
// - Ninguna estadia cuesta mas de 500 centavos.
//
// Escribe aqui tus pruebas a partir de esta descripcion, antes de abrir
// cualquier tarifa.h. Compila el mismo archivo contra cada version
// cambiando la carpeta de -I:
//
//     g++ -std=c++20 -Wall -Wextra -g -I ejercicio3/version_a ejercicio3/test_tarifa.cpp -lgtest_main -lgtest -pthread -o bin/test_tarifa_a
//     ./bin/test_tarifa_a

// TODO 1: Minutos negativos lanza std::invalid_argument.
TEST(TarifaTest, MinutosNegativosLanzaExcepcion) {
    EXPECT_THROW(tarifaEnCentavos(-1), std::invalid_argument);
    EXPECT_THROW(tarifaEnCentavos(-60), std::invalid_argument);
}

// TODO 2: Hasta 15 minutos inclusive es gratis (0 centavos).
TEST(TarifaTest, Hasta15MinutosEsGratis) {
    EXPECT_EQ(tarifaEnCentavos(0), 0);
    EXPECT_EQ(tarifaEnCentavos(1), 0);
    EXPECT_EQ(tarifaEnCentavos(15), 0);
}

// TODO 3: Cobro por horas y fracciones de hora a partir del minuto 16.
TEST(TarifaTest, CobroPorHoraYFraccion) {
    // 16 a 60 minutos = 1 hora -> 50 centavos
    EXPECT_EQ(tarifaEnCentavos(16), 50);
    EXPECT_EQ(tarifaEnCentavos(30), 50);
    EXPECT_EQ(tarifaEnCentavos(60), 50);

    // 61 a 120 minutos = 2 horas -> 100 centavos
    EXPECT_EQ(tarifaEnCentavos(61), 100);
    EXPECT_EQ(tarifaEnCentavos(120), 100);

    // 121 minutos = 3 horas -> 150 centavos
    EXPECT_EQ(tarifaEnCentavos(121), 150);
}

// TODO 4: Tope máximo de 500 centavos.
TEST(TarifaTest, TopeMaximoDeCobro) {
    // 10 horas = 500 centavos
    EXPECT_EQ(tarifaEnCentavos(600), 500);

    // Más de 10 horas debe mantenerse en el tope de 500 centavos
    EXPECT_EQ(tarifaEnCentavos(601), 500);
    EXPECT_EQ(tarifaEnCentavos(1440), 500);
}