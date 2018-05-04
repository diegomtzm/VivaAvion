#include "vervuelos.h"
#include "verhoteles.h"
#include "ui_vervuelos.h"
#include <QMessageBox>

VerVuelos::VerVuelos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VerVuelos)
{
    ui->setupUi(this);
}

VerVuelos::~VerVuelos()
{
    delete ui;
}

void VerVuelos::on_salir_V_clicked()
{
    QDialog::accept();
}

void VerVuelos::on_reservarVuelo_clicked()
{
    QMessageBox::StandardButton preguntaHotel = QMessageBox::question(this, "Reserva de hotel", "¿Te interesa reservar un hotel?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (preguntaHotel == QMessageBox::Yes) {
        verHoteles hoteles;
        if(hoteles.exec() == QDialog::Accepted) {

        }
    }

    QDialog::accept();
}
