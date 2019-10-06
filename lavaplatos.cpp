#include "lavaplatos.h"


void Lavaplatos::encolar (Solicitud * solicitud)
{
    if (vacia())
        frente = new Solicitud();
    else
    {
        Solicitud * actual = frente;
        while (actual->siguiente != nullptr)
            actual = actual->siguiente;

        actual->siguiente = solicitud;
    }
}


Solicitud * Lavaplatos::desencolar()
{
    if (vacia())
    {
        return nullptr;
    }
    else
    {
        Solicitud* borrado = frente;
        frente = frente->siguiente;
        borrado->siguiente = nullptr;
        return borrado;
    }
}

bool Lavaplatos::vacia ()
{
    if (frente == nullptr)
        return true;
    else
        return false;
}


Solicitud * Lavaplatos::verFrente()
{
    return frente;
}

