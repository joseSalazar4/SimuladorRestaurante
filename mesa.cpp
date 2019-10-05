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
        clienteAux->mutexComensal->tryLock(10);
        if(!clienteAux->comensal->comensalTerminoComer){
            clienteAux->mutexComensal->unlock();
            return false;
        }
        clienteAux->mutexComensal->unlock();
        clienteAux = clienteAux->siguiente;
    }
    //SolicitandoAsistencia  = true;
    return true;
}
