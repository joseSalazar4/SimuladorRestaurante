#include "MainWindow.h"
#include "qdebug.h"
#include "ui_mainwindow.h"
#include "qtextbrowser.h"
//#include <unistd.h>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->labelGenerador->setStyleSheet("QLabel {color : white; }");
    ui->labelGenerador_2->setStyleSheet("QLabel {color : white; }");
    ui->labelCajaInfo->setStyleSheet("QLabel {color : white; }");
    ui->labelPostresInfo->setStyleSheet("QLabel {color : white; }");
    ui->labelLavaplatosInfo->setStyleSheet("QLabel {color : white; }");
    ui->labelEnsaladasInfo->setStyleSheet("QLabel {color : white; }");
    ui->labelCocinaFuerteInfo->setStyleSheet("QLabel {color : white; }");
    ui->labelCocinaFuerteInfo_3->setStyleSheet("QLabel {color : white; }");
    ui->labelCocinaFuerteInfo_2->setStyleSheet("QLabel {color : white; }");
    ui->labelGeneradorCola->setStyleSheet("QLabel {color : white; }");


    ui->labelCocinaFuerteInfo->hide();
    ui->labelCocinaFuerteInfo_3->hide();
    ui->labelCocinaFuerteInfo_2->hide();
    ui->pushButton_2->hide();
    ui->labelDatosCajera->setStyleSheet("QLabel {color : white; }");
    ui->labelDatosFuerte->setStyleSheet("QLabel {color : white; }");
    ui->labelDatosPostres->setStyleSheet("QLabel {color : white; }");
    ui->labelDatosEnsalada->setStyleSheet("QLabel {color : white; }");
    show();

    botonesMesas = {ui->pushMesa_1,ui->pushMesa_2, ui->pushMesa_3,ui->pushMesa_4,ui->pushMesa_5,
                    ui->pushMesa_6,ui->pushMesa_7,ui->pushMesa_8,ui->pushMesa_9,ui->pushMesa_10,ui->pushMesa_11,
                    ui->pushMesa_12,ui->pushMesa_13,ui->pushMesa_14,ui->pushMesa_15,ui->pushMesa_16,
                    ui->pushMesa_17,ui->pushMesa_18,ui->pushMesa_19,ui->pushMesa_20};

    arrayMesas = {{ui->c1,ui->c2,ui->c3,ui->c4,ui->c5,ui->c6, ui->m1},
                  {ui->c7,ui->c8,ui->c9,ui->c10,ui->c11,ui->c12, ui->m2},
                  {ui->c13,ui->c14,ui->c15,ui->c16,ui->c17,ui->c18, ui->m3},
                  {ui->c19,ui->c20,ui->c21,ui->c22,ui->c23,ui->c24, ui->m4},
                  {ui->c25,ui->c26,ui->c27,ui->c28,ui->c29,ui->c30, ui->m5},
                  {ui->c31,ui->c32,ui->c33,ui->c34,ui->c35,ui->c36, ui->m6},
                  {ui->c37,ui->c38,ui->c39,ui->c40,ui->c41,ui->c42, ui->m7},
                  {ui->c43,ui->c44,ui->c45,ui->c46,ui->c47,ui->c48, ui->m8},
                  {ui->c49,ui->c50,ui->c51,ui->c52,ui->c53,ui->c54, ui->m9},
                  {ui->c55,ui->c56,ui->c57,ui->c58,ui->c59,ui->c60, ui->m10},
                  {ui->c61,ui->c62,ui->c63,ui->c64,ui->c65,ui->c66, ui->m11},
                  {ui->c67,ui->c68,ui->c69,ui->c70,ui->c71,ui->c72, ui->m12},
                  {ui->c73,ui->c74,ui->c75,ui->c76,ui->c77,ui->c78, ui->m13},
                  {ui->c79,ui->c80,ui->c81,ui->c82,ui->c83,ui->c84, ui->m14},
                  {ui->c85,ui->c86,ui->c87,ui->c88,ui->c89,ui->c90, ui->m15},
                  {ui->c91,ui->c92,ui->c93,ui->c94,ui->c95,ui->c96, ui->m16},
                  {ui->c97,ui->c98,ui->c99,ui->c100,ui->c101,ui->c102, ui->m17},
                  {ui->c103,ui->c104,ui->c105,ui->c106,ui->c107,ui->c108, ui->m18},
                  {ui->c109,ui->c110,ui->c111,ui->c112,ui->c113,ui->c114, ui->m19},
                  {ui->c115,ui->c116,ui->c117,ui->c118,ui->c119,ui->c120, ui->m20}};

    for(int i = 0;i<20;i++)
        for(int j = 0;j<7;j++){
            arrayMesas[i][j]->hide();
        }
    arrayMeseros = {ui->w1,ui->w2,ui->w3,ui->w4,ui->w5,ui->w6,ui->w7,ui->w8,ui->w9,
                    ui->w10,ui->w11,ui->w12,ui->w13,ui->w14,ui->w15,ui->w16,ui->w17,ui->w18,
                    ui->w19,ui->w20};

    for(int i = 0;i<20;i++) arrayMeseros[i]->hide();
    for(int i = 0;i<20;i++) botonesMesas[i]->hide();

    ui->botonReservar->hide();
    ui->botonCajaSwitch->hide();
    ui->botonModAsistencia->hide();
    ui->botonModGenClientes->hide();
    ui->botonCajeraStop->setFlat(true);
    ui->botonFuertesStop->setFlat(true);
    ui->botonPostresStop->setFlat(true);
    ui->btonGeneradorStop->setFlat(true);
    ui->botonEnsaladasStop->setFlat(true);
    ui->botonLavaplatostop->setFlat(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    //Hacemos el start de todos los hilos y setteamos cada estructura
    restaurante = new Restaurante(probPlatoFuerte, probEnsalada, probPostre,cantCocineros,cantMeseros, cantMesas, cantMesasPorMesero, genPersonas1,genPersonas2,intervaloPostres1, intervaloPostres2, intervaloEnsaladas1, intervaloEnsaladas2, intervaloFuerte1, intervaloFuerte2,tiempoSleepCocinero, tiempoSleepCaja,tiempoSleepLavaplatos, tiempoSleepMesero, &mutexCaj , &mutexLavaplatos, &mutexCocina, &mutexEnsaladas, &mutexPasteleria, &mutexManejador, arrayMesas, arrayMeseros,ui->labelCaja, ui->labelLavaplatos, ui->labelComidaFuerte,ui->labelEnsaladas,ui->labelPasteleria,ui->labelGenerador, ui->labelGeneradorCola, ui->labelCajaInfo,ui->labelLavaplatosInfo,ui->labelEnsaladasInfo, ui->labelPostresInfo, ui->labelCocinaFuerteInfo, ui->labelCocinaFuerteInfo_2, ui->labelCocinaFuerteInfo_3,ui->labelDatosCajera,ui->labelDatosFuerte,ui->labelDatosPostres,ui->labelDatosEnsalada, botonesMesas);
    listaMesas = restaurante->mesas;

    ui->pushButton->hide();
    ui->pushButton_2->show();

    ui->botonReservar->show();
    ui->botonCajaSwitch->show();
    ui->botonModAsistencia->show();
    ui->botonModGenClientes->show();

    show();
}

void MainWindow::infoMesa(QPushButton * boton){
    int i;
    QString texto = "";
    Mesa * mesaAux = listaMesas->primerNodo;

    //To find the button n we look it up in the Vector
    for(i=0;i<botonesMesas.size()-1;i++) {
        if(botonesMesas[i] == boton) break;
    }

    //We look for the table that is in the same position as the button assigned to it
    while(mesaAux){
        mesaAux->mutexMesa.tryLock(10);
        if(mesaAux->ID[mesaAux->ID.size()-1] == QString::number(i+1)) break;
        mesaAux->mutexMesa.unlock();
        mesaAux = mesaAux->siguiente;
    }
    //If the table was found, just so he program doesn't surrender to the revision and keeps going
    if(mesaAux){
        qDebug()<<mesaAux->ID+" es la mesaa y matcheo con"+QString::number(i);
        Solicitud * sol = mesaAux->pilaPlatosSucios->tope;
        texto.append(mesaAux->ID+"\n");

        if(!mesaAux->listaComensales->estaVacia() && mesaAux->listaComensales->primerNodo->comensal){

            //mesaAux->listaComensales->primerNodo->mutexComensal->tryLock(10);
            ComensalThread * cliente = mesaAux->listaComensales->primerNodo;
            //mesaAux->listaComensales->primerNodo->mutexComensal->unlock();
            texto.append("Clientes:\n--");
            //We add the names of the clients
            for (int i = 0;i<mesaAux->listaComensales->largo;i++){
                texto.append(cliente->comensal->nombre+" \t");
                cliente = cliente->siguiente;
            }

            //Some styling
            if(mesaAux->listaComensales->largo!=1)texto.append("--\n");
            else texto.append("\n");


            texto.append("Platos servidos:\n--");
            for (int i = 0;i<mesaAux->pilaPlatosSucios->largo;i++){
                texto.append(sol->plato->nombre+"\t");
            }

            if(mesaAux->pilaPlatosSucios->largo!=1)texto.append("--\n");
            else texto.append("\n");

            QTextBrowser * informacionMesa  = new QTextBrowser();
            informacionMesa->setText(texto);
            informacionMesa->show();
        }
        else{
            QTextBrowser * informacionMesa  = new QTextBrowser();
            informacionMesa->setText("La "+mesaAux->ID+" No tiene clientes por el momento");
            informacionMesa->show();
        }
        mesaAux->mutexMesa.unlock();
    }
    else{
        QTextBrowser * informacionMesa  = new QTextBrowser();
        informacionMesa->setText("Aun no se han puesto los cubiertos, espere 1s mas");
        informacionMesa->show();
    }


}
void MainWindow::on_pushMesa_1_clicked()
{
    infoMesa(ui->pushMesa_1);

}
void MainWindow::on_pushMesa_2_clicked()
{
    infoMesa(ui->pushMesa_2);
}

void MainWindow::on_pushMesa_3_clicked()
{
    infoMesa(ui->pushMesa_3);
}
void MainWindow::on_pushMesa_4_clicked()
{
    infoMesa(ui->pushMesa_4);

}
void MainWindow::on_pushMesa_5_clicked()
{
    infoMesa(ui->pushMesa_5);

}
void MainWindow::on_pushMesa_6_clicked()
{
    infoMesa(ui->pushMesa_6);

}
void MainWindow::on_pushMesa_7_clicked()
{
    infoMesa(ui->pushMesa_7);
}
void MainWindow::on_pushMesa_8_clicked()
{
    infoMesa(ui->pushMesa_8);

}
void MainWindow::on_pushMesa_9_clicked()
{
    infoMesa(ui->pushMesa_9);

}
void MainWindow::on_pushMesa_10_clicked()
{
    infoMesa(ui->pushMesa_10);

}
void MainWindow::on_pushMesa_11_clicked()
{
    infoMesa(ui->pushMesa_11);

}
void MainWindow::on_pushMesa_12_clicked()
{
    infoMesa(ui->pushMesa_12);

}
void MainWindow::on_pushMesa_13_clicked()
{
    infoMesa(ui->pushMesa_13);

}
void MainWindow::on_pushMesa_14_clicked()
{
    infoMesa(ui->pushMesa_14);

}
void MainWindow::on_pushMesa_15_clicked()
{
    infoMesa(ui->pushMesa_15);

}
void MainWindow::on_pushMesa_16_clicked()
{
    infoMesa(ui->pushMesa_16);

}
void MainWindow::on_pushMesa_17_clicked()
{

    infoMesa(ui->pushMesa_17);

}
void MainWindow::on_pushMesa_18_clicked()
{
    infoMesa(ui->pushMesa_18);

}
void MainWindow::on_pushMesa_19_clicked()
{
    infoMesa(ui->pushMesa_19);

}
void MainWindow::on_pushMesa_20_clicked()
{
    infoMesa(ui->pushMesa_20);


}

void MainWindow::on_pushButton_2_clicked(){
    //Si le damos click a detener
    if(detenido==0){
        restaurante->cocineroPast->pausar();
        restaurante->cocineroEns->pausar();
        if(restaurante->cantCocineros==3){
            restaurante->cocineroF1->pausar();
            restaurante->cocineroF2->pausar();
            restaurante->cocineroF3->pausar();
        }
        else if(restaurante->cantCocineros==2){
            restaurante->cocineroF1->pausar();
            restaurante->cocineroF2->pausar();
        }
        else{
            restaurante->cocineroF1->pausar();
        }
        restaurante->lavaplatosThread->pausar();
        restaurante->cajaThread->pausar();
        restaurante->generadorPersonas.pausar();
        for(int i=0;i<cantMeseros;i++)restaurante->arrayMeserosThread[i]->pausar();
        ui->pushButton_2->setText("Resumir");
        detenido=1;
    }
    //Si le damos click a resumir
    else{
        for(int i=0;i<cantMeseros;i++)restaurante->arrayMeserosThread[i]->continuar();
        restaurante->cocineroPast->continuar();
        restaurante->cocineroEns->continuar();
        if(restaurante->cantCocineros==3){
            restaurante->cocineroF1->continuar();
            restaurante->cocineroF2->continuar();
            restaurante->cocineroF3->continuar();
        }
        else if(restaurante->cantCocineros==2){
            restaurante->cocineroF1->continuar();
            restaurante->cocineroF2->continuar();
        }
        else{
            restaurante->cocineroF1->continuar();
        }
        restaurante->lavaplatosThread->continuar();
        restaurante->cajaThread->continuar();
        restaurante->generadorPersonas.continuar();
        ui->pushButton_2->setText("Detener");
        detenido=0;
    }

}

void MainWindow::on_botonLavaplatostop_clicked()
{
    if(restaurante->lavaplatosThread){
        restaurante->lavaplatosThread->mutex->tryLock(10);
        if(detenido==0){
            detenido=1;
            restaurante->lavaplatosThread->pausar();
                    restaurante->lavaplatosThread->mutex->unlock();

        }
        else {
            detenido = 0;
            restaurante->lavaplatosThread->continuar();
            restaurante->lavaplatosThread->mutex->unlock();
        }
    }
}


void MainWindow::on_botonPostresStop_clicked()
{
    if(restaurante->cocineroPast){
        restaurante->cocineroPast->mutexCocinero->tryLock(10);
        if(detenido==0){
            detenido=1;
            restaurante->cocineroPast->pausar();
                restaurante->cocineroPast->mutexCocinero->unlock();

        }
        else {
            detenido = 0;
            restaurante->cocineroPast->continuar();
                restaurante->cocineroPast->mutexCocinero->unlock();
        }
    }

}

void MainWindow::on_botonFuertesStop_clicked()
{
    if(detenido==0){
        detenido=1;
        if(restaurante->cantCocineros==3){
            restaurante->cocineroF1->pausar();
            restaurante->cocineroF2->pausar();
            restaurante->cocineroF3->pausar();
        }
        else if(restaurante->cantCocineros==2){
            restaurante->cocineroF1->pausar();
            restaurante->cocineroF2->pausar();
        }
        else{
            restaurante->cocineroF1->pausar();
        }
    }
    else {
        detenido = 0;
        if(restaurante->cantCocineros==3){
            restaurante->cocineroF1->continuar();
            restaurante->cocineroF2->continuar();
            restaurante->cocineroF3->continuar();
        }
        else if(restaurante->cantCocineros==2){
            restaurante->cocineroF1->continuar();
            restaurante->cocineroF2->continuar();
        }
        else{
            restaurante->cocineroF1->continuar();
        }
    }
}

void MainWindow::on_botonEnsaladasStop_clicked()
{
    if (restaurante->cocineroEns){
        restaurante->cocineroEns->mutexCocinero->tryLock(10);
        if(detenido==0){
            detenido=1;
            restaurante->cocineroEns->pausar();
                restaurante->cocineroEns->mutexCocinero->unlock();

        }
        else {
            detenido = 0;
            restaurante->cocineroEns->continuar();
                restaurante->cocineroEns->mutexCocinero->unlock();
        }
    }

}

void MainWindow::on_botonCajeraStop_clicked()
{
    if(restaurante->cajaThread){
        restaurante->cajaThread->mutexCaja->tryLock(10);
        if(detenido==0){
            detenido=1;
            restaurante->cajaThread->pausar();
                restaurante->cajaThread->mutexCaja->unlock();

        }
        else {
            detenido = 0;
            restaurante->cajaThread->continuar();
                restaurante->cajaThread->mutexCaja->unlock();
        }
    }

}

void MainWindow::on_btonGeneradorStop_clicked()
{
   if(detenido==0){
        detenido=1;
        restaurante->generadorPersonas.pausar();

    }
    else {
        detenido = 0;
        restaurante->generadorPersonas.continuar();
    }
}

void MainWindow::on_botonModAsistencia_clicked()
{
        ventanaModificadora.show();
}

void MainWindow::on_botonModGenClientes_clicked()
{
        ventanaModificadora.show();

}

void MainWindow::on_botonCajaSwitch_clicked()
{
    if(cajaPila==0){
        cajaPila = 1;
        ui->botonCajaSwitch->setText("Convertir Caja a Cola");
        cajaThread.caja->modoCola = false;
        //sacar en forma de cola
    }

    else{
        cajaPila = 0;
        //sacar en forma de pila
        ui->botonCajaSwitch->setText("Convertir Caja a Cola");
        cajaThread.caja->modoCola = true;
    }
}
