#ifndef VERHOTELESADMIN_H
#define VERHOTELESADMIN_H

#include <QDialog>

namespace Ui {
class verHotelesAdmin;
}

class verHotelesAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit verHotelesAdmin(QWidget *parent = 0);
    ~verHotelesAdmin();

private slots:
    void on_salir_H_A_clicked();

    void on_agregarHotel_clicked();

    void on_verReservasHotel_clicked();

private:
    Ui::verHotelesAdmin *ui;
};

#endif // VERHOTELESADMIN_H
