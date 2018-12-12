#include "iniciarsesion.h"
#include "ui_iniciarsesion.h"
#include "menu.h"

IniciarSesion::IniciarSesion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IniciarSesion)
{
    ui->setupUi(this);
}

IniciarSesion::~IniciarSesion()
{
    delete ui;
}

void IniciarSesion::on_pushButtonCancelar_clicked()
{
    close();
}

void IniciarSesion::on_pushButtonAceptar_clicked()
{
   Menu *ventana= new Menu;
   ventana->show();
}
