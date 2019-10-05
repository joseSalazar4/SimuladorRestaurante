#ifndef LAVAPLATOSTHREAD_H
#define LAVAPLATOSTHREAD_H


#include<QtCore>
#include <QtWidgets/QLabel>
#include"lavaplatos.h"

struct LavaplatosThread : public QThread
{
    QMutex * mutex;
    bool pausa, activo;
    Lavaplatos * lavaplatos;
    Lavaplatos * inventarioOrdenes;
    unsigned int tiempoSleep;
    QLabel * imagenLavanderia, * lavaplatosInfo ;

    LavaplatosThread();


    void run();
    void pausar();
    void continuar();
    void lavar(Plato * plato);
    void establecerSleep(unsigned int nuevoTemp);
    void __init__(Lavaplatos * lava , QMutex * mmu);
};

#endif // LAVAPLATOSTHREAD_H
