#include "mesa.h"

bool Mesa::estaOcupada(){
    return ocupada == 1;
}


void Mesa::vaciarMesa(){
    listaComensales->vaciar();
    ocupada = 0;
    imagen->setToolTip("La mesa está vacía"); //repetir esto en todos los labels en los metodos correspondientes.
}

bool Mesa::comensalesTerminaron(){
    ComensalThread * clienteAux = listaComensales->primerNodo;
    while(clienteAux){
        if(!clienteAux->comensal->comensalTerminoComer) return false;
        clienteAux = clienteAux->siguiente;
    }
    return true;
}
