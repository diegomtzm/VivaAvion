#ifndef VERRESERVAS_H
#define VERRESERVAS_H

#include <QDialog>

namespace Ui {
class verReservas;
}

class verReservas : public QDialog
{
    Q_OBJECT

public:
    explicit verReservas(QWidget *parent = 0);
    ~verReservas();

private slots:
    void on_salir_R_clicked();

    void on_reservarHotel_clicked();

private:
    Ui::verReservas *ui;
};

#endif // VERRESERVAS_H
