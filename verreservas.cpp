#include "verreservas.h"
#include "verhoteles.h"
#include "vervuelos.h"
#include "ui_verreservas.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool tablaVuelos, tablaHotel;

verReservas::verReservas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verReservas)
{
    ui->setupUi(this);
    ui->tableWidget_Vuelos->clear();
    ui->tableWidget_Vuelos->setColumnCount(11);
    ui->tableWidget_Vuelos->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList titulos;
    titulos << "No. Vuelo" << "Fecha" << "Hora Partida" << "Hora Abordaje" << "Origen" << "Destino" <<
               "Duracion" << "Cant. Pasajeros" << "Piloto" << "Puerta Abordaje" << "Precio";
    ui->tableWidget_Vuelos->setHorizontalHeaderLabels(titulos);

    ui->tableWidget_Hotel->clear();
    ui->tableWidget_Hotel->setColumnCount(5);
    ui->tableWidget_Hotel->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList titulos2;
    titulos2 << "Id" << "Hotel" << "Dirección" << "Cant. Habitaciones" << "Precio p/noche";
    ui->tableWidget_Hotel->setHorizontalHeaderLabels(titulos2);
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
    if(tablaVuelos) {
        VerVuelos vuelos;
        QString destino = ui->tableWidget_Vuelos->selectedItems().at(5)->data(0).toString();
        vuelos.setDestino(destino);
        verHoteles hoteles;
        if(hoteles.exec() == QDialog::Accepted) {

        }
    } else if (tablaHotel) {
        QMessageBox msg;
        msg.setText("Selecciona una reservación de vuelo para poder rentar hotel ahí");
        msg.exec();
    }
}

void verReservas::on_lineEdit_ID_returnPressed()
{
    ui->tableWidget_Vuelos->clear();
    ui->tableWidget_Vuelos->setRowCount(0);
    ui->tableWidget_Vuelos->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList titulos;
    titulos << "No. Vuelo" << "Fecha" << "Hora Partida" << "Hora Abordaje" << "Origen" << "Destino" <<
               "Duracion" << "Cant. Pasajeros" << "Piloto" << "Puerta Abordaje" << "Precio";
    ui->tableWidget_Vuelos->setHorizontalHeaderLabels(titulos);

    ui->tableWidget_Hotel->clear();
    ui->tableWidget_Hotel->setRowCount(0);
    ui->tableWidget_Hotel->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList titulos2;
    titulos2 << "Id" << "Hotel" << "Dirección" << "Cant. Habitaciones" << "Precio p/noche";
    ui->tableWidget_Hotel->setHorizontalHeaderLabels(titulos2);

    QString idCliente = ui->lineEdit_ID->text();

    QSqlQuery query;
    query.prepare("SELECT v.* FROM vuelo AS v, reservacionVuelo AS rv "
                  "WHERE rv.id_cliente == ?"
                  "AND rv.id_vuelo == v.id_vuelo");
    query.addBindValue(idCliente);

    if(!query.exec()) {
        qWarning() << "ERROR: " << query.lastError().text();
    }

    while(query.next()) {
        ui->tableWidget_Vuelos->insertRow(ui->tableWidget_Vuelos->rowCount());
        for(int i = 0; i < 11; i++) {
            ui->tableWidget_Vuelos->setItem(ui->tableWidget_Vuelos->rowCount()-1, i, new QTableWidgetItem(query.value(i).toString()));
        }
    }

    QSqlQuery query2;
    query2.prepare("SELECT h.* FROM Hotel AS h, reservacionHotel AS rh "
                   "WHERE rh.id_cliente == ?"
                   "AND rh.id_hotel == h.id_hotel");
    query2.addBindValue(idCliente);

    if(!query2.exec()) {
        qWarning() << "ERROR: " << query2.lastError().text();
    }

    while(query2.next()) {
        ui->tableWidget_Hotel->insertRow(ui->tableWidget_Hotel->rowCount());
        for(int i = 0; i < 5; i++) {
            ui->tableWidget_Hotel->setItem(ui->tableWidget_Hotel->rowCount()-1, i, new QTableWidgetItem(query2.value(i).toString()));
        }
    }
}

void verReservas::on_tableWidget_Vuelos_clicked(const QModelIndex &index)
{
    tablaVuelos = true;
    tablaHotel = false;
    ui->reservarHotel->setEnabled(true);
    ui->quitarReserva->setEnabled(true);
}

void verReservas::on_tableWidget_Hotel_clicked(const QModelIndex &index)
{
    tablaHotel = true;
    tablaVuelos = false;
    ui->quitarReserva->setEnabled(false);
    ui->quitarReserva->setEnabled(true);
}

void verReservas::on_quitarReserva_clicked()
{
    QSqlQuery query;
    if(tablaVuelos) {
        QString id = ui->tableWidget_Vuelos->selectedItems().at(0)->data(0).toString();
        query.prepare("DELETE FROM ReservacionVuelo WHERE id_vuelo == ?");
        query.addBindValue(id);
        query.exec();

        ui->tableWidget_Vuelos->clear();
        ui->tableWidget_Vuelos->setRowCount(0);
        ui->tableWidget_Vuelos->setSelectionBehavior(QAbstractItemView::SelectRows);
        QStringList titulos;
        titulos << "No. Vuelo" << "Fecha" << "Hora Partida" << "Hora Abordaje" << "Origen" << "Destino" <<
                   "Duracion" << "Cant. Pasajeros" << "Piloto" << "Puerta Abordaje" << "Precio";
        ui->tableWidget_Vuelos->setHorizontalHeaderLabels(titulos);

        QString idCliente = ui->lineEdit_ID->text();

        QSqlQuery query;
        query.prepare("SELECT v.* FROM vuelo AS v, reservacionVuelo AS rv "
                      "WHERE rv.id_cliente == ?"
                      "AND rv.id_vuelo == v.id_vuelo");
        query.addBindValue(idCliente);

        if(!query.exec()) {
            qWarning() << "ERROR: " << query.lastError().text();
        }

        while(query.next()) {
            ui->tableWidget_Vuelos->insertRow(ui->tableWidget_Vuelos->rowCount());
            for(int i = 0; i < 11; i++) {
                ui->tableWidget_Vuelos->setItem(ui->tableWidget_Vuelos->rowCount()-1, i, new QTableWidgetItem(query.value(i).toString()));
            }
        }
    } else if (tablaHotel) {
        QString id = ui->tableWidget_Hotel->selectedItems().at(0)->data(0).toString();
        query.prepare("DELETE FROM ReservacionHotel WHERE id_hotel == ?");
        query.addBindValue(id);
        query.exec();

        ui->tableWidget_Hotel->clear();
        ui->tableWidget_Hotel->setRowCount(0);
        ui->tableWidget_Hotel->setSelectionBehavior(QAbstractItemView::SelectRows);
        QStringList titulos2;
        titulos2 << "Id" << "Hotel" << "Dirección" << "Cant. Habitaciones" << "Precio p/noche";
        ui->tableWidget_Hotel->setHorizontalHeaderLabels(titulos2);

        QString idCliente = ui->lineEdit_ID->text();

        QSqlQuery query2;
        query2.prepare("SELECT h.* FROM Hotel AS h, reservacionHotel AS rh "
                       "WHERE rh.id_cliente == ?"
                       "AND rh.id_hotel == h.id_hotel");
        query2.addBindValue(idCliente);

        if(!query2.exec()) {
            qWarning() << "ERROR: " << query2.lastError().text();
        }

        while(query2.next()) {
            ui->tableWidget_Hotel->insertRow(ui->tableWidget_Hotel->rowCount());
            for(int i = 0; i < 5; i++) {
                ui->tableWidget_Hotel->setItem(ui->tableWidget_Hotel->rowCount()-1, i, new QTableWidgetItem(query2.value(i).toString()));
            }
        }
    }
}
