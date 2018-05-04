#ifndef VERVUELOSADMIN_H
#define VERVUELOSADMIN_H

#include <QDialog>

namespace Ui {
class verVuelosAdmin;
}

class verVuelosAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit verVuelosAdmin(QWidget *parent = 0);
    ~verVuelosAdmin();

private slots:
    void on_salir_V_A_clicked();

    void on_agregarVuelo_clicked();

    void on_verReserva_V_A_clicked();

private:
    Ui::verVuelosAdmin *ui;
};

#endif // VERVUELOSADMIN_H
