#include "listamesas.h"


void ListaMesas::insertarFinal(QString id, Mesero * mesero) {
    if (estaVacia()) {
        primerNodo = ultimoNodo = new Mesa(id, Mesero * mesero);
        largo++;
    }
    else {
            ultimoNodo->siguiente = new Mesa(id, Mesero * mesero);
            ultimoNodo->siguiente->anterior = ultimoNodo;
            ultimoNodo = ultimoNodo->siguiente;
            largo++;
        }
}

bool ListaMesas::estaVacia(){
    return  primerNodo == nullptr;
}
