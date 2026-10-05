#include <iostream>
#include <memory>
#include <utility>

// ---------- Bateria: ya la conoces (encapsulacion, invariante con setter que devuelve bool) ----------
class Bateria {
private:
    double capacidadMax;
    double cargaActual;

public:
    Bateria() {
        capacidadMax = 100.0;
        cargaActual = 100.0;
    }

    bool setCapacidad(double nuevaCapacidad) {
        if (nuevaCapacidad <= 0) {
            return false;
        }
        capacidadMax = nuevaCapacidad;
        cargaActual = nuevaCapacidad;
        return true;
    }

    bool descargar(double cantidad) {
        if (cantidad > cargaActual) {
            return false;
        }
        cargaActual = cargaActual - cantidad;
        return true;
    }

    void recargar() {
        cargaActual = capacidadMax;
    }

    double getCargaActual() {
        return cargaActual;
    }
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
    RegistroVuelo(){ 
        capacidad = 10;
        siguiente = 0;
        alturas = new double[capacidad];

        std::cout<<"Registro vuelo creado, capacidad 10"<<std::endl;
    }

    void agregar(double altura){
        if(siguiente < capacidad){
            alturas[siguiente] = altura;
            siguiente++;
        }
    }

    double getAltura(int indice){
        if (alturas == nullptr){
            std::cout<<"Registro vacio (fue movido)"<<std::endl;
            return 0.0;
        }
        return alturas[indice];
    }

    RegistroVuelo(RegistroVuelo&& otro) noexcept : siguiente(otro.siguiente), capacidad(otro.capacidad){
        alturas = otro.alturas;
        capacidad = otro.capacidad;
        siguiente = otro.siguiente;

        otro.alturas = nullptr;
        otro.capacidad = 0;
        otro.siguiente = 0;

    }

    RegistroVuelo& operator = (RegistroVuelo&& otro) noexcept{
        if(this != &otro){
            delete[] alturas;
            alturas = otro.alturas;
            capacidad = otro.capacidad;
            siguiente = otro.siguiente;

            otro.alturas = nullptr;
            otro.capacidad = 0;
            otro.siguiente = 0;
        }
        return *this;
    }

    ~RegistroVuelo(){
        delete[] alturas;
        std::cout<<"Destruyendo registro de vuelo (capacidad "<<capacidad<<")"<<std::endl;
    }


};

// ---------- Aeronave: ya la conoces (base de una jerarquia con herencia publica) ----------
class Aeronave {
private:
    int id;
    double altitud;

public:
    Aeronave() {
        id = 0;
        altitud = 0.0;
    }

    void setId(int nuevoId) {
        id = nuevoId;
    }

    int getId() {
        return id;
    }

    bool despegar(double altitudCrucero) {
        if (altitudCrucero <= 0) {
            return false;
        }
        altitud = altitudCrucero;
        std::cout << "Aeronave " << id << " despega a " << altitud << " metros" << std::endl;
        return true;
    }

    void aterrizar() {
        altitud = 0.0;
        std::cout << "Aeronave " << id << " aterriza" << std::endl;
    }

    double getAltitud() {
        return altitud;
    }
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
class Dron: public Aeronave{
    private:
    Bateria bateria;
    RegistroVuelo registro;

    public:
    Dron(int id,double capacidadBateria){
        setId(id);
        bateria.setCapacidad(capacidadBateria);
        bateria.recargar();
    }

    bool puedeDespegar(double consumoEstidamo){
        if(bateria.getCargaActual() >= consumoEstidamo){
            return true;
        }
        return false;
    }

    bool realizarVuelo(double altitudCrucero, double consumoBateria){
        if(!puedeDespegar(consumoBateria)){
            std::cout<<"Dron "<<getId()<<" no tiene carga suficiente"<<std::endl;
            return false;
        }
        despegar(altitudCrucero);
        registro.agregar(altitudCrucero);
        bateria.descargar(consumoBateria);
        aterrizar();
        return true;
    }

    double getAlturaRegistrada(int indice){
        return registro.getAltura(indice);
    }

    double getCargaActual(){
        return bateria.getCargaActual();
    }



};

// ---------- TorreControl: ya la conoces (recurso que varias Estacion van a compartir) ----------
class TorreControl {
private:
    int totalDespachos;

public:
    TorreControl() {
        totalDespachos = 0;
        std::cout << "Torre de control creada" << std::endl;
    }

    void registrarDespacho() {
        totalDespachos = totalDespachos + 1;
    }

    int getTotalDespachos() {
        return totalDespachos;
    }

    ~TorreControl() {
        std::cout << "Destruyendo torre de control (" << totalDespachos << " despachos)" << std::endl;
    }
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
    std::unique_ptr<Dron> dronAsignado;
    std::shared_ptr<TorreControl> torre;
    public:
    Estacion(int id, std::shared_ptr<TorreControl> TorreCompartida){
        idEstacion = id;
        torre = TorreCompartida;
        std::cout<<"Estacion "<<idEstacion<<" conectada a la torre, "<<torre.use_count()<<std::endl;

    }
    void asignarDron(std::unique_ptr<Dron> dron){
        dronAsignado = std::move(dron);
        torre -> registrarDespacho();
        std::cout<<"Estacion "<<idEstacion<<" recibe el dron "<< dronAsignado->getId()<<std::endl;
    }
    std::unique_ptr<Dron> liberarDron(){
        std::cout << "Estacion " << idEstacion << " libera su dron" << std::endl;
        return std::move(dronAsignado);

    }

    bool tieneDron(){
        if(dronAsignado != nullptr){
            return true;
        }
        return false;
    }
    Dron* verDron(){
        return dronAsignado.get();
    }

};

int main() {
    // Demostracion directa de RAII + move semantics sobre RegistroVuelo,
    // independiente de cualquier smart pointer: mueve el objeto por valor.
    RegistroVuelo registroTemporal;
    registroTemporal.agregar(999.0);

    // Crear el registro final moviendo el registro temporal a registroFinal
    RegistroVuelo registroFinal(std::move(registroTemporal));
    std::cout << "registroFinal.getAltura(0): " << registroFinal.getAltura(0) << std::endl;
    std::cout << "registroTemporal tras moverlo: ";
    registroTemporal.getAltura(0);

    // Crear la primera torre de control como un puntero compartido
    auto torre = std::make_shared<TorreControl>();
    std::cout << "use_count inicial: " << torre.use_count() << std::endl;  // TODO: Contar cuantos punteros a memoria hay en torre 

    Estacion base1(1, torre);
    Estacion base2(2, torre);

    std::cout << "use_count tras conectar 2 estaciones: " <<torre.use_count() <<std::endl; // TODO: Contar cuantos punteros a memoria hay en torre 

    // Crear dron1 como un puntero unico con los valores (101, 80.0)
    auto dron1 = std::make_unique<Dron>(101, 80.0);// TODO

    // Realizar un vuelo con el dron con a una altitud de 120 y un consumo de bateria de 15
    // TODO
    dron1->realizarVuelo(120.0, 15.0);
    
    // Asignar dron1 a la base1, moviendo dron1 
    // TODO
    base1.asignarDron(std::move(dron1));

    if (base1.tieneDron()) {
        base1.verDron()->realizarVuelo(150.0, 20.0);
        std::cout << "Altitud registrada [0]: " << base1.verDron()->getAlturaRegistrada(0) << std::endl;
        std::cout << "Altitud registrada [1]: " << base1.verDron()->getAlturaRegistrada(1) << std::endl;
    }

    // Liberar el dron de base1, el dron liberado luego va a ser transferido a la base 2
    // TODO
    auto dronTransferido = base1.liberarDron();
    std::cout << "base1 tiene dron tras liberar: " << base1.tieneDron() << std::endl;

    // Asignar el dron transferido a la base2
    base2.asignarDron(std::move(dronTransferido));// TODO);

    if (base2.tieneDron()) {
        base2.verDron()->realizarVuelo(100.0, 10.0);
        std::cout << "Carga restante en base2: " << base2.verDron()->getCargaActual() << std::endl;
        std::cout << "Altitud registrada [0] tras la transferencia: "
                   << base2.verDron()->getAlturaRegistrada(0) << std::endl;
    }

    std::cout << "Total despachos registrados por la torre: " << torre->getTotalDespachos() << std::endl;

    return 0;
}
