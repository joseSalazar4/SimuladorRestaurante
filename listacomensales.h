#ifndef LISTACOMENSALES_H
#define LISTACOMENSALES_H


#include "Comensal.h"

struct ListaComensales
{
    int largo, id;
    Comensal * siguiente, * primerNodo, * ultimoNodo,* anterior;
    ListaComensales * siguienteLista, * primerLista, *listaAnterior;
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
