#include "comensal.h"
#include "QRandomGenerator"


int generadorNumRandom(int rango1){
    int r = (rand() % 100);
    return r<rango1?true:false;
}

Solicitud * Comensal::pedirEntrada(int porcentajeACumplir){

    bool probabilidad = generadorNumRandom(porcentajeACumplir);
    if(porcentajeACumplir>probabilidad){
        //Elige el plato, pide comida en el menú y crea la solicitud
        Solicitud * nueva = new Solicitud(1, 1); //1 Es para ir a las entradas
        Plato * platillo = escogerPlato(1);
        nueva->plato= platillo;
        imagenPersona->setToolTip(platillo->nombre);
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
        imagenPersona->setToolTip(platillo->nombre);
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
        imagenPersona->setToolTip(platillo->nombre);
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

Plato *  Comensal::comer(Plato * plato){
    int tiempoComer1, tiempoComer2;
    //Depending on the plate the time will be different
    if(plato->tipo == 1){
        tiempoComer1 = tiempoComerEnsalada1;
        tiempoComer2 = tiempoComerEnsalada2;
    }
    else if(plato->tipo == 2){
        tiempoComer1 = tiempoComer1Fuerte;
        tiempoComer2 = tiempoComer2Fuerte;
    }
    else{
        tiempoComer1 = tiempoComerPostre1;
        tiempoComer2 = tiempoComerPostre2;
    }

    int duracionComida = QRandomGenerator::global()->bounded(tiempoComer1, tiempoComer2);
    comensalTerminoComer = false;
    while (duracionComida>0) {
        //todo debe durar segundos pero no es un thread
        this->imagenPersona->setToolTip("Faltan "+QString::number(duracionComida)+" segundos para que termine de comer");
        duracionComida--;
    }
    comensalTerminoComer = true;
    plato->vacio = true;
    plato->limpio = false;
    return plato;
}
