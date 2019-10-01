#ifndef LISTAMESAS_H
#define LISTAMESAS_H

#include "mesa.h"

struct ListaMesas
{
    int largo = 0;
    Mesa  * primerNodo, * ultimoNodo;
    ListaMesas(){
        primerNodo = ultimoNodo = nullptr;
    }

    bool estaVacia();
    Mesa * buscarDisponibilidad();
    void vaciarMesa();
    void insertarFinal(QString id);
    void insertarFinal(Mesa * mesita);
};

#endif // LISTAMESAS_H
