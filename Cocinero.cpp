#include "Cocinero.h"


Plato * Cocinero::recogerPedido(){
    if(!cocina->vacia()){
        Plato * plato = cocina->desencolar()->plato;
        return plato;
    }
}

void Cocinero::colocarOrdenLista(Plato * plato){
    Solicitud * sol = new Solicitud(,plato); //hielp
    sol->plato = plato;
    cocina->encolar(sol);
}


