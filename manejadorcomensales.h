#ifndef MANEJADORCOMENSALES_H
#define MANEJADORCOMENSALES_H

#include "colacomensales.h"
#include "qsemaphore.h"
#include "listamesas.h"

class ManejadorComensales
{
public:
    QSemaphore semaforo;
    int  ultimaMesaUsada;
    ColaComensal * colaClientesEnEspera;

    ManejadorComensales(){
        colaClientesEnEspera = new ColaComensal();

    }

    //cola de clientes y lea RESERVAS QUICK BRO QUICK
};

#endif // MANEJADORCOMENSALES_H
