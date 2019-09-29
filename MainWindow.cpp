#include "MainWindow.h"
#include "qdebug.h"
#include "ui_mainwindow.h"
#include <unistd.h>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    show();

}

/*MainWindow::~MainWindow()
{
    delete ui;
}
*/

void MainWindow::on_pushButton_clicked()
{
    //Hacemos el start de todos los hilos y setteamos cada estructura
    restaurante = new Restaurante(cantCocineros,cantMeseros, cantMesas, cantMesasPorMesero, genPersonas1,genPersonas2, &mutexCaj , &mutexLavaplatos, &mutexCocina, &mutexEnsaladas, &mutexPasteleria, &mutexManejador);
    qDebug()<<"Ya pasó el constructor";
    ui->pushButton->hide();
    this->show();
}
