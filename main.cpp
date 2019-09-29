#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Dialog ventanaConfiguarcion;
    ventanaConfiguarcion.show();
    return a.exec();
}
