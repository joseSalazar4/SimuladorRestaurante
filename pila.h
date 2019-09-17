#ifndef PILA_H
#define PILA_H

#include <cstdlib>
#include <iostream>

#include "Solicitud.h"
using namespace std;


struct Pila {

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
