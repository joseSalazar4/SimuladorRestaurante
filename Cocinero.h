#ifndef COCINERO_H
#define COCINERO_H

#include <QtCore>
#include"cocina.h"
#include "plato.h"

struct Cocinero{
    QString tipoCocinero;
    Cocina * cocina;
    bool activo;

    Cocinero(QString _tipoCocinero) {
        tipoCocinero = _tipoCocinero ;
        activo = true;

    }

    void recogerPedido();
    Plato * cocinar(Plato * plato);
    void colocarOrdenLista(Plato * plato);
};


#endif // COCINERO_H
