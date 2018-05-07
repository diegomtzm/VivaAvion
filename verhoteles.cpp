#include "verhoteles.h"
#include "ui_verhoteles.h"
#include "vervuelos.h"
#include "infocliente.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

QString ciudadDestino, IDcliente, idHotel;

verHoteles::verHoteles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verHoteles)
{
    ui->setupUi(this);
    VerVuelos vuelos;
    ciudadDestino = vuelos.getDestino();
    infoCliente cliente;
    IDcliente = cliente.getIdCliente();

    ui->label_ciudad->setText(ciudadDestino);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList titulos;
    titulos << "Id" << "Hotel" << "Dirección" << "Cant. Habitaciones" << "Precio p/noche";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);


    ciudadDestino = "%" + ciudadDestino + "%";
    QSqlQuery query;
    query.prepare("SELECT * FROM Hotel WHERE Direccion LIKE ?");
    query.addBindValue(ciudadDestino);

    query.exec();

    while(query.next()) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        for(int i = 0; i < 5; i++) {
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem(query.value(i).toString()));
        }
    }
}


verHoteles::~verHoteles()
{
    delete ui;
}

void verHoteles::on_salir_H_clicked()
{
    QDialog::accept();
}


void verHoteles::on_reservarHotel_clicked()
{
    idHotel = ui->tableWidget->selectedItems().at(0)->data(0).toString();
    QSqlQuery query;
    query.prepare("INSERT INTO ReservacionHotel VALUES(?, ?)");
    query.addBindValue(IDcliente);
    query.addBindValue(idHotel);

    if(query.exec())
        QDialog::accept();
}

void verHoteles::on_tableWidget_clicked(const QModelIndex &index)
{
    ui->reservarHotel->setEnabled(true);
}
