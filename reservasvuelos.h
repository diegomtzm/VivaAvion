#ifndef RESERVASVUELOS_H
#define RESERVASVUELOS_H

#include <QDialog>

namespace Ui {
class reservasVuelos;
}

class reservasVuelos : public QDialog
{
    Q_OBJECT

public:
    explicit reservasVuelos(QWidget *parent = 0);
    ~reservasVuelos();
    QString getIdCliente();
    void setActive(bool);
    bool getActive();

private slots:
    void on_salir_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

    void on_infoCliente_clicked(bool checked);

private:
    Ui::reservasVuelos *ui;
};

#endif // RESERVASVUELOS_H
