#ifndef LISTAMESEROTHREADS_H
#define LISTAMESEROTHREADS_H

#include"meserothread.h"

class ListaMeseroThreads
{
public:
    int largo;
    MeseroThread * primerNodo, * ultimoNodo;

    ListaMeseroThreads(){
        primerNodo = ultimoNodo = nullptr;
    }

    bool estaVacia();
    void insertarFinal(MeseroThread * mesita);

};

#endif // LISTAMESEROTHREADS_H
