#include "reservashoteles.h"
#include "ui_reservashoteles.h"

reservasHoteles::reservasHoteles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reservasHoteles)
{
    ui->setupUi(this);
}

reservasHoteles::~reservasHoteles()
{
    delete ui;
}

void reservasHoteles::on_salir_clicked()
{
    QDialog::accept();
}
