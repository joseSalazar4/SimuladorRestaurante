#ifndef SOLICITUD_H
#define SOLICITUD_H

#include "plato.h"

struct Solicitud {
    int destino, tipo, cuenta, accion; //Saber que hacer con esa petición
    Solicitud * siguiente;
    Plato * plato;

    Solicitud(int _destino, int _accion){  //La accion debe ser leída por cada "persona" tons mesero lee 1 tons lleva a la cocina yantes de dejarla pone accion = #
                                           //Por lo que el cocinero sabe que debe cocinar, aunque no puede hacer mucho mas que eso o nada mas, pero el mesero
                                           //Puede ir a entregar unos platos listos. Pueden haber solicitudes que al encontrarlas pare de sacar cosas(?) y así si saque todos los platos listo.
        plato = nullptr;
        accion = _accion;
        destino = _destino;
        siguiente = nullptr;
    }
};

#endif // SOLICITUD_H
