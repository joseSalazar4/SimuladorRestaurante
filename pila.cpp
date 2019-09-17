
#include "pila.h"


void Pila::push (Solicitud * dato)
{
     if (empty ())
     {
         tope = new Solicitud();
     }
     else
     {
         Solicitud * nuevo = new Solicitud();
         nuevo->siguiente = tope;
         tope = nuevo;
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

Solicitud * Pila::peek()
{
     return tope;
     }

