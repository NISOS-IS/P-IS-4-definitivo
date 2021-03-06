#ifndef MENU_H
#define MENU_H

#include <QDialog>

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private slots:
    void on_pushButtonInsertarAlumno_clicked();

    void on_pushButtonMostrarAlumno_clicked();

    void on_pushButtonBorrarAlumno_clicked();

    void on_pushButtonModificarAlumno_clicked();

    void on_pushButtonListadoAlumnos_clicked();

    void on_pushButtonGuardarCopia_clicked();

    void on_pushButtonCargarCopia_clicked();

    void on_pushButtonSalir_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
