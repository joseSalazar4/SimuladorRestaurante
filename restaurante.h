#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include "listamesas.h"
#include "cajathread.h"
#include "listameseros.h"
#include "cocinerothread.h"
#include "lavaplatosthread.h"
#include "meserothread.h"
#include "manejadorcomensales.h"
#include "generadorpersonasthread.h"
#include"qurl.h"
struct Restaurante {
public:

    Caja * caja;
    ListaMesas * mesas;
    CajaThread cajaThread;
    ListaMeseros * meseros;
    Lavaplatos * lavaplatos;
    LavaplatosThread lavaplatosThread;
    MeseroThread * arrayMeserosThread[20];
    ManejadorComensales * manejadorComensales;
    GeneradorPersonasThread generadorPersonas;
    Cocina * principal, * pasteleria, * ensaladas;
    QLabel * arrayImagenesMesas[20]=  {};
    int cantMeseros, cantCocineros, cantMesas, cantMesasPorMesero,tiempoGen1,tiempoGen2,mesasSobrantes = 0;
    QMutex * mutexPasteleria , *mutexCocinaFuerte , * mutexEnsaladas, * mutexLavaplatos, * mutexCaja, * mutexManejador;

    Restaurante(int cantidadCocineros,
                int cantidadMeseros,
                int cantidadMesas,
                int cantMesasMesero,
                int tiempoGen1,
                int tiempoGen2,
                QMutex * _mutexCaja,
                QMutex *  _mutexLavaplatos,
                QMutex * _mutexCocina,
                QMutex * _mutexEnsaladas,
                QMutex*  _mutexPasteleria,
                QMutex * _mutexManejador,
                QVector<QVector<QLabel*>> arrayMesas, QLabel * imagenCaja,QLabel * imagenLavaplatos, QLabel * imagenCocina, QLabel * imagenEnsaladas ,QLabel * imagenPostres, QLabel * imagenGen){

        this->mutexCaja = _mutexCaja;
        this->mutexCocinaFuerte = _mutexCocina;
        this->mutexEnsaladas = _mutexEnsaladas;
        this->mutexManejador = _mutexManejador;
        this->mutexPasteleria = _mutexPasteleria;
        this->mutexLavaplatos = _mutexLavaplatos;

        caja = new Caja();
        mesas = new ListaMesas();
        meseros = new ListaMeseros();
        lavaplatos = new Lavaplatos();
        manejadorComensales = new ManejadorComensales();

        Cocinero * cocineroPostres = new Cocinero("postres");
        Cocinero * cocineroEnsaladas = new Cocinero("postres");


        principal = new Cocina("fuerte");
        pasteleria = new Cocina("pasteleria", cocineroPostres);
        ensaladas = new Cocina("ensaladas", cocineroEnsaladas);

        CocineroThread pasteleroThread;
        pasteleroThread.__init__(mutexPasteleria,imagenPostres,cocineroPostres,pasteleria);

        CocineroThread ensaladasThread;
        ensaladasThread.__init__(mutexEnsaladas, imagenEnsaladas, cocineroEnsaladas, ensaladas);

        if(cantidadCocineros == 3){
            Cocinero * cocineroFuerte3= new Cocinero("fuerte");
            Cocinero * cocineroFuerte2 = new Cocinero("fuerte");
            Cocinero * cocineroFuerte1 = new Cocinero("fuerte");

            principal->cocinero1 = cocineroFuerte1;
            principal->cocinero1->tipoCocinero = "fuerte";
            principal->cocinero2 = cocineroFuerte2;
            principal->cocinero2->tipoCocinero = "fuerte";
            principal->cocinero3 = cocineroFuerte3;
            principal->cocinero3->tipoCocinero = "fuerte";


            CocineroThread cocineroFuerteThread;
            cocineroFuerteThread.__init__(mutexCocinaFuerte, imagenCocina,cocineroFuerte1 ,principal);
            cocineroFuerteThread.start();

            CocineroThread cocineroFuerteThread2;
            cocineroFuerteThread2.__init__(mutexCocinaFuerte, imagenCocina,cocineroFuerte2 ,principal);
            cocineroFuerteThread2.start();


            CocineroThread cocineroFuerteThread3;
            cocineroFuerteThread3.__init__(mutexCocinaFuerte, imagenCocina,cocineroFuerte3 ,principal);
            cocineroFuerteThread3.start();

        }

        else if (cantidadCocineros == 2){
            Cocinero * cocineroFuerte1 = new Cocinero("fuerte");
            Cocinero * cocineroFuerte2 = new Cocinero("fuerte");
            principal->cocinero1 = cocineroFuerte1;
            principal->cocinero1->tipoCocinero = "fuerte";
            principal->cocinero2 = cocineroFuerte2;
            principal->cocinero2->tipoCocinero = "fuerte";

            CocineroThread cocineroFuerteThread1;
            cocineroFuerteThread1.__init__(mutexCocinaFuerte, imagenCocina,cocineroFuerte1, principal);

            CocineroThread cocineroFuerteThread2;
            cocineroFuerteThread2.__init__(mutexCocinaFuerte, imagenCocina, cocineroFuerte2,principal);

            cocineroFuerteThread1.start();
            cocineroFuerteThread2.start();

        }

        else{
            Cocinero * cocineroFuerte1 = new Cocinero("fuerte");
            principal->cocinero1 = cocineroFuerte1;
            principal->cocinero1->tipoCocinero = "fuerte";

            CocineroThread cocineroFuerteThread;
            cocineroFuerteThread.__init__(mutexCocinaFuerte, imagenCocina, cocineroFuerte1,principal);

            cocineroFuerteThread.start();

        }




        cantMesas = cantidadMesas;
        cantMeseros = cantidadMeseros;

        for(int i = 0;i<cantidadMeseros;i++){

        }

        if(cantMesas%cantMeseros != 0) mesasSobrantes = cantMesas-(cantMesasMesero*(cantMeseros-1));

        if(mesasSobrantes == 0){
            for(int i = 0;i<cantidadMeseros;i++){
                Mesero * meseroAux = new Mesero(cantMesasMesero);

                MeseroThread * meseroThread = new MeseroThread();
                ListaMesas * listaMesasAsignada = new ListaMesas();

                meseroAux->caja = caja;
                meseroAux->cocina = principal;
                meseroAux->ensaladas = ensaladas;
                meseroAux->pasteleria = pasteleria;
                meseroAux->lavaplatos = lavaplatos;

                for(int j = 0;j<cantMesasMesero;j++){
                    Mesa * mesaAux = new Mesa("Mesa #"+QString::number(j+1));
                    mesaAux->tipoPedido=1;
                    *mesaAux->arrayComensales = arrayMesas[i];
                    mesaAux->imagen = &arrayMesas[i][7]; //ACA VA UN ARRAY DE QLABELS PA ASIGNAR CON UNF FORVEA LO DE EL ORDEN
                    //insertamos en la lista total de mesas
                    mesas->insertarFinal(mesaAux);
                    mesaAux->imagen->show();
                    mesaAux->imagen->setToolTip("Yo estoy activa y esperando clientes");
                    //insertamos en la lista que se asignará a cada mesero y que tiene las mesas que le corresponden
                    listaMesasAsignada->insertarFinal(mesaAux);
                }

                meseroThread->__init__(meseroAux, listaMesasAsignada, mutexPasteleria, mutexEnsaladas, mutexCocinaFuerte, mutexLavaplatos,mutexCaja, mutexManejador);
                qDebug()<<"init al mesero #"+QString::number(i);
                arrayMeserosThread[i] = meseroThread;
                meseros->insertarFinal(meseroAux);
            }

            qDebug()<<"pongo a correr los hilos de mesero";
            for(int i = 0;i<cantidadMeseros;i++){
                arrayMeserosThread[i]->mesero->nombre = "Mesero #"+QString::number(i);
                arrayMeserosThread[i]->start();
            }


        }
        qDebug()<<"init al thread de lavarplatos";
        lavaplatosThread.__init__(lavaplatos, _mutexLavaplatos);
        lavaplatosThread.imagenLavanderia = imagenLavaplatos;
        lavaplatosThread.start();

        cajaThread.__init__(caja,mutexCaja, imagenCaja);
        cajaThread.start();

        ensaladasThread.start();
        pasteleroThread.start();

        generadorPersonas.__init__(manejadorComensales,mutexManejador, tiempoGen1, tiempoGen2);
        generadorPersonas.listaMesas = this->mesas;
        generadorPersonas.cantPersonasGeneradas = imagenGen;
        generadorPersonas.start();
    }

    void Iniciar();
    bool asignarMesa(ListaComensales * lista);   ///ASIGNE MESAS PIENSE QUIEN LLAMA EL METODO A DONDE VEA WINDOW.CPP HKUNA MATATA


};

#endif // RESTAURANTE_H
