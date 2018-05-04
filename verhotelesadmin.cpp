#include "verhotelesadmin.h"
#include "agregarhotel.h"
#include "reservashoteles.h"
#include "ui_verhotelesadmin.h"

verHotelesAdmin::verHotelesAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verHotelesAdmin)
{
    ui->setupUi(this);
}

verHotelesAdmin::~verHotelesAdmin()
{
    delete ui;
}

void verHotelesAdmin::on_salir_H_A_clicked()
{
    QDialog::accept();
}

void verHotelesAdmin::on_agregarHotel_clicked()
{
    agregarHotel agregar;
    if(agregar.exec() == QDialog::Accepted) {

    }
}

void verHotelesAdmin::on_verReservasHotel_clicked()
{
    reservasHoteles reservas;
    if(reservas.exec() == QDialog::Accepted) {

    }
}
