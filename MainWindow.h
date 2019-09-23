#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "meserothread.h"
#include <QMainWindow>


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Mesero * mesero;
    MeseroThread hiloMesero;

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void on_progressBar_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
