#include "menu.h"
#include "ui_menu.h"

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
