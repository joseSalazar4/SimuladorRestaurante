#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Dialog ventanaConfiguarcion;
    ventanaConfiguarcion.show();
    //ventanaConfiguarcion.ventanaPrincipal.show();
    return a.exec();
}
