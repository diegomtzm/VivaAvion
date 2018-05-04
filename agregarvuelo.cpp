#include "agregarvuelo.h"
#include "ui_agregarvuelo.h"

agregarVuelo::agregarVuelo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agregarVuelo)
{
    ui->setupUi(this);
}

agregarVuelo::~agregarVuelo()
{
    delete ui;
}

void agregarVuelo::on_cancelar_clicked()
{
    QDialog::accept();
}
