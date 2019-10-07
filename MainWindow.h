#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include "meserothread.h"
#include "restaurante.h"
#include <QtWidgets/QMainWindow>
#include "qpushbutton.h"
#include"modificartiempo.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{

    Q_OBJECT


public:
    CajaThread cajaThread;
    ListaMesas * listaMesas;
    Restaurante * restaurante;
    QVector<QLabel*> arrayMeseros;
    ModificarTiempo * ventanaModificadora
    LavaplatosThread lavaplatosthread;
    QVector<QPushButton*> botonesMesas;
    QVector<QVector<QLabel*>> arrayMesas;
    CocineroThread cocineroPasteleria, cocineroEnsaladas, cocineroFuerte;
    QLabel * caja, * lavaplatos, * ensaladas, * cocinaFuerte, *pasteleria;
    QMutex mutexPasteleria, mutexCocina, mutexEnsaladas, mutexCaj, mutexLavaplatos, mutexManejador;
    int cantMeseros, cantMesas, cantCocineros, genPersonas1, genPersonas2, cantMesasPorMesero, intervaloPostres1,
        intervaloPostres2, intervaloEnsaladas1, intervaloEnsaladas2, intervaloFuerte1, intervaloFuerte2, detenido = 0,
        tiempoSleepCocinero,tiempoSleepMesero, tiempoSleepLavaplatos, tiempoSleepCaja,probPlatoFuerte, probEnsalada, probPostre,
        postresDetenido = 0,ensaladaDetenido= 0, fuerteDetenido= 0, cajaDetenida= 0 ;


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

    void infoMesa(QPushButton * boton);


    void on_botonLavaplatostop_clicked();

    void on_botonPostresStop_clicked();

    void on_botonFuertesStop_clicked();

    void on_botonEnsaladasStop_clicked();

    void on_botonCajeraStop_clicked();

    void on_btonGeneradorStop_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
