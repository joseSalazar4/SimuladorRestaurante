#ifndef COCINEROTHREAD_H
#define COCINEROTHREAD_H

#include <QtCore>
#include <QLabel>
#include"cocina.h"

struct CocineroThread : public QThread{
    QMutex * mutex;
    bool pausa, activo;
    QLabel * imagenChef;
    Cocinero * cocinero;
    Cocina * cocina;
    unsigned int tiempoSleep;

    CocineroThread();

    void run();
    void pausar();
    void continuar();
    void cocinar(Plato * plato);
    void __init__(QMutex *, QLabel *, Cocinero *, Cocina *);
    void establecerSleep(unsigned int nuevoTemp);
};

#endif // COCINEROTHREAD_H
