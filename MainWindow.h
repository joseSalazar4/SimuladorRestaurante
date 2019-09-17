#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "meserothread.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Mesero * mesero;
    MeseroThread hiloMesero;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_progressBar_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
