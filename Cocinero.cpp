#include "Cocinero.h"


Solicitud * Cocinero::colocarOrdenLista(Plato * plato){
    Solicitud * sol = new Solicitud(1,3,plato);
    sol->plato = plato;
    return sol;
}


