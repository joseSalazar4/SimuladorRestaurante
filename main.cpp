#include "dialog.h"

#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Dialog ventanaConfiguarcion;
    ventanaConfiguarcion.ventanaPrincipal.hide();
    ventanaConfiguarcion.show();
    return a.exec();
}
