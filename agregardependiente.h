#ifndef AGREGARDEPENDIENTE_H
#define AGREGARDEPENDIENTE_H

#include <QDialog>

namespace Ui {
class agregarDependiente;
}

class agregarDependiente : public QDialog
{
    Q_OBJECT

public:
    explicit agregarDependiente(QWidget *parent = 0);
    ~agregarDependiente();

private slots:
    void on_lineEdit_parentesco_editingFinished();

    void on_cancelar_clicked();

    void on_agregar_clicked();

private:
    Ui::agregarDependiente *ui;
};

#endif // AGREGARDEPENDIENTE_H
