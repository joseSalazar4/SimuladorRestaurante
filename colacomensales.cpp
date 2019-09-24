#include "colacomensales.h"

void ColaComensal::encolar (ListaComensales * dato)
{
if (vacia())
         frente = dato;
      else
      {
            ListaComensales * actual = frente;
            while (actual->siguiente != nullptr)
                          actual = actual->siguienteLista;

            actual->siguienteLista = dato;
        }
}


ListaComensales* ColaComensal::desencolar(void)
{
      if (vacia())
      {
         return nullptr;
      }
      else
      {
          ListaComensales * borrado = frente;
          frente = frente->siguienteLista;
          borrado->siguiente = nullptr;
          return borrado;
      }
}

bool ColaComensal::vacia ()
{
     if (frente == nullptr)
        return true;
     else
         return false;
}


ListaComensales * ColaComensal::verFrente()
{
      return frente;
}

