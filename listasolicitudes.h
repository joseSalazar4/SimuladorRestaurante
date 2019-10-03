#ifndef LISTASOLICITUDES_H
#define LISTASOLICITUDES_H

#include "solicitud.h"

struct ListaSolicitudes {
    int largo;
    Solicitud * primerNodo, *ultimoNodo;
    ListaSolicitudes * siguienteLista= nullptr, *anteriorLista = nullptr;
    ListaSolicitudes(){
        primerNodo = ultimoNodo = nullptr;
        largo = 0;
    }


    bool estaVacia();
    void insertarFinal(Solicitud * mesita);
};

#endif // LISTASOLICITUDES_H
