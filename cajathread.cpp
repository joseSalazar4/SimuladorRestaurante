#include "cajathread.h"

CajaThread::CajaThread()
{

}

void CajaThread::__init__(QLabel* _etiqueta, Caja * _caja){
    imagenCaja = _etiqueta;
    caja = _caja;
    this->activo = true;
    this->pausa = false;
}

void CajaThread::run(){
    while(activo){
        if(!caja->vacia()){
            QString mesaActual = caja->frente->mesa->ID;  //Tons si hay solicitudes que saque todas hasta que haya otra mesa
            while(caja->frente->mesa->ID == mesaActual){
                caja->desencolar()->cuenta = caja->calcularCuenta();
                Solicitud * nueva  = new Solicitud();

                sleep(tiempoSleep);
            }
        }
        while(pausa)
            sleep(1);
    }
}

void CajaThread::pausar(){
    this->pausa = true;
}

void CajaThread::continuar()
{
    this->pausa = false;
}

void CajaThread::establecerSleep(unsigned int nuevoTemp){
    tiempoSleep = nuevoTemp;
}
