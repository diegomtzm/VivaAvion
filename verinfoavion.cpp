#include "verinfoavion.h"
#include "ui_verinfoavion.h"
#include "vervuelosadmin.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

verInfoAvion::verInfoAvion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verInfoAvion)
{
    ui->setupUi(this);
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList titulos2;
    titulos2 << "Id Avion" << "Modelo" << "Cant. Asientos";
    ui->tableWidget->setHorizontalHeaderLabels(titulos2);

    verVuelosAdmin vuelos;
    QString idAvion = vuelos.getIdAvion();

    QSqlQuery query2;
    query2.prepare("SELECT * FROM Avion WHERE id_avion == ?");
    query2.addBindValue(idAvion);

    if(!query2.exec()) {
        qWarning() << "ERROR: " << query2.lastError().text();
    }

    while(query2.next()) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        for(int i = 0; i < 3; i++) {
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem(query2.value(i).toString()));
        }
    }
}

verInfoAvion::~verInfoAvion()
{
    delete ui;
}

void verInfoAvion::on_regresar_clicked()
{
    QDialog::accept();
}
