#ifndef LISTAMESAS_H
#define LISTAMESAS_H

#include "mesa.h"

struct ListaMesas
{
    int largo;
    Mesa * siguiente, * primerNodo, * ultimoNodo,* anterior;
    ListaMesas(){
        primerNodo = ultimoNodo = nullptr;
    }

    bool estaVacia();
    void insertarFinal(QString id);
    void insertarFinal(Mesa * mesita);
};

#endif // LISTAMESAS_H
