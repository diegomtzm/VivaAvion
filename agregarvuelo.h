#ifndef AGREGARVUELO_H
#define AGREGARVUELO_H

#include <QDialog>

namespace Ui {
class agregarVuelo;
}

class agregarVuelo : public QDialog
{
    Q_OBJECT

public:
    explicit agregarVuelo(QWidget *parent = 0);
    ~agregarVuelo();

private slots:
    void on_cancelar_clicked();

    void on_lineEdit_destino_editingFinished();

    void on_agregar_clicked();

private:
    Ui::agregarVuelo *ui;
};

#endif // AGREGARVUELO_H
