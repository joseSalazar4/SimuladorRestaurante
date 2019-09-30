#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "qdebug.h"
#include "MainWindow.h"
#include "qmessagebox.h"

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

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
