#ifndef PILA_H
#define PILA_H

#include <cstdlib>
#include <iostream>

#include "solicitud.h"
using namespace std;


struct Pila {
       int largo = 0;
       Solicitud * tope;

       Pila(){
          tope = nullptr;
       }

       bool empty();
       void imprimir();
       Solicitud * pop ();
       Solicitud * peek();
       void push (Solicitud * dato);
};



#endif // PILA_H
