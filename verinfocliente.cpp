#include "verinfocliente.h"
#include "ui_verinfocliente.h"
#include "reservashoteles.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

verInfoCliente::verInfoCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verInfoCliente)
{
    ui->setupUi(this);
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList titulos2;
    titulos2 << "Id" << "Nombre" << "Apellido Pat." << "Apellido Mat." << "Email" << "Telefono" << "Asist. Personal" << "Edad";
    ui->tableWidget->setHorizontalHeaderLabels(titulos2);

    reservasHoteles reservas;
    QString cliente = reservas.getIdCliente();

    QSqlQuery query2;
    query2.prepare("SELECT * FROM Cliente WHERE id_cliente == ?");
    query2.addBindValue(cliente);

    if(!query2.exec()) {
        qWarning() << "ERROR: " << query2.lastError().text();
    }

    while(query2.next()) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        for(int i = 0; i < 8; i++) {
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem(query2.value(i).toString()));
        }
    }
}

verInfoCliente::~verInfoCliente()
{
    delete ui;
}

void verInfoCliente::on_regresar_clicked()
{
    QDialog::accept();
}
