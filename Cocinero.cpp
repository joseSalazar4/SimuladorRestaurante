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
    if(pilaOrdenes->peek()!=nullptr){
        Plato * plato = pilaOrdenes->pop()->plato;
        cocinar(plato);
    }

}

void Cocinero::colocarOrdenLista(Plato * plato){
    Solicitud * sol = new Solicitud();
    sol->plato = plato;
    pilaOrdenesListas->push(sol);
}

