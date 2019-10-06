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

    show();
}

/*
void MainWindow::push{
con esto maybe con alguno de los dos
ui->QTextBrowser ->setText(datos);

QMessageBox::information(this,"Error! ","Hay una cantidad de pasaportes diferente a la cantidad de personas que viajan");

}*/
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


void MainWindow::on_pushMesa_1_clicked()
{
    Mesa * mesaAux = listaMesas->primerNodo;

    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}
void MainWindow::on_pushMesa_2_clicked()
{
    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 1) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}

void MainWindow::on_pushMesa_3_clicked()
{
    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 2) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}
void MainWindow::on_pushMesa_4_clicked()
{
    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 3) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}
void MainWindow::on_pushMesa_5_clicked()
{
    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 4) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}
void MainWindow::on_pushMesa_6_clicked()
{
    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 5) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}
void MainWindow::on_pushMesa_7_clicked()
{

    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 6) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");
}
void MainWindow::on_pushMesa_8_clicked()
{
    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 7) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}
void MainWindow::on_pushMesa_9_clicked()
{
    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 8) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}
void MainWindow::on_pushMesa_10_clicked()
{
    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 9) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}
void MainWindow::on_pushMesa_11_clicked()
{
    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 10) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}
void MainWindow::on_pushMesa_12_clicked()
{
    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 11) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}
void MainWindow::on_pushMesa_13_clicked()
{
    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 12) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}
void MainWindow::on_pushMesa_14_clicked()
{
    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 13) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}
void MainWindow::on_pushMesa_15_clicked()
{
    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 14) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}
void MainWindow::on_pushMesa_16_clicked()
{
    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 15) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}
void MainWindow::on_pushMesa_17_clicked()
{
    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 16) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}
void MainWindow::on_pushMesa_18_clicked()
{
    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 17) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}
void MainWindow::on_pushMesa_19_clicked()
{
    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 18) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}
void MainWindow::on_pushMesa_20_clicked()
{
    int cont = 0;
    Mesa * mesaAux = listaMesas->primerNodo;
    while(mesaAux){
        if(cont == 19) break;
        mesaAux = mesaAux->siguiente;
    }
    QTextBrowser * informacionMesa  = new QTextBrowser();
    informacionMesa->setText("");

}

