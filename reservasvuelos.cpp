#include "reservasvuelos.h"
#include "ui_reservasvuelos.h"
#include "reservashoteles.h"
#include "verinfocliente.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

QString clienteV;
bool activeV;

reservasVuelos::reservasVuelos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reservasVuelos)
{
    ui->setupUi(this);
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(13);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList titulos;
    titulos << "No. Vuelo" << "Fecha" << "Hora Partida" << "Hora Abordaje" << "Origen" << "Destino" <<
               "Duracion" << "Cant. Pasajeros" << "Piloto" << "Puerta Abordaje" << "Precio" << "Id cliente" << "Nombre cliente";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);

    QSqlQuery query;
    query.prepare("SELECT v.*, c.id_cliente, c.Nombre FROM vuelo AS v, reservacionVuelo AS rv, Cliente AS c "
                  "WHERE rv.id_cliente == c.id_cliente "
                  "AND rv.id_vuelo == v.id_vuelo");

    if(!query.exec()) {
        qWarning() << "ERROR: " << query.lastError().text();
    }

    while(query.next()) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        for(int i = 0; i < 13; i++) {
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem(query.value(i).toString()));
        }
    }
}

reservasVuelos::~reservasVuelos()
{
    delete ui;
}

void reservasVuelos::setActive(bool b) {
    activeV = b;
}

bool reservasVuelos::getActive() {
    return activeV;
}

QString reservasVuelos::getIdCliente() {
    return clienteV;
}

void reservasVuelos::on_salir_clicked()
{
    QDialog::accept();
}

void reservasVuelos::on_tableWidget_clicked(const QModelIndex &index)
{
    ui->infoCliente->setEnabled(true);
}

void reservasVuelos::on_infoCliente_clicked(bool checked)
{
    reservasHoteles rh;
    rh.setActive(false);
    this->setActive(true);
    clienteV = ui->tableWidget->selectedItems().at(11)->data(0).toString();
    verInfoCliente infoCliente;
    if(infoCliente.exec() == QDialog::Accepted){

    }
}
