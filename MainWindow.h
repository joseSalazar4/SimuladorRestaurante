#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include "meserothread.h"
#include "restaurante.h"
#include <QtWidgets/QMainWindow>


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
    QVector<QLabel*> arrayMeseros;
    CocineroThread cocineroPasteleria, cocineroEnsaladas, cocineroFuerte;
    QLabel * caja, * lavaplatos, * ensaladas, * cocinaFuerte, *pasteleria;
    QMutex mutexPasteleria, mutexCocina, mutexEnsaladas, mutexCaj, mutexLavaplatos, mutexManejador;
    int cantMeseros, cantMesas, cantCocineros, genPersonas1, genPersonas2, cantMesasPorMesero, intervaloPostres1,
        intervaloPostres2, intervaloEnsaladas1, intervaloEnsaladas2, intervaloFuerte1, intervaloFuerte2,
        tiempoSleepCocinero,tiempoSleepMesero, tiempoSleepLavaplatos, tiempoSleepCaja,probPlatoFuerte, probEnsalada, probPostre;


    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void on_progressBar_valueChanged(int value);

public slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
