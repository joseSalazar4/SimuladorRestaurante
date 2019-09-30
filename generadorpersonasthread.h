#ifndef GENERADORPERSONASTHREAD_H
#define GENERADORPERSONASTHREAD_H

#include "qmutex.h"
#include "qthread.h"
#include "QRandomGenerator"
#include "manejadorcomensales.h"
#include "qlabel.h"
class GeneradorPersonasThread : public QThread
{

public:
    QLabel * etiqueta;
    QMutex * mutexManejador, * mutexMesas;
    ListaMesas * listaMesas;
    bool pausa = false, activo = true;
    ManejadorComensales * manejadorComensales;
    int tiempoGeneracion1,tiempoGeneracion, cantidadGenerada;
    QString arrayNombres[10] = {"Palpatine" , "Padme" , "Kit Fisto","Anakin", "Obi-Wan", "San Holo", "Sofia", "Luis", "Fiorella", "Jose"};;
    GeneradorPersonasThread();

    void run();
    void pausar();
    void continuar();
    QString generarNombre();
    int generadorNumRandom(int rango1);
    int generadorNumRandom(int rango1, int rango2);
    ListaComensales * generarPersonas(int personasCreadas);
    void __init__(ManejadorComensales * manejador, QMutex *,QMutex * ,int t1, int t2);
};

#endif // GENERADORPERSONASTHREAD_H
