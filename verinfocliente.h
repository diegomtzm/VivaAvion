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
    QString getIdCliente();

private slots:
    void on_regresar_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

    void on_dependientes_clicked();

private:
    Ui::verInfoCliente *ui;
};

#endif // VERINFOCLIENTE_H
