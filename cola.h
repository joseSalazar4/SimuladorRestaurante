#ifndef COLA_H
#define COLA_H

#include "Solicitud.h"
#include "iostream"

using namespace std;

struct Cola {
       // solo con pN es suficiente
       Solicitud * frente;

       Cola()
       {
            frente = nullptr;
       }

       // encabezados de funcion
       void encolar (Solicitud * dato);
       Solicitud * desencolar ();
       Solicitud * verFrente();
       bool vacia();
       void imprimir();
};

#endif // COLA_H
