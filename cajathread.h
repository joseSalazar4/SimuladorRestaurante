#ifndef CAJATHREAD_H
#define CAJATHREAD_H


#include <QtCore>
#include <QLabel>
#include"caja.h"

struct CajaThread : public QThread{

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
    void __init__(QLabel * _etiqueta, Caja * _mesero);
};




#endif // CAJATHREAD_H
