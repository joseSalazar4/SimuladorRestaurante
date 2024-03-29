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

Mesa * ListaMesas::buscarDisponibilidad(){
    Mesa * tmp = primerNodo;
    while(tmp){
        if(!tmp->estaOcupada()){
            return tmp;
        }
        tmp = tmp->siguiente;
    }
    return nullptr;
}

void ListaMesas::insertarFinal(Mesa * m) {
    if (estaVacia()) {
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


bool ListaMesas::estaVacia(){
    return  primerNodo == nullptr;
}
