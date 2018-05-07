#include "infocliente.h"
#include "verhoteles.h"
#include "vervuelos.h"
#include "ui_infocliente.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

QString idCliente, noVuelo, ciudad;

infoCliente::infoCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoCliente)
{
    ui->setupUi(this);
    VerVuelos vuelos;
    noVuelo = vuelos.getIdVuelo();
    ui->label_idVuelo->setText(noVuelo);
    ciudad = vuelos.getDestino();
}

infoCliente::~infoCliente()
{
    delete ui;
}

QString infoCliente::getIdCliente() {
    return idCliente;
}


void infoCliente::on_pushButton_aceptar_clicked()
{
    idCliente = ui->lineEdit->text();

    QSqlQuery query;
    query.prepare("INSERT INTO ReservacionVuelo VALUES(?, ?)");
    query.addBindValue(noVuelo);
    query.addBindValue(idCliente);
    query.exec();

    QMessageBox::StandardButton preguntaHotel = QMessageBox::question(this, "Reserva de hotel", "¿Te interesa reservar un hotel en "
                                                                      + ciudad + "?",
                                                               QMessageBox::Yes | QMessageBox::No);
     if (preguntaHotel == QMessageBox::Yes) {
         verHoteles hoteles;
         if(hoteles.exec() == QDialog::Accepted) {

         }
     }

    QDialog::accept();
}

void infoCliente::on_lineEdit_textEdited(const QString &arg1)
{
    ui->pushButton_aceptar->setEnabled(true);
}
