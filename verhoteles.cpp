#include "verhoteles.h"
#include "ui_verhoteles.h"

verHoteles::verHoteles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verHoteles)
{
    ui->setupUi(this);
}

verHoteles::~verHoteles()
{
    delete ui;
}

void verHoteles::on_salir_H_clicked()
{
    QDialog::accept();
}

