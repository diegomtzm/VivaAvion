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
    QString getIdCliente();
    void setActive(bool);
    bool getActive();

private slots:
    void on_salir_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

    void on_infoCliente_clicked();

private:
    Ui::reservasHoteles *ui;
};

#endif // RESERVASHOTELES_H
