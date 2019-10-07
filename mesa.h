#ifndef MESA_H
#define MESA_H

#include <qstring.h>
#include"pila.h"
#include "listacomensales.h"
struct Mesa
{
    QString ID;
    short numero_mesa;
    short ocupada;          //1 es Ocupada 0 es disponible -1 no está disponible del todo
    QLabel * imagen;
    QMutex * arrayQmutex[6], mutexMesa;
    Pila * pilaPlatosSucios;
    bool SolicitandoAsistencia = true;
    QVector<QLabel*> arrayComensales;
    ListaComensales * listaComensales;
    Mesa * siguiente=nullptr, * anterior=nullptr;
    int tipoPedido, intervaloPostres1,intervaloPostres2, intervaloEnsaladas1, intervaloEnsaladas2, intervaloFuerte1, intervaloFuerte2;       //1 Entrada 2 Plato fuerte 3 postre 4 cuenta

    Mesa(QString _id, short numero){
        ID = _id;
        numero_mesa=numero;
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
