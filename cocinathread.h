#ifndef COCINATHREAD_H
#define COCINATHREAD_H

#include <QtCore>
#include <QtWidgets/QLabel>
#include"cocina.h"

struct CocinaThread : public QThread{
    Cocina * cocina;
    bool pausa, activo;
    QLabel * imagenChef;
    QMutex * mutexCocina;
    unsigned int tiempoSleep, tiempoRestante;
    Cocinero * cocinero1, * cocinero2, * cocinero3;

    CocinaThread();

    void run();
    void pausar();
    void continuar();
    void cocinar(Plato * plato);
    Cocinero * buscarCocineroDisponible();
    void __init__(QMutex *,Cocina *);
    void establecerSleep(unsigned int nuevoTemp);
};

#endif // COCINATHREAD_H
