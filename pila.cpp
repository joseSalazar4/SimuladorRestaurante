
#include "pila.h"


void Pila::push (Solicitud * dato)
{
    if (empty ())
    {
        tope = dato;
        largo++;
    }
    else
    {
        Solicitud * nuevo = dato;
        nuevo->siguiente = tope;
        tope = nuevo;
        largo++;
    }
}


Solicitud* Pila::pop(void)
{
    if (empty())
    {
        return nullptr;
    }
    else
    {
        Solicitud* borrado = tope;
        tope = tope->siguiente;
        borrado->siguiente = nullptr;
        largo--;
        return borrado;
    }
}

bool Pila::empty (void)
{
    if (tope == nullptr)
        return true;
    else
        return false;
}

Solicitud * Pila::peek(){
    return tope;
}

