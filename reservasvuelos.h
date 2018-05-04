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

private slots:
    void on_salir_clicked();

private:
    Ui::reservasVuelos *ui;
};

#endif // RESERVASVUELOS_H
