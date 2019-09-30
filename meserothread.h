#ifndef MESEROTHREAD_H
#define MESEROTHREAD_H

#include <QtCore>
#include <QLabel>
#include "mesero.h"

class MeseroThread: public QThread
{

public:
    MeseroThread * siguiente, *anterior;
    Mesero * mesero;
    QLabel * etiqueta;
    bool pausa, activo;
    QMutex * mutexPasteleria, * mutexCocina, * mutexEnsaladas, * mutexCaja, * mutexLavaplatos, * mutexMesa;
    MeseroThread(){
        siguiente = anterior = nullptr;
    }

    void run();
    void pausar();
    void continuar();
    void __init__(Mesero*,ListaMesas *, QMutex * pasteleria, QMutex * ensaladas, QMutex * cocina, QMutex * lavaplatos, QMutex * caja, QMutex * mesa);
};

#endif // MESEROTHREAD_H
