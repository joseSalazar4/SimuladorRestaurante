#include "dialog.h"
#include "ui_dialog.h"
#include "MainWindow.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    qDebug()<<"Tengo sueno";
    destroy();
    MainWindow ventanaPrincipal;
    QString cantMesas=  ui->lineaCantMesas->text();
    QString tiempoGen1 = ui->lineaTiempoGen->text();
    QString cantCocineros= ui->lineaCocineros->text();
    QString cantMeseros= ui->lineaCantMeseros->text();
    QString tiempoGen2 = ui->lineaTiempoGen_2->text();

    QString cantMesasMesero;

     //                                                                                                  * _mutexCaja,  *  _mutexLavaplatos * _mutexCocina,  * _mutexEnsaladas,*  _mutexPasteleria,  * _mutexManejador){

    bool ok;
    ventanaPrincipal.restaurante = new Restaurante(cantCocineros.toInt(&ok, 10), cantMeseros.toInt(&ok, 10), cantMesas.toInt(&ok, 10), cantMesasMesero.toInt(&ok, 10), tiempoGen1.toInt(&ok, 10), tiempoGen2.toInt(&ok, 10), &ventanaPrincipal.mutexCaj, &ventanaPrincipal.mutexLavaplatos, &ventanaPrincipal.mutexCocina, &ventanaPrincipal.mutexEnsaladas, &ventanaPrincipal.mutexPasteleria,  &ventanaPrincipal.mutexManejador);
    this->hide();
    ventanaPrincipal.show();


}
