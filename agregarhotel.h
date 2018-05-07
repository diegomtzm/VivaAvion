#ifndef AGREGARHOTEL_H
#define AGREGARHOTEL_H

#include <QDialog>

namespace Ui {
class agregarHotel;
}

class agregarHotel : public QDialog
{
    Q_OBJECT

public:
    explicit agregarHotel(QWidget *parent = 0);
    ~agregarHotel();

private slots:
    void on_cancelar_clicked();

    void on_lineEdit_precio_editingFinished();

    void on_agregar_clicked();

private:
    Ui::agregarHotel *ui;
};

#endif // AGREGARHOTEL_H
