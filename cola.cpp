
#include "cola.h"
void Cola::encolar (Solicitud * dato)
{
if (vacia())
         frente = new Solicitud();
      else
      {
            Solicitud * actual = frente;
            while (actual->siguiente != nullptr)
                          actual = actual->siguiente;

            actual->siguiente = dato;
        }
}


Solicitud* Cola::desencolar(void)
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

bool Cola::vacia ()
{
     if (frente == nullptr)
        return true;
     else
         return false;
}


Solicitud * Cola::verFrente()
{
      return frente;
}

