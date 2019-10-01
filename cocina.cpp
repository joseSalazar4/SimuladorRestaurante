#include "cocina.h"


void Cocina::encolar (Solicitud * solicitud)
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

Solicitud * Cocina::desencolar()
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

bool Cocina::vacia ()
{
     if (frente == nullptr)
        return true;
     else
         return false;
}


Solicitud * Cocina::verFrente()
{
      return frente;
}

