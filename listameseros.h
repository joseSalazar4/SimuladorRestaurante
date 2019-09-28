#ifndef LISTAMESEROS_H
#define LISTAMESEROS_H

#include"meserothread.h"

class ListaMeseros
{
public:
    Mesero * primerNodo, *ultimoNodo;
    int largo = 0;

    ListaMeseros(){
        primerNodo = nullptr;
    }

    bool estaVacia();
    void insertarFinal(int cantMesas);
    void insertarFinal(Mesero * meserito);
    void activarMeseros(Mesero * mesero[20]);
};

#endif // LISTAMESEROS_H
