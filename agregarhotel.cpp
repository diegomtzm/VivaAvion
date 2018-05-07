#include "agregarhotel.h"
#include "ui_agregarhotel.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

agregarHotel::agregarHotel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agregarHotel)
{
    ui->setupUi(this);
}

agregarHotel::~agregarHotel()
{
    delete ui;
}

void agregarHotel::on_cancelar_clicked()
{
    QDialog::accept();
}

void agregarHotel::on_lineEdit_precio_editingFinished()
{
    ui->agregar->setEnabled(true);
}

void agregarHotel::on_agregar_clicked()
{
    QString nombre, dir;
    int cantH, precio;
    nombre = ui->lineEdit_nombreHotel->text();
    dir = ui->lineEdit_dir->text();
    cantH = ui->lineEdit_cantHabitaciones->text().toInt();
    precio = ui->lineEdit_precio->text().toInt();

    QSqlQuery query;
    query.prepare("INSERT INTO Hotel (Nombre, Direccion, cant_Habitaciones, precioPorNoche) VALUES(?,?,?,?)");
    query.addBindValue(nombre);
    query.addBindValue(dir);
    query.addBindValue(cantH);
    query.addBindValue(precio);

    if(!query.exec()) {
        qWarning() << "Error: " << query.lastError().text();
        QMessageBox msg;
        msg.setText("No se ha podido agregar el hotel");
        msg.exec();
    }
    else {
        QMessageBox msg;
        msg.setText("¡Hotel agregado correctamente!");
        msg.exec();
    }

    QDialog::accept();
}
