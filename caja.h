#ifndef CAJA_H
#define CAJA_H

#include"Solicitud.h"

struct Caja
{
    Solicitud * frente;
    Caja(){
        frente = nullptr;
    }
    bool vacia();
    int calcularCuenta();
    Solicitud * verFrente();
    Solicitud * desencolar ();
    void encolar (Solicitud * dato);
};

#endif // CAJA_H
