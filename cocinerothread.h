#ifndef COCINEROTHREAD_H
#define COCINEROTHREAD_H

#include <QtWidgets/QLabel>
#include"cocina.h"

class CocineroThread : public QThread{
public:
    QMutex * mutexCocinero;
    Cocina * cocina;
    bool pausa, activo;
    Cocinero * cocinero;
    unsigned int tiempoSleep;
    QLabel * imagenChef, * infoCocina;

    CocineroThread(){
        activo = true;
        tiempoSleep = 1;
    }

    void run();
    void pausar();
    void continuar();
    void cocinar(Plato * plato, QString nombre , QString mesa);
    void __init__(QMutex *, QLabel *,QLabel *, Cocinero *, Cocina *);
    void establecerSleep(unsigned int nuevoTemp);
};

#endif // COCINEROTHREAD_H
