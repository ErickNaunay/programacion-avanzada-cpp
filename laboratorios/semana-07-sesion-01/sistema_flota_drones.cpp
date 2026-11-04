#include <iostream>
#include <memory>
#include <utility>

using namespace std;

// ---------- Bateria: ya la conoces (encapsulacion, invariante con setter que devuelve bool) ----------
class Bateria {
private:
    double capacidadMax;
    double cargaActual;

public:
    Bateria() {
        capacidadMax = 100.0;
        cargaActual = 100.0;}

    bool setCapacidad(double nuevaCapacidad) {
        if (nuevaCapacidad <= 0) {
            return false;}

        capacidadMax = nuevaCapacidad;
        cargaActual = nuevaCapacidad;
        return true;}

    bool descargar(double cantidad) {
        if (cantidad > cargaActual) {
            return false;}

        cargaActual = cargaActual - cantidad;
        return true;}

    void recargar() {cargaActual = capacidadMax;}

    double getCargaActual() {return cargaActual;}
};

// TODO: RegistroVuelo (RAII + move semantics, Semana 5 y Semana 6 Sesion 1).
// - Atributos privados: double* alturas, int capacidad, int siguiente.
// - Constructor RegistroVuelo(): capacidad = 10, reserva "alturas" con
//   new[], siguiente = 0, imprime "Registro de vuelo creado, capacidad 10".
// - void agregar(double altura): guarda en alturas[siguiente] y avanza
//   siguiente, sin sobrepasar capacidad.
// - double getAltura(int indice): si alturas es nullptr, imprime
//   "Registro vacio (fue movido)" y devuelve 0.0; si no, devuelve
//   alturas[indice].
// - Constructor de movimiento RegistroVuelo(RegistroVuelo&& otro): roba
//   alturas, capacidad y siguiente de "otro", y deja "otro" vacio y seguro
//   (alturas = nullptr, capacidad = 0, siguiente = 0).
// - Operador de asignacion de movimiento
//   RegistroVuelo& operator=(RegistroVuelo&& otro): libera lo propio con
//   delete[] antes de robar lo de "otro" (comprobando this != &otro).
// - Destructor ~RegistroVuelo(): libera con delete[] e imprime
//   "Destruyendo registro de vuelo (capacidad <capacidad>)".

class RegistroVuelo {
private:
    double* alturas;
    int capacidad;
    int siguiente;

public:
    RegistroVuelo() {
        capacidad = 10;
        alturas = new double[capacidad];
        siguiente = 0;
        cout << "Registro de vuelo creado, capacidad " << capacidad << endl;}

    void agregar(double altura) {
        if (siguiente < capacidad) {
            alturas[siguiente] = altura;
            siguiente++;}}

    double getAltura(int indice) {
        if (alturas == nullptr) {
            cout << "Registro vacio (fue movido)" << endl;
            return 0.0;}

        return alturas[indice];}

    RegistroVuelo(RegistroVuelo&& otro) {
        alturas = otro.alturas;
        capacidad = otro.capacidad;
        siguiente = otro.siguiente;
        
        otro.alturas = nullptr;
        otro.capacidad = 0;
        otro.siguiente = 0;}

    RegistroVuelo& operator=(RegistroVuelo&& otro) {
        if (this != &otro) {
            delete[] alturas;
            
            alturas = otro.alturas;
            capacidad = otro.capacidad;
            siguiente = otro.siguiente;
            
            otro.alturas = nullptr;
            otro.capacidad = 0;
            otro.siguiente = 0;} 
            
            return *this;}

    ~RegistroVuelo() {
        delete[] alturas;
        cout << "Destruyendo registro de vuelo (capacidad " << capacidad << ")" << endl;}};

// ---------- Aeronave: ya la conoces (base de una jerarquia con herencia publica) ----------
class Aeronave {
private:
    int id;
    double altitud;

public:
    Aeronave() {
        id = 0;
        altitud = 0.0;}

    void setId(int nuevoId) {id = nuevoId;}

    int getId() {return id;}

    bool despegar(double altitudCrucero) {
        if (altitudCrucero <= 0) {
            return false;}

        altitud = altitudCrucero;
        cout << "Aeronave " << id << " despega a " << altitud << " metros" << endl;
        return true;}

    void aterrizar() {
        altitud = 0.0;
        cout << "Aeronave " << id << " aterriza" << endl;}

    double getAltitud() {
        return altitud;}
};

// TODO: Dron (herencia publica desde Aeronave + composicion con Bateria y
// RegistroVuelo, Semana 3-4).
// - class Dron : public Aeronave, con dos atributos privados por
//   composicion: Bateria bateria y RegistroVuelo registro (cada uno se
//   construye solo, con su propio constructor por defecto, antes de que
//   corra el cuerpo del constructor de Dron, igual que Motor dentro de
//   Carro en la Semana 4).
// - Constructor Dron(int id, double capacidadBateria): usa el setter
//   heredado setId(id) (Aeronave no tiene un constructor con parametros
//   que puedas llamar aqui), y configura bateria con setCapacidad(...) y
//   recargar().
// - bool puedeDespegar(double consumoEstimado): true si
//   bateria.getCargaActual() alcanza para el consumo estimado.
// - bool realizarVuelo(double altitudCrucero, double consumoBateria): si
//   no puedeDespegar, imprime "Dron <id> no tiene carga suficiente" y
//   devuelve false; si puede, llama despegar(altitudCrucero) (heredado),
//   registro.agregar(altitudCrucero), bateria.descargar(consumoBateria),
//   aterrizar() (heredado), y devuelve true.
// - double getAltitudRegistrada(int indice): delega en
//   registro.getAltura(indice).
// - double getCargaActual(): delega en bateria.getCargaActual().

class Dron : public Aeronave {
private:
    Bateria bateria;
    RegistroVuelo registro;

public:
    Dron(int id, double capacidadBateria) {
        setId(id);
        bateria.setCapacidad(capacidadBateria);
        bateria.recargar();}

    bool puedeDespegar(double consumoEstimado) {return bateria.getCargaActual() >= consumoEstimado;}

    bool realizarVuelo(double altitudCrucero, double consumoBateria) {
        if (!puedeDespegar(consumoBateria)) {
            cout << "Dron " << getId() << " no tiene carga suficiente" << endl;
            return false;}

        despegar(altitudCrucero);
        registro.agregar(altitudCrucero);
        bateria.descargar(consumoBateria);
        aterrizar();
        return true;}

    double getAltitudRegistrada(int indice) {
        return registro.getAltura(indice);}

    double getCargaActual() {
        return bateria.getCargaActual();}
};

// ---------- TorreControl: ya la conoces (recurso que varias Estacion van a compartir) ----------
class TorreControl {
private:
    int totalDespachos;

public:
    TorreControl(int totalDespachos) {
        this->totalDespachos = totalDespachos;
        cout << "Torre de control creada" << endl;}

    void registrarDespacho() {totalDespachos = totalDespachos + 1;}

    int getTotalDespachos() {return totalDespachos;}

    ~TorreControl() {cout << "Destruyendo torre de control (" << totalDespachos << " despachos)" << endl;}
};

// TODO: Estacion (smart pointers, Semana 6 Sesion 2).
// - Atributos privados: int idEstacion; std::unique_ptr<Dron> dronAsignado
//   (propiedad exclusiva del dron que tiene asignado en este momento, o
//   vacio); std::shared_ptr<TorreControl> torre (comparte la torre con las
//   demas estaciones).
// - Constructor Estacion(int id, std::shared_ptr<TorreControl>
//   torreCompartida): guarda id, guarda torreCompartida en torre, imprime
//   "Estacion <id> conectada a la torre, use_count = <torre.use_count()>".
// - void asignarDron(std::unique_ptr<Dron> dron): usa std::move para
//   transferir "dron" a dronAsignado, llama torre->registrarDespacho(), e
//   imprime "Estacion <id> recibe el dron <id del dron>".
// - std::unique_ptr<Dron> liberarDron(): imprime "Estacion <id> libera su
//   dron" y devuelve dronAsignado movido con std::move (dronAsignado queda
//   en nullptr).
// - bool tieneDron(): true si dronAsignado no es nullptr.
// - Dron* verDron(): devuelve el puntero crudo con .get(), sin ceder la
//   propiedad.

class Estacion {
private:
    int idEstacion;
    unique_ptr<Dron> dronAsignado;
    shared_ptr<TorreControl> torre;

public:
    Estacion(int id, shared_ptr<TorreControl> torreCompartida) {
        idEstacion = id;
        torre = torreCompartida;
        cout << "Estacion " << idEstacion << " conectada a la torre, use_count = " << torre.use_count() << endl;}

    void asignarDron(unique_ptr<Dron> dron) {
        dronAsignado = move(dron);
        torre->registrarDespacho();
        cout << "Estacion " << idEstacion << " recibe el dron " << dronAsignado->getId() << endl;}

    unique_ptr<Dron> liberarDron() {
        cout << "Estacion " << idEstacion << " libera su dron" << endl;
        return move(dronAsignado);}

    bool tieneDron() {return dronAsignado != nullptr;}

    Dron* verDron() {return dronAsignado.get();}
};

int main() {
    // Demostracion directa de RAII + move semantics sobre RegistroVuelo,
    // independiente de cualquier smart pointer: mueve el objeto por valor.
    RegistroVuelo registroTemporal;
    registroTemporal.agregar(999.0);

    // Crear el registro final moviendo el registro temporal a registroFinal
    RegistroVuelo registroFinal(move(registroTemporal));
    cout << "registroFinal.getAltura(0): " << registroFinal.getAltura(0) << endl;
    cout << "registroTemporal tras moverlo: ";
    registroTemporal.getAltura(0);

    // Crear la primera torre de control como un puntero compartido
    auto torre = make_shared<TorreControl>(0);
    cout << "use_count inicial: " << torre.use_count() << endl;

    Estacion base1(1, torre);
    Estacion base2(2, torre);

    cout << "use_count tras conectar 2 estaciones: " << torre.use_count() << endl;

    // Crear dron1 como un puntero unico con los valores (101, 80.0)
    auto dron1 = make_unique<Dron>(101, 80.0);

    // Realizar un vuelo con el dron con a una altitud de 120 y un consumo de bateria de 15
    // TODO
    dron1->realizarVuelo(120.0, 15.0);

    // Asignar dron1 a la base1, moviendo dron1 
    // TODO
    base1.asignarDron(move(dron1));

    if (base1.tieneDron()) {
        base1.verDron()->realizarVuelo(150.0, 20.0);
        cout << "Altitud registrada [0]: " << base1.verDron()->getAltitudRegistrada(0) << endl;
        cout << "Altitud registrada [1]: " << base1.verDron()->getAltitudRegistrada(1) << endl;}

    // Liberar el dron de base1, el dron liberado luego va a ser transferido a la base 2
    // TODO
    auto dronTransferido = base1.liberarDron();
    cout << "base1 tiene dron tras liberar: " << base1.tieneDron() << endl;

    // Asignar el dron transferido a la base2
    base2.asignarDron(move(dronTransferido));

    if (base2.tieneDron()) {
        base2.verDron()->realizarVuelo(100.0, 10.0);
        cout << "Carga restante en base2: " << base2.verDron()->getCargaActual() << endl;
        cout << "Altitud registrada [0] tras la transferencia: "<< base2.verDron()->getAltitudRegistrada(0) << endl;}

        cout << "Total despachos registrados por la torre: " << torre->getTotalDespachos() << endl;

    return 0;
}