#ifndef LISTACOMENSALES_H
#define LISTACOMENSALES_H


#include "comensalthread.h"

struct ListaComensales
{
    int largo, id;
    ComensalThread  * primerNodo, * ultimoNodo;
    ListaComensales * siguienteLista=nullptr, * primerLista=nullptr, *listanterior=nullptr;
    ListaComensales(){
        primerNodo = ultimoNodo = nullptr;
        largo = 0;
    }

    void vaciar();
    bool estaVacia();
    void borrarFinal();
    void insertarFinal(ComensalThread * cm);
};

#endif // LISTACOMENSALES_H
