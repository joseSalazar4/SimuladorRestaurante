#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "qdebug.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    bool activo = true;
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
