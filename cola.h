#ifndef COLA_H
#define COLA_H

#include "Solicitud.h"

struct Cola {
       // solo con pN es suficiente
       Solicitud * frente;

       Cola()
       {
            frente = nullptr;
       }

       // encabezados de funcion
       void encolar (int dato);
       Solicitud * desencolar (void);
       Solicitud * verFrente(void);
       bool vacia(void);
       void imprimir(void);
};

#endif // COLA_H
