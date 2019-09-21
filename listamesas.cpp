#include "listamesas.h"


void ListaMesas::insertarFinal(QString id) {
    if (estaVacia()) {
        primerNodo = ultimoNodo = new Mesa(id);
        largo++;
    }
    else {
            ultimoNodo->siguiente = new Mesa(id);
            ultimoNodo->siguiente->anterior = ultimoNodo;
            ultimoNodo = ultimoNodo->siguiente;
            largo++;
        }
}

bool ListaMesas::estaVacia(){
    return  primerNodo == nullptr;
}
