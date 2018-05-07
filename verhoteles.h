#ifndef VERHOTELES_H
#define VERHOTELES_H

#include <QDialog>

namespace Ui {
class verHoteles;
}

class verHoteles : public QDialog
{
    Q_OBJECT

public:
    explicit verHoteles(QWidget *parent = 0);
    ~verHoteles();

private slots:
    void on_salir_H_clicked();

    void on_reservarHotel_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

private:
    Ui::verHoteles *ui;
};

#endif // VERHOTELES_H
