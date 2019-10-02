#ifndef MESEROTHREAD_H
#define MESEROTHREAD_H

#include <QtCore>

#include <QtWidgets/QLabel>

#include "mesero.h"

class MeseroThread: public QThread
{

public:
    Mesero * mesero;
    QLabel * etiqueta;
    bool pausa, activo;
    unsigned int tiempoSleep;
    MeseroThread * siguiente, *anterior;
    QMutex * mutexPasteleria, * mutexCocina, * mutexEnsaladas, * mutexCaja, * mutexLavaplatos, * mutexMesa;
    MeseroThread(){
        siguiente = anterior = nullptr;
        tiempoSleep=5;
    }

    void run();
    void pausar();
    void continuar();
    void colocarOrden();
    void llevarOrdenes();
    void __init__(Mesero*,ListaMesas *, QMutex * pasteleria, QMutex * ensaladas, QMutex * cocina, QMutex * lavaplatos, QMutex * caja, QMutex * mesa);
};

#endif // MESEROTHREAD_H
