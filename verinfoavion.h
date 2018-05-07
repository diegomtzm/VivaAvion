#ifndef VERINFOAVION_H
#define VERINFOAVION_H

#include <QDialog>

namespace Ui {
class verInfoAvion;
}

class verInfoAvion : public QDialog
{
    Q_OBJECT

public:
    explicit verInfoAvion(QWidget *parent = 0);
    ~verInfoAvion();

private slots:
    void on_regresar_clicked();

private:
    Ui::verInfoAvion *ui;
};

#endif // VERINFOAVION_H
