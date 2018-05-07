#include "dependientes.h"
#include "ui_dependientes.h"
#include "verinfocliente.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

dependientes::dependientes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dependientes)
{
    ui->setupUi(this);
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList titulos2;
    titulos2 << "Id Cliente" << "Nombre" << "Apellido Pat." << "Apellido Mat." << "Edad" << "Asist. Personal" << "Parentesco";
    ui->tableWidget->setHorizontalHeaderLabels(titulos2);

    verInfoCliente infoCliente;
    QString cliente = infoCliente.getIdCliente();

    QSqlQuery query2;
    query2.prepare("SELECT * FROM Dependientes WHERE id_cliente == ?");
    query2.addBindValue(cliente);

    if(!query2.exec()) {
        qWarning() << "ERROR: " << query2.lastError().text();
    }

    while(query2.next()) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        for(int i = 0; i < 7; i++) {
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem(query2.value(i).toString()));
        }
    }
}

dependientes::~dependientes()
{
    delete ui;
}

void dependientes::on_regresar_clicked()
{
    QDialog::accept();
}
