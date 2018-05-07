#ifndef VERINFOCLIENTE_H
#define VERINFOCLIENTE_H

#include <QDialog>

namespace Ui {
class verInfoCliente;
}

class verInfoCliente : public QDialog
{
    Q_OBJECT

public:
    explicit verInfoCliente(QWidget *parent = 0);
    ~verInfoCliente();

private slots:
    void on_regresar_clicked();

private:
    Ui::verInfoCliente *ui;
};

#endif // VERINFOCLIENTE_H
