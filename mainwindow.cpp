#include "mainwindow.h"
#include "vervuelos.h"
#include "verreservas.h"
#include "verhoteles.h"
#include "verhotelesadmin.h"
#include "vervuelosadmin.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_VerVuelos_clicked()
{
    VerVuelos vuelos;
    if(vuelos.exec() == QDialog::Accepted) {

    }
}

void MainWindow::on_VerReservas_clicked()
{
    verReservas reservas;
    if(reservas.exec() == QDialog::Accepted) {

    }
}

void MainWindow::on_VerVuelosAdmin_clicked()
{
    verVuelosAdmin vuelosAdmin;
    if(vuelosAdmin.exec() == QDialog::Accepted) {

    }
}

void MainWindow::on_VerHotelesAdmin_clicked()
{
    verHotelesAdmin hotelesAdmin;
    if(hotelesAdmin.exec() == QDialog::Accepted) {

    }
}
