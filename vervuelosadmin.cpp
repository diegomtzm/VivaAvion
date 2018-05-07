#include "vervuelosadmin.h"
#include "agregarvuelo.h"
#include "reservasvuelos.h"
#include "ui_vervuelosadmin.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

verVuelosAdmin::verVuelosAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verVuelosAdmin)
{
    ui->setupUi(this);
    ui->tableWidget_vuelosAdmin->clear();
    ui->tableWidget_vuelosAdmin->setColumnCount(11);
    ui->tableWidget_vuelosAdmin->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList titulos;
    titulos << "No. Vuelo" << "Fecha" << "Hora Partida" << "Hora Abordaje" << "Origen" << "Destino" <<
               "Duracion" << "Cant. Pasajeros" << "Piloto" << "Puerta Abordaje" << "Precio";
    ui->tableWidget_vuelosAdmin->setHorizontalHeaderLabels(titulos);

    QSqlQuery query;
    query.prepare("SELECT * FROM vuelo");

    if(!query.exec()) {
        qWarning() << "ERROR: " << query.lastError().text();
    }

    while(query.next()) {
        ui->tableWidget_vuelosAdmin->insertRow(ui->tableWidget_vuelosAdmin->rowCount());
        for(int i = 0; i < 11; i++) {
            ui->tableWidget_vuelosAdmin->setItem(ui->tableWidget_vuelosAdmin->rowCount()-1, i, new QTableWidgetItem(query.value(i).toString()));
        }
    }
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

void verVuelosAdmin::on_tableWidget_vuelosAdmin_clicked(const QModelIndex &index)
{
    ui->infoAvion->setEnabled(true);
    ui->borrarVuelo->setEnabled(true);
}

void verVuelosAdmin::on_borrarVuelo_clicked()
{
    QSqlQuery query;
    QString id = ui->tableWidget_vuelosAdmin->selectedItems().at(0)->data(0).toString();
    query.prepare("DELETE FROM Vuelo WHERE id_vuelo == ?");
    query.addBindValue(id);
    query.exec();

    ui->tableWidget_vuelosAdmin->clear();
    ui->tableWidget_vuelosAdmin->setRowCount(0);
    ui->tableWidget_vuelosAdmin->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList titulos;
    titulos << "No. Vuelo" << "Fecha" << "Hora Partida" << "Hora Abordaje" << "Origen" << "Destino" <<
               "Duracion" << "Cant. Pasajeros" << "Piloto" << "Puerta Abordaje" << "Precio";
    ui->tableWidget_vuelosAdmin->setHorizontalHeaderLabels(titulos);


    QSqlQuery query2;
    query2.prepare("SELECT * FROM Vuelo");

    if(!query2.exec()) {
        qWarning() << "ERROR: " << query2.lastError().text();
    }

    while(query2.next()) {
        ui->tableWidget_vuelosAdmin->insertRow(ui->tableWidget_vuelosAdmin->rowCount());
        for(int i = 0; i < 11; i++) {
            ui->tableWidget_vuelosAdmin->setItem(ui->tableWidget_vuelosAdmin->rowCount()-1, i, new QTableWidgetItem(query2.value(i).toString()));
        }
    }
}
