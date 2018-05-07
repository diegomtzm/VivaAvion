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
    QString getIdVuelo();
    QString getDestino();
    void setDestino(QString d);

private slots:
    void on_salir_V_clicked();

    void on_reservarVuelo_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_editingFinished();

    void on_lineEdit_returnPressed();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_tableWidget_clicked(const QModelIndex &index);

private:
    Ui::VerVuelos *ui;
};

#endif // VERVUELOS_H
