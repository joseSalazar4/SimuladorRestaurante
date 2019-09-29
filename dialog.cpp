#include "dialog.h"
#include "ui_dialog.h"

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
    QString cantMesas =  ui->lineaCantMesas->text();
    QString tiempoGen1 = ui->lineaTiempoGen1->text();
    QString cantiCocineros = ui->lineaCocineros->text();
    qDebug()<<ui->lineaCocineros->text();
    QString cantMeseros = ui->lineaCantMeseros->text();
    QString tiempoGen2 = ui->lineaTiempoGen2->text();

    QString cantMesasMesero;
    hide();

    qDebug()<<"Voy a crearla";
    ventanaPrincipal.show();
    qDebug()<<"Se creo";

    ventanaPrincipal.cantCocineros  = cantiCocineros.toInt();
    ventanaPrincipal.cantMeseros =   cantMeseros.toInt();
    ventanaPrincipal.cantMesas =  cantMesas.toInt();
    ventanaPrincipal.cantMesasPorMesero = cantMesasMesero.toInt();
    ventanaPrincipal.genPersonas1 = tiempoGen1.toInt();
    ventanaPrincipal.genPersonas2 = tiempoGen1.toInt();
    qDebug()<<"Pasó los parametros nice :)";


}
