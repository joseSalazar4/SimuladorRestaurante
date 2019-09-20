#ifndef LAVAPLATOSTHREAD_H
#define LAVAPLATOSTHREAD_H


#include<QtCore>
#include <QLabel>
#include"lavaplatos.h"

struct LavaplatosThread : public QThread
{
    Lavaplatos * lavaplatos;
    QLabel * imagenLavanderia;
    bool pausa, activo;
    unsigned int tiempoSleep;

    LavaplatosThread();

    void __init__(QLabel*, Lavaplatos*);

    void run();
    void pausar();
    void continuar();
    void lavar(Plato * plato);
    void establecerSleep(unsigned int nuevoTemp);
};

#endif // LAVAPLATOSTHREAD_H
