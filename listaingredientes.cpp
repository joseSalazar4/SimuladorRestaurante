#include "listaingredientes.h"


bool ListaIngredientes::estaVacia(){
    return  primerNodo == nullptr;
}


void ListaIngredientes::insertarFinal(Ingrediente * ingredienteNuevo) {
    if (primerNodo==nullptr) {
        primerNodo = ultimoNodo = ingredienteNuevo;
        largo++;
    }
    else {
        ultimoNodo->siguiente  = ingredienteNuevo;
        ultimoNodo->siguiente->anterior = ultimoNodo;
        ultimoNodo = ultimoNodo->siguiente;
        largo++;
    }
}
