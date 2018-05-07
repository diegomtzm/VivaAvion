#include "verhotelesadmin.h"
#include "agregarhotel.h"
#include "reservashoteles.h"
#include "ui_verhotelesadmin.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

verHotelesAdmin::verHotelesAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verHotelesAdmin)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList titulos;
    titulos << "Id" << "Hotel" << "Dirección" << "Cant. Habitaciones" << "Precio p/noche";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);

    QSqlQuery query;
    query.prepare("SELECT * FROM Hotel");

    query.exec();

    while(query.next()) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        for(int i = 0; i < 5; i++) {
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem(query.value(i).toString()));
        }
    }
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

void verHotelesAdmin::on_lineEdit_returnPressed()
{
    QString ciudad = ui->lineEdit->text();
    if (ciudad != "") {
        QSqlQuery query;
        ciudad = "%" + ciudad + "%";
        query.prepare("SELECT * FROM Hotel WHERE Direccion LIKE ?");
        query.addBindValue(ciudad);


        if(!query.exec()) {
            qWarning() << "ERROR: " << query.lastError().text();
        }

        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        QStringList titulos;
        titulos << "Id" << "Hotel" << "Dirección" << "Cant. Habitaciones" << "Precio p/noche";
        ui->tableWidget->setHorizontalHeaderLabels(titulos);

        while(query.next()) {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            for(int i = 0; i < 5; i++) {
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem(query.value(i).toString()));
            }
        }
    } else {
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        QStringList titulos;
        titulos << "Id" << "Hotel" << "Dirección" << "Cant. Habitaciones" << "Precio p/noche";
        ui->tableWidget->setHorizontalHeaderLabels(titulos);

        QSqlQuery query;
        query.prepare("SELECT * FROM Hotel");

        if(!query.exec()) {
            qWarning() << "ERROR: " << query.lastError().text();
        }

        while(query.next()) {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            for(int i = 0; i < 5; i++) {
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem(query.value(i).toString()));
            }
        }
    }
}

void verHotelesAdmin::on_tableWidget_clicked(const QModelIndex &index)
{
    ui->eliminarHotel->setEnabled(true);
}

void verHotelesAdmin::on_eliminarHotel_clicked()
{
    QSqlQuery query;
    QString id = ui->tableWidget->selectedItems().at(0)->data(0).toString();
    query.prepare("DELETE FROM Hotel WHERE id_hotel == ?");
    query.addBindValue(id);
    query.exec();

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList titulos;
    titulos << "Id" << "Hotel" << "Dirección" << "Cant. Habitaciones" << "Precio p/noche";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);


    QSqlQuery query2;
    query2.prepare("SELECT * FROM Hotel");

    if(!query2.exec()) {
        qWarning() << "ERROR: " << query2.lastError().text();
    }

    while(query2.next()) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        for(int i = 0; i < 5; i++) {
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem(query2.value(i).toString()));
        }
    }
}
