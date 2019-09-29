#include "mesero.h"


void Mesero::pedirOrdenes(Mesa * mesa){
    Comensal * tmp = mesas->primerNodo->listaComensales->primerNodo;

    for(int i =0; (mesa->listaComensales->largo) > i; i++){
        if(tmp!=nullptr){
            if(mesa->tipoPedido == 1){

                Solicitud * nueva = tmp->pedirEntrada(tmp->probabilidadPedir);
                if(nueva){
                    nueva->cliente = tmp->nombre;
                    nueva->numeroMesa = tmp->numeroMesa;
                    tmp->cuentaAPagar+= nueva->plato->precio;
                    colaPeticiones->encolar(nueva);
                }
            }
            else if(mesa->tipoPedido == 2){

                Solicitud * nueva = tmp->pedirPlatoFuerte(tmp->probabilidadPedir);
                if(nueva){
                    nueva->cliente = tmp->nombre;
                    nueva->numeroMesa = tmp->numeroMesa;
                    tmp->cuentaAPagar+= nueva->plato->precio;
                    colaPeticiones->encolar(nueva);
                }
            }
            else if(mesa->tipoPedido == 3){

                Solicitud * nueva = tmp->pedirPostre(tmp->probabilidadPedir);
                if(nueva){
                    nueva->cliente = tmp->nombre;
                    nueva->numeroMesa = tmp->numeroMesa;
                    tmp->cuentaAPagar+= nueva->plato->precio;
                    colaPeticiones->encolar(nueva);
                }
            }
            else{
                Solicitud * nueva =tmp->pedirCuenta();
                if(nueva){
                    nueva->cliente = tmp->nombre;
                    nueva->numeroMesa = tmp->numeroMesa;
                    tmp->cuentaAPagar+= nueva->plato->precio;
                    colaPeticiones->encolar(nueva);
                }
            }
            tmp = tmp->siguiente;
        }
    }
    mesa->tipoPedido++;
}

Mesa * Mesero::revisarMesas(){
    Mesa * tmp = mesas->primerNodo;
    if(tmp == nullptr) return nullptr;
    for(int i =0; i<mesas->largo;i++){
        if (tmp->estaOcupada() && tmp->pedirAsistencia){
            return tmp;
        }
        tmp = tmp->siguiente;
    }
    return  nullptr;
}

void Mesero::recibirOrden(Solicitud * sol){
    colaPeticiones->encolar(sol);
}
void Mesero::llevarOrdenCocina(){

}
void Mesero::llevarCuenta(){

}
void Mesero::llevarComida(){

}
void Mesero::llevarPlatosALavar(){

}
