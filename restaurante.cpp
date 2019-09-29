#include "restaurante.h"



void Restaurante::Iniciar(){
    //Crear lista de mesas y de meseros para asignar
    //int cantMesas = 14, cantMeseros = 7;

}



bool Restaurante::asignarMesa(ListaComensales * lista){
    Mesa * aux = mesas->primerNodo;
    while(aux!= nullptr){
        if(aux->estaOcupada() == false){   //Para el primer caso, luego me muevo en todas
            aux->listaComensales = lista;
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
}

