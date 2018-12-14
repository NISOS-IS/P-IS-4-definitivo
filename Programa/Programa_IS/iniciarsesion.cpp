#include "iniciarsesion.h"
#include "ui_iniciarsesion.h"
#include "menu.h"
#include "profesor.h"
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
    hide();
}

void IniciarSesion::on_pushButtonAceptar_clicked()
{
    Profesor profesor;
    Profesor inicio;
    string usuario, contrasena;
    bool encontrado=false, habilitar=true;

    if(ui->lineEditUsuario->text().isEmpty()){
        QMessageBox::critical(this, "Error", "El usuario no está disponible");
        habilitar=false;
    }

    if(ui->lineEditContrasena->text().isEmpty()){
        QMessageBox::critical(this, "Error", "La contraseña debe tener al menos 4 caracteres");
        habilitar=false;
    }

    usuario= ui->lineEditUsuario->displayText().toStdString();
    contrasena= ui->lineEditContrasena->text().toStdString();

    inicio.setUsuario(usuario.c_str());
    inicio.setContrasena(contrasena.c_str());

    encontrado = profesor.login(inicio);
    if(encontrado==true){
        Menu *ventana = new Menu;
        ventana->show();
   }else{
        QMessageBox::critical(this, "Fallo al Iniciar Sesión", "El usuario o la contraseña son inválidos");
        habilitar=false;
    }
}
