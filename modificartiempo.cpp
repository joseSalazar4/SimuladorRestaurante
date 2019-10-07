#include "modificartiempo.h"
#include "ui_modificartiempo.h"

ModificarTiempo::ModificarTiempo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModificarTiempo)
{
    ui->setupUi(this);
    ui->lineEdit->setReadOnly(true);

    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Base,Qt::gray);
    palette->setColor(QPalette::Text,Qt::darkGray);
    ui->lineEdit->setPalette(*palette);
}

ModificarTiempo::~ModificarTiempo()
{
    delete ui;
}

void ModificarTiempo::on_pushButton_clicked()
{
    if(generador = 0){
    }

    else{

    }
}

void ModificarTiempo::on_radioButton_2_clicked()
{

}
