#include "registrarse.h"
#include "ui_registrarse.h"

Registrarse::Registrarse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registrarse)
{
    ui->setupUi(this);
}

Registrarse::~Registrarse()
{
    delete ui;
}

void Registrarse::on_pushButtonCancelar_clicked()
{
    close();
}

void Registrarse::on_pushButtonAceptar_clicked()
{

}
