#ifndef LAVAPLATOS_H
#define LAVAPLATOS_H

#include "solicitud.h"

struct Lavaplatos
{
    Solicitud * frente;
    int platosLavados;

    Lavaplatos(){
        frente = nullptr;
        platosLavados = 0;
    }
    void encolar (Solicitud * dato);
    Solicitud * desencolar ();
    Solicitud * verFrente();
    bool vacia();

};

#endif // LAVAPLATOS_H
