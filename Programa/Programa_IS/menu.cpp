#include "menu.h"
#include "ui_menu.h"
#include "insertar_modificar_alumno.h"
#include "profesor.h"
#include <QMessageBox>
#include "agenda.h"
#include "funcionesAux.h"
Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButtonInsertarAlumno_clicked()
{
    Insertar_Modificar_Alumno *ventana= new Insertar_Modificar_Alumno;
    ventana->show();
}

void Menu::on_pushButtonMostrarAlumno_clicked()
{

}

void Menu::on_pushButtonBorrarAlumno_clicked()
{

}

void Menu::on_pushButtonModificarAlumno_clicked()
{

}

void Menu::on_pushButtonListadoAlumnos_clicked()
{
    Agenda agenda;
    list<Alumno>aux = agenda.mostrarLista();
    if(aux.empty()){
       QMessageBox::information(this, "Title", "La Agenda esta vacia");
    }else {
        ui->tableWidgetListado->setEditTriggers(QAbstractItemView::NoEditTriggers);
        while (ui->tableWidgetListado->rowCount() > 0)
        {
            ui->tableWidgetListado->removeRow(0);
        }
       ui->tableWidgetListado->setColumnCount(10);
       QStringList cabeceras;
       cabeceras <<"DNI" <<"Nombre"<<"Apellidos"<<"Telefono"<<"Direccion"<<"E-mail"<<"FechaNacimiento"<<"Curso"<<"Equipo"<<"Lider";
       ui->tableWidgetListado->setHorizontalHeaderLabels(cabeceras);
       for (list<Alumno>::iterator it = aux.begin();it != aux.end(); it++){
                ui->tableWidgetListado->insertRow(ui->tableWidgetListado->rowCount());

                QString dni = QString::fromStdString(it->getDNI());
                ui->tableWidgetListado->setItem(ui->tableWidgetListado->rowCount()-1, 0, new QTableWidgetItem(dni));

                QString nombre = QString::fromStdString(it->getNombre());
                ui->tableWidgetListado->setItem(ui->tableWidgetListado->rowCount()-1, 1, new QTableWidgetItem(nombre));

                QString apellidos = QString::fromStdString(it->getApellidos());
                ui->tableWidgetListado->setItem(ui->tableWidgetListado->rowCount()-1, 2, new QTableWidgetItem(apellidos));

                QString telefono = QString::number(it->getTelefono());
                ui->tableWidgetListado->setItem(ui->tableWidgetListado->rowCount()-1, 3, new QTableWidgetItem(telefono));

                QString direccion = QString::fromStdString(it->getDireccion());
                ui->tableWidgetListado->setItem(ui->tableWidgetListado->rowCount()-1, 4, new QTableWidgetItem(direccion));

                QString email = QString::fromStdString(it->getEmail());
                ui->tableWidgetListado->setItem(ui->tableWidgetListado->rowCount()-1, 5, new QTableWidgetItem(email));

                QString fechaNacimiento = QString::fromStdString(it->getFechaNacimiento());
                ui->tableWidgetListado->setItem(ui->tableWidgetListado->rowCount()-1, 6, new QTableWidgetItem(fechaNacimiento));

                QString curso = QString::number(it->getCurso());
                ui->tableWidgetListado->setItem(ui->tableWidgetListado->rowCount()-1, 7, new QTableWidgetItem(curso));

                QString equipo = QString::number(it->getEquipo());
                ui->tableWidgetListado->setItem(ui->tableWidgetListado->rowCount()-1, 8, new QTableWidgetItem(equipo));

                QString lider = QString::fromStdString(convertirBoolLider(it->getLider()));
                ui->tableWidgetListado->setItem(ui->tableWidgetListado->rowCount()-1, 9, new QTableWidgetItem(lider));

            }
            aux.clear();
    }
}

void Menu::on_pushButtonGuardarCopia_clicked()
{

}

void Menu::on_pushButtonCargarCopia_clicked()
{

}

void Menu::on_pushButtonSalir_clicked()
{
   close();
}
