
#include "cola.h"
void Cola::encolar (Solicitud * dato)
{
if (vacia())
         frente = new Solicitud();
      else
      {
            Solicitud * actual = frente;
            while (actual->siguiente != NULL)
                          actual = actual->siguiente;

            Solicitud * nuevo = new Solicitud (dato);
            actual->siguiente = nuevo;
        }
}


Solicitud* Cola::desencolar(void)
{
      if (vacia())
      {
         return NULL;
      }
      else
      {
          Solicitud* borrado = frente;
          frente = frente->siguiente;
          borrado->siguiente = nullptr;
          return borrado;
      }
}

bool Cola::vacia (void)
{
     if (frente == NULL)
        return true;
     else
         return false;
}


Solicitud * Cola::verFrente()
{
      return frente;
}

