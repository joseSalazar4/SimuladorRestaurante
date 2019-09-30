#include "colacomensales.h"

void ColaComensal::encolar (ListaComensales * dato){
    if (vacia())
         frente = final = dato;
    else{
        final->siguienteLista = dato;
        final = final->siguienteLista;
    }
}


ListaComensales* ColaComensal::desencolar(){
    ListaComensales * lista = frente;
      if (!vacia()){
          frente = frente->siguienteLista;
          lista->siguienteLista = nullptr;
      }
      return lista;
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

