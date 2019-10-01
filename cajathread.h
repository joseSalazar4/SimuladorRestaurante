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
    void __init__(QLabel * _etiqueta, Caja * _mesero, QMutex *);
};




#endif // CAJATHREAD_H
