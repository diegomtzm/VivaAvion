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

QString idCliente, noVuelo;

infoCliente::infoCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoCliente)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    VerVuelos vuelos;
    noVuelo = vuelos.getIdVuelo();
    ui->label_idVuelo->setText(noVuelo);
}

infoCliente::~infoCliente()
{
    delete ui;
}

void infoCliente::on_pushButton_aceptar_clicked()
{
    idCliente = ui->lineEdit->text();

    QSqlQuery query;
    query.prepare("INSERT INTO ReservacionVuelo VALUES(?, ?)");
    query.addBindValue(noVuelo);
    query.addBindValue(idCliente);
    query.exec();

    QSqlQuery query2;
    query2.prepare("SELECT * FROM ReservacionVuelo");
    query2.exec();

    while(query2.next()) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        for(int i = 0; i < 2; i++) {
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem(query2.value(i).toString()));
        }
    }



    /* QMessageBox::StandardButton preguntaHotel = QMessageBox::question(this, "Reserva de hotel", "¿Te interesa reservar un hotel?",
                                                               QMessageBox::Yes | QMessageBox::No);
     if (preguntaHotel == QMessageBox::Yes) {
         verHoteles hoteles;
         if(hoteles.exec() == QDialog::Accepted) {

         }
     }
     */
}

void infoCliente::on_lineEdit_textEdited(const QString &arg1)
{
    ui->pushButton_aceptar->setEnabled(true);
}
