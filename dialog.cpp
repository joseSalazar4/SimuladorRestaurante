#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    //Extraemos los datos de la ventana.

    QString cantMesas =  ui->lineaCantMesas->text();
    QString tiempoGen1 = ui->lineaTiempoGen1->text();
    QString cantiCocineros = ui->lineaCocineros->text();
    QString cantMeseros = ui->lineaCantMeseros->text();
    QString tiempoGen2 = ui->lineaTiempoGen2->text();
    float cantMesasPorMeseroActivo = (cantMesas.toFloat())/(cantMeseros.toFloat());
    QString cantMesasMesero = QString::number(static_cast<int>( cantMesasPorMeseroActivo));

    //Si hay una cantidad de mesas no divisible entre los meseros.

    //Escondemos la ventana y vamos pasando los datos
    hide();

    //ELIMINAR ESTO Y DESCOMENTAR LO DE ABAJO
    //ELIMINAR ESTO Y DESCOMENTAR LO DE ABAJO

    ventanaPrincipal.cantMesas =  12;
    ventanaPrincipal.genPersonas1 = 10;
    ventanaPrincipal.genPersonas2 = 20;
    ventanaPrincipal.cantMeseros =   12;
    ventanaPrincipal.cantCocineros  = 3;
    ventanaPrincipal.cantMesasPorMesero = 1;


    ventanaPrincipal.show();

//    if(cantMesas.toInt()<=20 && cantMesas.toInt()>=cantMeseros.toInt() && cantMeseros.toInt()>=1 && cantMesas.toInt() >=1 && cantiCocineros.toInt()>=1 && cantiCocineros.toInt()<4){

//        qDebug()<<"Voy a crearla";
//        ventanaPrincipal.show();
//        qDebug()<<"Se creo";

//        ventanaPrincipal.cantMesas =  cantMesas.toInt();
//        ventanaPrincipal.genPersonas1 = tiempoGen1.toInt();
//        ventanaPrincipal.genPersonas2 = tiempoGen1.toInt();
//        ventanaPrincipal.cantMeseros =   cantMeseros.toInt();
//        ventanaPrincipal.cantCocineros  = cantiCocineros.toInt();
//        ventanaPrincipal.cantMesasPorMesero = cantMesasMesero.toInt();
//        qDebug()<<"Pasó los parametros nice :)";
//    }
//    else{
//        QMessageBox msgBox;
//        msgBox.setText("Hubo un error en la entrada de datos.");
//        msgBox.exec();
//    }


}
