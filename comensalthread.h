#ifndef COMENSALTHREAD_H
#define COMENSALTHREAD_H
#include "qthread.h"
#include "qmutex.h"
#include "qlabel.h"
#include "comensal.h"
class ComensalThread: public QThread
{
public:
    bool pausa, activo;
    Comensal * comensal;
    QMutex * mutexComensal;
    QLabel * imagenComensal;
    unsigned int tiempoSleep;
    ComensalThread * siguiente, * anterior;


    ComensalThread(){
        siguiente = anterior = nullptr;
        activo = true;
        pausa = false;
    }

    //TODO: FINALIZAR La construccion de esto y meterlo en ell restaurante.h con el generador de personas y en mesas. sueno
    void run();
    void pausar();
    void continuar();
    Plato * comer(Plato *);
    void __init__(QMutex *, QLabel *, Comensal *);
};
#endif // COMENSALTHREAD_H
