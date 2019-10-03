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
    CajaThread * cajaThread;
    ListaMeseros * meseros;
    Lavaplatos * lavaplatos;
    LavaplatosThread * lavaplatosThread;
    MeseroThread * arrayMeserosThread[20];
    ManejadorComensales * manejadorComensales;
    GeneradorPersonasThread generadorPersonas;
    Cocina * principal, * pasteleria, * ensaladas;
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

        }
      //Este es el caso en que sean mas mesas que meseros y no sea un numero divisible entonces se deben acomodar
        else{
            for(int i = 0;i<cantidadMeseros;i++){
                Mesero * meseroAux = new Mesero(cantMesasMesero);

                MeseroThread * meseroThread = new MeseroThread();
                ListaMesas * listaMesasAsignada = new ListaMesas();


                meseroAux->caja = caja;
                meseroAux->cocina = principal;
                meseroAux->ensaladas = ensaladas;
                meseroAux->pasteleria = pasteleria;
                meseroAux->lavaplatos = lavaplatos;

                if(i==cantidadMeseros--){
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
                else{
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
                }

                meseroThread->__init__(meseroAux, listaMesasAsignada, mutexPasteleria, mutexEnsaladas, mutexCocinaFuerte, mutexLavaplatos,mutexCaja, mutexManejador);
                qDebug()<<"init al mesero #"+QString::number(i);
                arrayMeserosThread[i] = meseroThread;
                meseros->insertarFinal(meseroAux);
            }
        }

        qDebug()<<"pongo a correr los hilos de mesero";
        for(int i = 0;i<cantidadMeseros;i++){
            Cola * nuevaCola = new Cola();
            arrayMeserosThread[i]->mesero->colaPeticiones = nuevaCola;
            arrayMeserosThread[i]->mesero->nombre = "Mesero #"+QString::number(i);
            arrayMeserosThread[i]->start();
        }

        qDebug()<<"init al thread de lavarplatos";
        LavaplatosThread * lavapl  = new LavaplatosThread();
        lavaplatosThread = lavapl;

        lavaplatosThread->__init__(lavaplatos, _mutexLavaplatos);
        lavaplatosThread->imagenLavanderia = imagenLavaplatos;
        lavaplatosThread->start();

        CajaThread * cajaThrd = new CajaThread();
        cajaThread = cajaThrd;

        cajaThread->__init__(caja,mutexCaja, imagenCaja);
        cajaThread->start();

        ensaladasThread->start();
        pasteleroThread->start();

        generadorPersonas.__init__(manejadorComensales,mutexManejador, tiempoGen1, tiempoGen2);
        generadorPersonas.platos = listaPlatos;
        generadorPersonas.listaMesas = this->mesas;
        generadorPersonas.cantPersonasGeneradas = imagenGen;
        generadorPersonas.start();
    }







    ListaPlatos * crearMenu(){

        //The menu that will be used by clients
        ListaPlatos * menuRestaurante = new ListaPlatos();

        //Creation of the Ingredients

         Ingrediente * sal = new Ingrediente("Sal", 1);
         Ingrediente * aceiteOliva = new Ingrediente("Aceite de Oliva", 1);
         Ingrediente * vinagre = new Ingrediente("Vinagre", 1);
         Ingrediente * culantro = new Ingrediente("Culantro", 1);
         Ingrediente * pimienta = new Ingrediente("Pimienta", 1);

        //Ingredientes ensaladas
        Ingrediente * lechuga = new Ingrediente("Lechuga", 3);
        Ingrediente * tomate = new Ingrediente("Tomate", 3);
        Ingrediente * zanahoria = new Ingrediente("Zanahoria", 2);
        Ingrediente * cebolla = new Ingrediente("Cebolla", 1);
        Ingrediente * mayonesa = new Ingrediente("Mayonesa", 3);
        Ingrediente * papa = new Ingrediente("Papa", 3);
        Ingrediente * olivas = new Ingrediente("Olivas Negras", 7);
        Ingrediente * quesoFeta = new Ingrediente("Queso Feta", 3);
        Ingrediente * pimientos = new Ingrediente("Pimientos", 3);
        Ingrediente * aceitunas = new Ingrediente("Aceitunas", 3);
        Ingrediente * pepino = new Ingrediente("Pepino", 4);
        Ingrediente * atun = new Ingrediente("Atun", 1);
        Ingrediente * apio = new Ingrediente("Apio", 3);
        Ingrediente * nueces = new Ingrediente("Nueces", 12);
        Ingrediente * albahaca = new Ingrediente("Albahaca", 3);
        Ingrediente * salchichas = new Ingrediente("Salchichas", 5);
        Ingrediente * pepinillos = new Ingrediente("Pepinillos", 3);
        Ingrediente * mostaza = new Ingrediente("Mostaza", 3);
        Ingrediente * maizDulce = new Ingrediente("Maíz dulce", 3);
        Ingrediente * quesoMozarella = new Ingrediente("Queso Mozarella", 3);
        Ingrediente * col = new Ingrediente("Col", 3);
        Ingrediente * azucar = new Ingrediente("Azúcar", 1);
        Ingrediente * crotones = new Ingrediente("Crotones", 12);
        Ingrediente * aderezo = new Ingrediente("Aderezo", 1);
        Ingrediente * yogur = new Ingrediente("Yogur", 1);
        Ingrediente * limon = new Ingrediente("Limón", 1);

        //Ingredientes platos fuertes
        Ingrediente * pollo = new Ingrediente("Pollo", 1);
        Ingrediente * arroz = new Ingrediente("Arroz", 1);
        Ingrediente * jamon = new Ingrediente("Jamón", 3);
        Ingrediente * hongos = new Ingrediente("Hongos", 10);
        Ingrediente * natilla = new Ingrediente("Natilla", 1);
        Ingrediente * tocineta = new Ingrediente("Tocineta", 3);
        Ingrediente * frijoles = new Ingrediente("Frijoles", 1);
        Ingrediente * panPizza = new Ingrediente("Pan Pizza", 1);
        Ingrediente * tortaS = new Ingrediente("Torta de carne", 1);
        Ingrediente * tortaD = new Ingrediente("Torta de carne", 2);
        Ingrediente * tortaC = new Ingrediente("Torta de carne", 4);
        Ingrediente * salsaLizano= new Ingrediente("Salza Lizano", 1);
        Ingrediente * quesoBlanco = new Ingrediente("Queso blanco", 1);
        Ingrediente * carneMolida = new Ingrediente("Carne molida", 1);
        Ingrediente * papasFritas = new Ingrediente("Papas fritas", 15);
        Ingrediente * salsaTomate = new Ingrediente("Salsa de tomate", 1);
        Ingrediente * arosCebolla = new Ingrediente("Aros de cebolla", 3);
        Ingrediente * quesoAmarillo = new Ingrediente("Queso amarillo", 3);
        Ingrediente * tortillasHarina = new Ingrediente("Tortillas de harina", 2);
        Ingrediente * panHamburguesa = new Ingrediente("Pan de hamburguesa", 2);

        //Ingredientes postres
        Ingrediente * cafe = new Ingrediente("Café", 10);
        Ingrediente * harina = new Ingrediente("Harina", 1);
        Ingrediente * canela = new Ingrediente("Canela", 5);
        Ingrediente * huevos = new Ingrediente("Huevos", 2);
        Ingrediente * gelatina = new Ingrediente("Gelatina", 1);
        Ingrediente * bizcocho = new Ingrediente("Bizcocho", 3);
        Ingrediente * vainilla = new Ingrediente("Vainilla", 1);
        Ingrediente * leche = new Ingrediente("Leche entera", 1);
        Ingrediente * chocolate = new Ingrediente("Chocolate", 1);
        Ingrediente * mermelada = new Ingrediente("Mermelada", 1);
        Ingrediente * clavos = new Ingrediente("Clavos de olor", 20);
        Ingrediente * cremaLeche = new Ingrediente("Crema de leche", 1);
        Ingrediente * heladoFresa = new Ingrediente("Helado de fresa", 2);
        Ingrediente * lecheEvaporada = new Ingrediente("Leche evaporada", 1);
        Ingrediente * lecheCondensada = new Ingrediente("Leche condensada", 1);
        Ingrediente * heladoVainilla = new Ingrediente("Helado de vainilla", 2);
        Ingrediente * dulceMembrillo = new Ingrediente("Dulce de membrillo", 2);

        //Lista de ensaladas
        ListaIngredientes * listaCol = new ListaIngredientes();
        ListaIngredientes * listaAtun = new ListaIngredientes();
        ListaIngredientes * listaRusa = new ListaIngredientes();
        ListaIngredientes * listaCesar = new ListaIngredientes();
        ListaIngredientes * listaMixta = new ListaIngredientes();
        ListaIngredientes * listaGriega = new ListaIngredientes();
        ListaIngredientes * listaCaprese = new ListaIngredientes();
        ListaIngredientes * listaWaldorf = new ListaIngredientes();
        ListaIngredientes * listaLibanesa = new ListaIngredientes();
        ListaIngredientes * listaKartoffesalat = new ListaIngredientes();

        //Lista de platos fuertes
        ListaIngredientes * listaPintico = new ListaIngredientes();
        ListaIngredientes * listaPizzaJamon = new ListaIngredientes();
        ListaIngredientes * listaPolloFrito = new ListaIngredientes();
        ListaIngredientes * listaBurritoJumbo = new ListaIngredientes();
        ListaIngredientes * listaPapasSupremas = new ListaIngredientes();
        ListaIngredientes * listaHamburguesaDoble = new ListaIngredientes();
        ListaIngredientes * listaHamburguesaSuprema = new ListaIngredientes();
        ListaIngredientes * listaHamburguesaInfarto = new ListaIngredientes();
        ListaIngredientes * listaHamburguesaSencilla = new ListaIngredientes();
        ListaIngredientes * listaHamburguesaCuadruple = new ListaIngredientes();

        //Lista de postres
        ListaIngredientes * listaTiramisu = new ListaIngredientes();
        ListaIngredientes * listaGelatina = new ListaIngredientes();
        ListaIngredientes * listaPastafrola = new ListaIngredientes();
        ListaIngredientes * listaTresLeches = new ListaIngredientes();
        ListaIngredientes * listaCheesecake = new ListaIngredientes();
        ListaIngredientes * listaHeladoFresa = new ListaIngredientes();
        ListaIngredientes * listaArrozConLeche = new ListaIngredientes();
        ListaIngredientes * listaHeladoVainilla = new ListaIngredientes();
        ListaIngredientes * listaTortaChocolate = new ListaIngredientes();
        ListaIngredientes * listaGelatinaConHelados = new ListaIngredientes();

        //Ensalada Kartoffesalat
        listaKartoffesalat->insertarFinal(papa);
        listaKartoffesalat->insertarFinal(salchichas);
        listaKartoffesalat->insertarFinal(mayonesa);
        listaKartoffesalat->insertarFinal(mostaza);
        //Ensalada Mixta
        listaMixta->insertarFinal(lechuga);
        listaMixta->insertarFinal(tomate);
        listaMixta->insertarFinal(zanahoria);
        listaMixta->insertarFinal(atun);
        listaMixta->insertarFinal(aceitunas);
        listaMixta->insertarFinal(cebolla);
        listaMixta->insertarFinal(maizDulce);
        //Ensalada Caprese
        listaCaprese->insertarFinal(tomate);
        listaCaprese->insertarFinal(albahaca);
        listaCaprese->insertarFinal(sal);
        listaCaprese->insertarFinal(quesoMozarella);
        //Ensalada Waldorf
        listaWaldorf->insertarFinal(lechuga);
        listaWaldorf->insertarFinal(apio);
        listaWaldorf->insertarFinal(nueces);
        listaWaldorf->insertarFinal(vinagre);
        listaWaldorf->insertarFinal(sal);
        listaWaldorf->insertarFinal(aceiteOliva);
        //Ensalada Rusa
        listaRusa->insertarFinal(papa);
        listaRusa->insertarFinal(cebolla);
        listaRusa->insertarFinal(zanahoria);
        listaRusa->insertarFinal(pollo);
        listaRusa->insertarFinal(mayonesa);
        listaRusa->insertarFinal(sal);
        //Ensalada de Col
        listaCol->insertarFinal(pimientos);
        listaCol->insertarFinal(aceiteOliva);
        listaCol->insertarFinal(sal);
        listaCol->insertarFinal(azucar);
        listaCol->insertarFinal(col);
        listaCol->insertarFinal(zanahoria);
        //Ensalada Griega
        listaGriega->insertarFinal(tomate);
        listaGriega->insertarFinal(pepino);
        listaGriega->insertarFinal(pimientos);
        listaGriega->insertarFinal(cebolla);
        listaGriega->insertarFinal(olivas);
        listaGriega->insertarFinal(quesoFeta);
        //Ensalada César
        listaCesar->insertarFinal(lechuga);
        listaCesar->insertarFinal(pollo);
        listaCesar->insertarFinal(aderezo);
        listaCesar->insertarFinal(crotones);
        //Ensalada Libanesa
        listaLibanesa->insertarFinal(tomate);
        listaLibanesa->insertarFinal(pepino);
        listaLibanesa->insertarFinal(aceiteOliva);
        listaLibanesa->insertarFinal(cebolla);
        listaLibanesa->insertarFinal(aceitunas);
        listaLibanesa->insertarFinal(yogur);
        //Ensalada Atun
        listaAtun->insertarFinal(atun);
        listaAtun->insertarFinal(cebolla);
        listaAtun->insertarFinal(apio);
        listaAtun->insertarFinal(mayonesa);
        listaAtun->insertarFinal(limon);

        //Plato Pizza de jamón y hongos
        listaPizzaJamon->insertarFinal(panPizza);
        listaPizzaJamon->insertarFinal(jamon);
        listaPizzaJamon->insertarFinal(hongos);
        listaPizzaJamon->insertarFinal(quesoMozarella);
        listaPizzaJamon->insertarFinal(salsaTomate);
        //Plato Pollo frito
        listaPolloFrito->insertarFinal(pollo);
        listaPolloFrito->insertarFinal(sal);
        listaPizzaJamon->insertarFinal(pimienta);
        //Plato Hamburguesa sencilla
        listaHamburguesaSencilla->insertarFinal(panHamburguesa);
        listaHamburguesaSencilla->insertarFinal(tomate);
        listaHamburguesaSencilla->insertarFinal(lechuga);
        listaHamburguesaSencilla->insertarFinal(tortaS);
        listaHamburguesaSencilla->insertarFinal(pepinillos);
        listaHamburguesaSencilla->insertarFinal(quesoAmarillo);
        //Plato Hamburguesa doble
        listaHamburguesaDoble->insertarFinal(panHamburguesa);
        listaHamburguesaDoble->insertarFinal(tomate);
        listaHamburguesaDoble->insertarFinal(lechuga);
        listaHamburguesaDoble->insertarFinal(tortaD);
        listaHamburguesaDoble->insertarFinal(pepinillos);
        listaHamburguesaDoble->insertarFinal(quesoAmarillo);
        //Plato Hamburguesa cuádruple
        listaHamburguesaCuadruple->insertarFinal(panHamburguesa);
        listaHamburguesaCuadruple->insertarFinal(tomate);
        listaHamburguesaCuadruple->insertarFinal(lechuga);
        listaHamburguesaCuadruple->insertarFinal(tortaC);
        listaHamburguesaCuadruple->insertarFinal(pepinillos);
        listaHamburguesaCuadruple->insertarFinal(quesoAmarillo);
        listaHamburguesaCuadruple->insertarFinal(papasFritas);
        //Plato Hamburguesa Suprema
        listaHamburguesaSuprema->insertarFinal(panHamburguesa);
        listaHamburguesaSuprema->insertarFinal(tomate);
        listaHamburguesaSuprema->insertarFinal(lechuga);
        listaHamburguesaSuprema->insertarFinal(tortaD);
        listaHamburguesaSuprema->insertarFinal(pepinillos);
        listaHamburguesaSuprema->insertarFinal(quesoAmarillo);
        listaHamburguesaSuprema->insertarFinal(quesoBlanco);
        listaHamburguesaSuprema->insertarFinal(tocineta);
        listaHamburguesaSuprema->insertarFinal(papasFritas);
        //Plato Hamburguesa de Infarto
        listaHamburguesaInfarto->insertarFinal(panHamburguesa);
        listaHamburguesaInfarto->insertarFinal(tomate);
        listaHamburguesaInfarto->insertarFinal(lechuga);
        listaHamburguesaInfarto->insertarFinal(tortaC);
        listaHamburguesaInfarto->insertarFinal(pepinillos);
        listaHamburguesaInfarto->insertarFinal(pepino);
        listaHamburguesaInfarto->insertarFinal(tocineta);
        listaHamburguesaInfarto->insertarFinal(jamon);
        listaHamburguesaInfarto->insertarFinal(quesoAmarillo);
        listaHamburguesaInfarto->insertarFinal(quesoBlanco);
        listaHamburguesaInfarto->insertarFinal(papasFritas);
        listaHamburguesaInfarto->insertarFinal(arosCebolla);
        //Plato Pintico
        listaPintico->insertarFinal(arroz);
        listaPintico->insertarFinal(frijoles);
        listaPintico->insertarFinal(salsaLizano);
        listaPintico->insertarFinal(culantro);
        listaPintico->insertarFinal(pimientos);
        //Plato Papas Supremas
        listaPapasSupremas->insertarFinal(papasFritas);
        listaPapasSupremas->insertarFinal(natilla);
        listaPapasSupremas->insertarFinal(carneMolida);
        listaPapasSupremas->insertarFinal(quesoAmarillo);
        listaPapasSupremas->insertarFinal(sal);
        //Plato Burrito Jumbo
        listaBurritoJumbo->insertarFinal(tortillasHarina);
        listaBurritoJumbo->insertarFinal(carneMolida);
        listaBurritoJumbo->insertarFinal(frijoles);
        listaBurritoJumbo->insertarFinal(quesoAmarillo);
        listaBurritoJumbo->insertarFinal(natilla);

        //Postre Helado de fresa
        listaHeladoFresa->insertarFinal(heladoFresa);
        //Postre Helado de vainilla
        listaHeladoVainilla->insertarFinal(heladoVainilla);
        //Postre Tiramisú
        listaTiramisu->insertarFinal(bizcocho);
        listaTiramisu->insertarFinal(cafe);
        listaTiramisu->insertarFinal(chocolate);
        listaTiramisu->insertarFinal(azucar);
        //Postre Tres Leches
        listaTresLeches->insertarFinal(lecheCondensada);
        listaTresLeches->insertarFinal(lecheEvaporada);
        listaTresLeches->insertarFinal(cremaLeche);
        listaTresLeches->insertarFinal(azucar);
        listaTresLeches->insertarFinal(vainilla);
        //Postre Cheescake
        listaCheesecake->insertarFinal(vainilla);
        listaCheesecake->insertarFinal(mermelada);
        listaCheesecake->insertarFinal(cremaLeche);
        listaCheesecake->insertarFinal(azucar);
        listaCheesecake->insertarFinal(huevos);
        //Postre Arroz con Leche
        listaArrozConLeche->insertarFinal(arroz);
        listaArrozConLeche->insertarFinal(leche);
        listaArrozConLeche->insertarFinal(canela);
        listaArrozConLeche->insertarFinal(azucar);
        listaArrozConLeche->insertarFinal(clavos);
        //Postre Gelatina
        listaGelatina->insertarFinal(gelatina);
        //Postre Gelatina con helados
        listaGelatinaConHelados->insertarFinal(gelatina);
        listaGelatinaConHelados->insertarFinal(heladoFresa);
        listaGelatinaConHelados->insertarFinal(heladoVainilla);
        //Postre Torta de chocolate
        listaTortaChocolate->insertarFinal(lecheCondensada);
        listaTortaChocolate->insertarFinal(lecheEvaporada);
        listaTortaChocolate->insertarFinal(chocolate);
        listaTortaChocolate->insertarFinal(vainilla);
        //Postre Pastafrola
        listaPastafrola->insertarFinal(harina);
        listaPastafrola->insertarFinal(azucar);
        listaPastafrola->insertarFinal(huevos);
        listaPastafrola->insertarFinal(vainilla);
        listaPastafrola->insertarFinal(dulceMembrillo);

        //Creation of the recipes

        //Entradas
        menuRestaurante->insertarFinal("1","Ensalada kartoffelsalat",1,2500,15,10, listaKartoffesalat);
        menuRestaurante->insertarFinal("1","Ensalada mixta",2,2500,20,20,listaMixta);
        menuRestaurante->insertarFinal("1","Ensalada Caprese",3,2000,20,20,listaCaprese);
        menuRestaurante->insertarFinal("1","Ensalada Waldorf",4,2500,20,20,listaWaldorf);
        menuRestaurante->insertarFinal("1","Ensalada rusa",5,2000,20,20,listaRusa);
        menuRestaurante->insertarFinal("1","Ensalada de col ",6,2000,8,5,listaCol);
        menuRestaurante->insertarFinal("1","Ensalada griega",7,2500,20,20,listaGriega);
        menuRestaurante->insertarFinal("1","Ensalada César",8,1250,20,20,listaCesar);
        menuRestaurante->insertarFinal("1","Ensalada libanesa",9,2500,20,20,listaLibanesa);
        menuRestaurante->insertarFinal("1","Ensalada con atun",10,1500,20,20,listaAtun);

        //Fuertes
        menuRestaurante->insertarFinal("2","Pizza de Jamón y Hongos",11,3000,25,20,listaPizzaJamon);
        menuRestaurante->insertarFinal("2","Pollo Frito",12,2500,12,8,listaPolloFrito);
        menuRestaurante->insertarFinal("2","Hamburguesa sencilla",13,2000,12,8,listaHamburguesaSencilla);
        menuRestaurante->insertarFinal("2","Hamburguesa Doble",14,2500,15,10,listaHamburguesaDoble);
        menuRestaurante->insertarFinal("2","Hamburguesa Cuadruple",15,2800,20,15,listaHamburguesaCuadruple);
        menuRestaurante->insertarFinal("2","Hamburguesa Suprema",16,3000,25,20,listaHamburguesaSuprema);
        menuRestaurante->insertarFinal("2","Hamburguesa de Infarto",17,3750,30,25,listaHamburguesaInfarto);
        menuRestaurante->insertarFinal("2","Pintico",18,2500,20,10,listaPintico);
        menuRestaurante->insertarFinal("2","Papas Supremas",19,2000,15,10,listaPapasSupremas);
        menuRestaurante->insertarFinal("2","Burrito Jumbo",20,2000,15,10,listaBurritoJumbo);

        //Entradas
        menuRestaurante->insertarFinal("3","Helado de Fresa",21,800,5,5,listaHeladoFresa);
        menuRestaurante->insertarFinal("3","Helado de Vainilla",22,800,5,5,listaHeladoVainilla);
        menuRestaurante->insertarFinal("3","Tiramisú",23,1500,20,20,listaTiramisu);
        menuRestaurante->insertarFinal("3","Tres Leches",24,1500,20,15,listaTresLeches);
        menuRestaurante->insertarFinal("3","Cheesecake",25,2000,20,15,listaCheesecake);
        menuRestaurante->insertarFinal("3","Arroz con Leche ",26,1500,15,10,listaArrozConLeche);
        menuRestaurante->insertarFinal("3","Gelatina",27,1000,5,5,listaGelatina);
        menuRestaurante->insertarFinal("3","Gelatina con helados",28,1500,8,5,listaGelatinaConHelados);
        menuRestaurante->insertarFinal("3","Torta de chocolate",29,2500,25,15,listaTortaChocolate);
        menuRestaurante->insertarFinal("3","Pastafrola",30,2500,15,10,listaPastafrola);

        return menuRestaurante;
    }



};

#endif // RESTAURANTE_H
