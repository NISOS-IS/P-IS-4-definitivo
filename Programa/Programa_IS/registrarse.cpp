#include "registrarse.h"
#include "ui_registrarse.h"
#include "profesor.h"
#include "funcionesAux.h"

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
    Profesor profesor, aux;
    RegUsu registro;
    string dni, nombre, apellidos, direccion, email, fechaNacimiento, getRol, usuario, contrasena;
    int telefono;
    bool habilitar=true, rol, funcionCorrecta=false, guardadoCorrecto=false;

    QString fecha;

    if(ui->lineEditDNI->text().isEmpty()){
       QMessageBox::critical(this, "Title", "El campo DNI es obligatorio");
       habilitar=false;
    }
    if(ui->lineEditNombre->text().isEmpty()){
       QMessageBox::critical(this, "Title", "El campo Nombre es obligatorio");
       habilitar=false;
    }
    if(ui->lineEditApellidos->text().isEmpty()){
       QMessageBox::critical(this, "Title", "El campo Apellidos es obligatorio");
       habilitar=false;
    }
    if(ui->lineEditTelefono->text().isEmpty()){
       QMessageBox::critical(this, "Title", "El campo Telefono es obligatorio");
       habilitar=false;
    }
    if(ui->lineEditDireccion->text().isEmpty()){
       QMessageBox::critical(this, "Title", "El campo Direccion es obligatorio");
       habilitar=false;
    }
    if(ui->lineEditEmail->text().isEmpty()){
       QMessageBox::critical(this, "Title", "El campo Email es obligatorio");
       habilitar=false;
    }

    if(ui->lineEditUsuario->text().isEmpty()){
        QMessageBox::critical(this, "Title", "El usuario no está disponible");
        habilitar=false;
    }

    if(ui->lineEditContrasena->text().isEmpty()){
        QMessageBox::critical(this, "Title", "La contraseña debe tener al menos 4 caracteres");
        habilitar=false;
    }

    if(habilitar==true){
       dni= ui->lineEditDNI->displayText().toStdString();
       nombre= ui->lineEditNombre->displayText().toStdString();
       apellidos= ui->lineEditApellidos->displayText().toStdString();
       telefono= ui->lineEditTelefono->displayText().toInt();
       direccion= ui->lineEditDireccion->displayText().toStdString();
       email= ui->lineEditEmail->displayText().toStdString();
       fecha = ui->dateEditFecha->date().toString("dd/MM/yyyy");
       fechaNacimiento= fecha.toStdString();
       getRol= ui->comboBoxRol->currentText().toStdString();
       if(getRol=="Coordinador"){
           rol=true;
       }else{
            rol=false;
       }
       usuario= ui->lineEditUsuario->displayText().toStdString();
       contrasena= ui->lineEditContrasena->displayText().toStdString();

       aux.setDNI(dni);
       aux.setNombre(nombre);
       aux.setApellidos(apellidos);
       aux.setTelefono(telefono);
       aux.setDireccion(direccion);
       aux.setEmail(email);
       aux.setFechaNacimiento(fechaNacimiento);
       aux.setRol(rol);
       aux.setUsuario(usuario);
       aux.setContrasena(contrasena);

       strcpy(registro.usuario, usuario.c_str());
       strcpy(registro.contrasena, contrasena.c_str());

       if(!buscaProfesor(aux.getDNI())){
           funcionCorrecta= profesor.registrarProfesor(aux);
           guardadoCorrecto= ActualizarFicheroInicio(registro);

           if(funcionCorrecta==true && guardadoCorrecto==true){
               QMessageBox::information(this, "Title", "Profesor Guardado");
               close();
           }else{
                QMessageBox::critical(this, "Title", "Profesor No Guardado");
           }
       }
    }
}
