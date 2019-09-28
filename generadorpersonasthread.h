#ifndef GENERADORPERSONASTHREAD_H
#define GENERADORPERSONASTHREAD_H

#include "qmutex.h"
#include "qthread.h"
#include "QRandomGenerator"
#include "manejadorcomensales.h"
class GeneradorPersonasThread : public QThread
{

public:
    int tiempoGeneracion1,tiempoGeneracion, cantidadGenerada;

    QMutex * mutexManejador;
    bool pausa = false, activo = true;
    //QLabel * etiqueta;
    ManejadorComensales * manejadorComensales;
    GeneradorPersonasThread();

    void run();
    void pausar();
    void continuar();
    int generadorNumRandom(int rango1);
    int generadorNumRandom(int rango1, int rango2);
    ListaComensales * generarPersonas(int personasCreadas);
    void __init__(ManejadorComensales * manejador, QMutex *);
};

#endif // GENERADORPERSONASTHREAD_H
