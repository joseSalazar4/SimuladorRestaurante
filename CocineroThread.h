#ifndef COCINEROTHREAD_H
#define COCINEROTHREAD_H

#include <QtCore>
#include <QLabel>
#include"Cocinero.h"
struct CocineroThread : public QThread{

    QLabel * imagenChef;
    Cocinero * cocinero;
    bool pausa, activo;
    CocineroThread();

    void run();
    void pausar();
    void continuar();
};

#endif // COCINEROTHREAD_H
