#include <iostream>

class IImpresora {
public:
    virtual void imprimir(int paginas) = 0;

    virtual ~IImpresora() {
    }
};

class IEscaner {
public:
    virtual void escanear(int paginas) = 0;

    virtual ~IEscaner() {
    }
};

class IFax {
public:
    virtual void enviarFax(int numero) = 0;

    virtual ~IFax() {
    }
};

class ImpresoraBasica : public IImpresora {
private:
    int id;

public:
    ImpresoraBasica(int nuevoId) {
        id = nuevoId;
    }

    void imprimir(int paginas) override {
        std::cout << "Impresora basica "
                  << id
                  << ": imprime "
                  << paginas
                  << " paginas"
                  << std::endl;
    }
};

class Multifuncional : public IImpresora, public IEscaner, public IFax {
private:
    int id;

public:
    Multifuncional(int nuevoId) {
        id = nuevoId;
    }

    void imprimir(int paginas) override {
        std::cout << "Multifuncional "
                  << id
                  << ": imprime "
                  << paginas
                  << " paginas"
                  << std::endl;
    }

    void escanear(int paginas) override {
        std::cout << "Multifuncional "
                  << id
                  << ": escanea "
                  << paginas
                  << " paginas"
                  << std::endl;
    }

    void enviarFax(int numero) override {
        std::cout << "Multifuncional "
                  << id
                  << ": envia fax al "
                  << numero
                  << std::endl;
    }
};

void imprimirLote(IImpresora* dispositivos[], int cantidad, int paginas) {
    for (int i = 0; i < cantidad; i++) {
        dispositivos[i]->imprimir(paginas);
    }
}

void escanearLote(IEscaner* dispositivos[], int cantidad, int paginas) {
    for (int i = 0; i < cantidad; i++) {
        dispositivos[i]->escanear(paginas);
    }
}

int main() {
    ImpresoraBasica basica(1);
    Multifuncional multi(2);

    IImpresora* impresoras[2];
    impresoras[0] = &basica;
    impresoras[1] = &multi;

    IEscaner* escaneres[1];
    escaneres[0] = &multi;

    std::cout << "Lote de impresion:" << std::endl;
    imprimirLote(impresoras, 2, 5);

    std::cout << "Lote de escaneo:" << std::endl;
    escanearLote(escaneres, 1, 3);

    std::cout << "Fax:" << std::endl;

    IFax* fax = &multi;
    fax->enviarFax(5550000);

    return 0;
}