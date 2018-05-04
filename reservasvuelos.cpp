#include "reservasvuelos.h"
#include "ui_reservasvuelos.h"

reservasVuelos::reservasVuelos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reservasVuelos)
{
    ui->setupUi(this);
}

reservasVuelos::~reservasVuelos()
{
    delete ui;
}

void reservasVuelos::on_salir_clicked()
{
    QDialog::accept();
}
