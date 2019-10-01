#ifndef COCINERO_H
#define COCINERO_H

#include <QtCore>
#include "solicitud.h"
#include "plato.h"

struct Cocinero {
    QString tipoCocinero;
    bool activo, cocinando;

    Cocinero(QString _tipoCocinero) {
        tipoCocinero = _tipoCocinero ;
        activo = true;
        cocinando = false;
    }

    Plato * recogerPedido();
    Solicitud * colocarOrdenLista(Plato * plato);

};


#endif // COCINERO_H
