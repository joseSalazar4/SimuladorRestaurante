#ifndef CAJA_H
#define CAJA_H

#include"solicitud.h"
#include "cola.h"

struct Caja
{
    Cola * colaCuentasPorHacer, * colaCuentasHechas;
    Caja(){
        colaCuentasPorHacer = new Cola();
        colaCuentasHechas = new Cola();

    }

    int calcularCuenta();
};

#endif // CAJA_H
