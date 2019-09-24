#ifndef LISTAMESEROS_H
#define LISTAMESEROS_H

#include"meserothread.h"

class ListaMeseros
{
public:
    MeseroThread * primerNodo, *ultimoNodo,* siguiente,* anterior;
    int largo = 0;
    ListaMeseros(){
        primerNodo = nullptr;
    }

    bool estaVacia();
    void insertarFinal();
    void activarMeseros(Mesero * mesero[20]);
    void insertarFinal(MeseroThread * meserito);
};

#endif // LISTAMESEROS_H
