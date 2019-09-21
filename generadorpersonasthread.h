#ifndef GENERADORPERSONASTHREAD_H
#define GENERADORPERSONASTHREAD_H


#include "restaurante.h"
class GeneradorPersonasThread
{

public:
    int tiempoGeneracion;
    ListaComensales * listaComensales;
    GeneradorPersonasThread();

    ListaIngredientes * generarPersonas();
};

#endif // GENERADORPERSONASTHREAD_H
