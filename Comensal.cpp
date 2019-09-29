#include "Comensal.h"


int generadorNumRandom(int rango1, int rango2){
    srand(static_cast<unsigned int>(time(nullptr)));
    int r = (rand() % rango1) + (rango2-rango1);
    return r;
}

int generadorNumRandom(int rango1){
    srand(static_cast<unsigned int>(time(nullptr)));
    int r = (rand() % rango1)+1;
    return r;
}

Solicitud * Comensal::pedirEntrada(int porcentajeACumplir){

    int probabilidad = generadorNumRandom(porcentajeACumplir);
    if(porcentajeACumplir>probabilidad){
        //Elige el plato, pide comida en el menú y crea la solicitud
        Solicitud * nueva = new Solicitud(1, 1); //1 Es para ir a las entradas
        Plato * platillo = escogerPlato(1);
        nueva->plato= platillo;
        cuentaAPagar+=nueva->plato->precio;
        nueva->numeroMesa = numeroMesa;
        return nueva;
    }
    return nullptr;
}

Solicitud * Comensal::pedirPlatoFuerte( int porcentajeACumplir){

    int probabilidad = generadorNumRandom(porcentajeACumplir);
    if(porcentajeACumplir>probabilidad){
        //Elige el plato, pide comida en el menú y crea la solicitud
        Solicitud * nueva = new Solicitud(1,2); //2 Es para ir a cocina de platos fuertes
        Plato * platillo = escogerPlato(2);
        nueva->plato= platillo;
        cuentaAPagar+=nueva->plato->precio;
        nueva->numeroMesa = numeroMesa;
        return nueva;

    }
    return nullptr;
}

Solicitud * Comensal::pedirPostre(int porcentajeACumplir){

    int probabilidad = generadorNumRandom(porcentajeACumplir);
    if(porcentajeACumplir>probabilidad){
        //Elige el plato, pide comida en el menú y crea la solicitud
        Solicitud * nueva = new Solicitud(1,3);  //3 Es para ir a los postres
        Plato * platillo = escogerPlato(3);
        nueva->plato= platillo;
        cuentaAPagar+=nueva->plato->precio;
        nueva->numeroMesa = numeroMesa;
        return nueva;
    }
    return nullptr;
}

Plato * Comensal::escogerPlato(int tipo){
    return listaPlatos->buscarPlatoRandomTipo(tipo);


}
Solicitud * Comensal::pedirCuenta(){
    Solicitud * nueva = new Solicitud(1,4);
    nueva->numeroMesa = numeroMesa;
    return nueva;
}

void Comensal::dejarMesa(){
    siguiente = anterior = nullptr;

}

void Comensal::llamarMesero(){

}
