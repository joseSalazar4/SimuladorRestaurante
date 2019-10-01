#ifndef LISTACOMENSALES_H
#define LISTACOMENSALES_H


#include "comensal.h"

struct ListaComensales
{
    int largo, id;
    Comensal * siguiente, * primerNodo, * ultimoNodo,* anterior;
    ListaComensales * siguienteLista=nullptr, * primerLista=nullptr, *listanterior=nullptr;
    ListaComensales(){
        primerNodo = ultimoNodo = nullptr;
        largo = 0;
    }

    void vaciar();
    bool estaVacia();
    void borrarFinal();
    void insertarFinal(Comensal * cm);
    void insertarFinal(QString nombre);
};

#endif // LISTACOMENSALES_H
