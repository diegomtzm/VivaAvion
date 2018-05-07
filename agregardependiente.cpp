#include "agregardependiente.h"
#include "ui_agregardependiente.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

agregarDependiente::agregarDependiente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agregarDependiente)
{
    ui->setupUi(this);
}

agregarDependiente::~agregarDependiente()
{
    delete ui;
}

void agregarDependiente::on_lineEdit_parentesco_editingFinished()
{
    ui->agregar->setEnabled(true);
}

void agregarDependiente::on_cancelar_clicked()
{
    QDialog::accept();
}

void agregarDependiente::on_agregar_clicked()
{
    QString idCliente, nombre, apPat, apMat, edad, asist, parentesco;
    idCliente = ui->lineEdit_idCliente->text();
    nombre = ui->lineEdit_nombre->text();
    apPat = ui->lineEdit_ap_pat->text();
    apMat = ui->lineEdit_ap_mat->text();
    edad = ui->lineEdit_edad->text();
    parentesco = ui->lineEdit_parentesco->text();
    if(ui->radioButton_si->isChecked())
        asist = "Si";
    else if(ui->radioButton_no->isChecked())
        asist = "No";

    QSqlQuery query;
    query.prepare("INSERT INTO Dependientes VALUES (?,?,?,?,?,?,?)");
    query.addBindValue(idCliente);
    query.addBindValue(nombre);
    query.addBindValue(apPat);
    query.addBindValue(apMat);
    query.addBindValue(edad);
    query.addBindValue(asist);
    query.addBindValue(parentesco);

    if(!query.exec()) {
        QMessageBox msg;
        msg.setText("Hubo un error al agregar al dependiente, intentelo de nuevo");
        msg.exec();
    } else {
        QMessageBox msg;
        msg.setText("¡Dependiente agregado con éxito!");
        msg.exec();
    }

    QDialog::accept();
}
