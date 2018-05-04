#ifndef RESERVASHOTELES_H
#define RESERVASHOTELES_H

#include <QDialog>

namespace Ui {
class reservasHoteles;
}

class reservasHoteles : public QDialog
{
    Q_OBJECT

public:
    explicit reservasHoteles(QWidget *parent = 0);
    ~reservasHoteles();

private slots:
    void on_salir_clicked();

private:
    Ui::reservasHoteles *ui;
};

#endif // RESERVASHOTELES_H
