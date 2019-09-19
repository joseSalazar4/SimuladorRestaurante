#include "Cocinero.h"

Plato * Cocinero::cocinar(Plato * plato){
    int tiempoCocinado = 0;
    if(plato){
        while(tiempoCocinado<plato->tiempoCocina){

        }
        tiempoCocinado = 0;
        colocarOrdenLista(plato);
    }
}

void Cocinero::recogerPedido(){
    if(!cocina->vacia()){
        Plato * plato = cocina->desencolar()->plato;
        cocinar(plato);
    }
    else:
        return nullptr;


}

void Cocinero::colocarOrdenLista(Plato * plato){
    Solicitud * sol = new Solicitud();
    sol->plato = plato;
    pilaOrdenesListas->push(sol);
}

