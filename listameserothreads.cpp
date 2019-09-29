#include "listameserothreads.h"



bool ListaMeseroThreads::estaVacia(){
    return  primerNodo == nullptr;
}


void ListaMeseroThreads::insertarFinal(MeseroThread * m) {
    if (primerNodo==nullptr) {
        primerNodo = ultimoNodo = m;
        largo++;
    }
    else {
            ultimoNodo->siguiente  = m;
            ultimoNodo->siguiente->anterior = ultimoNodo;
            ultimoNodo = ultimoNodo->siguiente;
            largo++;
        }
}


