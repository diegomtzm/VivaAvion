#ifndef INFOCLIENTE_H
#define INFOCLIENTE_H

#include <QDialog>

namespace Ui {
class infoCliente;
}

class infoCliente : public QDialog
{
    Q_OBJECT

public:
    explicit infoCliente(QWidget *parent = 0);
    ~infoCliente();

private slots:
    void on_pushButton_aceptar_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::infoCliente *ui;
};

#endif // INFOCLIENTE_H
