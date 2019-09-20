//
// Created by mikom on 8/28/2019.
//

#include "Receta.h"

void Receta::insertarIngrediente(Ingrediente pIngrediente) {
    if (cantidadIngredientes == 21) {
        cout << "Las recetas solo pueden contener 20 elementos";
    } else {
        if (buscarIngrediente(pIngrediente.nombre) != -1) {
            cout << "Este ingrediente ya está en la lista de ingredientes";
            return;
        }
        ingredientes[cantidadIngredientes] = pIngrediente;
        cantidadIngredientes++;
        cout << "El ingrediente fue agregado!\n\n" ;
    }
}

void Receta::borrarIngrediente(string pNombre) {
    if (buscarIngrediente(pNombre) != -1) {
        cantidadIngredientes--;
        for (int i = buscarIngrediente(pNombre); i < buscarIngrediente(pNombre); ++i) {
            ingredientes[i] = ingredientes[i + 1];
        }
        cout << "Ingrediente eliminada\n";
    } else
        cout << "El ingrediente por eliminar no existe\n";
}

int Receta::buscarIngrediente(string pNombre) {
    for (int i = 0; i < cantidadIngredientes; i++) {
        if ((ingredientes[i]).nombre == pNombre)
            return i;
    }
    return -1;
}

void Receta::pedirIngredientes(){
    string respuesta = "s";
    while (respuesta == "s" || respuesta == "S") {
        auto *ingredienteNuevo = new Ingrediente();
        cout << "Indique el nombre del ingrediente";
        cin.ignore();
        getline(cin, ingredienteNuevo->nombre);
        if(buscarIngrediente(ingredienteNuevo->nombre)!=-1) {
            cout << "Ya hay una receta con este nombre";
            pedirIngredientes();
            return;
        }
        cout << "Indique la cantidad ";
        cin >> ingredienteNuevo->cantidad;
        cout << "Indique la unidad de medida ";
        cin >> ingredienteNuevo->unidadMedida;
        insertarIngrediente((*ingredienteNuevo));
        cout<<"Desea agregar otro Ingrediente? (s/n)";
        cin>>respuesta;
    }

}

void Receta::modificarCantidadIngrediente(string pNombre, int pCantidad) {
    if(buscarIngrediente(pNombre) != -1){
        ingredientes[(buscarIngrediente(pNombre))].cantidad = pCantidad;
    }
    else{
        cout<<"El ingrediente no existe, no se podrá hacer la modificacion.";
    }
}
