#ifndef GENERADORPERSONASTHREAD_H
#define GENERADORPERSONASTHREAD_H

#include "qthread.h"
#include "manejadorcomensales.h"
class GeneradorPersonasThread : public QThread
{

public:
    int tiempoGeneracion1,tiempoGeneracion, cantidadGenerada;

    QSemaphore semaforo; //
    bool pausa = false, activo = true;
    //QLabel * etiqueta;
    ManejadorComensales * manejadorComensales;
    GeneradorPersonasThread();

    void __init__();
    void run();
    void pausar();
    void continuar();
    int generadorNumRandom(int rango1);
    ListaComensales * generarPersonas();
    int generadorNumRandom(int rango1, int rango2);
};

#endif // GENERADORPERSONASTHREAD_H
