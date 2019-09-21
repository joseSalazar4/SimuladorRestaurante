#ifndef LISTACOMENSALES_H
#define LISTACOMENSALES_H


#include "Comensal.h"

struct ListaComensales
{
    int largo;
    Comensal * siguiente, * primerNodo, * ultimoNodo,* anterior;
    ListaComensales(){
        primerNodo = ultimoNodo = nullptr;
    }
    void insertarFinal(QString nombre);
    bool estaVacia();
};

#endif // LISTACOMENSALES_H
