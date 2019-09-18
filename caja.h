#ifndef CAJA_H
#define CAJA_H

#include"Solicitud.h"

struct Caja
{
    Solicitud * frente;
    Caja(){
        frente = nullptr;
    }
    void encolar (Solicitud * dato);
    Solicitud * desencolar ();
    Solicitud * verFrente();
    bool vacia();
};

#endif // CAJA_H
