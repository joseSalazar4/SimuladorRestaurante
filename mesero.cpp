#include "mesero.h"


void Mesero::pedirOrdenes(Mesa * mesa){
    Comensal * tmp = mesas->primerNodo->listaComensales->primerNodo;

    for(int i =0; (mesa->listaComensales->largo) > i; i++){
        if(tmp!=nullptr){
            if(mesa->tipoPedido == 1)
                tmp->pedirEntrada(tmp->probabilidadPedir);

            else if(mesa->tipoPedido == 2)
                tmp->pedirPlatoFuerte(tmp->probabilidadPedir);

            else if(mesa->tipoPedido == 3){
                tmp->pedirPostre(tmp->probabilidadPedir);
            }
            else{
                tmp->pedirCuenta();
            }
            tmp = tmp->siguiente;
        }
    }
    mesa->tipoPedido++;
}

Mesa * Mesero::revisarMesas(){
    Mesa * tmp = mesas->primerNodo;
    for(int i =0; i<mesas->largo;i++){
        if (tmp->estaOcupada() && tmp->pedirAsistencia){
            return tmp;
        }
        tmp = tmp->siguiente;
    }
    return  nullptr;
}

void Mesero::recibirOrden(Solicitud * sol){
    pilaPeticiones.push(sol);
}
void Mesero::llevarOrdenCocina(){

}
void Mesero::llevarCuenta(){

}
void Mesero::llevarComida(){

}
void Mesero::llevarPlatosALavar(){

}
