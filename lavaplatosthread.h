#ifndef LAVAPLATOSTHREAD_H
#define LAVAPLATOSTHREAD_H


#include<QtCore>
#include <QLabel>
#include"lavaplatos.h"

struct LavaplatosThread : public QThread
{
    QMutex * mutex;
    Lavaplatos * lavaplatos;
    QLabel * imagenLavanderia;
    bool pausa, activo;
    unsigned int tiempoSleep;

    LavaplatosThread();


    void run();
    void pausar();
    void continuar();
    void lavar(Plato * plato);
    void establecerSleep(unsigned int nuevoTemp);
    void __init__(Lavaplatos * lava , QMutex * mmu);
};

#endif // LAVAPLATOSTHREAD_H
