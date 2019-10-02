#ifndef CAJATHREAD_H
#define CAJATHREAD_H


#include <QtCore>
#include <QtWidgets/QLabel>
#include"caja.h"

struct CajaThread : public QThread{
    QMutex * mutexCaja;
    Caja * caja;
    unsigned int tiempoSleep;
    bool pausa, activo;
    QLabel * imagenCaja;

    CajaThread();
    void run();
    void pausar();
    void continuar();
    Solicitud * entregarCuenta();
    void establecerSleep(unsigned int nuevoTemp);
    void __init__(Caja * ca, QMutex *, QLabel*);
};




#endif // CAJATHREAD_H
