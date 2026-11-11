#include <gtest/gtest.h>

#include "lecturas.h"

TEST(PromedioMovil, PrimerPromedioDeTres) {
    std::vector<double> lecturas = {18.0, 19.0, 20.0, 21.0, 22.0, 23.0};

    std::vector<double> promedios = promedioMovil(lecturas, 3);

    ASSERT_GE(promedios.size(), 1);
    EXPECT_NEAR(promedios[0], 19.0, 0.001);
}

TEST(PromedioMovil, VentanaDeUnoDevuelveLasMismasLecturas) {
    std::vector<double> lecturas = {18.5, 30.0, 12.25};

    std::vector<double> promedios = promedioMovil(lecturas, 1);

    ASSERT_EQ(promedios.size(), 3);
    EXPECT_NEAR(promedios[2], 12.25, 0.001);
}

// TODO 4: escribe la prueba CantidadDePromedios: con 6 lecturas y ventana
// 3 tiene que haber exactamente 4 promedios. Tiene que fallar antes de que
// corrijas lecturas.h.
