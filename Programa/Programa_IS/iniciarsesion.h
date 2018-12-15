#ifndef INICIARSESION_H
#define INICIARSESION_H

#include <QDialog>

namespace Ui {
class IniciarSesion;
}

class IniciarSesion : public QDialog
{
    Q_OBJECT

public:
    explicit IniciarSesion(QWidget *parent = nullptr);
    ~IniciarSesion();

private slots:
    void on_pushButtonCancelar_clicked();

    void on_pushButtonAceptar_clicked();

private:
    Ui::IniciarSesion *ui;
};

#endif // INICIARSESION_H
