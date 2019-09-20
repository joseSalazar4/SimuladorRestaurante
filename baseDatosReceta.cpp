//
// Created by mikom on 8/28/2019.
//

#include "baseDatosReceta.h"

//
// Created by mikom on 8/26/2019.
//

#include "Receta.h"

bool baseDatosReceta::estaVacia() {
    return primerNodo == nullptr;
}

bool baseDatosReceta::existeReceta(string pNombre) {
    if (!estaVacia()) {
        Receta *tmp = primerNodo;
        while (tmp != nullptr) {
            if (tmp->nombre == pNombre)
                return true;
            tmp = tmp->siguiente;
        }
        return false;
    }
}

Receta *baseDatosReceta::buscarReceta(string pNombre) {
    if (!estaVacia()) {
        Receta *tmp = primerNodo;
        while (tmp != nullptr) {
            if (tmp->nombre == pNombre)
                return tmp;
            tmp = tmp->siguiente;
        }
        return tmp;
    }
    return nullptr;
}

void baseDatosReceta::imprimirReceta(string pNombre) {
    if (!existeReceta(pNombre))
        cout << "La receta no existe";
    else {
        Receta *tmp = buscarReceta(pNombre);
        cout << "\n  La receta: " << tmp->nombre << "\n";
        cout << "  Tiene: " << tmp->cantidadPorciones << " cantidades de porciones\n";
        cout << "  Y sus ingredientes son: \n";
        int i = 0;
        if (tmp->cantidadIngredientes == 0) {
            cout << " No hay ingredientes por mostrar\n\n";
            return;
        }

        for (i; i < 20; i++) {
            if (tmp->ingredientes[i].cantidad != 0) {
                cout << "\t" << tmp->ingredientes[i].nombre << " y la cantidad recomendada es: ";
                cout << tmp->ingredientes[i].cantidad << "  ";
                cout << tmp->ingredientes[i].unidadMedida << "\n";
            }
        }
        cout << "\n\n\n  ----------------------------------------------\n";

    }
}

void baseDatosReceta::insertarFinal(string nombre, int cantidad) {
    if (estaVacia()) {
        primerNodo = ultimoNodo = new Receta(nombre, cantidad);
        primerNodo->pedirIngredientes();
    } else {
        if (!existeReceta(nombre)) {
            ultimoNodo->siguiente = new Receta(nombre, cantidad);
            ultimoNodo->siguiente->pedirIngredientes();
            ultimoNodo->siguiente->anterior = ultimoNodo;
            ultimoNodo = ultimoNodo->siguiente;
        } else
            cout << "\nYa existe la receta con el nombre: " << nombre << endl;
    }
}

void baseDatosReceta::insertarFinal(Receta pRecetaNueva) {
    Receta *m = new Receta();
    if (estaVacia()) {
        primerNodo = ultimoNodo = m;
        *primerNodo = *ultimoNodo = pRecetaNueva;
        //primerNodo->pedirIngredientes();
    } else {
        if (!existeReceta(pRecetaNueva.nombre)) {
            *m = pRecetaNueva;
            ultimoNodo->siguiente = m;
            // ultimoNodo->siguiente->pedirIngredientes();
            ultimoNodo->siguiente->anterior = ultimoNodo;
            ultimoNodo = ultimoNodo->siguiente;
        } else
            cout << "\nYa existe la receta con el nombre: " << pRecetaNueva.nombre << endl;
    }
}

void baseDatosReceta::borrarFinal() {
    Receta *temp = ultimoNodo;
    if (estaVacia() || primerNodo == ultimoNodo)
        primerNodo = ultimoNodo = nullptr;
    else {
        ultimoNodo = ultimoNodo->anterior;
        temp->anterior = nullptr;
        ultimoNodo->siguiente = nullptr;
    }
}

void baseDatosReceta::insertarInicio(string nombre, int cantidad) {
    if (estaVacia()) {
        primerNodo = ultimoNodo = new Receta(nombre, cantidad);   //todo ver esto despues
        primerNodo->pedirIngredientes();
    } else {
        primerNodo->anterior = new Receta(nombre, cantidad);
        primerNodo->anterior->pedirIngredientes();
        primerNodo->anterior->siguiente = primerNodo;
        primerNodo = primerNodo->anterior;
    }
}

void baseDatosReceta::borrarReceta() { //todo diay esto
    string nomb;
    cout << "Indique el nombre de la receta a borrar";
    cin.ignore();
    getline(cin, nomb);
    if (buscarReceta(nomb) == nullptr) {
        cout << "La receta no existe";
    } else {
        Receta *tmp = (buscarReceta(nomb));
        if (tmp == ultimoNodo) {
            borrarFinal();
        } else if (tmp == primerNodo) {
            borrarInicio();
        } else {
            tmp->anterior->siguiente = tmp->siguiente;
            tmp->siguiente->anterior = tmp->anterior;
            tmp->siguiente = tmp->anterior = nullptr;
            cout << "Se elimino con exito la receta\n";
        }
    }
}


void baseDatosReceta::modificarNombreReceta() {
    string nombreNuevo = "";
    cout << "Indique el nombre de la receta a la cual cambiar el nombre: ";
    cin.ignore();
    getline(cin, nombreNuevo);
    if (buscarReceta(nombreNuevo) != nullptr) {
        Receta *tmp = buscarReceta(nombreNuevo);
        cout << "Indique el nombre NUEVO de la receta: ";
        getline(cin, nombreNuevo);
        tmp->nombre = nombreNuevo;
    } else
        cout << "La receta no existe. \n";

}

void baseDatosReceta::imprimirMenu() {

    cout << "\n                         MENU" << endl;
    cout << " 1.	Agregar receta                                     " << endl;
    cout << " 2.	Buscar receta                                      " << endl;
    cout << " 3.	Borrar receta                                      " << endl;
    cout << " 4.	Imprimir todas las recetas                         " << endl;
    cout << " 5.	Modificar nombre de una receta                     " << endl;
    cout << " 6.	Modificar cantidad de un ingrediente de una receta " << endl;
    cout << " 7.	Agregar ingrediente a una receta                   " << endl;
    cout << " 8.	Borrar ingrediente a una receta                   " << endl;
    cout << " 9.	Salir                                              " << endl;
}

void baseDatosReceta::leerOpcionMenu() {
    string nombre;
    int eleccion = 0, cantidad;

    while (eleccion != 9) {
        imprimirMenu();
        cout << "\n\nIndique la opcion que desea efectuar: ";

        cin >> eleccion;

        if (cin.fail()) {
            cin.clear(); // clears error flags
            cin.ignore();
            cout << "Utilice solamente numeros";
            cout << "\n\nIndique la opcion que desea efectuar: ";
            cin >> eleccion;
        }
        switch (eleccion) {
            case 1:
                cout << "\n\nIndique el nombre de la receta: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "\n\nIndique la cantidad de la receta: ";
                cin >> cantidad;
                insertarFinal(nombre, cantidad);
                break;
            case 2:
                cout << "\nIndique el nombre de la receta: ";
                cin.ignore();
                getline(cin, nombre);
                imprimirReceta(nombre);
                break;
            case 3:
                borrarReceta();
                break;
            case 4:
                imprimir();
                break;
            case 5:
                modificarNombreReceta();
                break;
            case 6:
                modificarCantidadIngrediente();
                break;
            case 7:
                agregarIngredienteReceta();
                break;
            case 8:
                borrarIngrediente();
                break;
            case 9:
                cout << "Saliendo del menu..." << endl;
                break;
            default:
                cout << "ERROR!: La opción digitada no es valida" << endl << endl;
                break;
        }
    }
}

void baseDatosReceta::modificarCantidadIngrediente() {
    string nombre = "", ingrediente = "";
    int cantidadNueva = 0, pos;
    cout << "Indique el nombre de la receta: ";
    cin.ignore();
    getline(cin, nombre);
    if (buscarReceta(nombre) != nullptr) {
        cout << "Indique el nombre del ingrediente: ";
        getline(cin, ingrediente);
        if ((buscarReceta(nombre)->buscarIngrediente(ingrediente)) != -1) {
            pos = (buscarReceta(nombre)->buscarIngrediente(ingrediente));
            cout << "Indique la nueva cantidad de la receta: ";
            cin >> cantidadNueva;
            buscarReceta(nombre)->ingredientes[pos].cantidad = cantidadNueva;
        } else
            cout << "El ingrediente no existe";
    } else
        cout << "La receta no existe, no se podra modificar la cantidad del ingrediente";
}

void baseDatosReceta::borrarIngrediente() {
    string nombre = "", ingrediente = "";
    int pos;
    cout << "Indique el nombre de la receta: ";
    cin.ignore();
    getline(cin, nombre);
    if (buscarReceta(nombre) != nullptr) {
        cout << "Indique el nombre del ingrediente: ";
        getline(cin, ingrediente);
        if ((buscarReceta(nombre)->buscarIngrediente(ingrediente)) != -1) {
            pos = (buscarReceta(nombre)->buscarIngrediente(ingrediente));
            buscarReceta(nombre)->ingredientes[pos].cantidad = 0;
            buscarReceta(nombre)->ingredientes[pos].unidadMedida = "";
            buscarReceta(nombre)->ingredientes[pos].nombre = "*ELIMINADO*";

        } else
            cout << "El ingrediente no existe";
    } else
        cout << "La receta no existe, no se podra modificar la cantidad del ingrediente";
};

void baseDatosReceta::borrarInicio() {
    if (estaVacia())
        return;
    else {
        Receta *tmp = primerNodo;
        if (primerNodo->siguiente == nullptr)
            primerNodo = ultimoNodo = nullptr;
        else {
            primerNodo = primerNodo->siguiente;
            primerNodo->anterior = tmp->siguiente = nullptr;
        }
    }
}

void baseDatosReceta::agregarIngredienteReceta() {
    string nombre = "", ingredienteNuevo = "", medida = "";
    int cantidad;
    cout << "Indique el nombre de la receta por buscar: ";
    cin.ignore();
    getline(cin, nombre);
    if (buscarReceta(nombre) != nullptr) {
        cout << "Indique el nombre del ingrediente nuevo: ";
        getline(cin, ingredienteNuevo);
        if (buscarReceta(nombre)->buscarIngrediente(ingredienteNuevo) == -1) {
            cout << "Indique la cantidad del ingrediente: ";
            cin >> cantidad;
            cout << "Indique la medida del ingrediente: ";
            cin >> medida;
            (buscarReceta(nombre))->insertarIngrediente(Ingrediente(ingredienteNuevo, cantidad, medida));
        } else
            cout << "El ingrediente ya existe en la receta";
    } else
        cout << "La receta no existe";
}

void baseDatosReceta::imprimir() {
    if (estaVacia()) {
        cout << "No hay recetas";
        return;
    } else {
        Receta *tmp = primerNodo;
        cout << "\n\nLas Recetas actualmente en la base de Datos son: \n";
        while (tmp != nullptr) {
            cout << "  La receta: " << tmp->nombre << "\n";
            cout << "  Tiene: " << tmp->cantidadPorciones << " cantidades de porciones\n";
            cout << "  Y sus ingredientes son: \n";
            int i = 0;
            for (i; i < 20; i++) {
                if (tmp->ingredientes[i].cantidad != 0) {
                    cout << "\t" << tmp->ingredientes[i].nombre << " y la cantidad recomendada es: ";
                    cout << tmp->ingredientes[i].cantidad << "  ";
                    cout << tmp->ingredientes[i].unidadMedida << "\n";
                }
            }
            cout << "\n\n  ----------------------------------------------\n";
            tmp = tmp->siguiente;
        }
        return;
    }
}


void baseDatosReceta::recetasDefault() {
//Ingredientes
    auto ingrediente0 = Ingrediente("Leche", 8, "ml");
    auto ingrediente1 = Ingrediente("Tomate", 12, "kg");
    auto ingrediente2 = Ingrediente("Huevos ", 4, "g");
    auto ingrediente3 = Ingrediente("Sal", 1, "kg");
    auto ingrediente6 = Ingrediente("Azucar", 9, "kg");
    auto ingrediente7 = Ingrediente("Harina", 5, "kg");
    auto ingrediente8 = Ingrediente("Carne", 5, "kg");

//Recetas Default
    Receta receta1 = Receta("Tres Leches", 1);
    receta1.insertarIngrediente(ingrediente0);
    receta1.insertarIngrediente(ingrediente2);
    receta1.insertarIngrediente(ingrediente7);
    receta1.insertarIngrediente(ingrediente6);

    Receta receta2 = Receta("Lasagna", 2);
    receta2.insertarIngrediente(ingrediente3);
    receta2.insertarIngrediente(ingrediente1);
    receta2.insertarIngrediente(ingrediente2);
    receta2.insertarIngrediente(ingrediente8);

    Receta receta3 = Receta("Fetuccini", 4);
    receta3.insertarIngrediente(ingrediente8);
    receta3.insertarIngrediente(ingrediente3);
    receta3.insertarIngrediente(ingrediente0);
    receta3.insertarIngrediente(ingrediente2);

    Receta receta4 = Receta("Pizza", 5);
    receta4.insertarIngrediente(ingrediente1);
    receta4.insertarIngrediente(ingrediente2);
    receta4.insertarIngrediente(ingrediente3);
    receta4.insertarIngrediente(ingrediente7);

    Receta receta5 = Receta("Yogurt", 6);
    receta5.insertarIngrediente(ingrediente0);
    receta5.insertarIngrediente(ingrediente6);
    receta5.insertarIngrediente(ingrediente2);
    receta5.insertarIngrediente(ingrediente3);

    insertarFinal(receta1);
    insertarFinal(receta2);
    insertarFinal(receta3);
    insertarFinal(receta4);
    insertarFinal(receta5);
}