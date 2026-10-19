#include <iostream>
#include <memory>

// Salida esperada:
// Correo enviado al usuario 101
// SMS enviado al 5551234 (intento 1 de 3)
// Push enviado al dispositivo 7
// Fin del envio
// ~NotificacionPush
// ~Notificacion
// ~NotificacionSMS
// ~Notificacion
// ~NotificacionCorreo
// ~Notificacion

class Notificacion {
    public:
        // TODO: este metodo debe poder redefinirse en cada derivada y
        // ejecutarse segun el tipo real del objeto.
        virtual void enviar() {
            std::cout << "Notificacion generica" << std::endl;
        }

        // TODO: los objetos de esta jerarquia se destruyen a traves de un
        // std::unique_ptr<Notificacion>. Decide que le falta a este
        // destructor para que tambien corra el destructor de la derivada.
        virtual ~Notificacion() {
            std::cout << "~Notificacion" << std::endl;
        }
};

// TODO: completa NotificacionCorreo (hereda publicamente de Notificacion):
// - Atributo privado: int idUsuario.
// - Constructor NotificacionCorreo(int nuevoId).
// - enviar(), marcado con override: imprime
//   "Correo enviado al usuario <idUsuario>".
// - Destructor, marcado con override: imprime "~NotificacionCorreo".
class NotificacionCorreo: public Notificacion {
    private:
    int idUsuario;

    public:
    NotificacionCorreo(int nuevoId){
        idUsuario=nuevoId;
    }

    void enviar() override{
        std::cout<<"Correo enviado al usuario "<<idUsuario<<std::endl;
    }

    ~NotificacionCorreo() override{
        std::cout<<"~NotificacionCorreo"<<std::endl;
    }
};

// TODO: completa NotificacionSMS (hereda publicamente de Notificacion):
// - Atributos privados: int telefono, std::unique_ptr<int[]> intentos,
//   int maxIntentos.
// - Constructor NotificacionSMS(int nuevoTelefono): guarda el telefono,
//   fija maxIntentos en 3 y crea "intentos" con
//   std::make_unique<int[]>(maxIntentos).
// - enviar(), con override: guarda 1 en intentos[0] e imprime
//   "SMS enviado al <telefono> (intento <intentos[0]> de <maxIntentos>)".
// - Destructor, con override: imprime "~NotificacionSMS".
class NotificacionSMS: public Notificacion{
    private:
    int telefono;
    std::unique_ptr<int[]> intentos;
    int maxIntentos;
    public:
    NotificacionSMS(int nuevotelefono){
        telefono=nuevotelefono;
        maxIntentos=3;
        intentos=std::make_unique<int[]>(maxIntentos);
    }

    void enviar() override{
        intentos[0]=1;
        std::cout<<"SMS enviado al "<<telefono<<" (intento "<<intentos[0]<<" de "<<maxIntentos<<") "<<std::endl;
    }

    ~NotificacionSMS() override{
        std::cout<<"~NotificacionSMS"<<std::endl;
    }
};

// TODO: completa NotificacionPush (hereda publicamente de Notificacion):
// - Atributo privado: int idDispositivo.
// - Constructor NotificacionPush(int nuevoId).
// - enviar(), con override: imprime "Push enviado al dispositivo <idDispositivo>".
// - Destructor, con override: imprime "~NotificacionPush".
class NotificacionPush: public Notificacion {
    private:
    int idDispositivo;

    public:
    NotificacionPush(int nuevoid){
        idDispositivo=nuevoid;
    }

    void enviar() override{
        std::cout<<"Push enviado al dispositivo "<<idDispositivo<<std::endl;
    }

    ~NotificacionPush() override{
        std::cout<<"~NotificacionPush"<<std::endl;
    }
};

int main() {
    std::unique_ptr<Notificacion> cola[3];
    cola[0] = std::make_unique<NotificacionCorreo>(101);
    cola[1] = std::make_unique<NotificacionSMS>(5551234);
    cola[2] = std::make_unique<NotificacionPush>(7);

    for (int i = 0; i < 3; i++) {
        cola[i]->enviar();
    }

    std::cout << "Fin del envio" << std::endl;
    return 0;
}
