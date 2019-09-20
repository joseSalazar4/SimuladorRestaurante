#ifndef MESA_H
#define MESA_H

#include <qstring.h>
#include "listacomensales.h"
struct Mesa
{
    QString ID;
    int ocupada;          //1 es Ocupada 0 es disponible -1 no está disponible del todo
    int tipoPedido;       //1 Entrada 2 Plato fuerte 3 postre 4 cuenta
    Mesero * meseroActivo;
    bool pedirAsistencia = true;
    Mesa * siguiente, * anterior;
    ListaComensales * listaComensales;

    Mesa(QString _id, Mesero * mesero){
        ID = _id;
        meseroActivo = mesero;
        listaComensales = new ListaComensales();
    }
    void insertarComensales(QString);
    bool estaOcupada();
};

#endif // MESA_H
