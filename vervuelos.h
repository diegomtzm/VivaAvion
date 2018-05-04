#ifndef VERVUELOS_H
#define VERVUELOS_H

#include <QDialog>

namespace Ui {
class VerVuelos;
}

class VerVuelos : public QDialog
{
    Q_OBJECT

public:
    explicit VerVuelos(QWidget *parent = 0);
    ~VerVuelos();

private slots:
    void on_salir_V_clicked();

    void on_reservarVuelo_clicked();

private:
    Ui::VerVuelos *ui;
};

#endif // VERVUELOS_H
