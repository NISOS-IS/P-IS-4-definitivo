#include "registrarse.h"
#include "ui_registrarse.h"
#include "widget.h"
#include "ui_widget.h"
#include "iniciarsesion.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonSalir_clicked()
{
    close();
}

void Widget::on_pushButtonIniciarSesion_clicked()
{
    IniciarSesion *ventana = new IniciarSesion;
    ventana->show();
}

void Widget::on_pushButtonRegistrarse_clicked()
{
    Registrarse *ventana = new Registrarse;
    ventana->show();
}
