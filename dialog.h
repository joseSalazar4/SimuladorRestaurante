#ifndef DIALOG_H
#define DIALOG_H

#include "MainWindow.h"
#include "qdebug.h"

#include <QtWidgets/QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    bool activo = true;
    MainWindow ventanaPrincipal;
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void on_pushButton_clicked();

public:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
