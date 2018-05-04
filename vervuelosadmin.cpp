#include "vervuelosadmin.h"
#include "agregarvuelo.h"
#include "reservasvuelos.h"
#include "ui_vervuelosadmin.h"

verVuelosAdmin::verVuelosAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verVuelosAdmin)
{
    ui->setupUi(this);
}

verVuelosAdmin::~verVuelosAdmin()
{
    delete ui;
}

void verVuelosAdmin::on_salir_V_A_clicked()
{
    QDialog::accept();
}

void verVuelosAdmin::on_agregarVuelo_clicked()
{
    agregarVuelo agregar;
    if(agregar.exec() == QDialog::Accepted) {

    }
}

void verVuelosAdmin::on_verReserva_V_A_clicked()
{
    reservasVuelos reservas;
    if(reservas.exec() == QDialog::Accepted) {

    }
}
