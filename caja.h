#ifndef CAJA_H
#define CAJA_H

#include"solicitud.h"
#include "cola.h"

struct Caja
{
    bool modoCola = true;
    Cola * colaCuentasPorHacer, * colaCuentasHechas;
    Caja(){
        colaCuentasPorHacer = new Cola();
        colaCuentasHechas = new Cola();
    }

    void calcularCuenta();
};

#endif // CAJA_H
