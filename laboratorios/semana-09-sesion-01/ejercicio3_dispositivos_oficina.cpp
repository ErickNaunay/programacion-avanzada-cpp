#include <iostream>

// Este archivo compila y corre tal como esta. Ejecutalo primero:
//
// Lote de impresion:
// Impresora basica 1: imprime 5 paginas
// Multifuncional 2: imprime 5 paginas
// Lote de escaneo:
// Impresora basica 1: no puede escanear 3 paginas
// Multifuncional 2: escanea 3 paginas
// Fax:
// Multifuncional 2: envia fax al 5550000
//
// TODO: reemplaza IDispositivoOficina por tres interfaces, IImpresora
// (imprimir), IEscaner (escanear) e IFax (enviarFax), y haz que cada
// clase implemente solo las que de verdad soporta. imprimirLote y
// escanearLote deben recibir la interfaz que usan, no una que les sobra.
// Despues del cambio, en main, ImpresoraBasica ya no puede entrar al lote
// de escaneo: quita esa linea y ajusta el tamano del arreglo. El fax se
// envia a traves de un IFax*.
//
// Salida esperada despues del cambio:
// Lote de impresion:
// Impresora basica 1: imprime 5 paginas
// Multifuncional 2: imprime 5 paginas
// Lote de escaneo:
// Multifuncional 2: escanea 3 paginas
// Fax:
// Multifuncional 2: envia fax al 5550000

class IDispositivoOficina {
    public:
        virtual void imprimir(int paginas) = 0;
        virtual void escanear(int paginas) = 0;
        virtual void enviarFax(int numero) = 0;
        virtual ~IDispositivoOficina() {
        }
};

class ImpresoraBasica : public IDispositivoOficina {
    private:
        int id;
    public:
        ImpresoraBasica(int nuevoId) {
            id = nuevoId;
        }

        void imprimir(int paginas) override {
            std::cout << "Impresora basica " << id << ": imprime " << paginas << " paginas" << std::endl;
        }

        void escanear(int paginas) override {
            std::cout << "Impresora basica " << id << ": no puede escanear " << paginas << " paginas" << std::endl;
        }

        void enviarFax(int numero) override {
            std::cout << "Impresora basica " << id << ": no puede enviar fax al " << numero << std::endl;
        }
};

class Multifuncional : public IDispositivoOficina {
    private:
        int id;
    public:
        Multifuncional(int nuevoId) {
            id = nuevoId;
        }

        void imprimir(int paginas) override {
            std::cout << "Multifuncional " << id << ": imprime " << paginas << " paginas" << std::endl;
        }

        void escanear(int paginas) override {
            std::cout << "Multifuncional " << id << ": escanea " << paginas << " paginas" << std::endl;
        }

        void enviarFax(int numero) override {
            std::cout << "Multifuncional " << id << ": envia fax al " << numero << std::endl;
        }
};

void imprimirLote(IDispositivoOficina* dispositivos[], int cantidad, int paginas) {
    for (int i = 0; i < cantidad; i++) {
        dispositivos[i]->imprimir(paginas);
    }
}

void escanearLote(IDispositivoOficina* dispositivos[], int cantidad, int paginas) {
    for (int i = 0; i < cantidad; i++) {
        dispositivos[i]->escanear(paginas);
    }
}

int main() {
    ImpresoraBasica basica(1);
    Multifuncional multi(2);

    IDispositivoOficina* impresoras[2];
    impresoras[0] = &basica;
    impresoras[1] = &multi;

    IDispositivoOficina* escaneres[2];
    escaneres[0] = &basica;
    escaneres[1] = &multi;

    std::cout << "Lote de impresion:" << std::endl;
    imprimirLote(impresoras, 2, 5);

    std::cout << "Lote de escaneo:" << std::endl;
    escanearLote(escaneres, 2, 3);

    std::cout << "Fax:" << std::endl;
    multi.enviarFax(5550000);

    return 0;
}
