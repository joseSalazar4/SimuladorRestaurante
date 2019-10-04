#include "generadorpersonasthread.h"
#include "qdebug.h"

QString GeneradorPersonasThread::generarNombre(){
    QString random;
    random = arrayNombres[rand()%10];
    return random;
}

void GeneradorPersonasThread::__init__(ManejadorComensales * maneja, QMutex * mutex, int t1, int t2){
    pausa = false;
    activo = true;
    tiempoGeneracion = t1;
    tiempoGeneracion1 = t2;
    this->mutexManejador = mutex;
    this->manejadorComensales = maneja;
    srand(static_cast<unsigned int>(time(nullptr)));
}

GeneradorPersonasThread::GeneradorPersonasThread()
{
    tiempoGeneracion = tiempoGeneracion1 = cantidadGenerada = 0;
}

ListaComensales * GeneradorPersonasThread::generarPersonas(int personasCreadas ){

    ListaComensales * lista = new ListaComensales();

    for(int i = 0; i < personasCreadas; i++){
        QString nombre = generarNombre()+QString::number(i);
        qDebug()<<nombre;
        ComensalThread * nuevo = new ComensalThread();
        nuevo->comensal = new Comensal(nombre, platos);
        lista->insertarFinal(nuevo);
    }
    qDebug()<<lista->largo;
    qDebug()<<personasCreadas;
    return lista;
}

void GeneradorPersonasThread::run(){

    while(activo){
        int sleepTime = QRandomGenerator::global()->bounded(tiempoGeneracion, tiempoGeneracion1);
        int personasCreadas = QRandomGenerator::global()->bounded(1, 6);
        cantPersonasGeneradas->setText(QString::number(personasCreadas));
        mutexManejador->lock();
        manejadorComensales->colaClientesEnEspera->encolar(generarPersonas(personasCreadas));
        Mesa * mesaAux = listaMesas->buscarDisponibilidad();
        if(mesaAux && manejadorComensales->colaClientesEnEspera->frente != nullptr){
            mesaAux->listaComensales = manejadorComensales->colaClientesEnEspera->desencolar();
            mesaAux->ocupada=true;
            ComensalThread * comensalAux = mesaAux->listaComensales->primerNodo;
            cantidadFamiliasCola->setText(QString::number(manejadorComensales->colaClientesEnEspera->largo));
            for(int i = 0;i<mesaAux->listaComensales->largo;i++){
                comensalAux->comensal->tiempoComer1Fuerte = mesaAux->intervaloFuerte1;
                comensalAux->comensal->tiempoComer2Fuerte = mesaAux->intervaloFuerte2;

                comensalAux->comensal->tiempoComerPostre1 = mesaAux->intervaloPostres1;
                comensalAux->comensal->tiempoComerPostre2 = mesaAux->intervaloPostres2;

                comensalAux->comensal->tiempoComerEnsalada1 = mesaAux->intervaloEnsaladas1;
                comensalAux->comensal->tiempoComerEnsalada2 = mesaAux->intervaloEnsaladas2;
                comensalAux->comensal->imagenPersona =  mesaAux->arrayComensales[i];
                comensalAux->comensal->imagenPersona->show();
                comensalAux->mutexComensal = mesaAux->arrayQmutex[i];
                comensalAux = comensalAux->siguiente;
            }
        }
        cantidadFamiliasCola->setText(QString::number(manejadorComensales->colaClientesEnEspera->largo));
        mutexManejador->unlock();
        sleep(static_cast<unsigned int>(sleepTime));
        while(pausa) sleep(1);
    }
}


void GeneradorPersonasThread::pausar(){
    this->pausa = true;
}

void GeneradorPersonasThread::continuar(){
    this->pausa = false;
}
