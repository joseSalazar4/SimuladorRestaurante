#include "listasolicitudes.h"

bool ListaSolicitudes::estaVacia(){
    return  primerNodo == nullptr;
}


void ListaSolicitudes::insertarFinal(Solicitud * sol) {
    if (primerNodo==nullptr) {
        primerNodo = ultimoNodo = sol;
        largo++;
    }
    else {
            ultimoNodo->siguiente  = sol;
            ultimoNodo->siguiente->anterior = ultimoNodo;
            ultimoNodo = ultimoNodo->siguiente;
            largo++;
        }
}
