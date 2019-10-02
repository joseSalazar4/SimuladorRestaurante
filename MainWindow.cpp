#include "MainWindow.h"
#include "qdebug.h"
#include "ui_mainwindow.h"
//#include <unistd.h>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    show();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //ui->c1
    QLabel * arrayMesa1[7] = {ui->c1,ui->c2,ui->c3,ui->c4,ui->c5,ui->c6, ui->m1};
    QLabel * arrayMesa2[7] = {ui->c7,ui->c8,ui->c9,ui->c10,ui->c11,ui->c12, ui->m2};
    QLabel * arrayMesa3[7] = {ui->c13,ui->c14,ui->c15,ui->c16,ui->c17,ui->c18, ui->m3};
    QLabel * arrayMesa4[7] = {ui->c19,ui->c20,ui->c21,ui->c22,ui->c23,ui->c24, ui->m4};
    QLabel * arrayMesa5[7] = {ui->c25,ui->c26,ui->c27,ui->c28,ui->c29,ui->c30, ui->m5};
    QLabel * arrayMesa6[7] = {ui->c31,ui->c32,ui->c33,ui->c34,ui->c35,ui->c36, ui->m6};
    QLabel * arrayMesa7[7] = {ui->c37,ui->c38,ui->c39,ui->c40,ui->c41,ui->c42, ui->m7};
    QLabel * arrayMesa8[7] = {ui->c43,ui->c44,ui->c45,ui->c46,ui->c47,ui->c48, ui->m8};
    QLabel * arrayMesa9[7] = {ui->c49,ui->c50,ui->c51,ui->c52,ui->c53,ui->c54, ui->m9};
    QLabel * arrayMesa10[7] = {ui->c55,ui->c56,ui->c57,ui->c58,ui->c59,ui->c60, ui->m10};
    QLabel * arrayMesa11[7] = {ui->c61,ui->c62,ui->c63,ui->c64,ui->c65,ui->c66, ui->m11};
    QLabel * arrayMesa12[7] = {ui->c67,ui->c68,ui->c69,ui->c70,ui->c71,ui->c72, ui->m12};
    QLabel * arrayMesa13[7] = {ui->c73,ui->c74,ui->c75,ui->c76,ui->c77,ui->c78, ui->m13};
    QLabel * arrayMesa14[7] = {ui->c79,ui->c80,ui->c81,ui->c82,ui->c83,ui->c84, ui->m14};
    QLabel * arrayMesa15[7] = {ui->c85,ui->c86,ui->c87,ui->c88,ui->c89,ui->c90, ui->m15};
    QLabel * arrayMesa16[7] = {ui->c91,ui->c92,ui->c93,ui->c94,ui->c95,ui->c96, ui->m16};
    QLabel * arrayMesa17[7] = {ui->c97,ui->c98,ui->c99,ui->c100,ui->c101,ui->c102, ui->m17};
    QLabel * arrayMesa18[7] = {ui->c103,ui->c104,ui->c105,ui->c106,ui->c107,ui->c108, ui->m18};
    QLabel * arrayMesa19[7] = {ui->c109,ui->c110,ui->c111,ui->c112,ui->c113,ui->c114, ui->m19};
    QLabel * arrayMesa20[7] = {ui->c115,ui->c116,ui->c117,ui->c118,ui->c119,ui->c120, ui->m20};
    QLabel ** arrayMesas[20] = {arrayMesa1,arrayMesa2,arrayMesa3,arrayMesa4,arrayMesa5,arrayMesa6,arrayMesa7,arrayMesa8,arrayMesa9,arrayMesa10,arrayMesa11,arrayMesa12,arrayMesa13,arrayMesa14,arrayMesa15,arrayMesa16,arrayMesa17,arrayMesa18,arrayMesa19,arrayMesa20};

    //Hacemos el start de todos los hilos y setteamos cada estructura
    restaurante = new Restaurante(cantCocineros,cantMeseros, cantMesas, cantMesasPorMesero, genPersonas1,genPersonas2, &mutexCaj , &mutexLavaplatos, &mutexCocina, &mutexEnsaladas, &mutexPasteleria, &mutexManejador, *arrayMesas,ui->labelCaja, ui->labelLavaplatos, ui->labelComidaFuerte,ui->labelEnsaladas, ui->labelPasteleria,ui->labelGenerador);

    qDebug()<<"Ya pasó el constructor";
    ui->pushButton->hide();
    this->show();
}
