#include "listameseros.h"

void ListaMeseros::insertarFinal(Mesero * meserito){
    if (estaVacia()) {
        primerNodo = ultimoNodo = meserito;
        largo++;
    }
    else {
        ultimoNodo->siguiente = meserito;
        ultimoNodo->siguiente->anterior = ultimoNodo;
        ultimoNodo = ultimoNodo->siguiente;
        largo++;
    }
}

void ListaMeseros::insertarFinal(int cantMesasAsignadas) {
    if (estaVacia()) {
        primerNodo = ultimoNodo = new Mesero(cantMesasAsignadas);
        largo++;
    }
    else {
        ultimoNodo->siguiente = new Mesero(cantMesasAsignadas);
        ultimoNodo->siguiente->anterior = ultimoNodo;
        ultimoNodo = ultimoNodo->siguiente;
        largo++;
    }
}

bool ListaMeseros::estaVacia(){
    return  primerNodo == nullptr;
}
