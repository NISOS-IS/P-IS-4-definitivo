#include "insertar_modificar_alumno.h"
#include "ui_insertar_modificar_alumno.h"

Insertar_Modificar_Alumno::Insertar_Modificar_Alumno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Insertar_Modificar_Alumno)
{
    ui->setupUi(this);
}

Insertar_Modificar_Alumno::~Insertar_Modificar_Alumno()
{
    delete ui;
}

void Insertar_Modificar_Alumno::on_pushButtonAceptar_clicked()
{

}

void Insertar_Modificar_Alumno::on_pushButtonCancelar_clicked()
{
    close();
}
