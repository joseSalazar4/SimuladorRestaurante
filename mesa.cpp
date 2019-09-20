#include "mesa.h"

bool Mesa::estaOcupada(){
    return ocupada == 1;
}

void Mesa::insertarComensales(QString nombre){
    listaComensales->insertarFinal(nombre);
}
