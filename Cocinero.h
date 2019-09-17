#ifndef COCINERO_H
#define COCINERO_H

#include "pila.h"
#include "plato.h"

struct Cocinero{
    QString tipoCocinero;
    bool activo;
    Pila * pilaOrdenes;
    Pila * pilaOrdenesListas;

    Cocinero() {
        activo = true;
        pilaOrdenes = new Pila();
        pilaOrdenesListas = new Pila();
    }

    Plato * cocinar(Plato * plato);
    void recogerPedido();
    void colocarOrdenLista(Plato * plato);
};


#endif // COCINERO_H
