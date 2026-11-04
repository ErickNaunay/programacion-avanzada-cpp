// Ejercicio 24: Documento, Propietario y Observador
// (desde cero, shared_ptr y weak_ptr)
//
// Este archivo no tiene codigo de partida. Escribe tu de tu propia clase,
// tus propios includes (necesitas <memory> ademas de <iostream>) y tu
// propio main().
//
// Disena tres clases:
//
// Documento: atributo privado numeroVersion (int). Setter bool
// setNumeroVersion(int v) valido si v esta entre 1 y 999 (ambos
// incluidos). Getter int getNumeroVersion().
//
// Propietario: atributo privado documento, de tipo
// std::shared_ptr<Documento>. Metodo void adoptar(std::shared_ptr<Documento>
// doc) que asigna documento = doc (es un dueno mas del documento
// compartido). Metodo void soltar() que llama a documento.reset() (deja de
// ser dueno). Metodo int contadorReferencias() que devuelve
// documento.use_count().
//
// Observador: atributo privado documento, de tipo
// std::weak_ptr<Documento> (observa el documento sin ser su dueno, y sin
// mantenerlo vivo). Metodo void observar(std::shared_ptr<Documento> doc)
// que asigna documento = doc (un weak_ptr se puede asignar desde un
// shared_ptr, sin aumentar el numero de duenos). Metodo bool
// documentoTodaviaExiste() que devuelve true si el documento observado
// todavia existe (usa .expired() y niegalo).
//
// En main(): crea un std::shared_ptr<Documento> con std::make_shared,
// llamalo doc, y asignale numeroVersion = 3. Crea un Propietario llamado
// dueno y llama a dueno.adoptar(doc). Imprime dueno.contadorReferencias(),
// precedido por "Referencias tras adoptar: ". Crea un Observador llamado
// obs y llama a obs.observar(doc). Imprime
// obs.documentoTodaviaExiste(), precedido por "Documento existe
// (observador): " (usa std::boolalpha). Imprime
// dueno.contadorReferencias() otra vez, precedido por "Referencias despues
// de observar: " (debe seguir igual que antes, porque un weak_ptr no suma
// duenos). Llama a doc.reset() (el shared_ptr original de main() deja de
// ser dueno). Imprime dueno.contadorReferencias(), precedido por
// "Referencias tras reset del original: ". Imprime
// obs.documentoTodaviaExiste() otra vez, con la misma etiqueta de antes
// (todavia debe existir, porque dueno sigue siendo dueno). Llama a
// dueno.soltar() (ya no queda ningun dueno). Imprime
// obs.documentoTodaviaExiste() una ultima vez, con la misma etiqueta
// (ahora debe ser false, porque ya no queda ningun shared_ptr vivo).
//
// Compilar: g++ -std=c++20 -Wall -Wextra -g -o ejercicio24 ejercicio24_documento_observador.cpp
// Ejecutar: ./ejercicio24
//
// Salida esperada:
// Referencias tras adoptar: 2
// Documento existe (observador): true
// Referencias despues de observar: 2
// Referencias tras reset del original: 1
// Documento existe (observador): true
// Documento existe (observador): false

#include <iostream>
#include <memory>

class Documento {
private:
    int numeroVersion;
public:
    bool setNumeroVersion(int v) {
        if (v >= 1 && v <= 999) {
            numeroVersion = v;
            return true;
        }
        return false;
    }
    int getNumeroVersion() const {
        return numeroVersion;
    }
};

class Propietario {
private:
    std::shared_ptr<Documento> documento;
public:
    void adoptar(std::shared_ptr<Documento> doc) {
        documento = doc;
    }
    void soltar() {
        documento.reset();
    }
    int contadorReferencias() const {
        return documento.use_count();
    }
};

class Observador {
private:
    std::weak_ptr<Documento> documento;
public:
    void observar(std::shared_ptr<Documento> doc) {
        documento = doc;
    }
    bool documentoTodaviaExiste() const {
        return !documento.expired();
    }
};

int main() {
    auto doc = std::make_shared<Documento>();
    doc->setNumeroVersion(3);

    Propietario dueno;
    dueno.adoptar(doc);
    std::cout << "Referencias tras adoptar: " << dueno.contadorReferencias() << std::endl;

    Observador obs;
    obs.observar(doc);
    std::cout << std::boolalpha << "Documento existe (observador): " << obs.documentoTodaviaExiste() << std::endl;

    std::cout << "Referencias despues de observar: " << dueno.contadorReferencias() << std::endl;

    doc.reset();
    std::cout << "Referencias tras reset del original: " << dueno.contadorReferencias() << std::endl;
    std::cout << "Documento existe (observador): " << obs.documentoTodaviaExiste() << std::endl;

    dueno.soltar();
    std::cout << "Documento existe (observador): " << obs.documentoTodaviaExiste() << std::endl;

    return 0;
}