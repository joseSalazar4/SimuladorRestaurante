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

    void insertarFinal(QString id);
    bool estaVacia();

};

#endif // LISTAMESAS_H
