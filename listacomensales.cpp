#include "listacomensales.h"


void ListaComensales::insertarFinal(ComensalThread * nuevo) {
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
    ComensalThread * tmp = ultimoNodo;
    if(estaVacia() || primerNodo == ultimoNodo) primerNodo = ultimoNodo = nullptr;
    else{
        tmp->comensal->imagenPersona->hide();
        ultimoNodo = ultimoNodo->anterior;
        tmp->anterior = nullptr;
        ultimoNodo->siguiente = nullptr;
    }
}

void ListaComensales::vaciar(){
    ComensalThread * tmp = primerNodo;
    while(tmp){
        borrarFinal();
    }
}
