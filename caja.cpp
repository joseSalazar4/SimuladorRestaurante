#include "caja.h"

void Caja::encolar (Solicitud * solicitud)
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

int Caja::calcularCuenta(){

}
Solicitud * Caja::desencolar()
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

bool Caja::vacia ()
{
     if (frente == nullptr)
        return true;
     else
         return false;
}


Solicitud * Caja::verFrente()
{
      return frente;
}


