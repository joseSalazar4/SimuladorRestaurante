#ifndef MESA_H
#define MESA_H

#include <qstring.h>
#include"pila.h"
#include "listacomensales.h"
struct Mesa
{
    QString ID;
    short ocupada;          //1 es Ocupada 0 es disponible -1 no está disponible del todo
    int tipoPedido;       //1 Entrada 2 Plato fuerte 3 postre 4 cuenta
    //Mesero * meseroActivo;
    Pila * pilaPlatosSucios;
    QLabel * imagen, * numOrden;
    QVector<QLabel*> arrayComensales;
    bool pedirAsistencia = true;
    Mesa * siguiente=nullptr, * anterior=nullptr;
    ListaComensales * listaComensales;

    Mesa(QString _id){
        ID = _id;
        pilaPlatosSucios = new Pila();
        listaComensales = new ListaComensales();
    }

    void vaciarMesa();
    bool estaOcupada();
    bool comensalesTerminaron();
};

#endif // MESA_H
