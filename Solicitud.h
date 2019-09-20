#ifndef SOLICITUD_H
#define SOLICITUD_H

#include "plato.h"
#include "mesero.h"

struct Solicitud {
    Mesa * mesa;
    Plato * plato;
    Mesero * mesero;
    Solicitud * siguiente;
    QString cliente, responsable;
    int destino, tipo, cuenta, accion; //Saber que hacer con esa petición

    Solicitud(int _destino, int _accion){  //La accion debe ser leída por cada "persona" tons mesero lee 1 tons lleva a la cocina yantes de dejarla pone accion = #
                                           //Por lo que el cocinero sabe que debe cocinar, aunque no puede hacer mucho mas que eso o nada mas, pero el mesero
                                          //Puede ir a entregar unos platos listos. Pueden haber solicitudes que al encontrarlas pare de sacar cosas(?) y así si saque todos los platos listo.
        plato = nullptr;
        accion = _accion;
        destino = _destino;
        siguiente = nullptr;
    }
    Solicitud();
    Solicitud(int dest, int accion, Plato * plat);
    Solicitud(int dest, int accion, Plato * plat, Mesero * mesro);

    //Puede que necesite crear mas constructores para simplificar escenarios específicos
};

#endif // SOLICITUD_H

