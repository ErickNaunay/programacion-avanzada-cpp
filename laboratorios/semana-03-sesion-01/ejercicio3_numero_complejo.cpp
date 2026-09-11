#include <iostream>

class NumeroComplejo {
private:
    double real;
    double imaginario;

public:
    NumeroComplejo(double realInicial, double imaginarioInicial) {
        real = realInicial;
        imaginario = imaginarioInicial;
    }

    double getReal() { return real; }
    double getImaginario() { return imaginario; }

    NumeroComplejo operator+(NumeroComplejo otro) {
        return NumeroComplejo(real + otro.real, imaginario + otro.imaginario);
    }
};

std::ostream& operator<<(std::ostream& os, NumeroComplejo c) {
    os << c.getReal() << " + " << c.getImaginario() << "i";
    return os;
}

int main() {
    NumeroComplejo c1(3.0, 2.0);
    NumeroComplejo c2(1.0, -5.0);
    NumeroComplejo suma = c1 + c2;

    std::cout << c1 << " + " << c2 << " = " << suma << std::endl;

    return 0;
}
