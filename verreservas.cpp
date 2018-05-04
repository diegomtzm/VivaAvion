#include "verreservas.h"
#include "verhoteles.h"
#include "ui_verreservas.h"

verReservas::verReservas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verReservas)
{
    ui->setupUi(this);
}

verReservas::~verReservas()
{
    delete ui;
}

void verReservas::on_salir_R_clicked()
{
    QDialog::accept();
}

void verReservas::on_reservarHotel_clicked()
{
    verHoteles hoteles;
    if(hoteles.exec() == QDialog::Accepted) {

    }
}
