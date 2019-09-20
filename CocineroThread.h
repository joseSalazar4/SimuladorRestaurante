#ifndef COCINEROTHREAD_H
#define COCINEROTHREAD_H

#include <QtCore>
#include <QLabel>
#include"Cocinero.h"

struct CocineroThread : public QThread{

    bool pausa, activo;
    QLabel * imagenChef;
    Cocinero * cocinero;
    unsigned int tiempoSleep;

    CocineroThread();

    void run();
    void pausar();
    void continuar();
    void cocinar(Plato * plato);
    void establecerSleep(unsigned int nuevoTemp);
};

#endif // COCINEROTHREAD_H
