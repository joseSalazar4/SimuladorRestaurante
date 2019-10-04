#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>


Dialog::Dialog(QWidget *parent) :QDialog(parent), ui(new Ui::Dialog)
{

    ui->label->setStyleSheet("QLabel {color : white; }");
    ui->label_2->setStyleSheet("QLabel {color : white; }");
    ui->label_3->setStyleSheet("QLabel {color : white; }");
    ui->label_4->setStyleSheet("QLabel {color : white; }");
    ui->label_5->setStyleSheet("QLabel {color : white; }");
    ui->label_6->setStyleSheet("QLabel {color : white; }");
    ui->label_7->setStyleSheet("QLabel {color : white; }");
    ui->label_8->setStyleSheet("QLabel {color : white; }");
    ui->label_9->setStyleSheet("QLabel {color : white; }");
    ui->label_10->setStyleSheet("QLabel {color : white; }");
    ui->label_11->setStyleSheet("QLabel {color : white; }");
    ui->label_12->setStyleSheet("QLabel {color : white; }");
    ui->label_13->setStyleSheet("QLabel {color : white; }");
    ui->label_14->setStyleSheet("QLabel {color : white; }");
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked(){
    //Extraemos los datos de la ventana.
    ui->label->setToolTip("Hola");  //ASI HACEMOSLOS TOOLTIPS
    QString cantMesas =  ui->lineaCantMesas->text();
    QString tiempoGen1 = ui->lineaTiempoGen1->text();
    QString cantiCocineros = ui->lineaCocineros->text();
    QString cantMeseros = ui->lineaCantMeseros->text();
    QString tiempoGen2 = ui->lineaTiempoGen2->text();
    float cantMesasPorMeseroActivo = (cantMesas.toFloat())/(cantMeseros.toFloat());
    QString cantMesasMesero = QString::number(static_cast<int>(cantMesasPorMeseroActivo));

    //Si hay una cantidad de mesas no divisible entre los meseros.

    //Escondemos la ventana y vamos pasando los datos
    hide();
    //TODO: METER LA VALIDACION DE QUE LOS INTERVAOS Y SLEEPS NO SEAN NEGTVS
    if(cantMesas.toInt()<=20 && cantMesas.toInt()>=cantMeseros.toInt() && cantMeseros.toInt()>=1 && cantMesas.toInt() >=1 && cantiCocineros.toInt()>=1 && cantiCocineros.toInt()<4){

        qDebug()<<"Voy a crearla";
        ventanaPrincipal.show();
        qDebug()<<"Se creo";

        ventanaPrincipal.cantMesas =  cantMesas.toInt();
        ventanaPrincipal.genPersonas1 = tiempoGen1.toInt();
        ventanaPrincipal.genPersonas2 = tiempoGen2.toInt();
        ventanaPrincipal.cantMeseros =   cantMeseros.toInt();
        ventanaPrincipal.cantCocineros  = cantiCocineros.toInt();
        ventanaPrincipal.cantMesasPorMesero = cantMesasMesero.toInt();

        ventanaPrincipal.intervaloPostres1 = ui->IntervaloPostres1->text().toInt();
        ventanaPrincipal.intervaloPostres2 = ui->IntervaloPostres2->text().toInt();

        ventanaPrincipal.intervaloFuerte1 = ui->Intervalo1PlatoFuerte->text().toInt();
        ventanaPrincipal.intervaloFuerte2 = ui->Intervalo2PlatoFuerte->text().toInt();


        ventanaPrincipal.intervaloEnsaladas1 = ui->Intervalo1Ensalada->text().toInt();
        ventanaPrincipal.intervaloEnsaladas2 = ui->Intervalo2Ensalada->text().toInt();

        ventanaPrincipal.tiempoSleepCaja = ui->tiempoSleepCaja->text().toInt();
        ventanaPrincipal.tiempoSleepMesero = ui->tiempoSleepMesero->text().toInt();
        ventanaPrincipal.tiempoSleepCocinero = ui->tiempoSleepCocinero->text().toInt();
        ventanaPrincipal.tiempoSleepLavaplatos = ui->tiempoSleepLavaplatos->text().toInt();

        qDebug()<<"Pasó los parametros nice :)";
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("Hubo un error en la entrada de datos.");
        msgBox.exec();
    }


}
