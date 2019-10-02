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
    ListaPlatos * listaPlatos;
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
                QVector<QVector<QLabel*>> arrayMesas,
                QLabel * imagenCaja,
                QLabel * imagenLavaplatos, QLabel * imagenCocina, QLabel * imagenEnsaladas ,QLabel * imagenPostres, QLabel * imagenGen){


        listaPlatos =  crearMenu();

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

        CocineroThread *pasteleroThread = new CocineroThread();
        pasteleroThread->__init__(mutexPasteleria,imagenPostres,cocineroPostres,pasteleria);

        CocineroThread * ensaladasThread = new CocineroThread();
        ensaladasThread->__init__(mutexEnsaladas, imagenEnsaladas, cocineroEnsaladas, ensaladas);

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

            CocineroThread *cocineroFuerteThread1=new CocineroThread () ;
            cocineroFuerteThread1->__init__(mutexCocinaFuerte, imagenCocina,cocineroFuerte1, principal);

            CocineroThread *cocineroFuerteThread2=new CocineroThread () ;
            cocineroFuerteThread2->__init__(mutexCocinaFuerte, imagenCocina, cocineroFuerte2,principal);

            cocineroFuerteThread1->start();
            cocineroFuerteThread2->start();

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
                    mesaAux->arrayComensales = arrayMesas[i];
                    mesaAux->imagen = arrayMesas[i][6]; //ACA VA UN ARRAY DE QLABELS PA ASIGNAR CON UNF FORVEA LO DE EL ORDEN
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

        ensaladasThread->start();
        pasteleroThread->start();

        generadorPersonas.__init__(manejadorComensales,mutexManejador, tiempoGen1, tiempoGen2);
        generadorPersonas.listaMesas = this->mesas;
        generadorPersonas.cantPersonasGeneradas = imagenGen;
        generadorPersonas.start();
    }

    ListaPlatos * crearMenu(){

        //The menu that will be used by clients
        ListaPlatos * menuRestaurante = new ListaPlatos();

        //Creation of the Ingredients
        Ingrediente * ingrediente = new Ingrediente();
        ListaIngredientes * listaIngredientesGenerica = new ListaIngredientes();

        listaIngredientesGenerica->insertarFinal(ingrediente);

        //Creation of the recipes


        menuRestaurante->insertarFinal("1","Ensalada kartoffelsalat",2500,20,20);
        menuRestaurante->insertarFinal("1","Ensalada mixta",2500,20,20);
        menuRestaurante->insertarFinal("1","Ensalada Caprese",2500,20,20);
        menuRestaurante->insertarFinal("1","Ensalada Waldorf",2500,20,20);
        menuRestaurante->insertarFinal("1","Ensalada rusa",2500,20,20);
        menuRestaurante->insertarFinal("1","Ensalada de col ",2500,20,20);
        menuRestaurante->insertarFinal("1","Ensalada griega",2500,20,20);
        menuRestaurante->insertarFinal("1","Ensalada alemana",2500,20,20);
        menuRestaurante->insertarFinal("1","Ensalada libanesa",2500,20,20);
        menuRestaurante->insertarFinal("1","Ensalada con atun",2500,20,20);


        menuRestaurante->insertarFinal("2","Pizza de Jamón y Hongos",10,2500,20,20,);
        menuRestaurante->insertarFinal("2","Pollo Frito",11,2500,20,20);
        menuRestaurante->insertarFinal("2","Hamburguesa sencilla",12,2500,20,20);
        menuRestaurante->insertarFinal("2","Hamburguesa Doble",13,2500,20,20);
        menuRestaurante->insertarFinal("2","Hamburguesa Cuadruple",14,2500,20,20);
        menuRestaurante->insertarFinal("2","Hamburguesa Suprema",15,2500,20,20);
        menuRestaurante->insertarFinal("2","Hamburguesa de Infarto",16,2500,20,20);
        menuRestaurante->insertarFinal("2","Pintico",17,2500,20,20);
        menuRestaurante->insertarFinal("2","Calzone",18,2500,20,20);
        menuRestaurante->insertarFinal("2","Burrito Jumbo",19,2500,20,20);

        menuRestaurante->insertarFinal("3","Helado de Fresa",21,2500,20,20);
        menuRestaurante->insertarFinal("3","Helado de Vainilla",22,2500,20,20);
        menuRestaurante->insertarFinal("3","Tiramizú",23,2500,20,20);
        menuRestaurante->insertarFinal("3","Tres Leches",24,2500,20,20);
        menuRestaurante->insertarFinal("3","Cheesecake",25,2500,20,20);
        menuRestaurante->insertarFinal("3","Arroz con Leche ",26,2500,20,20);
        menuRestaurante->insertarFinal("3","Gelatina",27,2500,20,20);
        menuRestaurante->insertarFinal("3","Gelatina con helados ",28,2500,20,20);
        menuRestaurante->insertarFinal("3","Torta de chocolate",29,2500,20,20);
        menuRestaurante->insertarFinal("3","Pastafrola",30,2500,20,20);


    }


};

#endif // RESTAURANTE_H
