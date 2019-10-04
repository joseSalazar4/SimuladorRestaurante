#include "comensalthread.h"


void ComensalThread::__init__(QMutex * mutexCom, QLabel * label, Comensal * comens){
    imagenComensal = label;
    mutexComensal = mutexCom;
    comensal = comens;
    activo = true;
    pausa = false;

}

void ComensalThread::run(){
    while(activo){
        mutexComensal->lock();
        if(comensal->plato) comer(comensal->plato);
        mutexComensal->unlock();
        while(pausa) sleep(1);
    }
}
void ComensalThread::pausar()
{
    this->pausa = true;
}

void ComensalThread::continuar()
{
    this->pausa = false;
}
//METODOS DE SOLO LE COMENSAL ADAPTAR LOS NECESARIOS

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
        nueva->tipo = 1;
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
        nueva->tipo = 2;
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
        nueva->tipo = 3;
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
    nueva->cuenta = cuentaAPagar;
    nueva->tipo = 4;
    return nueva;
}

void Comensal::dejarMesa(){
    siguiente = anterior = nullptr;
    this->imagenPersona->hide();

}

Plato *  ComensalThread::comer(Plato * plato){
    int tiempoComer1, tiempoComer2;
    //Depending on the plate the time will be different
    if(plato->tipo == 1){
        tiempoComer1 = comensal->tiempoComerEnsalada1;
        tiempoComer2 = comensal->tiempoComerEnsalada2;
    }
    else if(plato->tipo == 2){
        tiempoComer1 = comensal->tiempoComer1Fuerte;
        tiempoComer2 = comensal->tiempoComer2Fuerte;
    }
    else{
        tiempoComer1 = comensal->tiempoComerPostre1;
        tiempoComer2 = comensal->tiempoComerPostre2;
    }

    int duracionComida = QRandomGenerator::global()->bounded(tiempoComer1, tiempoComer2);
    comensal->comensalTerminoComer = false;
    while (duracionComida>0) {
        this->comensal->imagenPersona->setToolTip("Faltan "+QString::number(duracionComida)+" segundos para que termine de comer");
        duracionComida--;
        sleep(1);
    }
    comensal->comensalTerminoComer = true;
    plato->vacio = true;
    plato->limpio = false;
    return plato;
}
