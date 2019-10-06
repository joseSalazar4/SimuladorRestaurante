
#include "cola.h"
void Cola::encolar (ListaSolicitudes * dato){
    if (vacia()){
        frente = dato;
        largo++;
    }
    else
    {
        ListaSolicitudes * actual = frente;
        while (actual->siguienteLista != nullptr)
            actual = actual->siguienteLista;
        actual->siguienteLista = dato;
        largo++;
    }
}


ListaSolicitudes * Cola::desencolar()
{
    if (vacia())
    {
        return nullptr;
    }
    else
    {
        ListaSolicitudes * borrado = frente;
        frente = frente->siguienteLista;
        borrado->siguienteLista = nullptr;
        return borrado;
    }
}

bool Cola::vacia ()
{
    if (frente == nullptr)
        return true;
    else
        return false;
}


ListaSolicitudes * Cola::verFrente()
{
    return frente;
}

