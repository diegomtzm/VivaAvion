#include "agregarvuelo.h"
#include "ui_agregarvuelo.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

agregarVuelo::agregarVuelo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agregarVuelo)
{
    ui->setupUi(this);
}

agregarVuelo::~agregarVuelo()
{
    delete ui;
}

void agregarVuelo::on_cancelar_clicked()
{
    QDialog::accept();
}

void agregarVuelo::on_lineEdit_destino_editingFinished()
{
    ui->agregar->setEnabled(true);
}

void agregarVuelo::on_agregar_clicked()
{
    QString idVuelo, idAvion, piloto, puertaAbordaje, duracion, origen, destino, horaAbordaje, horaPartida, precio;
    QDate fecha;
    idVuelo = ui->lineEdit_idVuelo->text();
    idAvion = ui->lineEdit_idAvion->text();
    piloto = ui->lineEdit_Piloto->text();
    puertaAbordaje = ui->lineEdit_puertaAbordaje->text();
    duracion = ui->lineEdit_dur_hrs->text();
    duracion += " horas " + ui->lineEdit_dur_mins->text() + " min";
    origen = ui->lineEdit_origen->text();
    destino = ui->lineEdit_destino->text();
    horaAbordaje = ui->lineEdit_hrAbordaje_hr->text();
    horaAbordaje += ":" + ui->lineEdit_hrAbordaje_mins->text();
    horaPartida = ui->lineEdit_hrPartida_hr->text();
    horaPartida += ":" + ui->lineEdit_hrPartida_mins->text();
    fecha = ui->calendarWidget->selectedDate();
    precio = ui->lineEdit_precio->text();

    QSqlQuery query;
    query.prepare("INSERT INTO Vuelo VALUES (?,?,?,?,?,?,?,?,?,?,?)");
    query.addBindValue(idVuelo);
    query.addBindValue(fecha);
    query.addBindValue(horaAbordaje);
    query.addBindValue(horaPartida);
    query.addBindValue(origen);
    query.addBindValue(destino);
    query.addBindValue(duracion);
    query.addBindValue(0);
    query.addBindValue(piloto);
    query.addBindValue(puertaAbordaje);
    query.addBindValue(precio);

    QSqlQuery query2;
    query2.prepare("INSERT INTO AvionUsado VALUES(?,?)");
    query2.addBindValue(idVuelo);
    query2.addBindValue(idAvion);

    query2.exec();

    if(!query.exec()) {
        QMessageBox msg;
        msg.setText("Hubo un error al agregar el vuelo, intentelo de nuevo");
        msg.exec();
    } else {
        QMessageBox msg;
        msg.setText("¡Vuelo agregado con éxito!");
        msg.exec();
    }

    QDialog::accept();
}
