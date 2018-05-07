#include "vervuelos.h"
#include "infocliente.h"
#include "ui_vervuelos.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

QString idVuelo;

VerVuelos::VerVuelos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VerVuelos)
{
    ui->setupUi(this);
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(11);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList titulos;
    titulos << "No. Vuelo" << "Fecha" << "Hora Partida" << "Hora Abordaje" << "Origen" << "Destino" <<
               "Duracion" << "Cant. Pasajeros" << "Piloto" << "Puerta Abordaje" << "Precio";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);

    QSqlQuery query;
    query.prepare("SELECT * FROM vuelo");

    if(!query.exec()) {
        qWarning() << "ERROR: " << query.lastError().text();
    }

    while(query.next()) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        for(int i = 0; i < 11; i++) {
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem(query.value(i).toString()));
        }
    }



}

QString VerVuelos::getIdVuelo() {
    return idVuelo;
}

VerVuelos::~VerVuelos()
{
    delete ui;
}

void VerVuelos::on_salir_V_clicked()
{
    QDialog::accept();
}

void VerVuelos::on_reservarVuelo_clicked()
{
    idVuelo = ui->tableWidget->selectedItems().at(0)->data(0).toString();

    infoCliente cliente;
    if(cliente.exec() == QDialog::Accepted) {

    }

    QDialog::accept();
}


void VerVuelos::on_lineEdit_returnPressed()
{
    if (ui->lineEdit->text() != "") {
        QSqlQuery query;
        if(ui->radioButton_origen->isChecked()) {
            query.prepare("SELECT * FROM vuelo WHERE origen = ?");
            query.addBindValue(ui->lineEdit->text());
        } else if (ui->radioButton_destino->isChecked()) {
            query.prepare("SELECT * FROM vuelo WHERE destino = ?");
            query.addBindValue(ui->lineEdit->text());
        }

        if(!query.exec()) {
            qWarning() << "ERROR: " << query.lastError().text();
        }

        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        QStringList titulos;
        titulos << "No. Vuelo" << "Fecha" << "Hora Partida" << "Hora Abordaje" << "Origen" << "Destino" <<
                   "Duracion" << "Cant. Pasajeros" << "Piloto" << "Puerta Abordaje" << "Precio";
        ui->tableWidget->setHorizontalHeaderLabels(titulos);

        while(query.next()) {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            for(int i = 0; i < 11; i++) {
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem(query.value(i).toString()));
            }
        }
    } else {
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        QStringList titulos;
        titulos << "No. Vuelo" << "Fecha" << "Hora Partida" << "Hora Abordaje" << "Origen" << "Destino" <<
                   "Duracion" << "Cant. Pasajeros" << "Piloto" << "Puerta Abordaje" << "Precio";
        ui->tableWidget->setHorizontalHeaderLabels(titulos);

        QSqlQuery query;
        query.prepare("SELECT * FROM vuelo");

        if(!query.exec()) {
            qWarning() << "ERROR: " << query.lastError().text();
        }

        while(query.next()) {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            for(int i = 0; i < 11; i++) {
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem(query.value(i).toString()));
            }
        }
    }
}


