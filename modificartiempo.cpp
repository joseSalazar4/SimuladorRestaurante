#include "modificartiempo.h"
#include "ui_modificartiempo.h"

ModificarTiempo::ModificarTiempo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModificarTiempo)
{
    ui->setupUi(this);
    ui->lineEdit->setReadOnly(true);

    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Text,Qt::gray);
    ui->lineEdit->setPalette(*palette);
    ui->lineEdit_2->setPalette(*palette);
}

ModificarTiempo::~ModificarTiempo()
{
    delete ui;
}

void ModificarTiempo::on_pushButton_clicked()
{
    hide();
    if(generador == 0){
        ui->lineEdit->text().toInt();
    }

    else{
        ui->lineEdit_2->text().toInt();
    }
}

void ModificarTiempo::on_radioButton_2_clicked()
{
    generador = 0;

    //Modificamos para deshabilitar
    ui->lineEdit->setReadOnly(true);
    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Text,Qt::gray);
    ui->lineEdit->setPalette(*palette);

    //Modifc
    ui->lineEdit_2->setReadOnly(false);
    palette->setColor(QPalette::Base,Qt::darkGray);
    ui->lineEdit_2->setPalette(*palette);
}

void ModificarTiempo::on_radioButton_clicked()
{
    generador = 1;
    //Modificamos para deshabilitar la entrada
    ui->lineEdit_2->setReadOnly(true);
    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Text,Qt::gray);
    ui->lineEdit_2->setPalette(*palette);

    //Modificamos y habilitamos la entrada al generador
    ui->lineEdit->setReadOnly(false);
    palette->setColor(QPalette::Base,Qt::darkGray);
    ui->lineEdit_2->setPalette(*palette);

}
