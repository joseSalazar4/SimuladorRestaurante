#ifndef MODIFICARTIEMPO_H
#define MODIFICARTIEMPO_H

#include <QDialog>

namespace Ui {
class ModificarTiempo;
}

class ModificarTiempo : public QDialog
{
    Q_OBJECT

public:
    int generador = 0 , mesero = 0 ;
    explicit ModificarTiempo(QWidget *parent = nullptr);
    ~ModificarTiempo();

private slots:
    void on_pushButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

private:
    Ui::ModificarTiempo *ui;

signals:
    void finished(short selection, int number);
};

#endif // MODIFICARTIEMPO_H
