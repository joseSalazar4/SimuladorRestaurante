#include "generadorpersonasthread.h"
#include "qdebug.h"


int GeneradorPersonasThread::generadorNumRandom(int rango1, int rango2){
    srand(static_cast<unsigned int>(time(nullptr)));
    int r = (rand() % rango1) + (rango2-rango1);
    return r;
}

int GeneradorPersonasThread::generadorNumRandom(int rango1){
    srand(static_cast<unsigned int>(time(nullptr)));
    int r = (rand() % rango1)+1;
    return r;
}

void GeneradorPersonasThread::__init__(ManejadorComensales * maneja){
    this->manejadorComensales = maneja;
    pausa = false;
    activo = true;
}

GeneradorPersonasThread::GeneradorPersonasThread()
{
    tiempoGeneracion = tiempoGeneracion1 = cantidadGenerada = 0;
}

ListaComensales * GeneradorPersonasThread::generarPersonas(){
    ListaComensales * lista = new ListaComensales();
    int personasCreadas = generadorNumRandom(1,6);
    qDebug()<< personasCreadas;
    for(int i = 0; i < personasCreadas; i++){
        Comensal * nuevo = new Comensal("Marco"+QString::number(i));

        lista->insertarFinal(nuevo);
    }
    qDebug()<<lista->primerNodo->nombre;
    qDebug()<<lista->primerNodo->siguiente->nombre;
    return lista;
}

void GeneradorPersonasThread::run(){
    manejadorComensales->semaforo.release();
    qDebug()<< "Le acabi de dar release vamos";

    while(activo){
        qDebug()<< "entre al RUUUN";
        manejadorComensales->semaforo.acquire();
        qDebug()<< "Pasé el acquire";
        manejadorComensales->colaClientesEnEspera->encolar(generarPersonas());
        manejadorComensales->semaforo.release() ;   //Revise los numeros para ver si es o no

        sleep(5);
        while(pausa){
            sleep(1);
        }
    }
}


void GeneradorPersonasThread::pausar()
{
    this->pausa = true;
}

void GeneradorPersonasThread::continuar()
{
    this->pausa = false;
}
