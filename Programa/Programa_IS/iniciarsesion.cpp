#include "iniciarsesion.h"
#include "ui_iniciarsesion.h"
#include "menu.h"
#include "funcionesAux.h"

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
    RegUsu inicio;
    string usuario, contrasena;
    bool encontrado=false, habilitar=true;

    if(ui->lineEditUsuario->text().isEmpty()){
        QMessageBox::critical(this, "Title", "El usuario no está disponible");
        habilitar=false;
    }

    if(ui->lineEditContrasena->text().isEmpty()){
        QMessageBox::critical(this, "Title", "La contraseña debe tener al menos 4 caracteres");
        habilitar=false;
    }

    usuario= ui->lineEditUsuario->displayText().toStdString();
    contrasena= ui->lineEditContrasena->displayText().toStdString();

    strcpy(inicio.usuario, usuario.c_str());
    strcpy(inicio.contrasena, contrasena.c_str());

    encontrado = comprobarUsuario(inicio);
    if(encontrado==true){
        Menu *ventana = new Menu;
        ventana->show();
    }
    else{
        QMessageBox::critical(this, "Title", "El usuario o la contraseña son inválidos");
        habilitar=false;
    }
}
