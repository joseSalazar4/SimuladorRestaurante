#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "meserothread.h"
#include "restaurante.h"
#include <QMainWindow>


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Restaurante * restaurante;
    int cantMeseros, cantMesas, cantCocineros, genPersonas1, genPersonas2;


    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void on_progressBar_valueChanged(int value);

public slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
