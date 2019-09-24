#include "listacomensales.h"


void ListaComensales::insertarFinal(QString nombre) {
    if (estaVacia()) {
        primerNodo = ultimoNodo = new Comensal(nombre);
        largo++;
    }
    else {
            ultimoNodo->siguiente = new Comensal(nombre);
            ultimoNodo->siguiente->anterior = ultimoNodo;
            ultimoNodo = ultimoNodo->siguiente;
            largo++;
        }
}

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

