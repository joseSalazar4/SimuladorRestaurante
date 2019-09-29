#include "MainWindow.h"
#include "qdebug.h"
#include "ui_mainwindow.h"
#include <unistd.h>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Dialog * dialog = new Dialog();
    dialog->show();

    hide();
    while(dialog->activo){
        qDebug()<<"Está en la introduccion de los datos";
        if(!dialog->activo) break;
        usleep(1000000);
    }
    show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //bool prueba = true;

    restaurante = new Restaurante(2, 4, 4, 1,2,8, &mutexCaj , &mutexLavaplatos, &mutexCocina, &mutexEnsaladas, &mutexPasteleria, &mutexManejador);

    qDebug()<<"Ya pasó el constructor";


    //restaurante->asignarCoc

//    while(prueba){
//        prueba  = (restaurante->generadorPersonas.manejadorComensales->colaClientesEnEspera->frente == nullptr);
//        ui->Texto->setText("es nula la cola de clientes");
//    }


//    ui->Texto->setText(restaurante->generadorPersonas.manejadorComensales->colaClientesEnEspera->frente->primerNodo->nombre);
//    //ui->Texto->setText(restaurante->generadorPersonas.manejadorComensales->colaClientesEnEspera->desencolar()->primerNodo->nombre);


    ui->pushButton->hide();
}
