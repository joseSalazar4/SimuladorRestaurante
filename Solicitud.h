#ifndef SOLICITUD_H
#define SOLICITUD_H

#include "plato.h"

struct Solicitud {
    int destino, tipo, cuenta, accion; //Saber que hacer con esa petición
    Solicitud * siguiente;
    Plato * plato;

    Solicitud(int _destino, int _accion){
        plato = nullptr;
        accion = _accion;
        destino = _destino;
        siguiente = nullptr;
    }
};

#endif // SOLICITUD_H
