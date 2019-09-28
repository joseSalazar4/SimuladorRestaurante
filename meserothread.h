#ifndef MESEROTHREAD_H
#define MESEROTHREAD_H

#include <QtCore>
#include <QLabel>
#include "mesero.h"

class MeseroThread: public QThread
{
public:
    Mesero * mesero;
    QLabel * etiqueta;
    bool pausa, activo;
    QMutex * mutexPasteleria, * mutexCocina, * mutexEnsaladas, * mutexCaja, * mutexLavaplatos;
    MeseroThread();

    void run();
    void pausar();
    void continuar();
    void __init__(Mesero*, QMutex * pasteleria, QMutex * ensaladas, QMutex * cocina, QMutex * lavaplatos, QMutex * caja);
};

#endif // MESEROTHREAD_H
