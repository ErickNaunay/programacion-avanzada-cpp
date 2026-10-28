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
    virtual void enviar() {
        std::cout << "Notificacion generica" << std::endl;
    }

    virtual ~Notificacion() {
        std::cout << "~Notificacion" << std::endl;
    }
};

class NotificacionCorreo : public Notificacion {
private:
    int idUsuario;

public:
    NotificacionCorreo(int nuevoId) {
        idUsuario = nuevoId;
    }

    void enviar() override {
        std::cout << "Correo enviado al usuario "
                  << idUsuario
                  << std::endl;
    }

    ~NotificacionCorreo() override {
        std::cout << "~NotificacionCorreo" << std::endl;
    }
};

class NotificacionSMS : public Notificacion {
private:
    int telefono;
    std::unique_ptr<int[]> intentos;
    int maxIntentos;

public:
    NotificacionSMS(int nuevoTelefono) {
        telefono = nuevoTelefono;
        maxIntentos = 3;
        intentos = std::make_unique<int[]>(maxIntentos);
    }

    void enviar() override {
        intentos[0] = 1;

        std::cout << "SMS enviado al "
                  << telefono
                  << " (intento "
                  << intentos[0]
                  << " de "
                  << maxIntentos
                  << ")"
                  << std::endl;
    }

    ~NotificacionSMS() override {
        std::cout << "~NotificacionSMS" << std::endl;
    }
};

class NotificacionPush : public Notificacion {
private:
    int idDispositivo;

public:
    NotificacionPush(int nuevoId) {
        idDispositivo = nuevoId;
    }

    void enviar() override {
        std::cout << "Push enviado al dispositivo "
                  << idDispositivo
                  << std::endl;
    }

    ~NotificacionPush() override {
        std::cout << "~NotificacionPush" << std::endl;
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