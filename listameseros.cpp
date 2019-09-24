#include "listameseros.h"

void ListaMeseros::activarMeseros(Mesero * mesero[20]){
    MeseroThread * tmp = new MeseroThread();
    int i = 0;
    while(tmp){
        tmp->__init__(nullptr, mesero[i]);
        tmp = tmp->siguiente;
        i++;
    }
}

void ListaMeseros::insertarFinal(MeseroThread * meserito){
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

void ListaMeseros::insertarFinal() {
    if (estaVacia()) {
        primerNodo = ultimoNodo = new MeseroThread();
        largo++;
    }
    else {
            ultimoNodo->siguiente = new MeseroThread();
            ultimoNodo->siguiente->anterior = ultimoNodo;
            ultimoNodo = ultimoNodo->siguiente;
            largo++;
        }
}

bool ListaMeseros::estaVacia(){
    return  primerNodo == nullptr;
}
