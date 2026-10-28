#include <iostream>

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double xInicial, double yInicial) {
        x = xInicial;
        y = yInicial;
    }

    double getX() {
        return x;
    }

    double getY() {
        return y;
    }

    Vector2D operator+(Vector2D otro) {
        return Vector2D(x + otro.getX(), y + otro.getY());
    }
};

std::ostream& operator<<(std::ostream& os, Vector2D v) {
    os << "(" << v.getX() << ", " << v.getY() << ")";
    return os;
}

template <typename T>
T mayor(T a, T b) {
    if (a > b) {
        return a;
    }

    return b;
}

template <typename T>
T sumarTres(T a, T b, T c) {
    return a + b + c;
}

int main() {
    std::cout << "mayor(3, 7) = "
              << mayor(3, 7)
              << std::endl;

    std::cout << "mayor(2.5, 1.5) = "
              << mayor(2.5, 1.5)
              << std::endl;

    std::cout << "mayor('a', 'z') = "
              << mayor('a', 'z')
              << std::endl;

    std::cout << "mayor(3, 4.5) = "
              << mayor<double>(3, 4.5)
              << std::endl;

    Vector2D v1(2.0, 3.0);
    Vector2D v2(4.0, -1.0);
    Vector2D v3(0.0, 1.0);

    std::cout << "sumarTres(1, 2, 3) = "
              << sumarTres(1, 2, 3)
              << std::endl;

    std::cout << "sumarTres(v1, v2, v3) = "
              << sumarTres(v1, v2, v3)
              << std::endl;

    // std::cout << "mayor(v1, v2) = " << mayor(v1, v2) << std::endl;

    return 0;
}