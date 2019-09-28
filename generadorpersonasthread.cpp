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

void GeneradorPersonasThread::__init__(ManejadorComensales * maneja, QMutex * mutex){
    pausa = false;
    activo = true;
    this->mutexManejador = mutex;
    this->manejadorComensales = maneja;
}

GeneradorPersonasThread::GeneradorPersonasThread()
{
    tiempoGeneracion = tiempoGeneracion1 = cantidadGenerada = 0;
}

ListaComensales * GeneradorPersonasThread::generarPersonas(int personasCreadas ){
    ListaComensales * lista = new ListaComensales();
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

    while(activo){

        int sleepTime = QRandomGenerator::global()->bounded(tiempoGeneracion, tiempoGeneracion1);

        int personasCreadas = QRandomGenerator::global()->bounded(tiempoGeneracion, tiempoGeneracion1);
        mutexManejador->lock();
        manejadorComensales->colaClientesEnEspera->encolar(generarPersonas(personasCreadas));
        mutexManejador->unlock();
        sleep(5);
        while(pausa){
            sleep(static_cast<unsigned int>(sleepTime));
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
