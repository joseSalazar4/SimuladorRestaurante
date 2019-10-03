#ifndef COLA_H
#define COLA_H

#include "iostream"
#include "listasolicitudes.h"

using namespace std;

struct Cola {
        int largo;
        ListaSolicitudes * frente;

       Cola(){
            frente = nullptr;
            largo = 0;
       }

       bool vacia();
       void imprimir();
       ListaSolicitudes * verFrente();
       ListaSolicitudes * desencolar ();
       void encolar (ListaSolicitudes * dato);
};

#endif // COLA_H
