#include "agregarhotel.h"
#include "ui_agregarhotel.h"

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
