#include "listaplatos.h"



void ListaPlatos::insertarFinal(QString _tipo, QString _nombre,int _ID, int _precio, int _tiempoCocina, int _tiempoLavado,ListaIngredientes * _Ingredientes) {
    if (estaVacia()) {
        primerNodo = ultimoNodo = new Plato(_tipo, _nombre, _ID,  _precio, _tiempoCocina,  _tiempoLavado, _Ingredientes);
        largo++;
    }
    else {
            ultimoNodo->siguiente = new Plato( _tipo, _nombre, _ID,  _precio, _tiempoCocina,  _tiempoLavado, _Ingredientes);
            ultimoNodo->siguiente->anterior = ultimoNodo;
            ultimoNodo = ultimoNodo->siguiente;
            largo++;
        }
}

bool ListaPlatos::estaVacia(){
    return  primerNodo == nullptr;
}

//TODO Que los primeros 10 sean entradas y así. El profe quiere que se cargen antes de tons maybe en el csontructor un for miedo
Plato * ListaPlatos::buscarPlatoRandomTipo(int tipo){
    Plato * tmp = primerNodo;
    if(tipo==1){
        //Los primeros 10 sean entradas

        for(int i = 0 ; primerEntrada; i++){

            tmp = tmp->siguiente;
        }

    }
    else if(tipo==2){
        //Luego los otros 10 sean fuertes

        for(int i = 0 ; primerFuerte; i++){

            tmp = tmp->siguiente;
        }
    }
    else if(tipo==3){
        //Los ultimos 10 sean postres

        for(int i = 0 ; primerPostre; i++){

            tmp = tmp->siguiente;
        }
    }

    return tmp;

}
