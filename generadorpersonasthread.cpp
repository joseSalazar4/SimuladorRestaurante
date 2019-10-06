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
        ComensalThread * nuevo = new ComensalThread();
        nuevo->comensal = new Comensal(nombre, platos);
        QMutex * mutexComensal = new QMutex();
        nuevo->mutexComensal = mutexComensal;
        nuevo->imagenComensal = nuevo->comensal->imagenPersona;
        lista->insertarFinal(nuevo);

        ComensalThread * tmp = lista->primerNodo;

        while(tmp){
            tmp->start();
            tmp = tmp->siguiente;
        }

    }
    return lista;
}

void GeneradorPersonasThread::run(){
    sleep(3);
    while(activo){
        int sleepTime = QRandomGenerator::global()->bounded(tiempoGeneracion, tiempoGeneracion1);
        int personasCreadas = QRandomGenerator::global()->bounded(1, 6);
        cantPersonasGeneradas->setText(QString::number(personasCreadas));
        mutexManejador->tryLock(10);
        manejadorComensales->colaClientesEnEspera->encolar(generarPersonas(personasCreadas));
        Mesa * mesaAux = listaMesas->buscarDisponibilidad();
        if(mesaAux && manejadorComensales->colaClientesEnEspera->frente != nullptr){
            mesaAux->listaComensales = manejadorComensales->colaClientesEnEspera->desencolar();
            mesaAux->imagen->setToolTip("Hay "+QString::number(mesaAux->listaComensales->largo)+" comensales");
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

                comensalAux->comensal->probabilidadPedirPostre = probPostre;
                comensalAux->comensal->probabilidadPedirPlatoFuerte = probPlatoFuerte;
                comensalAux->comensal->probabilidadPedirEnsalada = probEnsalada;

                comensalAux->comensal->imagenPersona =  mesaAux->arrayComensales[i];
                comensalAux->comensal->mesaSentado = mesaAux->ID;
                comensalAux->comensal->imagenPersona->show();
                comensalAux->comensal->imagenPersona->setToolTip("Esperando al mesero");
                comensalAux->mutexComensal = mesaAux->arrayQmutex[i];
                comensalAux = comensalAux->siguiente;
            }
            mutexManejador->unlock();
        }
        else mutexManejador->unlock();
        cantidadFamiliasCola->setText(QString::number(manejadorComensales->colaClientesEnEspera->largo));
        sleep(static_cast<unsigned int>(sleepTime));
        while(pausa){
            sleep(1);
            //cantPersonasGeneradas->text().set;
            cantPersonasGeneradas->setText("Closed");
        }
    }
}


void GeneradorPersonasThread::pausar(){
    this->pausa = true;
}

void GeneradorPersonasThread::continuar(){
    this->pausa = false;
}
