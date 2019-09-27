#ifndef MESEROTHREAD_H
#define MESEROTHREAD_H

#include <QtCore>
#include <QLabel>
#include "mesero.h"

class MeseroThread: public QThread
{
public:
    MeseroThread * siguiente, * anterior;
    Mesero * mesero;
    QLabel * etiqueta;
    bool pausa, activo;
    MeseroThread();

    void __init__(Mesero*);

    void run();
    void pausar();
    void continuar();
    QSemaphore semaforo;
};

#endif // MESEROTHREAD_H
