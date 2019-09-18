#ifndef LAVAPLATOS_H
#define LAVAPLATOS_H

#include "Solicitud.h"

struct Lavaplatos
{
    Solicitud * frente;
    Lavaplatos(){
        frente = nullptr;
    }
    void encolar (Solicitud * dato);
    Solicitud * desencolar ();
    Solicitud * verFrente();
    bool vacia();

};

#endif // LAVAPLATOS_H
