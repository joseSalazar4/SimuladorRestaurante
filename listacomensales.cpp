#include "listacomensales.h"


void ListaComensales::insertarFinal(Comensal * nuevo) {
    if (estaVacia()) {
        primerNodo = ultimoNodo = nuevo;
        largo++;
    }
    else {
            ultimoNodo->siguiente = nuevo;
            ultimoNodo->siguiente->anterior = ultimoNodo;
            ultimoNodo = ultimoNodo->siguiente;
            largo++;
        }
}


bool ListaComensales::estaVacia(){
    return  primerNodo == nullptr;
}

void ListaComensales::borrarFinal(){
    Comensal * tmp = ultimoNodo;
    if(estaVacia() || primerNodo == ultimoNodo) primerNodo = ultimoNodo = nullptr;
    else{
        ultimoNodo = ultimoNodo->anterior;
        tmp->anterior = nullptr;
        ultimoNodo->siguiente = nullptr;
    }
}

void ListaComensales::vaciar(){
    Comensal * tmp = primerNodo;
    while(tmp){
        borrarFinal();
    }
}
