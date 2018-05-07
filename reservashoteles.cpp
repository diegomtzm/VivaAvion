#include "reservashoteles.h"
#include "ui_reservashoteles.h"
#include "reservasvuelos.h"
#include "verinfocliente.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

QString cliente;
bool active;

reservasHoteles::reservasHoteles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reservasHoteles)
{
    ui->setupUi(this);
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList titulos2;
    titulos2 << "Id" << "Hotel" << "Dirección" << "Cant. Habitaciones" << "Precio p/noche" << "Id cliente" << "Nombre cliente";
    ui->tableWidget->setHorizontalHeaderLabels(titulos2);

    QSqlQuery query2;
    query2.prepare("SELECT h.*, c.id_cliente, c.Nombre FROM Hotel AS h, reservacionHotel AS rh, Cliente AS c "
                   "WHERE rh.id_hotel == h.id_hotel "
                   "AND c.id_cliente == rh.id_cliente");

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

void reservasHoteles::setActive(bool b) {
    active = b;
}

bool reservasHoteles::getActive() {
    return active;
}

QString reservasHoteles::getIdCliente() {
    return cliente;
}

reservasHoteles::~reservasHoteles()
{
    delete ui;
}

void reservasHoteles::on_salir_clicked()
{
    QDialog::accept();
}

void reservasHoteles::on_tableWidget_clicked(const QModelIndex &index)
{
    ui->infoCliente->setEnabled(true);
}

void reservasHoteles::on_infoCliente_clicked()
{
    reservasVuelos rv;
    rv.setActive(false);
    this->setActive(true);
    cliente = ui->tableWidget->selectedItems().at(5)->data(0).toString();
    verInfoCliente infoCliente;
    if(infoCliente.exec() == QDialog::Accepted){

    }
}
