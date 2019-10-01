#ifndef COCINEROTHREAD_H
#define COCINEROTHREAD_H

#include <QtWidgets/QLabel>
#include"cocina.h"

struct CocineroThread : public QThread{
    QMutex * mutex;
    Cocina * cocina;
    bool pausa, activo;
    Cocinero * cocinero;
    unsigned int tiempoSleep;
    QLabel * imagenChef, * tiempoRestante;

    CocineroThread(){}

    void run();
    void pausar();
    void continuar();
    void cocinar(Plato * plato);
    void __init__(QMutex *, QLabel *, Cocinero *, Cocina *);
    void establecerSleep(unsigned int nuevoTemp);
};

#endif // COCINEROTHREAD_H
