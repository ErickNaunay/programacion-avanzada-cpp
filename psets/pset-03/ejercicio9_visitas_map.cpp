// Ejercicio 9: ContadorDeVisitas (std::map)
//
// Completa los metodos marcados con TODO. No cambies las firmas ni el main().
// Ojo con visitasDe: preguntar por una sala que no existe no debe crearla.
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio9 ejercicio9_visitas_map.cpp
// Ejecutar: ./ejercicio9
//
// Salida esperada:
// Visitas a la sala 204: 3
// Visitas a la sala 999: 0
// Salas registradas: 3
// Sala 101: 1
// Sala 204: 3
// Sala 310: 2
// Sala mas visitada: 204

#include <iostream>
#include <map>

class ContadorDeVisitas {
private:
    std::map<int, int> visitasPorSala;
public:
    void registrar(int sala) {
        // TODO: suma 1 a las visitas de esa sala (si no existe, empieza en 0).
        visitasPorSala[sala]++;

    }
    int visitasDe(int sala) {
        // TODO: si la sala no esta (count), devuelve 0 sin crearla; si esta,
        // devuelve sus visitas.
        if (visitasPorSala.count(sala)) {
            return visitasPorSala[sala];
        }
        return 0;
    }
    int cantidadDeSalas() {
        // TODO: devuelve cuantas salas distintas hay.
        return visitasPorSala.size();
    }
    void imprimir() {
        // TODO: recorre el map con un iterador (auto it = visitasPorSala.begin())
        // e imprime "Sala " << clave << ": " << valor, una por linea.
        for (const auto& par : visitasPorSala) {
            std::cout << "Sala " << par.first << ": " << par.second << std::endl;
        }
    }
    int masVisitada() {
        // TODO: devuelve la sala con mas visitas (en un empate, la de numero
        // menor), o -1 si no hay ninguna.
        if (visitasPorSala.empty()) {
            return -1;
        }
        int salaMasVisitada = visitasPorSala.begin()->first;
        int maxVisitas = visitasPorSala.begin()->second;
        for (const auto& par : visitasPorSala) {
            if (par.second > maxVisitas || (par.second == maxVisitas && par.first < salaMasVisitada)) {
                salaMasVisitada = par.first;
                maxVisitas = par.second;
            }
        }
        return salaMasVisitada;
    }
};

int main() {
    ContadorDeVisitas contador;
    contador.registrar(204);
    contador.registrar(310);
    contador.registrar(204);
    contador.registrar(101);
    contador.registrar(310);
    contador.registrar(204);

    std::cout << "Visitas a la sala 204: " << contador.visitasDe(204) << std::endl;
    std::cout << "Visitas a la sala 999: " << contador.visitasDe(999) << std::endl;
    std::cout << "Salas registradas: " << contador.cantidadDeSalas() << std::endl;
    contador.imprimir();
    std::cout << "Sala mas visitada: " << contador.masVisitada() << std::endl;
    return 0;
}
