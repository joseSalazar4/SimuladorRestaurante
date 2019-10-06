#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include "meserothread.h"
#include "restaurante.h"
#include <QtWidgets/QMainWindow>
#include "qpushbutton.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{

    Q_OBJECT


public:
    CajaThread cajaThread;
    Restaurante * restaurante;
    LavaplatosThread lavaplatosthread;
    QVector<QVector<QLabel*>> arrayMesas;
    QVector<QPushButton*> botonesMesas;
    QVector<QLabel*> arrayMeseros;
    ListaMesas * listaMesas;
    CocineroThread cocineroPasteleria, cocineroEnsaladas, cocineroFuerte;
    QLabel * caja, * lavaplatos, * ensaladas, * cocinaFuerte, *pasteleria;
    QMutex mutexPasteleria, mutexCocina, mutexEnsaladas, mutexCaj, mutexLavaplatos, mutexManejador;
    int cantMeseros, cantMesas, cantCocineros, genPersonas1, genPersonas2, cantMesasPorMesero, intervaloPostres1,
        intervaloPostres2, intervaloEnsaladas1, intervaloEnsaladas2, intervaloFuerte1, intervaloFuerte2, detenido = 0,
        tiempoSleepCocinero,tiempoSleepMesero, tiempoSleepLavaplatos, tiempoSleepCaja,probPlatoFuerte, probEnsalada, probPostre;


    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void on_progressBar_valueChanged(int value);

public slots:
    void on_pushButton_clicked();

private slots:
    void on_pushButton_2_clicked();

    void on_pushMesa_1_clicked();
    void on_pushMesa_2_clicked();
    void on_pushMesa_3_clicked();
    void on_pushMesa_4_clicked();
    void on_pushMesa_5_clicked();
    void on_pushMesa_6_clicked();
    void on_pushMesa_7_clicked();
    void on_pushMesa_8_clicked();
    void on_pushMesa_9_clicked();
    void on_pushMesa_10_clicked();
    void on_pushMesa_11_clicked();
    void on_pushMesa_12_clicked();
    void on_pushMesa_13_clicked();
    void on_pushMesa_14_clicked();
    void on_pushMesa_15_clicked();
    void on_pushMesa_16_clicked();
    void on_pushMesa_17_clicked();
    void on_pushMesa_18_clicked();
    void on_pushMesa_19_clicked();
    void on_pushMesa_20_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
