#include <gtest/gtest.h>

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
TEST(tarifaEnCentavo, minutos_negativos){
    EXPECT_THROW(tarifaEnCentavos(-1),std::invalid_argument);
}
TEST(tarifaEnCentavo, No_se_cobra){
    EXPECT_EQ(tarifaEnCentavos(0), 0);
    EXPECT_EQ(tarifaEnCentavos(13), 0);
    EXPECT_EQ(tarifaEnCentavos(15), 0);
}
TEST(tarifaEnCentavo, Se_cobra){
    EXPECT_EQ(tarifaEnCentavos(16), 50);
    EXPECT_EQ(tarifaEnCentavos(60), 50);
    EXPECT_EQ(tarifaEnCentavos(61), 100);
}
TEST(tarifaEnCentavo, Cobro_maximo){
    EXPECT_EQ(tarifaEnCentavos(600), 500);
    EXPECT_EQ(tarifaEnCentavos(700), 500);
    EXPECT_EQ(tarifaEnCentavos(1000), 500);
}
//
//     g++ -std=c++20 -Wall -Wextra -g -I ejercicio3/version_a ejercicio3/test_tarifa.cpp -lgtest_main -lgtest -pthread -o bin/test_tarifa_a
//     ./bin/test_tarifa_a
