#include "Comensal.h"


bool comer();

int generadorNumRandom(int rango1, int rango2){
    srand((int)time(0));
    int r = (rand() % rango1) + (rango2-rango1);

    return r;
}

int generadorNumRandom(int rango1){
    srand((int)time(nullptr));
    int r = (rand() % rango1)+1;

    return r;
}

Solicitud * Comensal::pedirEntrada(int porcentajeACumplir){
    int pos;

    int probabilidad = generadorNumRandom(porcentajeACumplir);
    if(porcentajeACumplir>probabilidad){
        //Elige el plato, pide comida en el menú y crea la solicitud
        Plato * platillo   = new Plato();
        platillo = elegirPlato();
        Solicitud * nueva = new Solicitud(1, 1); //1 Es para ir a las entradas
        nueva->plato= platillo;
        meseroActivo->recibirOrden(nueva);
    }
}

Solicitud * Comensal::pedirPlatoFuerte( int porcentajeACumplir){

    int probabilidad = generadorNumRandom(porcentajeACumplir);
    if(porcentajeACumplir>probabilidad){
        //Elige el plato, pide comida en el menú y crea la solicitud
        Solicitud * nueva = new Solicitud(1,2); //2 Es para ir a cocina de platos fuertes
        nueva->plato= platillo;
        meseroActivo->recibirOrden(nueva);

    }
}

Solicitud * Comensal::pedirPostre(int porcentajeACumplir){

    int probabilidad = generadorNumRandom(porcentajeACumplir);
    if(porcentajeACumplir>probabilidad){
        //Elige el plato, pide comida en el menú y crea la solicitud
        Solicitud * nueva = new Solicitud(1,3);  //3 Es para ir a los postres
        nueva->plato= platillo;
        meseroActivo->recibirOrden(nueva);
    }
}

Solicitud * pedirCuenta();

void dejarMesa();

void llamarMesero();
