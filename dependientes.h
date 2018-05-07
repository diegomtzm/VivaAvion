#ifndef DEPENDIENTES_H
#define DEPENDIENTES_H

#include <QDialog>

namespace Ui {
class dependientes;
}

class dependientes : public QDialog
{
    Q_OBJECT

public:
    explicit dependientes(QWidget *parent = 0);
    ~dependientes();

private slots:
    void on_regresar_clicked();

private:
    Ui::dependientes *ui;
};

#endif // DEPENDIENTES_H
