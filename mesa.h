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
    QLabel * imagen;
    Pila * pilaPlatosSucios;
    bool pedirAsistencia = true;
    QVector<QLabel*> arrayComensales;
    ListaComensales * listaComensales;
    QMutex * arrayQmutex[6];
    Mesa * siguiente=nullptr, * anterior=nullptr;

    Mesa(QString _id){
        ID = _id;
        pilaPlatosSucios = new Pila();
        listaComensales = new ListaComensales();
        for(int i=0;i<6;i++){
            QMutex * nuevo = new QMutex() ;
            arrayQmutex[i] = nuevo;
        }
    }

    void vaciarMesa();
    bool estaOcupada();
    bool comensalesTerminaron();
};

#endif // MESA_H
