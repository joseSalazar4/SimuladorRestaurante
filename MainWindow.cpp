#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_progressBar_valueChanged(int value)
{

}


void MainWindow::on_pushButton_clicked()
{
    bool prueba = true;

    restaurante = new Restaurante(2,2,2);
    while(prueba){
        prueba  = (restaurante->generadorPersonas.manejadorComensales->colaClientesEnEspera->frente == nullptr);
        ui->Texto->setText("es nula la cola de clientes");
    }


    ui->Texto->setText(restaurante->generadorPersonas.manejadorComensales->colaClientesEnEspera->frente->primerNodo->nombre);
    //ui->Texto->setText(restaurante->generadorPersonas.manejadorComensales->colaClientesEnEspera->desencolar()->primerNodo->nombre);


    ui->pushButton->hide();
}
